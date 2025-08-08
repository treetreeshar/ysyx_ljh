/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <memory/paddr.h>
#include <elf.h>

void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm();
void init_ftrace();

FuncSymbol *func_symbols = NULL;
int func_count = 0;

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  //Log("Exercise: Please remove me in the source code and compile NEMU again.");
  //assert(0);
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static char *ftrace_file = NULL;
static int difftest_port = 1234;

static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"ftrace"   , required_argument, NULL, 'f'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:f:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'f': ftrace_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. */

  /* Parse arguments. */
  parse_args(argc, argv);

  /* Set random seed. */
  init_rand();

  /* Open the log file. */
  init_log(log_file);

  /* Initialize memory. */
  init_mem();

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());

  /*ftrace*/
  if(ftrace_file != NULL){
    init_ftrace(ftrace_file);
  }

  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  init_sdb();

  IFDEF(CONFIG_ITRACE, init_disasm());

  /* Display welcome message. */
  welcome();
}
#else // CONFIG_TARGET_AM
static long load_img() {
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
  return size;
}

void am_init_monitor() {
  init_rand();
  init_mem();
  init_isa();
  load_img();
  IFDEF(CONFIG_DEVICE, init_device());
  welcome();
}
#endif

/***********************ftrace***********************/

void init_ftrace(const char *ftrace_file){
  FILE *fp = fopen(ftrace_file, "rb");
  if(!fp){
    printf("ftrace: failed to open file.\n");
    return;
  }

  Elf32_Ehdr ehdr;
  if(fread(&ehdr, sizeof(ehdr), 1, fp) != 1) {
    printf("Failed to read ELF header.\n");
    fclose(fp);
    return;
  }

  if(memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0){
    printf("Not an ELF file.\n");
    fclose(fp);
    return;
  }

  fseek(fp, ehdr.e_shoff, SEEK_SET);//节头表偏移量, 从文件头开始
  Elf32_Shdr *shdr = malloc(ehdr.e_shentsize * ehdr.e_shnum);//单个节头表条目的大小*节头表条目数量
  assert(shdr != NULL);
  if (fread(shdr, ehdr.e_shentsize, ehdr.e_shnum, fp) != ehdr.e_shnum) {
    free(shdr);
    fclose(fp);
    assert(0 && "Failed to read section headers");
  }//读取节头表 每次读取, 读取次数

  char* shstrtab = (char*)malloc(shdr[ehdr.e_shstrndx].sh_size);//节名称字符串表的大小
  fseek(fp, shdr[ehdr.e_shstrndx].sh_offset, SEEK_SET);//节名称字符串表偏移量
  if (fread(shstrtab, 1, shdr[ehdr.e_shstrndx].sh_size, fp) != shdr[ehdr.e_shstrndx].sh_size) {
    free(shstrtab);
    free(shdr);
    fclose(fp);
    assert(0 && "Failed to read section string table");
  }//读取节名称字符串表

  Elf32_Shdr* symtab_shdr = NULL;
  Elf32_Shdr* strtab_shdr = NULL;

  for (int i = 0; i < ehdr.e_shnum; i++) {//节头表条目总数
    char* section_name = shstrtab + shdr[i].sh_name;//获取节名称
    if (strcmp(section_name, ".symtab") == 0) {//符号
      symtab_shdr = &shdr[i];
    } else if (strcmp(section_name, ".strtab") == 0) {//字符串
      strtab_shdr = &shdr[i];
    }
  }

  if (!symtab_shdr || !strtab_shdr) {
    printf("Symbol table or string table not found.\n");
    free(shstrtab);
    free(shdr);
    fclose(fp);
    return;
  }
    
  char* strtab = (char*)malloc(strtab_shdr->sh_size);
  fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
  if (fread(strtab, 1, strtab_shdr->sh_size, fp) != strtab_shdr->sh_size) {
    free(strtab);
    free(shstrtab);
    free(shdr);
    fclose(fp);
    assert(0 && "Failed to read string table");
  }//读取字符串表

  Elf32_Sym* symtab = (Elf32_Sym*)malloc(symtab_shdr->sh_size);//节的大小
  fseek(fp, symtab_shdr->sh_offset, SEEK_SET);
  if (fread(symtab, 1, symtab_shdr->sh_size, fp) != symtab_shdr->sh_size) {
    free(symtab);
    free(strtab);
    free(shstrtab);
    free(shdr);
    fclose(fp);
    assert(0 && "Failed to read symbol table");
  }//读取符号表

  int num_funcs = 0;
  for (int i = 0; i < symtab_shdr->sh_size / sizeof(Elf32_Sym); i++) {
    if (ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC) {
      num_funcs++;
    }
  }//统计函数符号数量

  func_symbols = malloc(num_funcs * sizeof(FuncSymbol));//保存函数符号信息
    
  for (int i = 0; i < symtab_shdr->sh_size / sizeof(Elf32_Sym); i++) {
    if (ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC) {
      func_symbols[func_count].addr = symtab[i].st_value;
      func_symbols[func_count].size = symtab[i].st_size;
      func_symbols[func_count].name = strtab + symtab[i].st_name;
      func_count++;
    }
  }

  free(symtab);
  free(strtab);
  free(shdr);
  free(shstrtab);
  fclose(fp);

}
/*
  
  printf("Loaded %d function symbols:\n", func_count);
    for (int i = 0; i < func_count; i++) {
        printf("  [0x%08x] %s (size: %u bytes)\n", 
               func_symbols[i].addr, 
               func_symbols[i].name, 
               func_symbols[i].size);
    }

记得在程序退出时释放 func_symbols 的内存。?


typedef struct
{
  unsigned char	e_ident[EI_NIDENT];	 魔数和文件标识
  Elf32_Half	e_type;	               文件类型（可执行/共享库等）
  Elf32_Half	e_machine;             CPU架构
  Elf32_Word	e_version;             ELF版本
  Elf32_Addr	e_entry;	             程序入口地址
  Elf32_Off	e_phoff;	               程序头表偏移
  Elf32_Off	e_shoff;		             节头表偏移
  Elf32_Word	e_flags;		           处理器特定标志
  Elf32_Half	e_ehsize;		           ELF头大小
  Elf32_Half	e_phentsize;           程序头表条目大小
  Elf32_Half	e_phnum;		           程序头表条目数
  Elf32_Half	e_shentsize;           节头表条目大小
  Elf32_Half	e_shnum;		           节头表条目数
  Elf32_Half	e_shstrndx;	           节名字符串表索引
} Elf32_Ehdr;

typedef struct
{
  Elf32_Word	sh_name;      节名称在 .shstrtab 字符串表中的偏移量	
  Elf32_Word	sh_type;      节的类型
  Elf32_Word	sh_flags;     节的属性标志（可读/可写/可执行）
  Elf32_Addr	sh_addr;      节加载到内存时的虚拟地址（若不可加载则为 0）
  Elf32_Off	sh_offset;      节在ELF文件中的起始偏移量（字节）
  Elf32_Word	sh_size;      节的大小（字节）
  Elf32_Word	sh_link;      依赖的关联节索引
  Elf32_Word	sh_info;      附加信息
  Elf32_Word	sh_addralign; 节的内存对齐要求
  Elf32_Word	sh_entsize;   固定大小节的条目大小
  } Elf32_Shdr;
*/