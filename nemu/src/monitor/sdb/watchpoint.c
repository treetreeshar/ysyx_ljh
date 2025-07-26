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

#include "sdb.h"

#define NR_WP 32

static WP wp_pool[NR_WP] = {};
WP *head = NULL;
static WP *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;//使用中链表的指针为空
  free_ = wp_pool;//空闲链表的指针指向第一个
}

/* TODO: Implement the functionality of watchpoint */

WP *new_wp(){
	if(free_ == NULL){
		printf("No free wp now");
		assert(0);
		return NULL;
	}
	
	WP *wp = free_;//使wp声明在函数顶部（不在else中）
	free_ = free_->next;
		
	wp->next = head;//先让新节点指向原链表的（下一个/指针）
	head = wp;//再让原链表的指针指向新节点
		
	wp->expr[0] = '\0';//初始化表达式字符串
	wp->last_val = 0;
	
	
	return wp;
}

void free_wp (WP *wp){
	if(head == NULL){
		printf("No working wp now");
		return;
	}
	else{
		if(head == wp){
			head = head->next;//如果是头节点
		}
		else{
			WP *pre = head;
			while(pre !=NULL && pre->next != wp){
				pre = pre->next;
			}
			if(pre != NULL){
				pre->next = wp->next;
			}
		}
		wp->next = free_;
		free_ = wp;
	}
}

void wp_display(){
	if (head == NULL) {
		printf("No wp yet\n");
		return;
	}
	    
	printf("%-8s%-16s%s\n", "NO", "Value", "Expression");
	    
	WP *wp = head;
	while(wp != NULL) {
		printf("%-8d0x%-14x%s\n", wp->NO, wp->last_val, wp->expr);
		wp = wp->next;
	}
}


bool wp_scan(){
    bool changed = false;
    WP *wp = head;
    
    while(wp != NULL){
        bool success;
        uint32_t new_val = expr(wp->expr, &success);
        if(!success){
            printf("Wp: %d Expr: \"%s\" expr failed\n", wp->NO, wp->expr);
            wp = wp->next;
            continue;
        }
        if(new_val != wp->last_val){
            printf("Wp %d: %s Changed.\n\tOld value = 0x%x\n\tNew value = 0x%x\n", wp->NO, wp->expr, wp->last_val, new_val);
            
            wp->last_val = new_val;
            changed = true;
        }
        wp = wp->next;
    }
    return changed;
}







