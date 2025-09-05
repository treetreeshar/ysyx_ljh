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
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
word_t paddr_read(paddr_t addr, int len);//先声明


/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");//阻塞并等待用户在终端输入，显示提示符 "(nemu) "

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
	nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args){
    int steps = 1;
   if (args) {
        sscanf(args, "%d", &steps);
    }
    cpu_exec(steps);
    return 0;
}

static int cmd_info(char *args){
	char *arg = strtok(NULL, " ");
	if(arg == NULL) printf("print \'info r or w\'\n");
	else{
		switch(*arg){
			case 'r':{printf("pc: 0x%x\n",cpu.pc);isa_reg_display(); break;}
			case 'w':{wp_display(); break;}
			default:{printf("print \'info r or w\'\n"); break;}
			}
	}
	return 0;
}

static int cmd_x(char*args){
	char *arg1 = strtok(NULL, " ");
	char *arg2 = strtok(NULL, " ");
	if(arg1 == NULL || arg2 == NULL) printf("print \'x N EXPR\'\n");
	else {
		char *endptr;
		long len = strtol(arg1, &endptr, 0);
		if(*endptr != '\0' || len <= 0) printf("wrong len\n");
		else{
			unsigned long addr = strtoul(arg2, &endptr, 0);
			if(*endptr != '\0') printf("wrong addr\n");
			else{
				for (int i = 0; i < len * 4; i+=4) {
					printf("0x%08lx: 0x%08x \n ",addr + i, paddr_read(addr + i, 4));
				    }
			}
		}
	}
	return 0;
}

static int cmd_p(char *args){
	if(args == NULL){
		printf("print \'p Expression\'\n");
	}
	bool success;
	uint32_t ans = expr(args, &success);
	
	if(success) {
		printf("Ans: %u\n", ans);
	}else{
		printf("Expr failed.Sth is wrong.Maybe Chinese token?\n");
	}
	return 0;
}

static int cmd_w(char *args){
	if(args == NULL){
		printf("print \'w Expression\'\n");
		return 0;
	}
	
	bool success;
	uint32_t expr_val = expr(args, &success);
	if (!success) {
        	printf("Expr failed: %s\n", args);
        return 1;
	}
	else{
		printf("Expr: %d\n", expr_val);
	}
	
	WP *wp = new_wp();
	if (wp == NULL) {
		printf("new_wp failed\n");
		return 1;
	}
	strncpy(wp->expr, args, sizeof(wp->expr) - 1);
	wp->expr[sizeof(wp->expr) - 1] = '\0';
	wp->last_val = expr_val;
	printf("Watchpoint %d: %s (initial value = 0x%x)\n", wp->NO, wp->expr, wp->last_val);
	return 0;
}

static int cmd_d(char *args){
	if(args == NULL){
		printf("print \'d [N]\'\n");
		return 0;
	}
	char *endptr;
	long no = strtol(args, &endptr, 10);
	if(*endptr != '\0' || no < 0){
        	printf("Invalid number: %s\n", args);
        	return 0;
	}
	WP *wp = head;
	while(wp != NULL){
		if(wp->NO == no){
			printf("Delete watchpoint %d: %s\n", wp->NO, wp->expr);
			free_wp(wp);
			return 0;
        }
        wp = wp->next;
    }
    
    printf("No wp: %ld\n", no);
    return 1;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Step in for [N] times", cmd_si },
  { "info", "Print the information of [r]eg/[w]atchpoint", cmd_info },
  { "x", "Print internal storage for [N] byte, start from [EXPR]", cmd_x },
  { "p", "Culculate [Exprssion]", cmd_p },
  { "w", "Set wathchpoint at [Exprssion]", cmd_w },
  { "d", "Delete wathchpoint NO.[N]", cmd_d },
  
  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {//rl_gets返回字符串
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");//分割
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
