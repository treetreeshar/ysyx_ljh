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

#include <common.h>
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <isa.h>
*/
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

word_t expr(char *e, bool *success);//声明

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
  
  FILE *fp = fopen("./tools/gen-expr/input", "r");
    if(fp == NULL) {
        printf("Can't open");
        return -1;
    }

    char line[65530];
    int total = 0, pass = 0;

    while(fgets(line, sizeof(line), fp)){
        total++;
        line[strcspn(line, "\n")] = 0;//将换行符设置为字符串结束字符\0
        
        char *space = strchr(line, ' ');//查找空格
        if(!space){
            printf("Can't find space");
            continue;
        }
        *space = '\0';
        
        uint32_t expected = atoi(line);
        char *expr_str = space + 1;
        
        bool success;
        uint32_t result = expr(expr_str, &success);
        
        if(!success){
            printf("Test %d: Eval failed! Expr: %s\n", total, expr_str);
        }else if(result != expected){
            printf("Test %d: Failed. Expr: %s\n", total, expr_str);
            printf("  Expected: %u, Got: %u\n", expected, result);
        }else{
            pass++;
        }
    }

    fclose(fp);
    printf("Summary: %d/%d passed\n", pass, total);
    
  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
