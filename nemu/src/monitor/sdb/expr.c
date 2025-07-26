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
/* We use the POSIX regex functions to process regular expressions.正则表达式函数库
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

bool check_parentheses(int p, int q);
int find_op(int p, int q);
int find_priority(int a);
word_t isa_reg_str2val(const char *s, bool *success);
extern const char *regs[32];
word_t vaddr_read(vaddr_t addr, int len);

enum {//枚举 自动+1
  TK_NOTYPE = 256, TK_EQ, TK_NUM, TK_NEQ, TK_AND, TK_REG, TK_PTR, TK_MUS

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
   
  {"0x[0-9a-fA-F]+|[0-9]+", TK_NUM},
  
  {"\\(", '('},
  {"\\)", ')'},
  
  {"\\*", '*'},
  {"/", '/'},
  
  {"\\-", '-'},
  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  
  {"==", TK_EQ},        // equal
  {"!=", TK_NEQ},
  {"&&", TK_AND},
  
  {"\\$[a-z]+[0-9]*", TK_REG},
  
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};//声明一个正则表达式数组 存储编译结果

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);//regcomp：编译正则表达式
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[65536] __attribute__((used)) = {};//存放已识别出的token信息 __arrrubutr__((uesd)):强制gcc保留此变量
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;//声明一个匹配结果结构体类型 0开始 [.rm_so起始偏移  .rm_eo结束偏移)

  nr_token = 0;//已被识别出的token数目

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {//正则匹配成功&&匹配从字符串开头开始 regexec:执行模式匹配
        char *substr_start = e + position;//开始的地方
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
         
        switch (rules[i].token_type) {
        	case TK_NOTYPE:break;
        	case TK_EQ  : tokens[nr_token].type=TK_EQ ; nr_token++; break;
        	case TK_NEQ : tokens[nr_token].type=TK_NEQ; nr_token++; break;
        	case TK_AND : tokens[nr_token].type=TK_AND; nr_token++; break;
        	
        	case TK_REG:
			    tokens[nr_token].type = TK_REG;
			    snprintf(tokens[nr_token].str, sizeof(tokens[nr_token].str), "%.*s", substr_len, substr_start);
			    nr_token++;
			    break;
        	
        	case '(' : tokens[nr_token].type='('; nr_token++; break;
        	case ')' : tokens[nr_token].type=')'; nr_token++; break;
        	
        	case '*' : 
        		if(     tokens[nr_token-1].type == 0 || 
				tokens[nr_token-1].type == '(' ||
				tokens[nr_token-1].type == '+' || 
				tokens[nr_token-1].type == '-' ||
				tokens[nr_token-1].type == '*' || 
				tokens[nr_token-1].type == '/' 
				){
				tokens[nr_token].type=TK_PTR; nr_token++; break;}
        		else {tokens[nr_token].type='*'; nr_token++; break;}
        	
        	case '/' : tokens[nr_token].type='/'; nr_token++; break;
        	case '+' : tokens[nr_token].type='+'; nr_token++; break;
        	
        	case '-' : 
        		if(     tokens[nr_token-1].type == 0 || 
				tokens[nr_token-1].type == '(' ||
				tokens[nr_token-1].type == '+' || 
				tokens[nr_token-1].type == '-' ||
				tokens[nr_token-1].type == '*' || 
				tokens[nr_token-1].type == '/' 
				){
        			tokens[nr_token].type=TK_MUS; nr_token++; break;}
        		else{tokens[nr_token].type='-';nr_token++; break;}
        	
        	case TK_NUM :   tokens[nr_token].type=TK_NUM; 
        			int len = pmatch.rm_eo - pmatch.rm_so;
				if(len >= 32) {printf("num is too long\n"); return false;}
				snprintf(tokens[nr_token].str, 32, "%.*s", len, substr_start);
        			nr_token++; 
        			break;
          default: printf("no this type: %d ?\n",rules[i].token_type);
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}


int32_t eval(int p, int q,bool *success){
	*success = true;
	//先检查括号是否正确闭合
	if(p == 0 && q == nr_token - 1){
		int count = 0;
		for(int i = p;i <= q;i++){
			switch(tokens[i].type){
				    case '(': {count++; break;}
				    case ')': {count--; break;}
				    default: break;
			}
		}
		if(count < 0){printf("中途括号不匹配\n"); *success = false; return false;}
		if(count != 0){printf("括号未闭合\n"); *success = false; return false;}
	}	
	
	//求值
	if (tokens[p].type == TK_MUS) {
	    return -eval(p+1, q, success);
	}
	else if(p > q){
		printf("bad expression\n");
		*success = false;
		return false;
	}
	else if(p == q) {
		switch(tokens[p].type) {
		    case TK_NUM:
		        return strtoul(tokens[p].str, NULL, 0);
		        
		    case TK_REG:
		        bool success_reg;
		        uint32_t val = isa_reg_str2val(tokens[p].str + 1, &success_reg);
		        if(!success_reg) {
		            printf("Invalid register: %s\n", tokens[p].str);
		            *success = false;
		        }
		        return val;
		  
		    default:
		        printf("Invalid single token: type=%d\n", tokens[p].type);
		        *success = false;
		        return 0;
			}
		}
	    
	else if(check_parentheses(p, q) == true){
		return eval(p + 1, q - 1, success);
	}
	else if(tokens[p].type == TK_PTR) {
		uint32_t addr = eval(p+1, q, success);
		return vaddr_read(addr, 4);
    	}
	else{
		int op = find_op(p, q);//主运算符在token表达式里的位置
		int32_t val1 = eval(p, op - 1,success);
		int32_t val2 = eval(op + 1, q,success);
		
		switch(tokens[op].type){
			case '+': return val1 + val2;
			case '-': return val1 - val2;
			case '*': return val1 * val2;
			case '/': 
				if(val2 == 0){printf("除数为零"); *success = false; return false;}
				else return val1 / val2;
			case TK_EQ:
			case TK_AND: 
			 	if(val1 == val2) return 1;
				else return 0;
			case TK_NEQ: 
				if(val1 != val2) return 1;
				else return 0;
			default:{
				printf("unavailable expression operator: %d\n", tokens[op].type); 
				*success = false; 
				return 0;}
		}
	}
	return *success;
}



bool check_parentheses(int p, int q) {
	if(tokens[p].type != '(' || tokens[q].type != ')') return false;//如果最外层不是括号
    
	int count = 0;
	for(int i=p; i<=q; i++){
    		switch(tokens[i].type){
	    		case '(': {count++; break;}
	    		case ')': {count--; break;}
	    		default: break;
	    	}
    	if(count == 0 && i < q) return false;//(3+4)*5未完全包围
    	if(count < 0) return false;//())(
	}
	return count == 0;
}


    
int find_op(int p, int q){
	int cnt = 0;
	int pri_now;
	int pri_min = -1;
	int op = 0;
	for(int i=0; i<(q-p); i++){
		switch(tokens[p+i].type){
			case '(': {cnt++;break;}
			case ')': {cnt--;break;}
			default:break;
		}
		if(cnt != 0) continue;
		else {  pri_now=find_priority(tokens[p+i].type);
			if(pri_now >= pri_min){
				op = p+i;
				pri_min = pri_now;
			}
		}
	}
	return op;
}

int find_priority(int a){
	int pri = 0;
	switch(a){
		case TK_AND: return 5;
		case TK_EQ: 
		case TK_NEQ: return 4;
		case '+': 
		case '-': return 3;
		case '*': 
		case '/':
		case TK_MUS: return 2;
		case TK_PTR: return 1;
		default: return 0;
		}
	return pri;
}



word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  
  	bool eval_success = true;
    uint32_t ans = eval(0, nr_token - 1, &eval_success);
    *success = eval_success;
    
  /* TODO: Insert codes to evaluate the expression. */
  //TODO();

  return ans;
}















