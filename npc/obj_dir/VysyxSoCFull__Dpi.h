// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYXSOCFULL__DPI_H_
#define VERILATED_VYSYXSOCFULL__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/treetree/ysyx-workbench/npc/../ysyxSoC/perip/flash/flash.v:84:30
    extern void flash_read(int addr, int* data);
    // DPI import at /home/treetree/ysyx-workbench/npc/vsrc/ysyx_25070198.v:62:34
    extern void npc_ebreak();
    // DPI import at /home/treetree/ysyx-workbench/npc/vsrc/ysyx_25070198.v:63:33
    extern int pmem_read(int raddr);
    // DPI import at /home/treetree/ysyx-workbench/npc/vsrc/ysyx_25070198.v:64:34
    extern void pmem_write(int waddr, int wdata, char wmask);
    // DPI import at /home/treetree/ysyx-workbench/npc/vsrc/ysyx_25070198.v:61:34
    extern void trans(int pc0, int inst0, int a00);

#ifdef __cplusplus
}
#endif

#endif  // guard
