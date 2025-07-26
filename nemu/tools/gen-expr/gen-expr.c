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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
static int buf_index = 0;
static int depth = 0;

static void gen_rand_op();
static void gen_num();
static void gen(char ch);
static uint32_t choose(uint32_t n);

static void gen_rand_expr() {
	if(depth == 10) {gen_num(); return;}
	depth++;
	switch (choose(3)){
		case 0: gen_num(); break;
		case 1: gen('('); gen_rand_expr(); gen(')'); break;
		default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
	}
	depth--;
	if(rand() % 4 == 0) gen(' ');
}

static void gen_num(){
	int num = choose(100) + 1;
	buf_index += snprintf(buf + buf_index, sizeof(buf) - buf_index, "%d", num);
}

static void gen(char ch){
	if(buf_index < sizeof(buf) - 1) buf[buf_index++] = ch;
	else return;
}

static void gen_rand_op(){
	  char ops[] = {'+', '-', '*', '/'};
	  gen(ops[choose(4)]);
}

static uint32_t choose(uint32_t n){
	return rand() % n;
}


int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    buf_index = 0;//
    depth = 0;//
    gen_rand_expr();
    buf[buf_index] = '\0';//

    sprintf(code_buf, code_format, buf);//生成的表达式放在buf里

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -Wall -Werror=div-by-zero -Werror=overflow -o /tmp/.expr");//调用命令行指令
    if (ret != 0) continue;//0:编译成功 执行下面代码  非0:跳过下面代码
   
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
    
  }
  return 0;
}
