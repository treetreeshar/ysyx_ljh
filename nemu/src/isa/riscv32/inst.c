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

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J, TYPE_R, TYPE_B,
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs1); } while (0)//提取寄存器r1的值
#define src2R() do { *src2 = R(rs2); } while (0)//提取寄存器r2的值
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)//提取12位有符号立即数
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)//提取20位立即数并左移12位
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)//提取并合并12位立即数
#define immJ() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 20) | \
                                BITS(i, 19, 12) << 12 | \
                                BITS(i, 20, 20) << 11 | \
                                BITS(i, 30, 21) << 1; } while (0)
#define immB() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 12) | \
                                BITS(i, 7, 7) << 11 | \
                                BITS(i, 30, 25) << 5 | \
                                BITS(i, 11, 8) << 1; } while(0)
/*
static word_t csr_read(word_t csr_addr) {
  switch (csr_addr) {
    case 0x300: return cpu.mstatus;
    case 0x305: return cpu.mtvec;
    case 0x341: return cpu.mepc;
    case 0x342: return cpu.mcause;
    case 0x304: return cpu.mie;
    case 0x344: return cpu.mip;
    case 0x340: return cpu.mscratch;
    default: 
      printf("Unsupported CSR read: 0x%03x\n", csr_addr);
      isa_raise_intr(EXCEPTION_ILLEGAL_INSTRUCTION, cpu.pc);
      return 0;
  }
}

static void csr_write(word_t csr_addr, word_t value) {
  switch (csr_addr) {
    case 0x300: cpu.mstatus = value; break;
    case 0x305: cpu.mtvec = value; printf("mtvec set to 0x%08x\n", value); break;
    case 0x341: cpu.mepc = value; break;
    case 0x342: cpu.mcause = value; break;
    case 0x304: cpu.mie = value; break;
    case 0x344: cpu.mip = value; break;
    case 0x340: cpu.mscratch = value; break;
    default:
      printf("Unsupported CSR write: 0x%03x\n", csr_addr);
      isa_raise_intr(EXCEPTION_ILLEGAL_INSTRUCTION, cpu.pc);
      break;
  }
}
*/
static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_J:                   immJ(); break;
    case TYPE_N: break;
    case TYPE_R: src1R(); src2R();         break;
    case TYPE_B: src1R(); src2R(); immB(); break;
    default: panic("unsupported type = %d", type);
  }
}

static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));
  //dummy
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = imm + src1);
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s->pc + 4; s->dnpc = s->pc + imm;);
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2));
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, R(rd) = s->pc + 4; s->dnpc = (src1 + imm) & ~0x1;);
  //sum
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4));
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if(src1 != src2) {s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = (src1 < (word_t)imm) ? 1 : 0;);
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if(src1 == src2) {s->dnpc = s->pc + imm;});
  //fib
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
  //fact
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = src1 * src2);
  //div
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = (sword_t)src1 / (sword_t)src2);//补码==有符号
  //wanshu
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = (int32_t)src1 % (int32_t)src2);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, word_t i = INSTPAT_INST(s); R(rd) = src1 << BITS(i, 24, 20));
  //add add-longlong
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = ((word_t)src1 < (word_t)src2) ? 1 : 0;);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
  //bit
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2));//对齐？
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, word_t i = INSTPAT_INST(s); R(rd) = (sword_t)src1 >> BITS(i, 24, 20));
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << BITS(src2, 4, 0));
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm);
  //bubble-sort
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if((sword_t)src1 >= (sword_t)src2) {s->dnpc = s->pc + imm;});//补码=有符号
  //crc32
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, word_t i = INSTPAT_INST(s); R(rd) = src1 >> BITS(i, 24, 20));
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if(src1 >= src2) {s->dnpc = s->pc + imm;});
  //goldbach if-else
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if((sword_t)src1 < (sword_t)src2) {s->dnpc = s->pc + imm;});
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = ((sword_t)src1 < (sword_t)src2) ? 1 : 0;);
  //leap-year load-store
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));//对齐？
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2));
  //matrix-mul max mersenne
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, int64_t product = (int64_t)(int32_t)src1 * (int64_t)(int32_t)src2; R(rd) = (uint32_t)(product >> 32););
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = src1 % src2);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = src1 / src2);
  //min3 mov-c movsx mul-longlong pascal prime quick-sort recursion select-sort shift
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (word_t)((int32_t)src1 >> BITS(src2, 4, 0)));//算术右移：转为有符号数移再转回2
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", remu   , R, R(rd) = src1 >> BITS(src2, 4, 0));
  //shuixianhua sub-longlong switch
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if(src1 < src2) {s->dnpc = s->pc + imm;});
  //to-lower-case unalign
  //time?
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, int64_t product = (uint64_t)(uint32_t)src1 * (uint64_t)(uint32_t)src2; R(rd) = (uint32_t)(product >> 32););
  //dhrystone
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(rd) = ((int32_t)src1 < (int32_t)imm) ? 1 : 0;);
  //coremark
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm);
  //intr
  INSTPAT("??????? ????? ????? ??? ????? 11100 11", ecall  , I, isa_raise_intr(11, s->pc));
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, word_t t = cpu.mtvec; cpu.mtvec = src1; R(rd) = t;);

  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);//？获取指令（在nemu/include/cpu）
  return decode_exec(s);//？解码 执行
}
