// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VysyxSoCFull__Syms.h"


VL_ATTR_COLD void VysyxSoCFull___024root__trace_init_sub__TOP__0(VysyxSoCFull___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+574,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+575,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("ysyxSoCFull ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+574,"externalPins_uart_rx", false,-1);
    tracep->declBit(c+575,"externalPins_uart_tx", false,-1);
    tracep->pushNamePrefix("asic ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+365,"spi_sck", false,-1);
    tracep->declBus(c+366,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+367,"spi_mosi", false,-1);
    tracep->declBit(c+576,"spi_miso", false,-1);
    tracep->declBit(c+574,"uart_rx", false,-1);
    tracep->declBit(c+575,"uart_tx", false,-1);
    tracep->declBit(c+577,"sdram_clk", false,-1);
    tracep->declBit(c+368,"sdram_cke", false,-1);
    tracep->declBit(c+369,"sdram_cs", false,-1);
    tracep->declBit(c+370,"sdram_ras", false,-1);
    tracep->declBit(c+371,"sdram_cas", false,-1);
    tracep->declBit(c+372,"sdram_we", false,-1);
    tracep->declBus(c+373,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+374,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+375,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+578,"sdram_dq", false,-1, 15,0);
    tracep->pushNamePrefix("apbdelay_delayer ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBus(c+458,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+138,"in_psel", false,-1);
    tracep->declBit(c+139,"in_penable", false,-1);
    tracep->declBus(c+594,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+140,"in_pwrite", false,-1);
    tracep->declBus(c+141,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+549,"in_pready", false,-1);
    tracep->declBus(c+550,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+595,"in_pslverr", false,-1);
    tracep->declBus(c+458,"out_paddr", false,-1, 31,0);
    tracep->declBit(c+138,"out_psel", false,-1);
    tracep->declBit(c+139,"out_penable", false,-1);
    tracep->declBus(c+594,"out_pprot", false,-1, 2,0);
    tracep->declBit(c+140,"out_pwrite", false,-1);
    tracep->declBus(c+141,"out_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"out_pstrb", false,-1, 3,0);
    tracep->declBit(c+549,"out_pready", false,-1);
    tracep->declBus(c+550,"out_prdata", false,-1, 31,0);
    tracep->declBit(c+595,"out_pslverr", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("apbxbar ");
    tracep->declBit(c+138,"auto_anon_in_psel", false,-1);
    tracep->declBit(c+139,"auto_anon_in_penable", false,-1);
    tracep->declBit(c+140,"auto_anon_in_pwrite", false,-1);
    tracep->declBus(c+458,"auto_anon_in_paddr", false,-1, 31,0);
    tracep->declBus(c+594,"auto_anon_in_pprot", false,-1, 2,0);
    tracep->declBus(c+141,"auto_anon_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"auto_anon_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+549,"auto_anon_in_pready", false,-1);
    tracep->declBit(c+595,"auto_anon_in_pslverr", false,-1);
    tracep->declBus(c+550,"auto_anon_in_prdata", false,-1, 31,0);
    tracep->declBit(c+303,"auto_anon_out_2_psel", false,-1);
    tracep->declBit(c+304,"auto_anon_out_2_penable", false,-1);
    tracep->declBit(c+140,"auto_anon_out_2_pwrite", false,-1);
    tracep->declBus(c+458,"auto_anon_out_2_paddr", false,-1, 31,0);
    tracep->declBus(c+594,"auto_anon_out_2_pprot", false,-1, 2,0);
    tracep->declBus(c+141,"auto_anon_out_2_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"auto_anon_out_2_pstrb", false,-1, 3,0);
    tracep->declBit(c+376,"auto_anon_out_2_pready", false,-1);
    tracep->declBit(c+595,"auto_anon_out_2_pslverr", false,-1);
    tracep->declBus(c+7,"auto_anon_out_2_prdata", false,-1, 31,0);
    tracep->declBit(c+459,"auto_anon_out_1_psel", false,-1);
    tracep->declBit(c+460,"auto_anon_out_1_penable", false,-1);
    tracep->declBit(c+140,"auto_anon_out_1_pwrite", false,-1);
    tracep->declBus(c+461,"auto_anon_out_1_paddr", false,-1, 28,0);
    tracep->declBus(c+594,"auto_anon_out_1_pprot", false,-1, 2,0);
    tracep->declBus(c+141,"auto_anon_out_1_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"auto_anon_out_1_pstrb", false,-1, 3,0);
    tracep->declBit(c+462,"auto_anon_out_1_pready", false,-1);
    tracep->declBit(c+595,"auto_anon_out_1_pslverr", false,-1);
    tracep->declBus(c+579,"auto_anon_out_1_prdata", false,-1, 31,0);
    tracep->declBit(c+305,"auto_anon_out_0_psel", false,-1);
    tracep->declBit(c+306,"auto_anon_out_0_penable", false,-1);
    tracep->declBit(c+140,"auto_anon_out_0_pwrite", false,-1);
    tracep->declBus(c+463,"auto_anon_out_0_paddr", false,-1, 29,0);
    tracep->declBus(c+594,"auto_anon_out_0_pprot", false,-1, 2,0);
    tracep->declBus(c+141,"auto_anon_out_0_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"auto_anon_out_0_pstrb", false,-1, 3,0);
    tracep->declBit(c+580,"auto_anon_out_0_pready", false,-1);
    tracep->declBus(c+581,"auto_anon_out_0_prdata", false,-1, 31,0);
    tracep->declBit(c+464,"sel_0", false,-1);
    tracep->declBit(c+465,"sel_1", false,-1);
    tracep->declBit(c+466,"sel_2", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("axi42apb ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+143,"auto_in_awready", false,-1);
    tracep->declBit(c+144,"auto_in_awvalid", false,-1);
    tracep->declBus(c+145,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+146,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+147,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+148,"auto_in_awsize", false,-1, 2,0);
    tracep->declBit(c+143,"auto_in_wready", false,-1);
    tracep->declBit(c+149,"auto_in_wvalid", false,-1);
    tracep->declBus(c+150,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+151,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+152,"auto_in_bready", false,-1);
    tracep->declBit(c+551,"auto_in_bvalid", false,-1);
    tracep->declBus(c+153,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+154,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+155,"auto_in_arready", false,-1);
    tracep->declBit(c+156,"auto_in_arvalid", false,-1);
    tracep->declBus(c+157,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+158,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+159,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+160,"auto_in_arsize", false,-1, 2,0);
    tracep->declBit(c+161,"auto_in_rready", false,-1);
    tracep->declBit(c+552,"auto_in_rvalid", false,-1);
    tracep->declBus(c+162,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+582,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+154,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+138,"auto_out_psel", false,-1);
    tracep->declBit(c+139,"auto_out_penable", false,-1);
    tracep->declBit(c+140,"auto_out_pwrite", false,-1);
    tracep->declBus(c+458,"auto_out_paddr", false,-1, 31,0);
    tracep->declBus(c+141,"auto_out_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"auto_out_pstrb", false,-1, 3,0);
    tracep->declBit(c+549,"auto_out_pready", false,-1);
    tracep->declBit(c+595,"auto_out_pslverr", false,-1);
    tracep->declBus(c+550,"auto_out_prdata", false,-1, 31,0);
    tracep->declBit(c+139,"nodeOut_penable", false,-1);
    tracep->declBus(c+163,"state", false,-1, 1,0);
    tracep->declBit(c+155,"accept_read", false,-1);
    tracep->declBit(c+143,"accept_write", false,-1);
    tracep->declBit(c+164,"is_write_r", false,-1);
    tracep->declBit(c+140,"is_write", false,-1);
    tracep->declBus(c+162,"rid_reg", false,-1, 3,0);
    tracep->declBus(c+153,"bid_reg", false,-1, 3,0);
    tracep->declBus(c+165,"araddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+166,"awaddr_reg_r", false,-1, 31,0);
    tracep->declBus(c+167,"wdata_reg_r", false,-1, 31,0);
    tracep->declBus(c+168,"wstrb_reg_r", false,-1, 3,0);
    tracep->declBus(c+596,"resp", false,-1, 1,0);
    tracep->declBus(c+169,"resp_hold_r", false,-1, 1,0);
    tracep->declBus(c+154,"resp_hold", false,-1, 1,0);
    tracep->declBit(c+552,"nodeIn_rvalid", false,-1);
    tracep->declBus(c+170,"nodeIn_rdata_r", false,-1, 31,0);
    tracep->declBit(c+551,"nodeIn_bvalid", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("axi4buf ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+171,"auto_in_awready", false,-1);
    tracep->declBit(c+307,"auto_in_awvalid", false,-1);
    tracep->declBus(c+597,"auto_in_awid", false,-1, 3,0);
    tracep->declBus(c+562,"auto_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+598,"auto_in_awlen", false,-1, 7,0);
    tracep->declBus(c+467,"auto_in_awsize", false,-1, 2,0);
    tracep->declBus(c+596,"auto_in_awburst", false,-1, 1,0);
    tracep->declBit(c+172,"auto_in_wready", false,-1);
    tracep->declBit(c+308,"auto_in_wvalid", false,-1);
    tracep->declBus(c+563,"auto_in_wdata", false,-1, 31,0);
    tracep->declBus(c+564,"auto_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+599,"auto_in_wlast", false,-1);
    tracep->declBit(c+173,"auto_in_bready", false,-1);
    tracep->declBit(c+174,"auto_in_bvalid", false,-1);
    tracep->declBus(c+175,"auto_in_bid", false,-1, 3,0);
    tracep->declBus(c+176,"auto_in_bresp", false,-1, 1,0);
    tracep->declBit(c+177,"auto_in_arready", false,-1);
    tracep->declBit(c+309,"auto_in_arvalid", false,-1);
    tracep->declBus(c+597,"auto_in_arid", false,-1, 3,0);
    tracep->declBus(c+539,"auto_in_araddr", false,-1, 31,0);
    tracep->declBus(c+598,"auto_in_arlen", false,-1, 7,0);
    tracep->declBus(c+468,"auto_in_arsize", false,-1, 2,0);
    tracep->declBus(c+596,"auto_in_arburst", false,-1, 1,0);
    tracep->declBit(c+178,"auto_in_rready", false,-1);
    tracep->declBit(c+179,"auto_in_rvalid", false,-1);
    tracep->declBus(c+180,"auto_in_rid", false,-1, 3,0);
    tracep->declBus(c+181,"auto_in_rdata", false,-1, 31,0);
    tracep->declBus(c+182,"auto_in_rresp", false,-1, 1,0);
    tracep->declBit(c+183,"auto_in_rlast", false,-1);
    tracep->declBit(c+143,"auto_out_awready", false,-1);
    tracep->declBit(c+144,"auto_out_awvalid", false,-1);
    tracep->declBus(c+145,"auto_out_awid", false,-1, 3,0);
    tracep->declBus(c+146,"auto_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+147,"auto_out_awlen", false,-1, 7,0);
    tracep->declBus(c+148,"auto_out_awsize", false,-1, 2,0);
    tracep->declBit(c+143,"auto_out_wready", false,-1);
    tracep->declBit(c+149,"auto_out_wvalid", false,-1);
    tracep->declBus(c+150,"auto_out_wdata", false,-1, 31,0);
    tracep->declBus(c+151,"auto_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+152,"auto_out_bready", false,-1);
    tracep->declBit(c+551,"auto_out_bvalid", false,-1);
    tracep->declBus(c+153,"auto_out_bid", false,-1, 3,0);
    tracep->declBus(c+154,"auto_out_bresp", false,-1, 1,0);
    tracep->declBit(c+155,"auto_out_arready", false,-1);
    tracep->declBit(c+156,"auto_out_arvalid", false,-1);
    tracep->declBus(c+157,"auto_out_arid", false,-1, 3,0);
    tracep->declBus(c+158,"auto_out_araddr", false,-1, 31,0);
    tracep->declBus(c+159,"auto_out_arlen", false,-1, 7,0);
    tracep->declBus(c+160,"auto_out_arsize", false,-1, 2,0);
    tracep->declBit(c+161,"auto_out_rready", false,-1);
    tracep->declBit(c+552,"auto_out_rvalid", false,-1);
    tracep->declBus(c+162,"auto_out_rid", false,-1, 3,0);
    tracep->declBus(c+582,"auto_out_rdata", false,-1, 31,0);
    tracep->declBus(c+154,"auto_out_rresp", false,-1, 1,0);
    tracep->pushNamePrefix("nodeIn_bdeq_q ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+152,"io_enq_ready", false,-1);
    tracep->declBit(c+551,"io_enq_valid", false,-1);
    tracep->declBus(c+153,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+154,"io_enq_bits_resp", false,-1, 1,0);
    tracep->declBit(c+173,"io_deq_ready", false,-1);
    tracep->declBit(c+174,"io_deq_valid", false,-1);
    tracep->declBus(c+175,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+176,"io_deq_bits_resp", false,-1, 1,0);
    tracep->declBit(c+184,"wrap", false,-1);
    tracep->declBit(c+185,"wrap_1", false,-1);
    tracep->declBit(c+186,"maybe_full", false,-1);
    tracep->declBit(c+187,"ptr_match", false,-1);
    tracep->declBit(c+188,"empty", false,-1);
    tracep->declBit(c+189,"full", false,-1);
    tracep->declBit(c+553,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+185,"R0_addr", false,-1);
    tracep->declBit(c+599,"R0_en", false,-1);
    tracep->declBit(c+572,"R0_clk", false,-1);
    tracep->declBus(c+190,"R0_data", false,-1, 5,0);
    tracep->declBit(c+184,"W0_addr", false,-1);
    tracep->declBit(c+553,"W0_en", false,-1);
    tracep->declBit(c+572,"W0_clk", false,-1);
    tracep->declBus(c+191,"W0_data", false,-1, 5,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+192+i*1,"Memory", true,(i+0), 5,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+194,"do_deq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("nodeIn_rdeq_q ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+161,"io_enq_ready", false,-1);
    tracep->declBit(c+552,"io_enq_valid", false,-1);
    tracep->declBus(c+162,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+582,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+154,"io_enq_bits_resp", false,-1, 1,0);
    tracep->declBit(c+178,"io_deq_ready", false,-1);
    tracep->declBit(c+179,"io_deq_valid", false,-1);
    tracep->declBus(c+180,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+181,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+182,"io_deq_bits_resp", false,-1, 1,0);
    tracep->declBit(c+183,"io_deq_bits_last", false,-1);
    tracep->declBit(c+195,"wrap", false,-1);
    tracep->declBit(c+196,"wrap_1", false,-1);
    tracep->declBit(c+197,"maybe_full", false,-1);
    tracep->declBit(c+198,"ptr_match", false,-1);
    tracep->declBit(c+199,"empty", false,-1);
    tracep->declBit(c+200,"full", false,-1);
    tracep->declBit(c+554,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+196,"R0_addr", false,-1);
    tracep->declBit(c+599,"R0_en", false,-1);
    tracep->declBit(c+572,"R0_clk", false,-1);
    tracep->declQuad(c+201,"R0_data", false,-1, 38,0);
    tracep->declBit(c+195,"W0_addr", false,-1);
    tracep->declBit(c+554,"W0_en", false,-1);
    tracep->declBit(c+572,"W0_clk", false,-1);
    tracep->declQuad(c+583,"W0_data", false,-1, 38,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+203+i*2,"Memory", true,(i+0), 38,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+207,"do_deq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("nodeOut_ardeq_q ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+177,"io_enq_ready", false,-1);
    tracep->declBit(c+309,"io_enq_valid", false,-1);
    tracep->declBus(c+597,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+539,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+598,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+468,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+596,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+155,"io_deq_ready", false,-1);
    tracep->declBit(c+156,"io_deq_valid", false,-1);
    tracep->declBus(c+157,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+158,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+159,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+160,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBit(c+208,"wrap", false,-1);
    tracep->declBit(c+209,"wrap_1", false,-1);
    tracep->declBit(c+210,"maybe_full", false,-1);
    tracep->declBit(c+211,"ptr_match", false,-1);
    tracep->declBit(c+212,"empty", false,-1);
    tracep->declBit(c+213,"full", false,-1);
    tracep->declBit(c+469,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+209,"R0_addr", false,-1);
    tracep->declBit(c+599,"R0_en", false,-1);
    tracep->declBit(c+572,"R0_clk", false,-1);
    tracep->declQuad(c+214,"R0_data", false,-1, 46,0);
    tracep->declBit(c+208,"W0_addr", false,-1);
    tracep->declBit(c+469,"W0_en", false,-1);
    tracep->declBit(c+572,"W0_clk", false,-1);
    tracep->declQuad(c+540,"W0_data", false,-1, 46,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+216+i*2,"Memory", true,(i+0), 46,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+220,"do_deq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("nodeOut_awdeq_q ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+171,"io_enq_ready", false,-1);
    tracep->declBit(c+307,"io_enq_valid", false,-1);
    tracep->declBus(c+597,"io_enq_bits_id", false,-1, 3,0);
    tracep->declBus(c+562,"io_enq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+598,"io_enq_bits_len", false,-1, 7,0);
    tracep->declBus(c+467,"io_enq_bits_size", false,-1, 2,0);
    tracep->declBus(c+596,"io_enq_bits_burst", false,-1, 1,0);
    tracep->declBit(c+143,"io_deq_ready", false,-1);
    tracep->declBit(c+144,"io_deq_valid", false,-1);
    tracep->declBus(c+145,"io_deq_bits_id", false,-1, 3,0);
    tracep->declBus(c+146,"io_deq_bits_addr", false,-1, 31,0);
    tracep->declBus(c+147,"io_deq_bits_len", false,-1, 7,0);
    tracep->declBus(c+148,"io_deq_bits_size", false,-1, 2,0);
    tracep->declBit(c+221,"wrap", false,-1);
    tracep->declBit(c+222,"wrap_1", false,-1);
    tracep->declBit(c+223,"maybe_full", false,-1);
    tracep->declBit(c+224,"ptr_match", false,-1);
    tracep->declBit(c+225,"empty", false,-1);
    tracep->declBit(c+226,"full", false,-1);
    tracep->declBit(c+470,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+222,"R0_addr", false,-1);
    tracep->declBit(c+599,"R0_en", false,-1);
    tracep->declBit(c+572,"R0_clk", false,-1);
    tracep->declQuad(c+227,"R0_data", false,-1, 46,0);
    tracep->declBit(c+221,"W0_addr", false,-1);
    tracep->declBit(c+470,"W0_en", false,-1);
    tracep->declBit(c+572,"W0_clk", false,-1);
    tracep->declQuad(c+542,"W0_data", false,-1, 46,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+229+i*2,"Memory", true,(i+0), 46,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+233,"do_deq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("nodeOut_wdeq_q ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+172,"io_enq_ready", false,-1);
    tracep->declBit(c+308,"io_enq_valid", false,-1);
    tracep->declBus(c+563,"io_enq_bits_data", false,-1, 31,0);
    tracep->declBus(c+564,"io_enq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+599,"io_enq_bits_last", false,-1);
    tracep->declBit(c+143,"io_deq_ready", false,-1);
    tracep->declBit(c+149,"io_deq_valid", false,-1);
    tracep->declBus(c+150,"io_deq_bits_data", false,-1, 31,0);
    tracep->declBus(c+151,"io_deq_bits_strb", false,-1, 3,0);
    tracep->declBit(c+234,"wrap", false,-1);
    tracep->declBit(c+235,"wrap_1", false,-1);
    tracep->declBit(c+236,"maybe_full", false,-1);
    tracep->declBit(c+237,"ptr_match", false,-1);
    tracep->declBit(c+238,"empty", false,-1);
    tracep->declBit(c+239,"full", false,-1);
    tracep->declBit(c+471,"do_enq", false,-1);
    tracep->pushNamePrefix("ram_ext ");
    tracep->declBit(c+235,"R0_addr", false,-1);
    tracep->declBit(c+599,"R0_en", false,-1);
    tracep->declBit(c+572,"R0_clk", false,-1);
    tracep->declQuad(c+240,"R0_data", false,-1, 35,0);
    tracep->declBit(c+234,"W0_addr", false,-1);
    tracep->declBit(c+471,"W0_en", false,-1);
    tracep->declBit(c+572,"W0_clk", false,-1);
    tracep->declQuad(c+565,"W0_data", false,-1, 35,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+242+i*2,"Memory", true,(i+0), 35,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBit(c+246,"do_deq", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("axi4xbar ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+171,"auto_anon_in_awready", false,-1);
    tracep->declBit(c+307,"auto_anon_in_awvalid", false,-1);
    tracep->declBus(c+597,"auto_anon_in_awid", false,-1, 3,0);
    tracep->declBus(c+562,"auto_anon_in_awaddr", false,-1, 31,0);
    tracep->declBus(c+598,"auto_anon_in_awlen", false,-1, 7,0);
    tracep->declBus(c+467,"auto_anon_in_awsize", false,-1, 2,0);
    tracep->declBus(c+596,"auto_anon_in_awburst", false,-1, 1,0);
    tracep->declBit(c+172,"auto_anon_in_wready", false,-1);
    tracep->declBit(c+308,"auto_anon_in_wvalid", false,-1);
    tracep->declBus(c+563,"auto_anon_in_wdata", false,-1, 31,0);
    tracep->declBus(c+564,"auto_anon_in_wstrb", false,-1, 3,0);
    tracep->declBit(c+599,"auto_anon_in_wlast", false,-1);
    tracep->declBit(c+173,"auto_anon_in_bready", false,-1);
    tracep->declBit(c+174,"auto_anon_in_bvalid", false,-1);
    tracep->declBus(c+175,"auto_anon_in_bid", false,-1, 3,0);
    tracep->declBus(c+176,"auto_anon_in_bresp", false,-1, 1,0);
    tracep->declBit(c+177,"auto_anon_in_arready", false,-1);
    tracep->declBit(c+309,"auto_anon_in_arvalid", false,-1);
    tracep->declBus(c+597,"auto_anon_in_arid", false,-1, 3,0);
    tracep->declBus(c+539,"auto_anon_in_araddr", false,-1, 31,0);
    tracep->declBus(c+598,"auto_anon_in_arlen", false,-1, 7,0);
    tracep->declBus(c+468,"auto_anon_in_arsize", false,-1, 2,0);
    tracep->declBus(c+596,"auto_anon_in_arburst", false,-1, 1,0);
    tracep->declBit(c+178,"auto_anon_in_rready", false,-1);
    tracep->declBit(c+179,"auto_anon_in_rvalid", false,-1);
    tracep->declBus(c+180,"auto_anon_in_rid", false,-1, 3,0);
    tracep->declBus(c+181,"auto_anon_in_rdata", false,-1, 31,0);
    tracep->declBus(c+182,"auto_anon_in_rresp", false,-1, 1,0);
    tracep->declBit(c+183,"auto_anon_in_rlast", false,-1);
    tracep->declBit(c+171,"auto_anon_out_awready", false,-1);
    tracep->declBit(c+307,"auto_anon_out_awvalid", false,-1);
    tracep->declBus(c+597,"auto_anon_out_awid", false,-1, 3,0);
    tracep->declBus(c+562,"auto_anon_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+598,"auto_anon_out_awlen", false,-1, 7,0);
    tracep->declBus(c+467,"auto_anon_out_awsize", false,-1, 2,0);
    tracep->declBus(c+596,"auto_anon_out_awburst", false,-1, 1,0);
    tracep->declBit(c+172,"auto_anon_out_wready", false,-1);
    tracep->declBit(c+308,"auto_anon_out_wvalid", false,-1);
    tracep->declBus(c+563,"auto_anon_out_wdata", false,-1, 31,0);
    tracep->declBus(c+564,"auto_anon_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+599,"auto_anon_out_wlast", false,-1);
    tracep->declBit(c+173,"auto_anon_out_bready", false,-1);
    tracep->declBit(c+174,"auto_anon_out_bvalid", false,-1);
    tracep->declBus(c+175,"auto_anon_out_bid", false,-1, 3,0);
    tracep->declBus(c+176,"auto_anon_out_bresp", false,-1, 1,0);
    tracep->declBit(c+177,"auto_anon_out_arready", false,-1);
    tracep->declBit(c+309,"auto_anon_out_arvalid", false,-1);
    tracep->declBus(c+597,"auto_anon_out_arid", false,-1, 3,0);
    tracep->declBus(c+539,"auto_anon_out_araddr", false,-1, 31,0);
    tracep->declBus(c+598,"auto_anon_out_arlen", false,-1, 7,0);
    tracep->declBus(c+468,"auto_anon_out_arsize", false,-1, 2,0);
    tracep->declBus(c+596,"auto_anon_out_arburst", false,-1, 1,0);
    tracep->declBit(c+178,"auto_anon_out_rready", false,-1);
    tracep->declBit(c+179,"auto_anon_out_rvalid", false,-1);
    tracep->declBus(c+180,"auto_anon_out_rid", false,-1, 3,0);
    tracep->declBus(c+181,"auto_anon_out_rdata", false,-1, 31,0);
    tracep->declBus(c+182,"auto_anon_out_rresp", false,-1, 1,0);
    tracep->declBit(c+183,"auto_anon_out_rlast", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+585,"reset", false,-1);
    tracep->declBit(c+171,"auto_master_out_awready", false,-1);
    tracep->declBit(c+307,"auto_master_out_awvalid", false,-1);
    tracep->declBus(c+597,"auto_master_out_awid", false,-1, 3,0);
    tracep->declBus(c+562,"auto_master_out_awaddr", false,-1, 31,0);
    tracep->declBus(c+598,"auto_master_out_awlen", false,-1, 7,0);
    tracep->declBus(c+467,"auto_master_out_awsize", false,-1, 2,0);
    tracep->declBus(c+596,"auto_master_out_awburst", false,-1, 1,0);
    tracep->declBit(c+172,"auto_master_out_wready", false,-1);
    tracep->declBit(c+308,"auto_master_out_wvalid", false,-1);
    tracep->declBus(c+563,"auto_master_out_wdata", false,-1, 31,0);
    tracep->declBus(c+564,"auto_master_out_wstrb", false,-1, 3,0);
    tracep->declBit(c+599,"auto_master_out_wlast", false,-1);
    tracep->declBit(c+173,"auto_master_out_bready", false,-1);
    tracep->declBit(c+174,"auto_master_out_bvalid", false,-1);
    tracep->declBus(c+175,"auto_master_out_bid", false,-1, 3,0);
    tracep->declBus(c+176,"auto_master_out_bresp", false,-1, 1,0);
    tracep->declBit(c+177,"auto_master_out_arready", false,-1);
    tracep->declBit(c+309,"auto_master_out_arvalid", false,-1);
    tracep->declBus(c+597,"auto_master_out_arid", false,-1, 3,0);
    tracep->declBus(c+539,"auto_master_out_araddr", false,-1, 31,0);
    tracep->declBus(c+598,"auto_master_out_arlen", false,-1, 7,0);
    tracep->declBus(c+468,"auto_master_out_arsize", false,-1, 2,0);
    tracep->declBus(c+596,"auto_master_out_arburst", false,-1, 1,0);
    tracep->declBit(c+178,"auto_master_out_rready", false,-1);
    tracep->declBit(c+179,"auto_master_out_rvalid", false,-1);
    tracep->declBus(c+180,"auto_master_out_rid", false,-1, 3,0);
    tracep->declBus(c+181,"auto_master_out_rdata", false,-1, 31,0);
    tracep->declBus(c+182,"auto_master_out_rresp", false,-1, 1,0);
    tracep->declBit(c+183,"auto_master_out_rlast", false,-1);
    tracep->declBit(c+595,"io_interrupt", false,-1);
    tracep->declBit(c+595,"io_slave_awready", false,-1);
    tracep->declBit(c+595,"io_slave_awvalid", false,-1);
    tracep->declBus(c+597,"io_slave_awid", false,-1, 3,0);
    tracep->declBus(c+600,"io_slave_awaddr", false,-1, 31,0);
    tracep->declBus(c+598,"io_slave_awlen", false,-1, 7,0);
    tracep->declBus(c+601,"io_slave_awsize", false,-1, 2,0);
    tracep->declBus(c+596,"io_slave_awburst", false,-1, 1,0);
    tracep->declBit(c+595,"io_slave_wready", false,-1);
    tracep->declBit(c+595,"io_slave_wvalid", false,-1);
    tracep->declBus(c+600,"io_slave_wdata", false,-1, 31,0);
    tracep->declBus(c+597,"io_slave_wstrb", false,-1, 3,0);
    tracep->declBit(c+595,"io_slave_wlast", false,-1);
    tracep->declBit(c+595,"io_slave_bready", false,-1);
    tracep->declBit(c+595,"io_slave_bvalid", false,-1);
    tracep->declBus(c+597,"io_slave_bid", false,-1, 3,0);
    tracep->declBus(c+596,"io_slave_bresp", false,-1, 1,0);
    tracep->declBit(c+595,"io_slave_arready", false,-1);
    tracep->declBit(c+595,"io_slave_arvalid", false,-1);
    tracep->declBus(c+597,"io_slave_arid", false,-1, 3,0);
    tracep->declBus(c+600,"io_slave_araddr", false,-1, 31,0);
    tracep->declBus(c+598,"io_slave_arlen", false,-1, 7,0);
    tracep->declBus(c+601,"io_slave_arsize", false,-1, 2,0);
    tracep->declBus(c+596,"io_slave_arburst", false,-1, 1,0);
    tracep->declBit(c+595,"io_slave_rready", false,-1);
    tracep->declBit(c+595,"io_slave_rvalid", false,-1);
    tracep->declBus(c+597,"io_slave_rid", false,-1, 3,0);
    tracep->declBus(c+600,"io_slave_rdata", false,-1, 31,0);
    tracep->declBus(c+596,"io_slave_rresp", false,-1, 1,0);
    tracep->declBit(c+595,"io_slave_rlast", false,-1);
    tracep->pushNamePrefix("bridge ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+585,"reset", false,-1);
    tracep->declBus(c+472,"io_ifu_addr", false,-1, 31,0);
    tracep->declBit(c+247,"io_ifu_reqValid", false,-1);
    tracep->declBus(c+248,"io_ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+249,"io_ifu_respValid", false,-1);
    tracep->declBus(c+562,"io_lsu_addr", false,-1, 31,0);
    tracep->declBit(c+473,"io_lsu_reqValid", false,-1);
    tracep->declBus(c+181,"io_lsu_rdata", false,-1, 31,0);
    tracep->declBit(c+474,"io_lsu_respValid", false,-1);
    tracep->declBus(c+475,"io_lsu_size", false,-1, 1,0);
    tracep->declBit(c+476,"io_lsu_wen", false,-1);
    tracep->declBus(c+563,"io_lsu_wdata", false,-1, 31,0);
    tracep->declBus(c+564,"io_lsu_wmask", false,-1, 3,0);
    tracep->declBit(c+171,"io_master_awready", false,-1);
    tracep->declBit(c+307,"io_master_awvalid", false,-1);
    tracep->declBus(c+597,"io_master_awid", false,-1, 3,0);
    tracep->declBus(c+562,"io_master_awaddr", false,-1, 31,0);
    tracep->declBus(c+598,"io_master_awlen", false,-1, 7,0);
    tracep->declBus(c+467,"io_master_awsize", false,-1, 2,0);
    tracep->declBus(c+596,"io_master_awburst", false,-1, 1,0);
    tracep->declBit(c+172,"io_master_wready", false,-1);
    tracep->declBit(c+308,"io_master_wvalid", false,-1);
    tracep->declBus(c+563,"io_master_wdata", false,-1, 31,0);
    tracep->declBus(c+564,"io_master_wstrb", false,-1, 3,0);
    tracep->declBit(c+599,"io_master_wlast", false,-1);
    tracep->declBit(c+173,"io_master_bready", false,-1);
    tracep->declBit(c+174,"io_master_bvalid", false,-1);
    tracep->declBus(c+175,"io_master_bid", false,-1, 3,0);
    tracep->declBus(c+176,"io_master_bresp", false,-1, 1,0);
    tracep->declBit(c+177,"io_master_arready", false,-1);
    tracep->declBit(c+309,"io_master_arvalid", false,-1);
    tracep->declBus(c+597,"io_master_arid", false,-1, 3,0);
    tracep->declBus(c+539,"io_master_araddr", false,-1, 31,0);
    tracep->declBus(c+598,"io_master_arlen", false,-1, 7,0);
    tracep->declBus(c+468,"io_master_arsize", false,-1, 2,0);
    tracep->declBus(c+596,"io_master_arburst", false,-1, 1,0);
    tracep->declBit(c+178,"io_master_rready", false,-1);
    tracep->declBit(c+179,"io_master_rvalid", false,-1);
    tracep->declBus(c+180,"io_master_rid", false,-1, 3,0);
    tracep->declBus(c+181,"io_master_rdata", false,-1, 31,0);
    tracep->declBus(c+182,"io_master_rresp", false,-1, 1,0);
    tracep->declBit(c+183,"io_master_rlast", false,-1);
    tracep->declBit(c+477,"isValidLoad", false,-1);
    tracep->declBit(c+478,"isValidStore", false,-1);
    tracep->declBus(c+250,"stateI", false,-1, 1,0);
    tracep->declBus(c+251,"stateD", false,-1, 2,0);
    tracep->declBit(c+173,"io_master_bready_0", false,-1);
    tracep->declBit(c+479,"lsuRead", false,-1);
    tracep->declBit(c+249,"instReturn", false,-1);
    tracep->declBus(c+252,"io_ifu_rdata_r", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+585,"reset", false,-1);
    tracep->declBit(c+247,"io_ifu_reqValid", false,-1);
    tracep->declBus(c+472,"io_ifu_addr", false,-1, 31,0);
    tracep->declBit(c+249,"io_ifu_respValid", false,-1);
    tracep->declBus(c+248,"io_ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+473,"io_lsu_reqValid", false,-1);
    tracep->declBus(c+562,"io_lsu_addr", false,-1, 31,0);
    tracep->declBus(c+475,"io_lsu_size", false,-1, 1,0);
    tracep->declBit(c+476,"io_lsu_wen", false,-1);
    tracep->declBus(c+563,"io_lsu_wdata", false,-1, 31,0);
    tracep->declBus(c+564,"io_lsu_wmask", false,-1, 3,0);
    tracep->declBit(c+474,"io_lsu_respValid", false,-1);
    tracep->declBus(c+181,"io_lsu_rdata", false,-1, 31,0);
    tracep->declBus(c+480,"pc", false,-1, 31,0);
    tracep->declBus(c+544,"jump_pc", false,-1, 31,0);
    tracep->declBit(c+481,"jump", false,-1);
    tracep->declBit(c+482,"inst_valid", false,-1);
    tracep->declBus(c+483,"inst", false,-1, 31,0);
    tracep->declBus(c+484,"rs1", false,-1, 4,0);
    tracep->declBus(c+485,"rs2", false,-1, 4,0);
    tracep->declBus(c+486,"rd", false,-1, 4,0);
    tracep->declBus(c+487,"imm", false,-1, 31,0);
    tracep->declBit(c+488,"is_addi", false,-1);
    tracep->declBit(c+489,"is_jalr", false,-1);
    tracep->declBit(c+490,"is_add", false,-1);
    tracep->declBit(c+491,"is_lui", false,-1);
    tracep->declBit(c+492,"is_lw", false,-1);
    tracep->declBit(c+493,"is_lbu", false,-1);
    tracep->declBit(c+494,"is_sw", false,-1);
    tracep->declBit(c+495,"is_sb", false,-1);
    tracep->declBit(c+496,"is_csrrw", false,-1);
    tracep->declBus(c+567,"reg_rdata1", false,-1, 31,0);
    tracep->declBus(c+568,"reg_rdata2", false,-1, 31,0);
    tracep->declBit(c+497,"mem_ren", false,-1);
    tracep->declBit(c+498,"mem_wen", false,-1);
    tracep->declBit(c+499,"reg_wen", false,-1);
    tracep->declBit(c+500,"reg_men", false,-1);
    tracep->declBus(c+545,"reg_wdata", false,-1, 31,0);
    tracep->declBus(c+569,"mem_wdata", false,-1, 31,0);
    tracep->declBus(c+546,"mem_addr", false,-1, 29,0);
    tracep->declBus(c+570,"mem_mask", false,-1, 3,0);
    tracep->declBus(c+571,"sel", false,-1, 1,0);
    tracep->declBit(c+501,"csr_wen", false,-1);
    tracep->declBus(c+502,"csr_addr", false,-1, 11,0);
    tracep->declBus(c+503,"csr_rdata", false,-1, 31,0);
    tracep->declBit(c+504,"inst_done", false,-1);
    tracep->declBus(c+505,"mem_rdata", false,-1, 31,0);
    tracep->declBus(c+472,"ifu_raddr", false,-1, 31,0);
    tracep->declBus(c+602,"debug_x10", false,-1, 31,0);
    tracep->pushNamePrefix("ysyx_25070198_csr_reg0 ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+585,"reset", false,-1);
    tracep->declBit(c+501,"csr_wen", false,-1);
    tracep->declBus(c+502,"csr_addr", false,-1, 11,0);
    tracep->declBus(c+567,"csr_wdata", false,-1, 31,0);
    tracep->declBus(c+503,"csr_rdata", false,-1, 31,0);
    tracep->declBus(c+506,"mcycle", false,-1, 31,0);
    tracep->declBus(c+507,"mcycleh", false,-1, 31,0);
    tracep->declBus(c+508,"mvendorid", false,-1, 31,0);
    tracep->declBus(c+509,"marchid", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ysyx_25070198_exu0 ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+585,"reset", false,-1);
    tracep->declBit(c+482,"inst_valid", false,-1);
    tracep->declBit(c+488,"is_addi", false,-1);
    tracep->declBit(c+489,"is_jalr", false,-1);
    tracep->declBit(c+490,"is_add", false,-1);
    tracep->declBit(c+491,"is_lui", false,-1);
    tracep->declBit(c+492,"is_lw", false,-1);
    tracep->declBit(c+493,"is_lbu", false,-1);
    tracep->declBit(c+494,"is_sw", false,-1);
    tracep->declBit(c+495,"is_sb", false,-1);
    tracep->declBit(c+496,"is_csrrw", false,-1);
    tracep->declBus(c+503,"csr_rdata", false,-1, 31,0);
    tracep->declBit(c+501,"csr_wen", false,-1);
    tracep->declBus(c+502,"csr_addr", false,-1, 11,0);
    tracep->declBit(c+474,"io_lsu_respValid", false,-1);
    tracep->declBus(c+480,"pc", false,-1, 31,0);
    tracep->declBus(c+567,"reg_rdata1", false,-1, 31,0);
    tracep->declBus(c+568,"reg_rdata2", false,-1, 31,0);
    tracep->declBus(c+487,"imm", false,-1, 31,0);
    tracep->declBit(c+497,"mem_ren", false,-1);
    tracep->declBit(c+498,"mem_wen", false,-1);
    tracep->declBit(c+499,"reg_wen", false,-1);
    tracep->declBit(c+500,"reg_men", false,-1);
    tracep->declBus(c+545,"reg_wdata", false,-1, 31,0);
    tracep->declBus(c+569,"mem_wdata", false,-1, 31,0);
    tracep->declBus(c+546,"mem_addr", false,-1, 29,0);
    tracep->declBus(c+570,"mem_mask", false,-1, 3,0);
    tracep->declBus(c+571,"sel", false,-1, 1,0);
    tracep->declBus(c+544,"jump_pc", false,-1, 31,0);
    tracep->declBit(c+481,"jump", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ysyx_25070198_idu0 ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+585,"reset", false,-1);
    tracep->declBus(c+483,"inst", false,-1, 31,0);
    tracep->declBus(c+484,"rs1", false,-1, 4,0);
    tracep->declBus(c+485,"rs2", false,-1, 4,0);
    tracep->declBus(c+486,"rd", false,-1, 4,0);
    tracep->declBus(c+487,"imm", false,-1, 31,0);
    tracep->declBus(c+475,"io_lsu_size", false,-1, 1,0);
    tracep->declBit(c+488,"is_addi", false,-1);
    tracep->declBit(c+489,"is_jalr", false,-1);
    tracep->declBit(c+490,"is_add", false,-1);
    tracep->declBit(c+491,"is_lui", false,-1);
    tracep->declBit(c+492,"is_lw", false,-1);
    tracep->declBit(c+493,"is_lbu", false,-1);
    tracep->declBit(c+494,"is_sw", false,-1);
    tracep->declBit(c+495,"is_sb", false,-1);
    tracep->declBit(c+496,"is_csrrw", false,-1);
    tracep->declBus(c+510,"opcode", false,-1, 6,0);
    tracep->declBus(c+511,"funct3", false,-1, 2,0);
    tracep->declBus(c+512,"funct7", false,-1, 6,0);
    tracep->declBus(c+513,"i_imm", false,-1, 31,0);
    tracep->declBus(c+514,"s_imm", false,-1, 31,0);
    tracep->declBus(c+515,"u_imm", false,-1, 31,0);
    tracep->declBus(c+516,"csr_imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ysyx_25070198_ifu0 ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+585,"reset", false,-1);
    tracep->declBus(c+544,"jump_pc", false,-1, 31,0);
    tracep->declBit(c+481,"jump", false,-1);
    tracep->declBit(c+474,"io_lsu_respValid", false,-1);
    tracep->declBit(c+497,"mem_ren", false,-1);
    tracep->declBit(c+504,"inst_done", false,-1);
    tracep->declBus(c+480,"pc", false,-1, 31,0);
    tracep->declBus(c+483,"inst", false,-1, 31,0);
    tracep->declBit(c+482,"inst_valid", false,-1);
    tracep->declBus(c+472,"ifu_raddr", false,-1, 31,0);
    tracep->declBus(c+248,"io_ifu_rdata", false,-1, 31,0);
    tracep->declBit(c+247,"io_ifu_reqValid", false,-1);
    tracep->declBit(c+249,"io_ifu_respValid", false,-1);
    tracep->declBus(c+253,"ifu_current_state", false,-1, 1,0);
    tracep->declBus(c+517,"ifu_next_state", false,-1, 1,0);
    tracep->declBus(c+483,"inst_reg", false,-1, 31,0);
    tracep->declBus(c+310,"inst_next", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ysyx_25070198_lsu0 ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+585,"reset", false,-1);
    tracep->declBit(c+497,"mem_ren", false,-1);
    tracep->declBit(c+498,"mem_wen", false,-1);
    tracep->declBus(c+547,"mem_addr", false,-1, 31,0);
    tracep->declBus(c+569,"mem_wdata", false,-1, 31,0);
    tracep->declBus(c+570,"mem_mask", false,-1, 3,0);
    tracep->declBus(c+505,"mem_rdata", false,-1, 31,0);
    tracep->declBus(c+562,"io_lsu_addr", false,-1, 31,0);
    tracep->declBit(c+476,"io_lsu_wen", false,-1);
    tracep->declBus(c+563,"io_lsu_wdata", false,-1, 31,0);
    tracep->declBus(c+564,"io_lsu_wmask", false,-1, 3,0);
    tracep->declBus(c+181,"io_lsu_rdata", false,-1, 31,0);
    tracep->declBit(c+473,"io_lsu_reqValid", false,-1);
    tracep->declBit(c+474,"io_lsu_respValid", false,-1);
    tracep->declBit(c+254,"lsu_current_state", false,-1);
    tracep->declBit(c+311,"lsu_next_state", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ysyx_25070198_rf0 ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+585,"reset", false,-1);
    tracep->declBus(c+545,"reg_wdata", false,-1, 31,0);
    tracep->declBus(c+505,"mem_rdata", false,-1, 31,0);
    tracep->declBus(c+486,"reg_waddr", false,-1, 4,0);
    tracep->declBit(c+499,"reg_wen", false,-1);
    tracep->declBit(c+500,"reg_men", false,-1);
    tracep->declBit(c+493,"is_lbu", false,-1);
    tracep->declBus(c+571,"sel", false,-1, 1,0);
    tracep->declBus(c+602,"debug_x10", false,-1, 31,0);
    tracep->declBus(c+484,"reg_raddr1", false,-1, 4,0);
    tracep->declBus(c+485,"reg_raddr2", false,-1, 4,0);
    tracep->declBus(c+567,"reg_rdata1", false,-1, 31,0);
    tracep->declBus(c+568,"reg_rdata2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+326+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->declBus(c+548,"mem_rdatas", false,-1, 7,0);
    tracep->declBus(c+358,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("cpu_reset_chain ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"io_d", false,-1);
    tracep->declBit(c+255,"io_q", false,-1);
    tracep->pushNamePrefix("output_chain ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"io_d", false,-1);
    tracep->declBit(c+255,"io_q", false,-1);
    tracep->declBit(c+255,"sync_0", false,-1);
    tracep->declBit(c+256,"sync_1", false,-1);
    tracep->declBit(c+257,"sync_2", false,-1);
    tracep->declBit(c+258,"sync_3", false,-1);
    tracep->declBit(c+259,"sync_4", false,-1);
    tracep->declBit(c+260,"sync_5", false,-1);
    tracep->declBit(c+261,"sync_6", false,-1);
    tracep->declBit(c+262,"sync_7", false,-1);
    tracep->declBit(c+263,"sync_8", false,-1);
    tracep->declBit(c+264,"sync_9", false,-1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lsdram_apb ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+303,"auto_in_psel", false,-1);
    tracep->declBit(c+304,"auto_in_penable", false,-1);
    tracep->declBit(c+140,"auto_in_pwrite", false,-1);
    tracep->declBus(c+458,"auto_in_paddr", false,-1, 31,0);
    tracep->declBus(c+594,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+141,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+376,"auto_in_pready", false,-1);
    tracep->declBit(c+595,"auto_in_pslverr", false,-1);
    tracep->declBus(c+7,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+577,"sdram_bundle_clk", false,-1);
    tracep->declBit(c+368,"sdram_bundle_cke", false,-1);
    tracep->declBit(c+369,"sdram_bundle_cs", false,-1);
    tracep->declBit(c+370,"sdram_bundle_ras", false,-1);
    tracep->declBit(c+371,"sdram_bundle_cas", false,-1);
    tracep->declBit(c+372,"sdram_bundle_we", false,-1);
    tracep->declBus(c+373,"sdram_bundle_a", false,-1, 12,0);
    tracep->declBus(c+374,"sdram_bundle_ba", false,-1, 1,0);
    tracep->declBus(c+375,"sdram_bundle_dqm", false,-1, 1,0);
    tracep->declBus(c+578,"sdram_bundle_dq", false,-1, 15,0);
    tracep->pushNamePrefix("msdram ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBus(c+458,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+303,"in_psel", false,-1);
    tracep->declBit(c+304,"in_penable", false,-1);
    tracep->declBus(c+594,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+140,"in_pwrite", false,-1);
    tracep->declBus(c+141,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+376,"in_pready", false,-1);
    tracep->declBus(c+7,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+595,"in_pslverr", false,-1);
    tracep->declBit(c+577,"sdram_clk", false,-1);
    tracep->declBit(c+368,"sdram_cke", false,-1);
    tracep->declBit(c+369,"sdram_cs", false,-1);
    tracep->declBit(c+370,"sdram_ras", false,-1);
    tracep->declBit(c+371,"sdram_cas", false,-1);
    tracep->declBit(c+372,"sdram_we", false,-1);
    tracep->declBus(c+373,"sdram_a", false,-1, 12,0);
    tracep->declBus(c+374,"sdram_ba", false,-1, 1,0);
    tracep->declBus(c+375,"sdram_dqm", false,-1, 1,0);
    tracep->declBus(c+578,"sdram_dq", false,-1, 15,0);
    tracep->declBit(c+8,"sdram_dout_en", false,-1);
    tracep->declBus(c+9,"sdram_dout", false,-1, 15,0);
    tracep->declBus(c+265,"state", false,-1, 1,0);
    tracep->declBit(c+377,"req_accept", false,-1);
    tracep->declBit(c+518,"is_read", false,-1);
    tracep->declBit(c+519,"is_write", false,-1);
    tracep->pushNamePrefix("u_sdram_ctrl ");
    tracep->declBit(c+572,"clk_i", false,-1);
    tracep->declBit(c+573,"rst_i", false,-1);
    tracep->declBus(c+520,"inport_wr_i", false,-1, 3,0);
    tracep->declBit(c+518,"inport_rd_i", false,-1);
    tracep->declBus(c+598,"inport_len_i", false,-1, 7,0);
    tracep->declBus(c+458,"inport_addr_i", false,-1, 31,0);
    tracep->declBus(c+141,"inport_write_data_i", false,-1, 31,0);
    tracep->declBus(c+578,"sdram_data_input_i", false,-1, 15,0);
    tracep->declBit(c+377,"inport_accept_o", false,-1);
    tracep->declBit(c+376,"inport_ack_o", false,-1);
    tracep->declBit(c+595,"inport_error_o", false,-1);
    tracep->declBus(c+7,"inport_read_data_o", false,-1, 31,0);
    tracep->declBit(c+577,"sdram_clk_o", false,-1);
    tracep->declBit(c+368,"sdram_cke_o", false,-1);
    tracep->declBit(c+369,"sdram_cs_o", false,-1);
    tracep->declBit(c+370,"sdram_ras_o", false,-1);
    tracep->declBit(c+371,"sdram_cas_o", false,-1);
    tracep->declBit(c+372,"sdram_we_o", false,-1);
    tracep->declBus(c+375,"sdram_dqm_o", false,-1, 1,0);
    tracep->declBus(c+373,"sdram_addr_o", false,-1, 12,0);
    tracep->declBus(c+374,"sdram_ba_o", false,-1, 1,0);
    tracep->declBus(c+9,"sdram_data_output_o", false,-1, 15,0);
    tracep->declBit(c+8,"sdram_data_out_en_o", false,-1);
    tracep->declBus(c+603,"SDRAM_MHZ", false,-1, 31,0);
    tracep->declBus(c+604,"SDRAM_ADDR_W", false,-1, 31,0);
    tracep->declBus(c+605,"SDRAM_COL_W", false,-1, 31,0);
    tracep->declBus(c+606,"SDRAM_READ_LATENCY", false,-1, 31,0);
    tracep->declBus(c+606,"SDRAM_BANK_W", false,-1, 31,0);
    tracep->declBus(c+606,"SDRAM_DQM_W", false,-1, 31,0);
    tracep->declBus(c+607,"SDRAM_BANKS", false,-1, 31,0);
    tracep->declBus(c+608,"SDRAM_ROW_W", false,-1, 31,0);
    tracep->declBus(c+609,"SDRAM_REFRESH_CNT", false,-1, 31,0);
    tracep->declBus(c+610,"SDRAM_START_DELAY", false,-1, 31,0);
    tracep->declBus(c+611,"SDRAM_REFRESH_CYCLES", false,-1, 31,0);
    tracep->declBus(c+607,"CMD_W", false,-1, 31,0);
    tracep->declBus(c+612,"CMD_NOP", false,-1, 3,0);
    tracep->declBus(c+613,"CMD_ACTIVE", false,-1, 3,0);
    tracep->declBus(c+614,"CMD_READ", false,-1, 3,0);
    tracep->declBus(c+615,"CMD_WRITE", false,-1, 3,0);
    tracep->declBus(c+616,"CMD_TERMINATE", false,-1, 3,0);
    tracep->declBus(c+617,"CMD_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+618,"CMD_REFRESH", false,-1, 3,0);
    tracep->declBus(c+597,"CMD_LOAD_MODE", false,-1, 3,0);
    tracep->declBus(c+619,"MODE_REG", false,-1, 12,0);
    tracep->declBus(c+607,"STATE_W", false,-1, 31,0);
    tracep->declBus(c+597,"STATE_INIT", false,-1, 3,0);
    tracep->declBus(c+618,"STATE_DELAY", false,-1, 3,0);
    tracep->declBus(c+617,"STATE_IDLE", false,-1, 3,0);
    tracep->declBus(c+613,"STATE_ACTIVATE", false,-1, 3,0);
    tracep->declBus(c+615,"STATE_READ", false,-1, 3,0);
    tracep->declBus(c+614,"STATE_READ_WAIT", false,-1, 3,0);
    tracep->declBus(c+616,"STATE_WRITE0", false,-1, 3,0);
    tracep->declBus(c+612,"STATE_WRITE1", false,-1, 3,0);
    tracep->declBus(c+620,"STATE_PRECHARGE", false,-1, 3,0);
    tracep->declBus(c+621,"STATE_REFRESH", false,-1, 3,0);
    tracep->declBus(c+622,"AUTO_PRECHARGE", false,-1, 31,0);
    tracep->declBus(c+622,"ALL_BANKS", false,-1, 31,0);
    tracep->declBus(c+623,"SDRAM_DATA_W", false,-1, 31,0);
    tracep->declBus(c+622,"CYCLE_TIME_NS", false,-1, 31,0);
    tracep->declBus(c+606,"SDRAM_TRCD_CYCLES", false,-1, 31,0);
    tracep->declBus(c+606,"SDRAM_TRP_CYCLES", false,-1, 31,0);
    tracep->declBus(c+624,"SDRAM_TRFC_CYCLES", false,-1, 31,0);
    tracep->declBus(c+458,"ram_addr_w", false,-1, 31,0);
    tracep->declBus(c+520,"ram_wr_w", false,-1, 3,0);
    tracep->declBit(c+518,"ram_rd_w", false,-1);
    tracep->declBit(c+377,"ram_accept_w", false,-1);
    tracep->declBus(c+141,"ram_write_data_w", false,-1, 31,0);
    tracep->declBus(c+7,"ram_read_data_w", false,-1, 31,0);
    tracep->declBit(c+376,"ram_ack_w", false,-1);
    tracep->declBit(c+521,"ram_req_w", false,-1);
    tracep->declBus(c+378,"command_q", false,-1, 3,0);
    tracep->declBus(c+373,"addr_q", false,-1, 12,0);
    tracep->declBus(c+9,"data_q", false,-1, 15,0);
    tracep->declBit(c+10,"data_rd_en_q", false,-1);
    tracep->declBus(c+375,"dqm_q", false,-1, 1,0);
    tracep->declBit(c+368,"cke_q", false,-1);
    tracep->declBus(c+374,"bank_q", false,-1, 1,0);
    tracep->declBus(c+11,"data_buffer_q", false,-1, 15,0);
    tracep->declBus(c+379,"dqm_buffer_q", false,-1, 1,0);
    tracep->declBus(c+578,"sdram_data_in_w", false,-1, 15,0);
    tracep->declBit(c+12,"refresh_q", false,-1);
    tracep->declBus(c+13,"row_open_q", false,-1, 3,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+14+i*1,"active_row_q", true,(i+0), 12,0);
    }
    tracep->declBus(c+380,"state_q", false,-1, 3,0);
    tracep->declBus(c+555,"next_state_r", false,-1, 3,0);
    tracep->declBus(c+556,"target_state_r", false,-1, 3,0);
    tracep->declBus(c+18,"target_state_q", false,-1, 3,0);
    tracep->declBus(c+19,"delay_state_q", false,-1, 3,0);
    tracep->declBus(c+522,"addr_col_w", false,-1, 12,0);
    tracep->declBus(c+523,"addr_row_w", false,-1, 12,0);
    tracep->declBus(c+524,"addr_bank_w", false,-1, 1,0);
    tracep->declBus(c+607,"DELAY_W", false,-1, 31,0);
    tracep->declBus(c+20,"delay_q", false,-1, 3,0);
    tracep->declBus(c+557,"delay_r", false,-1, 3,0);
    tracep->declBus(c+625,"REFRESH_CNT_W", false,-1, 31,0);
    tracep->declBus(c+381,"refresh_timer_q", false,-1, 16,0);
    tracep->declBus(c+21,"sample_data0_q", false,-1, 15,0);
    tracep->declBus(c+22,"sample_data_q", false,-1, 15,0);
    tracep->declBus(c+23,"idx", false,-1, 31,0);
    tracep->declBus(c+382,"rd_q", false,-1, 3,0);
    tracep->declBit(c+376,"ack_q", false,-1);
    tracep->declArray(c+383,"dbg_state", false,-1, 79,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("lspi ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+305,"auto_in_psel", false,-1);
    tracep->declBit(c+306,"auto_in_penable", false,-1);
    tracep->declBit(c+140,"auto_in_pwrite", false,-1);
    tracep->declBus(c+463,"auto_in_paddr", false,-1, 29,0);
    tracep->declBus(c+594,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+141,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+580,"auto_in_pready", false,-1);
    tracep->declBus(c+581,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+365,"spi_bundle_sck", false,-1);
    tracep->declBus(c+366,"spi_bundle_ss", false,-1, 7,0);
    tracep->declBit(c+367,"spi_bundle_mosi", false,-1);
    tracep->declBit(c+576,"spi_bundle_miso", false,-1);
    tracep->declBus(c+266,"cmd_state", false,-1, 3,0);
    tracep->declBus(c+267,"spi_state", false,-1, 1,0);
    tracep->declBit(c+268,"mspi_in_psel", false,-1);
    tracep->declBit(c+558,"spi_ack", false,-1);
    tracep->pushNamePrefix("mspi ");
    tracep->declBus(c+626,"flash_addr_start", false,-1, 31,0);
    tracep->declBus(c+627,"flash_addr_end", false,-1, 31,0);
    tracep->declBus(c+628,"spi_ss_num", false,-1, 31,0);
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBus(c+525,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+268,"in_psel", false,-1);
    tracep->declBit(c+269,"in_penable", false,-1);
    tracep->declBus(c+594,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+526,"in_pwrite", false,-1);
    tracep->declBus(c+527,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+528,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+386,"in_pready", false,-1);
    tracep->declBus(c+24,"in_prdata", false,-1, 31,0);
    tracep->declBit(c+595,"in_pslverr", false,-1);
    tracep->declBit(c+365,"spi_sck", false,-1);
    tracep->declBus(c+366,"spi_ss", false,-1, 7,0);
    tracep->declBit(c+367,"spi_mosi", false,-1);
    tracep->declBit(c+576,"spi_miso", false,-1);
    tracep->declBit(c+387,"spi_irq_out", false,-1);
    tracep->pushNamePrefix("u0_spi_top ");
    tracep->declBus(c+629,"Tp", false,-1, 31,0);
    tracep->declBit(c+572,"wb_clk_i", false,-1);
    tracep->declBit(c+573,"wb_rst_i", false,-1);
    tracep->declBus(c+529,"wb_adr_i", false,-1, 4,0);
    tracep->declBus(c+527,"wb_dat_i", false,-1, 31,0);
    tracep->declBus(c+24,"wb_dat_o", false,-1, 31,0);
    tracep->declBus(c+528,"wb_sel_i", false,-1, 3,0);
    tracep->declBit(c+526,"wb_we_i", false,-1);
    tracep->declBit(c+268,"wb_stb_i", false,-1);
    tracep->declBit(c+269,"wb_cyc_i", false,-1);
    tracep->declBit(c+386,"wb_ack_o", false,-1);
    tracep->declBit(c+595,"wb_err_o", false,-1);
    tracep->declBit(c+387,"wb_int_o", false,-1);
    tracep->declBus(c+366,"ss_pad_o", false,-1, 7,0);
    tracep->declBit(c+365,"sclk_pad_o", false,-1);
    tracep->declBit(c+367,"mosi_pad_o", false,-1);
    tracep->declBit(c+576,"miso_pad_i", false,-1);
    tracep->declBus(c+388,"divider", false,-1, 15,0);
    tracep->declBus(c+389,"ctrl", false,-1, 13,0);
    tracep->declBus(c+25,"ss", false,-1, 7,0);
    tracep->declBus(c+559,"wb_dat", false,-1, 31,0);
    tracep->declArray(c+26,"rx", false,-1, 127,0);
    tracep->declBit(c+390,"rx_negedge", false,-1);
    tracep->declBit(c+391,"tx_negedge", false,-1);
    tracep->declBus(c+392,"char_len", false,-1, 6,0);
    tracep->declBit(c+393,"go", false,-1);
    tracep->declBit(c+394,"lsb", false,-1);
    tracep->declBit(c+395,"ie", false,-1);
    tracep->declBit(c+396,"ass", false,-1);
    tracep->declBit(c+530,"spi_divider_sel", false,-1);
    tracep->declBit(c+531,"spi_ctrl_sel", false,-1);
    tracep->declBus(c+532,"spi_tx_sel", false,-1, 3,0);
    tracep->declBit(c+533,"spi_ss_sel", false,-1);
    tracep->declBit(c+397,"tip", false,-1);
    tracep->declBit(c+398,"pos_edge", false,-1);
    tracep->declBit(c+30,"neg_edge", false,-1);
    tracep->declBit(c+399,"last_bit", false,-1);
    tracep->pushNamePrefix("clgen ");
    tracep->declBus(c+629,"Tp", false,-1, 31,0);
    tracep->declBit(c+572,"clk_in", false,-1);
    tracep->declBit(c+573,"rst", false,-1);
    tracep->declBit(c+397,"enable", false,-1);
    tracep->declBit(c+393,"go", false,-1);
    tracep->declBit(c+399,"last_clk", false,-1);
    tracep->declBus(c+388,"divider", false,-1, 15,0);
    tracep->declBit(c+365,"clk_out", false,-1);
    tracep->declBit(c+398,"pos_edge", false,-1);
    tracep->declBit(c+30,"neg_edge", false,-1);
    tracep->declBus(c+400,"cnt", false,-1, 15,0);
    tracep->declBit(c+401,"cnt_zero", false,-1);
    tracep->declBit(c+402,"cnt_one", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("shift ");
    tracep->declBus(c+629,"Tp", false,-1, 31,0);
    tracep->declBit(c+572,"clk", false,-1);
    tracep->declBit(c+573,"rst", false,-1);
    tracep->declBus(c+534,"latch", false,-1, 3,0);
    tracep->declBus(c+528,"byte_sel", false,-1, 3,0);
    tracep->declBus(c+392,"len", false,-1, 6,0);
    tracep->declBit(c+394,"lsb", false,-1);
    tracep->declBit(c+393,"go", false,-1);
    tracep->declBit(c+398,"pos_edge", false,-1);
    tracep->declBit(c+30,"neg_edge", false,-1);
    tracep->declBit(c+390,"rx_negedge", false,-1);
    tracep->declBit(c+391,"tx_negedge", false,-1);
    tracep->declBit(c+397,"tip", false,-1);
    tracep->declBit(c+399,"last", false,-1);
    tracep->declBus(c+527,"p_in", false,-1, 31,0);
    tracep->declArray(c+26,"p_out", false,-1, 127,0);
    tracep->declBit(c+365,"s_clk", false,-1);
    tracep->declBit(c+576,"s_in", false,-1);
    tracep->declBit(c+367,"s_out", false,-1);
    tracep->declBus(c+403,"cnt", false,-1, 7,0);
    tracep->declArray(c+26,"data", false,-1, 127,0);
    tracep->declBus(c+404,"tx_bit_pos", false,-1, 7,0);
    tracep->declBus(c+405,"rx_bit_pos", false,-1, 7,0);
    tracep->declBit(c+406,"rx_clk", false,-1);
    tracep->declBit(c+407,"tx_clk", false,-1);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("luart ");
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+459,"auto_in_psel", false,-1);
    tracep->declBit(c+460,"auto_in_penable", false,-1);
    tracep->declBit(c+140,"auto_in_pwrite", false,-1);
    tracep->declBus(c+461,"auto_in_paddr", false,-1, 28,0);
    tracep->declBus(c+594,"auto_in_pprot", false,-1, 2,0);
    tracep->declBus(c+141,"auto_in_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"auto_in_pstrb", false,-1, 3,0);
    tracep->declBit(c+462,"auto_in_pready", false,-1);
    tracep->declBit(c+595,"auto_in_pslverr", false,-1);
    tracep->declBus(c+579,"auto_in_prdata", false,-1, 31,0);
    tracep->declBit(c+574,"uart_rx", false,-1);
    tracep->declBit(c+575,"uart_tx", false,-1);
    tracep->pushNamePrefix("muart ");
    tracep->declBit(c+573,"reset", false,-1);
    tracep->declBit(c+572,"clock", false,-1);
    tracep->declBit(c+459,"in_psel", false,-1);
    tracep->declBit(c+460,"in_penable", false,-1);
    tracep->declBus(c+594,"in_pprot", false,-1, 2,0);
    tracep->declBit(c+462,"in_pready", false,-1);
    tracep->declBit(c+595,"in_pslverr", false,-1);
    tracep->declBus(c+535,"in_paddr", false,-1, 31,0);
    tracep->declBit(c+140,"in_pwrite", false,-1);
    tracep->declBus(c+579,"in_prdata", false,-1, 31,0);
    tracep->declBus(c+141,"in_pwdata", false,-1, 31,0);
    tracep->declBus(c+142,"in_pstrb", false,-1, 3,0);
    tracep->declBit(c+574,"uart_rx", false,-1);
    tracep->declBit(c+575,"uart_tx", false,-1);
    tracep->declBit(c+31,"rtsn", false,-1);
    tracep->declBit(c+595,"ctsn", false,-1);
    tracep->declBit(c+32,"dtr_pad_o", false,-1);
    tracep->declBit(c+595,"dsr_pad_i", false,-1);
    tracep->declBit(c+595,"ri_pad_i", false,-1);
    tracep->declBit(c+595,"dcd_pad_i", false,-1);
    tracep->declBit(c+33,"interrupt", false,-1);
    tracep->declBit(c+586,"reg_we", false,-1);
    tracep->declBit(c+587,"reg_re", false,-1);
    tracep->declBus(c+536,"reg_adr", false,-1, 2,0);
    tracep->declBus(c+537,"reg_dat8_w", false,-1, 7,0);
    tracep->declBus(c+270,"reg_dat8_w_reg", false,-1, 7,0);
    tracep->declBus(c+560,"reg_dat8_r", false,-1, 7,0);
    tracep->declBit(c+34,"rts_internal", false,-1);
    tracep->pushNamePrefix("Uregs ");
    tracep->declBit(c+572,"clk", false,-1);
    tracep->declBit(c+573,"wb_rst_i", false,-1);
    tracep->declBus(c+536,"wb_addr_i", false,-1, 2,0);
    tracep->declBus(c+538,"wb_dat_i", false,-1, 7,0);
    tracep->declBus(c+560,"wb_dat_o", false,-1, 7,0);
    tracep->declBit(c+586,"wb_we_i", false,-1);
    tracep->declBit(c+587,"wb_re_i", false,-1);
    tracep->declBit(c+575,"stx_pad_o", false,-1);
    tracep->declBit(c+574,"srx_pad_i", false,-1);
    tracep->declBus(c+620,"modem_inputs", false,-1, 3,0);
    tracep->declBit(c+34,"rts_pad_o", false,-1);
    tracep->declBit(c+32,"dtr_pad_o", false,-1);
    tracep->declBit(c+33,"int_o", false,-1);
    tracep->declBit(c+408,"enable", false,-1);
    tracep->declBit(c+35,"srx_pad", false,-1);
    tracep->declBus(c+36,"ier", false,-1, 3,0);
    tracep->declBus(c+37,"iir", false,-1, 3,0);
    tracep->declBus(c+38,"fcr", false,-1, 1,0);
    tracep->declBus(c+39,"mcr", false,-1, 4,0);
    tracep->declBus(c+409,"lcr", false,-1, 7,0);
    tracep->declBus(c+40,"msr", false,-1, 7,0);
    tracep->declBus(c+410,"dl", false,-1, 15,0);
    tracep->declBus(c+41,"scratch", false,-1, 7,0);
    tracep->declBit(c+42,"start_dlc", false,-1);
    tracep->declBit(c+43,"lsr_mask_d", false,-1);
    tracep->declBit(c+44,"msi_reset", false,-1);
    tracep->declBus(c+411,"dlc", false,-1, 15,0);
    tracep->declBus(c+45,"trigger_level", false,-1, 3,0);
    tracep->declBit(c+46,"rx_reset", false,-1);
    tracep->declBit(c+412,"tx_reset", false,-1);
    tracep->declBit(c+413,"dlab", false,-1);
    tracep->declBit(c+599,"cts_pad_i", false,-1);
    tracep->declBit(c+595,"dsr_pad_i", false,-1);
    tracep->declBit(c+595,"ri_pad_i", false,-1);
    tracep->declBit(c+595,"dcd_pad_i", false,-1);
    tracep->declBit(c+47,"loopback", false,-1);
    tracep->declBit(c+595,"cts", false,-1);
    tracep->declBit(c+599,"dsr", false,-1);
    tracep->declBit(c+599,"ri", false,-1);
    tracep->declBit(c+599,"dcd", false,-1);
    tracep->declBit(c+48,"cts_c", false,-1);
    tracep->declBit(c+49,"dsr_c", false,-1);
    tracep->declBit(c+50,"ri_c", false,-1);
    tracep->declBit(c+51,"dcd_c", false,-1);
    tracep->declBus(c+52,"lsr", false,-1, 7,0);
    tracep->declBit(c+414,"lsr0", false,-1);
    tracep->declBit(c+53,"lsr1", false,-1);
    tracep->declBit(c+54,"lsr2", false,-1);
    tracep->declBit(c+55,"lsr3", false,-1);
    tracep->declBit(c+56,"lsr4", false,-1);
    tracep->declBit(c+415,"lsr5", false,-1);
    tracep->declBit(c+416,"lsr6", false,-1);
    tracep->declBit(c+57,"lsr7", false,-1);
    tracep->declBit(c+58,"lsr0r", false,-1);
    tracep->declBit(c+59,"lsr1r", false,-1);
    tracep->declBit(c+60,"lsr2r", false,-1);
    tracep->declBit(c+61,"lsr3r", false,-1);
    tracep->declBit(c+62,"lsr4r", false,-1);
    tracep->declBit(c+63,"lsr5r", false,-1);
    tracep->declBit(c+64,"lsr6r", false,-1);
    tracep->declBit(c+65,"lsr7r", false,-1);
    tracep->declBit(c+1,"lsr_mask", false,-1);
    tracep->declBit(c+66,"rls_int", false,-1);
    tracep->declBit(c+67,"rda_int", false,-1);
    tracep->declBit(c+68,"ti_int", false,-1);
    tracep->declBit(c+69,"thre_int", false,-1);
    tracep->declBit(c+70,"ms_int", false,-1);
    tracep->declBit(c+417,"tf_push", false,-1);
    tracep->declBit(c+71,"rf_pop", false,-1);
    tracep->declBus(c+588,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+72,"rf_error_bit", false,-1);
    tracep->declBit(c+53,"rf_overrun", false,-1);
    tracep->declBit(c+418,"rf_push_pulse", false,-1);
    tracep->declBus(c+73,"rf_count", false,-1, 4,0);
    tracep->declBus(c+419,"tf_count", false,-1, 4,0);
    tracep->declBus(c+420,"tstate", false,-1, 2,0);
    tracep->declBus(c+421,"rstate", false,-1, 3,0);
    tracep->declBus(c+74,"counter_t", false,-1, 9,0);
    tracep->declBit(c+75,"thre_set_en", false,-1);
    tracep->declBus(c+76,"block_cnt", false,-1, 7,0);
    tracep->declBus(c+422,"block_value", false,-1, 7,0);
    tracep->declBit(c+423,"serial_out", false,-1);
    tracep->declBit(c+424,"serial_in", false,-1);
    tracep->declBit(c+2,"lsr_mask_condition", false,-1);
    tracep->declBit(c+3,"iir_read", false,-1);
    tracep->declBit(c+4,"msr_read", false,-1);
    tracep->declBit(c+5,"fifo_read", false,-1);
    tracep->declBit(c+6,"fifo_write", false,-1);
    tracep->declBus(c+77,"delayed_modem_signals", false,-1, 3,0);
    tracep->declBit(c+78,"lsr0_d", false,-1);
    tracep->declBit(c+79,"lsr1_d", false,-1);
    tracep->declBit(c+80,"lsr2_d", false,-1);
    tracep->declBit(c+81,"lsr3_d", false,-1);
    tracep->declBit(c+82,"lsr4_d", false,-1);
    tracep->declBit(c+83,"lsr5_d", false,-1);
    tracep->declBit(c+84,"lsr6_d", false,-1);
    tracep->declBit(c+85,"lsr7_d", false,-1);
    tracep->declBit(c+86,"rls_int_d", false,-1);
    tracep->declBit(c+87,"thre_int_d", false,-1);
    tracep->declBit(c+88,"ms_int_d", false,-1);
    tracep->declBit(c+89,"ti_int_d", false,-1);
    tracep->declBit(c+90,"rda_int_d", false,-1);
    tracep->declBit(c+91,"rls_int_rise", false,-1);
    tracep->declBit(c+92,"thre_int_rise", false,-1);
    tracep->declBit(c+93,"ms_int_rise", false,-1);
    tracep->declBit(c+94,"ti_int_rise", false,-1);
    tracep->declBit(c+95,"rda_int_rise", false,-1);
    tracep->declBit(c+96,"rls_int_pnd", false,-1);
    tracep->declBit(c+97,"rda_int_pnd", false,-1);
    tracep->declBit(c+98,"thre_int_pnd", false,-1);
    tracep->declBit(c+99,"ms_int_pnd", false,-1);
    tracep->declBit(c+100,"ti_int_pnd", false,-1);
    tracep->pushNamePrefix("i_uart_sync_flops ");
    tracep->declBus(c+629,"Tp", false,-1, 31,0);
    tracep->declBus(c+629,"width", false,-1, 31,0);
    tracep->declBus(c+630,"init_value", false,-1, 0,0);
    tracep->declBit(c+573,"rst_i", false,-1);
    tracep->declBit(c+572,"clk_i", false,-1);
    tracep->declBit(c+595,"stage1_rst_i", false,-1);
    tracep->declBit(c+599,"stage1_clk_en_i", false,-1);
    tracep->declBus(c+574,"async_dat_i", false,-1, 0,0);
    tracep->declBus(c+35,"sync_dat_o", false,-1, 0,0);
    tracep->declBus(c+101,"flop_0", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("receiver ");
    tracep->declBit(c+572,"clk", false,-1);
    tracep->declBit(c+573,"wb_rst_i", false,-1);
    tracep->declBus(c+409,"lcr", false,-1, 7,0);
    tracep->declBit(c+71,"rf_pop", false,-1);
    tracep->declBit(c+424,"srx_pad_i", false,-1);
    tracep->declBit(c+408,"enable", false,-1);
    tracep->declBit(c+46,"rx_reset", false,-1);
    tracep->declBit(c+1,"lsr_mask", false,-1);
    tracep->declBus(c+74,"counter_t", false,-1, 9,0);
    tracep->declBus(c+73,"rf_count", false,-1, 4,0);
    tracep->declBus(c+588,"rf_data_out", false,-1, 10,0);
    tracep->declBit(c+53,"rf_overrun", false,-1);
    tracep->declBit(c+72,"rf_error_bit", false,-1);
    tracep->declBus(c+421,"rstate", false,-1, 3,0);
    tracep->declBit(c+418,"rf_push_pulse", false,-1);
    tracep->declBus(c+425,"rcounter16", false,-1, 3,0);
    tracep->declBus(c+426,"rbit_counter", false,-1, 2,0);
    tracep->declBus(c+427,"rshift", false,-1, 7,0);
    tracep->declBit(c+428,"rparity", false,-1);
    tracep->declBit(c+429,"rparity_error", false,-1);
    tracep->declBit(c+430,"rframing_error", false,-1);
    tracep->declBit(c+102,"rbit_in", false,-1);
    tracep->declBit(c+431,"rparity_xor", false,-1);
    tracep->declBus(c+432,"counter_b", false,-1, 7,0);
    tracep->declBit(c+103,"rf_push_q", false,-1);
    tracep->declBus(c+433,"rf_data_in", false,-1, 10,0);
    tracep->declBit(c+434,"rf_push", false,-1);
    tracep->declBit(c+435,"break_error", false,-1);
    tracep->declBit(c+436,"rcounter16_eq_7", false,-1);
    tracep->declBit(c+437,"rcounter16_eq_0", false,-1);
    tracep->declBit(c+438,"rcounter16_eq_1", false,-1);
    tracep->declBus(c+439,"rcounter16_minus_1", false,-1, 3,0);
    tracep->declBus(c+597,"sr_idle", false,-1, 3,0);
    tracep->declBus(c+618,"sr_rec_start", false,-1, 3,0);
    tracep->declBus(c+617,"sr_rec_bit", false,-1, 3,0);
    tracep->declBus(c+613,"sr_rec_parity", false,-1, 3,0);
    tracep->declBus(c+615,"sr_rec_stop", false,-1, 3,0);
    tracep->declBus(c+614,"sr_check_parity", false,-1, 3,0);
    tracep->declBus(c+616,"sr_rec_prepare", false,-1, 3,0);
    tracep->declBus(c+612,"sr_end_bit", false,-1, 3,0);
    tracep->declBus(c+620,"sr_ca_lc_parity", false,-1, 3,0);
    tracep->declBus(c+621,"sr_wait1", false,-1, 3,0);
    tracep->declBus(c+631,"sr_push", false,-1, 3,0);
    tracep->declBus(c+440,"toc_value", false,-1, 9,0);
    tracep->declBus(c+441,"brc_value", false,-1, 7,0);
    tracep->pushNamePrefix("fifo_rx ");
    tracep->declBus(c+632,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+623,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+607,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+633,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+572,"clk", false,-1);
    tracep->declBit(c+573,"wb_rst_i", false,-1);
    tracep->declBit(c+418,"push", false,-1);
    tracep->declBit(c+71,"pop", false,-1);
    tracep->declBus(c+433,"data_in", false,-1, 10,0);
    tracep->declBit(c+46,"fifo_reset", false,-1);
    tracep->declBit(c+1,"reset_status", false,-1);
    tracep->declBus(c+588,"data_out", false,-1, 10,0);
    tracep->declBit(c+53,"overrun", false,-1);
    tracep->declBus(c+73,"count", false,-1, 4,0);
    tracep->declBit(c+72,"error_bit", false,-1);
    tracep->declBus(c+589,"data8_out", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+104+i*1,"fifo", true,(i+0), 2,0);
    }
    tracep->declBus(c+442,"top", false,-1, 3,0);
    tracep->declBus(c+120,"bottom", false,-1, 3,0);
    tracep->declBus(c+443,"top_plus_1", false,-1, 3,0);
    tracep->declBus(c+121,"word0", false,-1, 2,0);
    tracep->declBus(c+122,"word1", false,-1, 2,0);
    tracep->declBus(c+123,"word2", false,-1, 2,0);
    tracep->declBus(c+124,"word3", false,-1, 2,0);
    tracep->declBus(c+125,"word4", false,-1, 2,0);
    tracep->declBus(c+126,"word5", false,-1, 2,0);
    tracep->declBus(c+127,"word6", false,-1, 2,0);
    tracep->declBus(c+128,"word7", false,-1, 2,0);
    tracep->declBus(c+129,"word8", false,-1, 2,0);
    tracep->declBus(c+130,"word9", false,-1, 2,0);
    tracep->declBus(c+131,"word10", false,-1, 2,0);
    tracep->declBus(c+132,"word11", false,-1, 2,0);
    tracep->declBus(c+133,"word12", false,-1, 2,0);
    tracep->declBus(c+134,"word13", false,-1, 2,0);
    tracep->declBus(c+135,"word14", false,-1, 2,0);
    tracep->declBus(c+136,"word15", false,-1, 2,0);
    tracep->pushNamePrefix("rfifo ");
    tracep->declBus(c+607,"addr_width", false,-1, 31,0);
    tracep->declBus(c+628,"data_width", false,-1, 31,0);
    tracep->declBus(c+623,"depth", false,-1, 31,0);
    tracep->declBit(c+572,"clk", false,-1);
    tracep->declBit(c+418,"we", false,-1);
    tracep->declBus(c+442,"a", false,-1, 3,0);
    tracep->declBus(c+120,"dpra", false,-1, 3,0);
    tracep->declBus(c+444,"di", false,-1, 7,0);
    tracep->declBus(c+589,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+271+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("transmitter ");
    tracep->declBit(c+572,"clk", false,-1);
    tracep->declBit(c+573,"wb_rst_i", false,-1);
    tracep->declBus(c+409,"lcr", false,-1, 7,0);
    tracep->declBit(c+417,"tf_push", false,-1);
    tracep->declBus(c+538,"wb_dat_i", false,-1, 7,0);
    tracep->declBit(c+408,"enable", false,-1);
    tracep->declBit(c+412,"tx_reset", false,-1);
    tracep->declBit(c+1,"lsr_mask", false,-1);
    tracep->declBit(c+423,"stx_pad_o", false,-1);
    tracep->declBus(c+420,"tstate", false,-1, 2,0);
    tracep->declBus(c+419,"tf_count", false,-1, 4,0);
    tracep->declBus(c+445,"counter", false,-1, 4,0);
    tracep->declBus(c+446,"bit_counter", false,-1, 2,0);
    tracep->declBus(c+447,"shift_out", false,-1, 6,0);
    tracep->declBit(c+448,"stx_o_tmp", false,-1);
    tracep->declBit(c+449,"parity_xor", false,-1);
    tracep->declBit(c+450,"tf_pop", false,-1);
    tracep->declBit(c+451,"bit_out", false,-1);
    tracep->declBus(c+538,"tf_data_in", false,-1, 7,0);
    tracep->declBus(c+561,"tf_data_out", false,-1, 7,0);
    tracep->declBit(c+137,"tf_overrun", false,-1);
    tracep->declBus(c+601,"s_idle", false,-1, 2,0);
    tracep->declBus(c+594,"s_send_start", false,-1, 2,0);
    tracep->declBus(c+634,"s_send_byte", false,-1, 2,0);
    tracep->declBus(c+635,"s_send_parity", false,-1, 2,0);
    tracep->declBus(c+636,"s_send_stop", false,-1, 2,0);
    tracep->declBus(c+637,"s_pop_byte", false,-1, 2,0);
    tracep->pushNamePrefix("fifo_tx ");
    tracep->declBus(c+628,"fifo_width", false,-1, 31,0);
    tracep->declBus(c+623,"fifo_depth", false,-1, 31,0);
    tracep->declBus(c+607,"fifo_pointer_w", false,-1, 31,0);
    tracep->declBus(c+633,"fifo_counter_w", false,-1, 31,0);
    tracep->declBit(c+572,"clk", false,-1);
    tracep->declBit(c+573,"wb_rst_i", false,-1);
    tracep->declBit(c+417,"push", false,-1);
    tracep->declBit(c+450,"pop", false,-1);
    tracep->declBus(c+538,"data_in", false,-1, 7,0);
    tracep->declBit(c+412,"fifo_reset", false,-1);
    tracep->declBit(c+1,"reset_status", false,-1);
    tracep->declBus(c+561,"data_out", false,-1, 7,0);
    tracep->declBit(c+137,"overrun", false,-1);
    tracep->declBus(c+419,"count", false,-1, 4,0);
    tracep->declBus(c+452,"top", false,-1, 3,0);
    tracep->declBus(c+453,"bottom", false,-1, 3,0);
    tracep->declBus(c+454,"top_plus_1", false,-1, 3,0);
    tracep->pushNamePrefix("tfifo ");
    tracep->declBus(c+607,"addr_width", false,-1, 31,0);
    tracep->declBus(c+628,"data_width", false,-1, 31,0);
    tracep->declBus(c+623,"depth", false,-1, 31,0);
    tracep->declBit(c+572,"clk", false,-1);
    tracep->declBit(c+417,"we", false,-1);
    tracep->declBus(c+452,"a", false,-1, 3,0);
    tracep->declBus(c+453,"dpra", false,-1, 3,0);
    tracep->declBus(c+538,"di", false,-1, 7,0);
    tracep->declBus(c+561,"dpo", false,-1, 7,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+287+i*1,"ram", true,(i+0), 7,0);
    }
    tracep->popNamePrefix(7);
    tracep->pushNamePrefix("bitrev ");
    tracep->declBit(c+365,"sck", false,-1);
    tracep->declBit(c+455,"ss", false,-1);
    tracep->declBit(c+367,"mosi", false,-1);
    tracep->declBit(c+599,"miso", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("flash ");
    tracep->declBit(c+365,"sck", false,-1);
    tracep->declBit(c+456,"ss", false,-1);
    tracep->declBit(c+367,"mosi", false,-1);
    tracep->declBit(c+576,"miso", false,-1);
    tracep->declBit(c+456,"reset", false,-1);
    tracep->declBus(c+359,"state", false,-1, 2,0);
    tracep->declBus(c+360,"counter", false,-1, 7,0);
    tracep->declBus(c+361,"cmd", false,-1, 7,0);
    tracep->declBus(c+362,"addr", false,-1, 23,0);
    tracep->declBus(c+363,"data", false,-1, 31,0);
    tracep->declBit(c+364,"ren", false,-1);
    tracep->declBus(c+590,"rdata", false,-1, 31,0);
    tracep->declBus(c+591,"raddr", false,-1, 31,0);
    tracep->declBus(c+592,"data_bswap", false,-1, 31,0);
    tracep->pushNamePrefix("flash_cmd_i ");
    tracep->declBit(c+365,"clock", false,-1);
    tracep->declBit(c+364,"valid", false,-1);
    tracep->declBus(c+361,"cmd", false,-1, 7,0);
    tracep->declBus(c+591,"addr", false,-1, 31,0);
    tracep->declBus(c+590,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("sdram ");
    tracep->declBit(c+577,"io_clk", false,-1);
    tracep->declBit(c+368,"io_cke", false,-1);
    tracep->declBit(c+369,"io_cs", false,-1);
    tracep->declBit(c+370,"io_ras", false,-1);
    tracep->declBit(c+371,"io_cas", false,-1);
    tracep->declBit(c+372,"io_we", false,-1);
    tracep->declBus(c+373,"io_a", false,-1, 12,0);
    tracep->declBus(c+374,"io_ba", false,-1, 1,0);
    tracep->declBus(c+375,"io_dqm", false,-1, 1,0);
    tracep->declBus(c+578,"io_dq", false,-1, 15,0);
    tracep->declBus(c+312,"word_remain_1", false,-1, 3,0);
    tracep->declBus(c+378,"cmd", false,-1, 3,0);
    tracep->declBus(c+313,"mode", false,-1, 12,0);
    tracep->declBus(c+314,"word_remain", false,-1, 3,0);
    tracep->declBus(c+315,"raddr_s1", false,-1, 23,0);
    tracep->declBus(c+316,"waddr_s1", false,-1, 23,0);
    tracep->declBit(c+317,"di_REG", false,-1);
    tracep->declBus(c+318,"REG", false,-1, 15,0);
    tracep->declBus(c+319,"r", false,-1, 1,0);
    tracep->pushNamePrefix("di_buf ");
    tracep->declBus(c+623,"width", false,-1, 31,0);
    tracep->declBus(c+578,"dio", false,-1, 15,0);
    tracep->declBus(c+320,"dout", false,-1, 15,0);
    tracep->declBit(c+317,"out_en", false,-1);
    tracep->declBus(c+578,"din", false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem_ext ");
    tracep->declBus(c+315,"R0_addr", false,-1, 23,0);
    tracep->declBit(c+599,"R0_en", false,-1);
    tracep->declBit(c+577,"R0_clk", false,-1);
    tracep->declBus(c+320,"R0_data", false,-1, 15,0);
    tracep->declBus(c+316,"W0_addr", false,-1, 23,0);
    tracep->declBit(c+321,"W0_en", false,-1);
    tracep->declBit(c+577,"W0_clk", false,-1);
    tracep->declBus(c+318,"W0_data", false,-1, 15,0);
    tracep->declBus(c+319,"W0_mask", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("rowReg_ext ");
    tracep->declBus(c+374,"R0_addr", false,-1, 1,0);
    tracep->declBit(c+599,"R0_en", false,-1);
    tracep->declBit(c+577,"R0_clk", false,-1);
    tracep->declBus(c+593,"R0_data", false,-1, 12,0);
    tracep->declBus(c+374,"W0_addr", false,-1, 1,0);
    tracep->declBit(c+457,"W0_en", false,-1);
    tracep->declBit(c+577,"W0_clk", false,-1);
    tracep->declBus(c+373,"W0_data", false,-1, 12,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+322+i*1,"Memory", true,(i+0), 12,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("unnamedblk2 ");
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void VysyxSoCFull___024root__trace_init_top(VysyxSoCFull___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root__trace_init_top\n"); );
    // Body
    VysyxSoCFull___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VysyxSoCFull___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VysyxSoCFull___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VysyxSoCFull___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VysyxSoCFull___024root__trace_register(VysyxSoCFull___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VysyxSoCFull___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VysyxSoCFull___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VysyxSoCFull___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VysyxSoCFull___024root__trace_full_sub_0(VysyxSoCFull___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VysyxSoCFull___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root__trace_full_top_0\n"); );
    // Init
    VysyxSoCFull___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VysyxSoCFull___024root*>(voidSelf);
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VysyxSoCFull___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VysyxSoCFull___024root__trace_full_sub_0(VysyxSoCFull___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VysyxSoCFull__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VysyxSoCFull___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask));
    bufp->fullBit(oldp+2,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_condition));
    bufp->fullBit(oldp+3,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir_read));
    bufp->fullBit(oldp+4,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr_read));
    bufp->fullBit(oldp+5,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_read));
    bufp->fullBit(oldp+6,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fifo_write));
    bufp->fullIData(oldp+7,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q) 
                              << 0x10U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q))),32);
    bufp->fullBit(oldp+8,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q)))));
    bufp->fullSData(oldp+9,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_q),16);
    bufp->fullBit(oldp+10,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_rd_en_q));
    bufp->fullSData(oldp+11,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__data_buffer_q),16);
    bufp->fullBit(oldp+12,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_q));
    bufp->fullCData(oldp+13,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__row_open_q),4);
    bufp->fullSData(oldp+14,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[0]),13);
    bufp->fullSData(oldp+15,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[1]),13);
    bufp->fullSData(oldp+16,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[2]),13);
    bufp->fullSData(oldp+17,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__active_row_q[3]),13);
    bufp->fullCData(oldp+18,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_q),4);
    bufp->fullCData(oldp+19,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_state_q),4);
    bufp->fullCData(oldp+20,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_q),4);
    bufp->fullSData(oldp+21,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data0_q),16);
    bufp->fullSData(oldp+22,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sample_data_q),16);
    bufp->fullIData(oldp+23,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__idx),32);
    bufp->fullIData(oldp+24,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT___mspi_in_prdata),32);
    bufp->fullCData(oldp+25,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ss),8);
    bufp->fullWData(oldp+26,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__data),128);
    bufp->fullBit(oldp+30,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__neg_edge));
    bufp->fullBit(oldp+31,((1U & (~ ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                     >> 1U)))));
    bufp->fullBit(oldp+32,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))));
    bufp->fullBit(oldp+33,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__interrupt));
    bufp->fullBit(oldp+34,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                  >> 1U))));
    bufp->fullBit(oldp+35,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__srx_pad));
    bufp->fullCData(oldp+36,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ier),4);
    bufp->fullCData(oldp+37,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__iir),4);
    bufp->fullCData(oldp+38,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__fcr),2);
    bufp->fullCData(oldp+39,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr),5);
    bufp->fullCData(oldp+40,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msr),8);
    bufp->fullCData(oldp+41,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__scratch),8);
    bufp->fullBit(oldp+42,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__start_dlc));
    bufp->fullBit(oldp+43,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr_mask_d));
    bufp->fullBit(oldp+44,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__msi_reset));
    bufp->fullCData(oldp+45,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__trigger_level),4);
    bufp->fullBit(oldp+46,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rx_reset));
    bufp->fullBit(oldp+47,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr) 
                                  >> 4U))));
    bufp->fullBit(oldp+48,((IData)((0x10U != (0x12U 
                                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+49,((IData)((0x11U == (0x11U 
                                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+50,((IData)((0x14U == (0x14U 
                                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullBit(oldp+51,((IData)((0x18U == (0x18U 
                                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__mcr))))));
    bufp->fullCData(oldp+52,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r) 
                               << 7U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r) 
                                          << 6U) | 
                                         (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r) 
                                           << 5U) | 
                                          (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r) 
                                            << 4U) 
                                           | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r) 
                                               << 3U) 
                                              | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r))))))))),8);
    bufp->fullBit(oldp+53,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_overrun));
    bufp->fullBit(oldp+54,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                  >> 1U))));
    bufp->fullBit(oldp+55,((1U & (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))));
    bufp->fullBit(oldp+56,((1U & ((IData)(vlSelf->__VdfgTmp_ha17ae98a__0) 
                                  >> 2U))));
    bufp->fullBit(oldp+57,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7));
    bufp->fullBit(oldp+58,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0r));
    bufp->fullBit(oldp+59,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1r));
    bufp->fullBit(oldp+60,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2r));
    bufp->fullBit(oldp+61,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3r));
    bufp->fullBit(oldp+62,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4r));
    bufp->fullBit(oldp+63,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5r));
    bufp->fullBit(oldp+64,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6r));
    bufp->fullBit(oldp+65,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7r));
    bufp->fullBit(oldp+66,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int));
    bufp->fullBit(oldp+67,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int));
    bufp->fullBit(oldp+68,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int));
    bufp->fullBit(oldp+69,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int));
    bufp->fullBit(oldp+70,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int));
    bufp->fullBit(oldp+71,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_pop));
    bufp->fullBit(oldp+72,((0U != (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                   [0U] | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                           [1U] | (
                                                   vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                   [2U] 
                                                   | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                      [3U] 
                                                      | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                         [4U] 
                                                         | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                            [5U] 
                                                            | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                               [6U] 
                                                               | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                  [7U] 
                                                                  | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                     [8U] 
                                                                     | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                        [9U] 
                                                                        | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                           [0xaU] 
                                                                           | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                              [0xbU] 
                                                                              | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                                [0xcU] 
                                                                                | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                                [0xdU] 
                                                                                | (vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                                [0xeU] 
                                                                                | vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                                                                                [0xfU]))))))))))))))))));
    bufp->fullCData(oldp+73,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_count),5);
    bufp->fullSData(oldp+74,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__counter_t),10);
    bufp->fullBit(oldp+75,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt)))))));
    bufp->fullCData(oldp+76,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_cnt),8);
    bufp->fullCData(oldp+77,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__delayed_modem_signals),4);
    bufp->fullBit(oldp+78,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0_d));
    bufp->fullBit(oldp+79,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr1_d));
    bufp->fullBit(oldp+80,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr2_d));
    bufp->fullBit(oldp+81,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr3_d));
    bufp->fullBit(oldp+82,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr4_d));
    bufp->fullBit(oldp+83,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5_d));
    bufp->fullBit(oldp+84,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6_d));
    bufp->fullBit(oldp+85,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr7_d));
    bufp->fullBit(oldp+86,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d));
    bufp->fullBit(oldp+87,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d));
    bufp->fullBit(oldp+88,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d));
    bufp->fullBit(oldp+89,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d));
    bufp->fullBit(oldp+90,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d));
    bufp->fullBit(oldp+91,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_d)) 
                            & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int))));
    bufp->fullBit(oldp+92,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_d)) 
                            & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int))));
    bufp->fullBit(oldp+93,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_d)) 
                            & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int))));
    bufp->fullBit(oldp+94,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_d)) 
                            & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int))));
    bufp->fullBit(oldp+95,(((~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_d)) 
                            & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int))));
    bufp->fullBit(oldp+96,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rls_int_pnd));
    bufp->fullBit(oldp+97,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rda_int_pnd));
    bufp->fullBit(oldp+98,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__thre_int_pnd));
    bufp->fullBit(oldp+99,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ms_int_pnd));
    bufp->fullBit(oldp+100,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__ti_int_pnd));
    bufp->fullBit(oldp+101,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__i_uart_sync_flops__DOT__flop_0));
    bufp->fullBit(oldp+102,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_in));
    bufp->fullBit(oldp+103,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push_q));
    bufp->fullCData(oldp+104,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[0]),3);
    bufp->fullCData(oldp+105,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[1]),3);
    bufp->fullCData(oldp+106,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[2]),3);
    bufp->fullCData(oldp+107,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[3]),3);
    bufp->fullCData(oldp+108,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[4]),3);
    bufp->fullCData(oldp+109,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[5]),3);
    bufp->fullCData(oldp+110,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[6]),3);
    bufp->fullCData(oldp+111,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[7]),3);
    bufp->fullCData(oldp+112,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[8]),3);
    bufp->fullCData(oldp+113,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[9]),3);
    bufp->fullCData(oldp+114,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[10]),3);
    bufp->fullCData(oldp+115,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[11]),3);
    bufp->fullCData(oldp+116,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[12]),3);
    bufp->fullCData(oldp+117,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[13]),3);
    bufp->fullCData(oldp+118,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[14]),3);
    bufp->fullCData(oldp+119,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo[15]),3);
    bufp->fullCData(oldp+120,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom),4);
    bufp->fullCData(oldp+121,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0U]),3);
    bufp->fullCData(oldp+122,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [1U]),3);
    bufp->fullCData(oldp+123,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [2U]),3);
    bufp->fullCData(oldp+124,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [3U]),3);
    bufp->fullCData(oldp+125,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [4U]),3);
    bufp->fullCData(oldp+126,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [5U]),3);
    bufp->fullCData(oldp+127,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [6U]),3);
    bufp->fullCData(oldp+128,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [7U]),3);
    bufp->fullCData(oldp+129,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [8U]),3);
    bufp->fullCData(oldp+130,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [9U]),3);
    bufp->fullCData(oldp+131,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xaU]),3);
    bufp->fullCData(oldp+132,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xbU]),3);
    bufp->fullCData(oldp+133,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xcU]),3);
    bufp->fullCData(oldp+134,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xdU]),3);
    bufp->fullCData(oldp+135,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xeU]),3);
    bufp->fullCData(oldp+136,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__fifo
                              [0xfU]),3);
    bufp->fullBit(oldp+137,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_overrun));
    bufp->fullBit(oldp+138,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel));
    bufp->fullBit(oldp+139,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))));
    bufp->fullBit(oldp+140,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write));
    bufp->fullIData(oldp+141,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_write_data_w),32);
    bufp->fullCData(oldp+142,(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_pstrb),4);
    bufp->fullBit(oldp+143,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_write));
    bufp->fullBit(oldp+144,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__empty)))));
    bufp->fullCData(oldp+145,((0xfU & (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT___ram_ext_R0_data 
                                               >> 0x2bU)))),4);
    bufp->fullIData(oldp+146,((IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT___ram_ext_R0_data 
                                       >> 0xbU))),32);
    bufp->fullCData(oldp+147,((0xffU & (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT___ram_ext_R0_data 
                                                >> 3U)))),8);
    bufp->fullCData(oldp+148,((7U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT___ram_ext_R0_data))),3);
    bufp->fullBit(oldp+149,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__empty)))));
    bufp->fullIData(oldp+150,((IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT___ram_ext_R0_data 
                                       >> 4U))),32);
    bufp->fullCData(oldp+151,((0xfU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT___ram_ext_R0_data))),4);
    bufp->fullBit(oldp+152,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__full)))));
    bufp->fullCData(oldp+153,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg),4);
    bufp->fullCData(oldp+154,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold),2);
    bufp->fullBit(oldp+155,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__accept_read));
    bufp->fullBit(oldp+156,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__empty)))));
    bufp->fullCData(oldp+157,((0xfU & (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT___ram_ext_R0_data 
                                               >> 0x2bU)))),4);
    bufp->fullIData(oldp+158,((IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT___ram_ext_R0_data 
                                       >> 0xbU))),32);
    bufp->fullCData(oldp+159,((0xffU & (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT___ram_ext_R0_data 
                                                >> 3U)))),8);
    bufp->fullCData(oldp+160,((7U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT___ram_ext_R0_data))),3);
    bufp->fullBit(oldp+161,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__full)))));
    bufp->fullCData(oldp+162,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg),4);
    bufp->fullCData(oldp+163,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state),2);
    bufp->fullBit(oldp+164,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__is_write_r));
    bufp->fullIData(oldp+165,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__araddr_reg_r),32);
    bufp->fullIData(oldp+166,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__awaddr_reg_r),32);
    bufp->fullIData(oldp+167,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wdata_reg_r),32);
    bufp->fullCData(oldp+168,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__wstrb_reg_r),4);
    bufp->fullCData(oldp+169,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold_r),2);
    bufp->fullIData(oldp+170,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r),32);
    bufp->fullBit(oldp+171,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__full)))));
    bufp->fullBit(oldp+172,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__full)))));
    bufp->fullBit(oldp+173,((6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__stateD))));
    bufp->fullBit(oldp+174,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__empty)))));
    bufp->fullCData(oldp+175,((0xfU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__ram_ext__DOT__Memory
                                       [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__wrap_1] 
                                       >> 2U))),4);
    bufp->fullCData(oldp+176,((3U & vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__ram_ext__DOT__Memory
                               [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__wrap_1])),2);
    bufp->fullBit(oldp+177,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__full)))));
    bufp->fullBit(oldp+178,(((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__stateI)) 
                             | (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__stateD)))));
    bufp->fullBit(oldp+179,((1U & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__empty)))));
    bufp->fullCData(oldp+180,((0xfU & (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                               >> 0x23U)))),4);
    bufp->fullIData(oldp+181,((IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                       >> 3U))),32);
    bufp->fullCData(oldp+182,((3U & (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                             >> 1U)))),2);
    bufp->fullBit(oldp+183,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data))));
    bufp->fullBit(oldp+184,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__wrap));
    bufp->fullBit(oldp+185,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__wrap_1));
    bufp->fullBit(oldp+186,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__maybe_full));
    bufp->fullBit(oldp+187,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__ptr_match));
    bufp->fullBit(oldp+188,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__empty));
    bufp->fullBit(oldp+189,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__full));
    bufp->fullCData(oldp+190,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__ram_ext__DOT__Memory
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__wrap_1]),6);
    bufp->fullCData(oldp+191,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__bid_reg) 
                                << 2U) | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold))),6);
    bufp->fullCData(oldp+192,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__ram_ext__DOT__Memory[0]),6);
    bufp->fullCData(oldp+193,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__ram_ext__DOT__Memory[1]),6);
    bufp->fullBit(oldp+194,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__unnamedblk1__DOT__do_deq));
    bufp->fullBit(oldp+195,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__wrap));
    bufp->fullBit(oldp+196,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__wrap_1));
    bufp->fullBit(oldp+197,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__maybe_full));
    bufp->fullBit(oldp+198,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__ptr_match));
    bufp->fullBit(oldp+199,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__empty));
    bufp->fullBit(oldp+200,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__full));
    bufp->fullQData(oldp+201,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data),39);
    bufp->fullQData(oldp+203,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__ram_ext__DOT__Memory[0]),39);
    bufp->fullQData(oldp+205,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__ram_ext__DOT__Memory[1]),39);
    bufp->fullBit(oldp+207,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__unnamedblk1__DOT__do_deq));
    bufp->fullBit(oldp+208,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__wrap));
    bufp->fullBit(oldp+209,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__wrap_1));
    bufp->fullBit(oldp+210,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__maybe_full));
    bufp->fullBit(oldp+211,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__ptr_match));
    bufp->fullBit(oldp+212,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__empty));
    bufp->fullBit(oldp+213,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__full));
    bufp->fullQData(oldp+214,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT___ram_ext_R0_data),47);
    bufp->fullQData(oldp+216,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__ram_ext__DOT__Memory[0]),47);
    bufp->fullQData(oldp+218,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__ram_ext__DOT__Memory[1]),47);
    bufp->fullBit(oldp+220,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__unnamedblk1__DOT__do_deq));
    bufp->fullBit(oldp+221,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__wrap));
    bufp->fullBit(oldp+222,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__wrap_1));
    bufp->fullBit(oldp+223,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__maybe_full));
    bufp->fullBit(oldp+224,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__ptr_match));
    bufp->fullBit(oldp+225,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__empty));
    bufp->fullBit(oldp+226,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__full));
    bufp->fullQData(oldp+227,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT___ram_ext_R0_data),47);
    bufp->fullQData(oldp+229,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__ram_ext__DOT__Memory[0]),47);
    bufp->fullQData(oldp+231,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__ram_ext__DOT__Memory[1]),47);
    bufp->fullBit(oldp+233,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__unnamedblk1__DOT__do_deq));
    bufp->fullBit(oldp+234,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__wrap));
    bufp->fullBit(oldp+235,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__wrap_1));
    bufp->fullBit(oldp+236,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__maybe_full));
    bufp->fullBit(oldp+237,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__ptr_match));
    bufp->fullBit(oldp+238,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__empty));
    bufp->fullBit(oldp+239,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__full));
    bufp->fullQData(oldp+240,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT___ram_ext_R0_data),36);
    bufp->fullQData(oldp+242,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__ram_ext__DOT__Memory[0]),36);
    bufp->fullQData(oldp+244,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__ram_ext__DOT__Memory[1]),36);
    bufp->fullBit(oldp+246,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__unnamedblk1__DOT__do_deq));
    bufp->fullBit(oldp+247,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_ifu_reqValid));
    bufp->fullIData(oldp+248,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__instReturn)
                                ? (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                           >> 3U)) : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__io_ifu_rdata_r)),32);
    bufp->fullBit(oldp+249,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__instReturn));
    bufp->fullCData(oldp+250,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__stateI),2);
    bufp->fullCData(oldp+251,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__stateD),3);
    bufp->fullIData(oldp+252,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__io_ifu_rdata_r),32);
    bufp->fullCData(oldp+253,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__ifu_current_state),2);
    bufp->fullBit(oldp+254,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_lsu0__DOT__lsu_current_state));
    bufp->fullBit(oldp+255,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+256,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+257,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+258,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_3));
    bufp->fullBit(oldp+259,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_4));
    bufp->fullBit(oldp+260,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_5));
    bufp->fullBit(oldp+261,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_6));
    bufp->fullBit(oldp+262,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_7));
    bufp->fullBit(oldp+263,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_8));
    bufp->fullBit(oldp+264,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu_reset_chain__DOT__output_chain__DOT__sync_9));
    bufp->fullCData(oldp+265,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__state),2);
    bufp->fullCData(oldp+266,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__cmd_state),4);
    bufp->fullCData(oldp+267,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__spi_state),2);
    bufp->fullBit(oldp+268,((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__spi_state))));
    bufp->fullBit(oldp+269,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT____Vcellinp__mspi__in_penable));
    bufp->fullCData(oldp+270,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w_reg),8);
    bufp->fullCData(oldp+271,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+272,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+273,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+274,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+275,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+276,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+277,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+278,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+279,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+280,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+281,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+282,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+283,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+284,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+285,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+286,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram[15]),8);
    bufp->fullCData(oldp+287,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[0]),8);
    bufp->fullCData(oldp+288,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[1]),8);
    bufp->fullCData(oldp+289,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[2]),8);
    bufp->fullCData(oldp+290,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[3]),8);
    bufp->fullCData(oldp+291,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[4]),8);
    bufp->fullCData(oldp+292,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[5]),8);
    bufp->fullCData(oldp+293,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[6]),8);
    bufp->fullCData(oldp+294,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[7]),8);
    bufp->fullCData(oldp+295,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[8]),8);
    bufp->fullCData(oldp+296,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[9]),8);
    bufp->fullCData(oldp+297,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[10]),8);
    bufp->fullCData(oldp+298,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[11]),8);
    bufp->fullCData(oldp+299,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[12]),8);
    bufp->fullCData(oldp+300,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[13]),8);
    bufp->fullCData(oldp+301,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[14]),8);
    bufp->fullCData(oldp+302,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__tfifo__DOT__ram[15]),8);
    bufp->fullBit(oldp+303,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+304,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+305,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___axi42apb_auto_out_psel))));
    bufp->fullBit(oldp+306,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0) 
                             & (1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state)))));
    bufp->fullBit(oldp+307,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT____VdfgTmp_h1913f1ad__0) 
                             | ((5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__stateD)) 
                                | (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__stateD))))));
    bufp->fullBit(oldp+308,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT____VdfgTmp_h1913f1ad__0) 
                             | (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__stateD)))));
    bufp->fullBit(oldp+309,((((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__stateI)) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_ifu_reqValid)) 
                             | ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__stateI)) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__lsuRead)))));
    bufp->fullIData(oldp+310,(((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__ifu_current_state))
                                ? 0U : ((2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__ifu_current_state))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__instReturn)
                                             ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__instReturn)
                                                 ? (IData)(
                                                           (vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT___ram_ext_R0_data 
                                                            >> 3U))
                                                 : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__io_ifu_rdata_r)
                                             : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg)
                                         : ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__ifu_current_state))
                                             ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg
                                             : 0U)))),32);
    bufp->fullBit(oldp+311,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_lsu0__DOT__lsu_current_state)
                              ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_lsu0__DOT__lsu_current_state) 
                                 & (~ (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___bridge_io_lsu_respValid)))
                              : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_ren) 
                                 | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_wen)))));
    bufp->fullCData(oldp+312,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__word_remain_1),4);
    bufp->fullSData(oldp+313,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mode),13);
    bufp->fullCData(oldp+314,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__word_remain),4);
    bufp->fullIData(oldp+315,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__raddr_s1),24);
    bufp->fullIData(oldp+316,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__waddr_s1),24);
    bufp->fullBit(oldp+317,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__di_REG));
    bufp->fullSData(oldp+318,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__REG),16);
    bufp->fullCData(oldp+319,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__r),2);
    bufp->fullSData(oldp+320,(((IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__mem_ext__DOT___R0_en_d0)
                                ? vlSelf->ysyxSoCFull__DOT__sdram__DOT__mem_ext__DOT__Memory
                               [vlSelf->ysyxSoCFull__DOT__sdram__DOT__mem_ext__DOT___R0_addr_d0]
                                : 0U)),16);
    bufp->fullBit(oldp+321,((0U != (IData)(vlSelf->ysyxSoCFull__DOT__sdram__DOT__word_remain_1))));
    bufp->fullSData(oldp+322,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rowReg_ext__DOT__Memory[0]),13);
    bufp->fullSData(oldp+323,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rowReg_ext__DOT__Memory[1]),13);
    bufp->fullSData(oldp+324,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rowReg_ext__DOT__Memory[2]),13);
    bufp->fullSData(oldp+325,(vlSelf->ysyxSoCFull__DOT__sdram__DOT__rowReg_ext__DOT__Memory[3]),13);
    bufp->fullIData(oldp+326,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[0]),32);
    bufp->fullIData(oldp+327,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[1]),32);
    bufp->fullIData(oldp+328,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[2]),32);
    bufp->fullIData(oldp+329,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[3]),32);
    bufp->fullIData(oldp+330,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[4]),32);
    bufp->fullIData(oldp+331,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[5]),32);
    bufp->fullIData(oldp+332,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[6]),32);
    bufp->fullIData(oldp+333,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[7]),32);
    bufp->fullIData(oldp+334,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[8]),32);
    bufp->fullIData(oldp+335,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[9]),32);
    bufp->fullIData(oldp+336,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[10]),32);
    bufp->fullIData(oldp+337,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[11]),32);
    bufp->fullIData(oldp+338,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[12]),32);
    bufp->fullIData(oldp+339,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[13]),32);
    bufp->fullIData(oldp+340,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[14]),32);
    bufp->fullIData(oldp+341,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[15]),32);
    bufp->fullIData(oldp+342,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[16]),32);
    bufp->fullIData(oldp+343,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[17]),32);
    bufp->fullIData(oldp+344,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[18]),32);
    bufp->fullIData(oldp+345,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[19]),32);
    bufp->fullIData(oldp+346,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[20]),32);
    bufp->fullIData(oldp+347,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[21]),32);
    bufp->fullIData(oldp+348,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[22]),32);
    bufp->fullIData(oldp+349,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[23]),32);
    bufp->fullIData(oldp+350,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[24]),32);
    bufp->fullIData(oldp+351,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[25]),32);
    bufp->fullIData(oldp+352,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[26]),32);
    bufp->fullIData(oldp+353,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[27]),32);
    bufp->fullIData(oldp+354,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[28]),32);
    bufp->fullIData(oldp+355,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[29]),32);
    bufp->fullIData(oldp+356,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[30]),32);
    bufp->fullIData(oldp+357,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__rf[31]),32);
    bufp->fullIData(oldp+358,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_rf0__DOT__i),32);
    bufp->fullCData(oldp+359,(vlSelf->ysyxSoCFull__DOT__flash__DOT__state),3);
    bufp->fullCData(oldp+360,(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter),8);
    bufp->fullCData(oldp+361,(vlSelf->ysyxSoCFull__DOT__flash__DOT__cmd),8);
    bufp->fullIData(oldp+362,(vlSelf->ysyxSoCFull__DOT__flash__DOT__addr),24);
    bufp->fullIData(oldp+363,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data),32);
    bufp->fullBit(oldp+364,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                             & (0x17U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))));
    bufp->fullBit(oldp+365,(vlSelf->ysyxSoCFull__DOT___asic_spi_sck));
    bufp->fullCData(oldp+366,(vlSelf->ysyxSoCFull__DOT___asic_spi_ss),8);
    bufp->fullBit(oldp+367,(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi));
    bufp->fullBit(oldp+368,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q));
    bufp->fullBit(oldp+369,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 3U))));
    bufp->fullBit(oldp+370,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 2U))));
    bufp->fullBit(oldp+371,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+372,((1U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q))));
    bufp->fullSData(oldp+373,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__addr_q),13);
    bufp->fullCData(oldp+374,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__bank_q),2);
    bufp->fullCData(oldp+375,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_q),2);
    bufp->fullBit(oldp+376,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ack_q));
    bufp->fullBit(oldp+377,(((4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)) 
                             | (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q)))));
    bufp->fullCData(oldp+378,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q),4);
    bufp->fullCData(oldp+379,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dqm_buffer_q),2);
    bufp->fullCData(oldp+380,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q),4);
    bufp->fullIData(oldp+381,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__refresh_timer_q),17);
    bufp->fullCData(oldp+382,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__rd_q),4);
    bufp->fullWData(oldp+383,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__dbg_state),80);
    bufp->fullBit(oldp+386,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT___mspi_in_pready));
    bufp->fullBit(oldp+387,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT___mspi_spi_irq_out));
    bufp->fullSData(oldp+388,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__divider),16);
    bufp->fullSData(oldp+389,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl),14);
    bufp->fullBit(oldp+390,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 9U))));
    bufp->fullBit(oldp+391,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xaU))));
    bufp->fullCData(oldp+392,((0x7fU & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))),7);
    bufp->fullBit(oldp+393,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 8U))));
    bufp->fullBit(oldp+394,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xbU))));
    bufp->fullBit(oldp+395,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xcU))));
    bufp->fullBit(oldp+396,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl) 
                                   >> 0xdU))));
    bufp->fullBit(oldp+397,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__tip));
    bufp->fullBit(oldp+398,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__pos_edge));
    bufp->fullBit(oldp+399,((1U & (~ (IData)((0U != (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt)))))));
    bufp->fullSData(oldp+400,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt),16);
    bufp->fullBit(oldp+401,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullBit(oldp+402,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__clgen__DOT__cnt))));
    bufp->fullCData(oldp+403,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt),8);
    bufp->fullCData(oldp+404,((0xffU & ((0x800U & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__ctrl))
                                         ? ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT____VdfgTmp_h72d11e0c__0) 
                                            - (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt))
                                         : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__cnt) 
                                            - (IData)(1U))))),8);
    bufp->fullCData(oldp+405,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_bit_pos),8);
    bufp->fullBit(oldp+406,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__rx_clk));
    bufp->fullBit(oldp+407,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__shift__DOT__tx_clk));
    bufp->fullBit(oldp+408,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__enable));
    bufp->fullCData(oldp+409,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr),8);
    bufp->fullSData(oldp+410,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dl),16);
    bufp->fullSData(oldp+411,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__dlc),16);
    bufp->fullBit(oldp+412,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tx_reset));
    bufp->fullBit(oldp+413,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lcr) 
                                   >> 7U))));
    bufp->fullBit(oldp+414,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr0));
    bufp->fullBit(oldp+415,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr5));
    bufp->fullBit(oldp+416,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__lsr6));
    bufp->fullBit(oldp+417,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_push));
    bufp->fullBit(oldp+418,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rf_push_pulse));
    bufp->fullCData(oldp+419,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tf_count),5);
    bufp->fullCData(oldp+420,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__tstate),3);
    bufp->fullCData(oldp+421,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__rstate),4);
    bufp->fullCData(oldp+422,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__block_value),8);
    bufp->fullBit(oldp+423,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_out));
    bufp->fullBit(oldp+424,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__serial_in));
    bufp->fullCData(oldp+425,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16),4);
    bufp->fullCData(oldp+426,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rbit_counter),3);
    bufp->fullCData(oldp+427,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rshift),8);
    bufp->fullBit(oldp+428,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity));
    bufp->fullBit(oldp+429,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_error));
    bufp->fullBit(oldp+430,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rframing_error));
    bufp->fullBit(oldp+431,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rparity_xor));
    bufp->fullCData(oldp+432,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b),8);
    bufp->fullSData(oldp+433,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in),11);
    bufp->fullBit(oldp+434,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_push));
    bufp->fullBit(oldp+435,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__counter_b))));
    bufp->fullBit(oldp+436,((7U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+437,((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullBit(oldp+438,((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16))));
    bufp->fullCData(oldp+439,((0xfU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rcounter16) 
                                       - (IData)(1U)))),4);
    bufp->fullSData(oldp+440,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value),10);
    bufp->fullCData(oldp+441,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__toc_value) 
                                        >> 2U))),8);
    bufp->fullCData(oldp+442,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top),4);
    bufp->fullCData(oldp+443,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__top)))),4);
    bufp->fullCData(oldp+444,((0xffU & ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__rf_data_in) 
                                        >> 3U))),8);
    bufp->fullCData(oldp+445,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__counter),5);
    bufp->fullCData(oldp+446,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_counter),3);
    bufp->fullCData(oldp+447,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__shift_out),7);
    bufp->fullBit(oldp+448,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__stx_o_tmp));
    bufp->fullBit(oldp+449,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__parity_xor));
    bufp->fullBit(oldp+450,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_pop));
    bufp->fullBit(oldp+451,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__bit_out));
    bufp->fullCData(oldp+452,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top),4);
    bufp->fullCData(oldp+453,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__bottom),4);
    bufp->fullCData(oldp+454,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__fifo_tx__DOT__top)))),4);
    bufp->fullBit(oldp+455,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_ss) 
                                   >> 7U))));
    bufp->fullBit(oldp+456,(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss));
    bufp->fullBit(oldp+457,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__cke_q) 
                             & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__command_q)))));
    bufp->fullIData(oldp+458,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w),32);
    bufp->fullBit(oldp+459,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel));
    bufp->fullBit(oldp+460,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable));
    bufp->fullIData(oldp+461,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),29);
    bufp->fullBit(oldp+462,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_penable) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel))));
    bufp->fullIData(oldp+463,((0x3fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),30);
    bufp->fullBit(oldp+464,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_0));
    bufp->fullBit(oldp+465,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_1));
    bufp->fullBit(oldp+466,(vlSelf->ysyxSoCFull__DOT__asic__DOT__apbxbar__DOT__sel_2));
    bufp->fullCData(oldp+467,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_size),3);
    bufp->fullCData(oldp+468,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__lsuRead)
                                ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_size)
                                : 2U)),3);
    bufp->fullBit(oldp+469,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_ardeq_q__DOT__do_enq));
    bufp->fullBit(oldp+470,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_awdeq_q__DOT__do_enq));
    bufp->fullBit(oldp+471,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeOut_wdeq_q__DOT__do_enq));
    bufp->fullIData(oldp+472,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_raddr),32);
    bufp->fullBit(oldp+473,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_reqValid));
    bufp->fullBit(oldp+474,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___bridge_io_lsu_respValid));
    bufp->fullCData(oldp+475,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_size),2);
    bufp->fullBit(oldp+476,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_wen));
    bufp->fullBit(oldp+477,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__isValidLoad));
    bufp->fullBit(oldp+478,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__isValidStore));
    bufp->fullBit(oldp+479,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__lsuRead));
    bufp->fullIData(oldp+480,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc),32);
    bufp->fullBit(oldp+481,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__inst_valid) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_jalr))));
    bufp->fullBit(oldp+482,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__inst_valid));
    bufp->fullIData(oldp+483,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg),32);
    bufp->fullCData(oldp+484,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+485,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+486,((0x1fU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                                        >> 7U))),5);
    bufp->fullIData(oldp+487,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm),32);
    bufp->fullBit(oldp+488,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_addi));
    bufp->fullBit(oldp+489,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_jalr));
    bufp->fullBit(oldp+490,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_add));
    bufp->fullBit(oldp+491,((0x37U == (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg))));
    bufp->fullBit(oldp+492,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_lw));
    bufp->fullBit(oldp+493,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_lbu));
    bufp->fullBit(oldp+494,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_sw));
    bufp->fullBit(oldp+495,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_sb));
    bufp->fullBit(oldp+496,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_csrrw));
    bufp->fullBit(oldp+497,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_ren));
    bufp->fullBit(oldp+498,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_wen));
    bufp->fullBit(oldp+499,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_add) 
                               | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_addi) 
                                  | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_jalr) 
                                     | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_csrrw) 
                                        | (0x37U == 
                                           (0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg)))))) 
                              & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__inst_valid)) 
                             | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_exu0__DOT____VdfgTmp_hfdfc1d5e__0) 
                                & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___bridge_io_lsu_respValid)))));
    bufp->fullBit(oldp+500,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__reg_men));
    bufp->fullBit(oldp+501,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__inst_valid) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_csrrw))));
    bufp->fullSData(oldp+502,((0xfffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm)),12);
    bufp->fullIData(oldp+503,(((0xb00U == (0xfffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))
                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__mcycle
                                : ((0xb80U == (0xfffU 
                                               & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))
                                    ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__mcycleh
                                    : ((0xf11U == (0xfffU 
                                                   & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))
                                        ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__mvendorid
                                        : ((0xf12U 
                                            == (0xfffU 
                                                & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))
                                            ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__marchid
                                            : 0U))))),32);
    bufp->fullBit(oldp+504,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__inst_done));
    bufp->fullIData(oldp+505,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_rdata),32);
    bufp->fullIData(oldp+506,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__mcycle),32);
    bufp->fullIData(oldp+507,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__mcycleh),32);
    bufp->fullIData(oldp+508,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__mvendorid),32);
    bufp->fullIData(oldp+509,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__marchid),32);
    bufp->fullCData(oldp+510,((0x7fU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg)),7);
    bufp->fullCData(oldp+511,((7U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+512,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                               >> 0x19U)),7);
    bufp->fullIData(oldp+513,((((- (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                                            >> 0x14U))),32);
    bufp->fullIData(oldp+514,((((- (IData)((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0xfe0U 
                                             & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                                                  >> 7U))))),32);
    bufp->fullIData(oldp+515,((0xfffff000U & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg)),32);
    bufp->fullIData(oldp+516,((vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg 
                               >> 0x14U)),32);
    bufp->fullCData(oldp+517,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__ifu_next_state),2);
    bufp->fullBit(oldp+518,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_read));
    bufp->fullBit(oldp+519,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__is_write));
    bufp->fullCData(oldp+520,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT____Vcellinp__u_sdram_ctrl__inport_wr_i),4);
    bufp->fullBit(oldp+521,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_req_w));
    bufp->fullSData(oldp+522,((0x1feU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                         >> 1U))),13);
    bufp->fullSData(oldp+523,((0x1fffU & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                          >> 0xcU))),13);
    bufp->fullCData(oldp+524,((3U & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w 
                                     >> 0xaU))),2);
    bufp->fullIData(oldp+525,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_hd1274b5a__0) 
                               << 2U)),32);
    bufp->fullBit(oldp+526,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT____Vcellinp__mspi__in_pwrite));
    bufp->fullIData(oldp+527,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT____Vcellinp__mspi__in_pwdata),32);
    bufp->fullCData(oldp+528,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT____Vcellinp__mspi__in_pstrb),4);
    bufp->fullCData(oldp+529,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_hd1274b5a__0) 
                               << 2U)),5);
    bufp->fullBit(oldp+530,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (5U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_hd1274b5a__0)))));
    bufp->fullBit(oldp+531,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (4U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_hd1274b5a__0)))));
    bufp->fullCData(oldp+532,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                                 & (3U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_hd1274b5a__0))) 
                                << 3U) | ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                                            & (2U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_hd1274b5a__0))) 
                                           << 2U) | 
                                          ((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                                             & (1U 
                                                == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_hd1274b5a__0))) 
                                            << 1U) 
                                           | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                                              & (0U 
                                                 == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_hd1274b5a__0))))))),4);
    bufp->fullBit(oldp+533,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_h6152756d__0) 
                             & (6U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____VdfgTmp_hd1274b5a__0)))));
    bufp->fullCData(oldp+534,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT____Vcellinp__shift__latch),4);
    bufp->fullIData(oldp+535,((0x1fffffffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),32);
    bufp->fullCData(oldp+536,((7U & vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__ram_addr_w)),3);
    bufp->fullCData(oldp+537,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_w),8);
    bufp->fullCData(oldp+538,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT____Vcellinp__Uregs__wb_dat_i),8);
    bufp->fullIData(oldp+539,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__lsuRead)
                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_addr
                                : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_raddr)),32);
    bufp->fullQData(oldp+540,((((QData)((IData)(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__lsuRead)
                                                  ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_addr
                                                  : vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ifu_raddr))) 
                                << 0xbU) | (QData)((IData)(
                                                           ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__bridge__DOT__lsuRead)
                                                             ? (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_size)
                                                             : 2U))))),47);
    bufp->fullQData(oldp+542,((((QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_addr)) 
                                << 0xbU) | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_size)))),47);
    bufp->fullIData(oldp+544,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_jalr)
                                ? (0xfffffffeU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_exu0__DOT____VdfgTmp_h5f38b652__0)
                                : 0U)),32);
    bufp->fullIData(oldp+545,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_jalr)
                                ? ((IData)(4U) + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc)
                                : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_addi)
                                    ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_exu0__DOT____VdfgTmp_h5f38b652__0
                                    : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_add)
                                        ? (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__reg_rdata1 
                                           + vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__reg_rdata2)
                                        : ((0x37U == 
                                            (0x7fU 
                                             & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_ifu0__DOT__inst_reg))
                                            ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm
                                            : ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__is_csrrw)
                                                ? (
                                                   (0xb00U 
                                                    == 
                                                    (0xfffU 
                                                     & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))
                                                    ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__mcycle
                                                    : 
                                                   ((0xb80U 
                                                     == 
                                                     (0xfffU 
                                                      & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))
                                                     ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__mcycleh
                                                     : 
                                                    ((0xf11U 
                                                      == 
                                                      (0xfffU 
                                                       & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))
                                                      ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__mvendorid
                                                      : 
                                                     ((0xf12U 
                                                       == 
                                                       (0xfffU 
                                                        & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__imm))
                                                       ? vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_csr_reg0__DOT__marchid
                                                       : 0U))))
                                                : 0U)))))),32);
    bufp->fullIData(oldp+546,((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_ren) 
                                | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_wen))
                                ? (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_exu0__DOT____VdfgTmp_h5f38b652__0 
                                   >> 2U) : 0U)),30);
    bufp->fullIData(oldp+547,(((((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_ren) 
                                 | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_wen))
                                 ? (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_25070198_exu0__DOT____VdfgTmp_h5f38b652__0 
                                    >> 2U) : 0U) << 2U)),32);
    bufp->fullCData(oldp+548,((0xffU & ((0U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__sel))
                                         ? (0xffU & vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_rdata)
                                         : ((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__sel))
                                             ? (0xffU 
                                                & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_rdata 
                                                   >> 8U))
                                             : ((2U 
                                                 == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__sel))
                                                 ? 
                                                (0xffU 
                                                 & (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_rdata 
                                                    >> 0x10U))
                                                 : 
                                                ((3U 
                                                  == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__sel))
                                                  ? 
                                                 (vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_rdata 
                                                  >> 0x18U)
                                                  : 0U)))))),8);
    bufp->fullBit(oldp+549,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_pready));
    bufp->fullIData(oldp+550,(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata),32);
    bufp->fullBit(oldp+551,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_bvalid));
    bufp->fullBit(oldp+552,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rvalid));
    bufp->fullBit(oldp+553,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_bdeq_q__DOT__do_enq));
    bufp->fullBit(oldp+554,(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi4buf__DOT__nodeIn_rdeq_q__DOT__do_enq));
    bufp->fullCData(oldp+555,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__next_state_r),4);
    bufp->fullCData(oldp+556,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__target_state_r),4);
    bufp->fullCData(oldp+557,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__delay_r),4);
    bufp->fullBit(oldp+558,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__spi_ack));
    bufp->fullIData(oldp+559,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__mspi__DOT__u0_spi_top__DOT__wb_dat),32);
    bufp->fullCData(oldp+560,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r),8);
    bufp->fullCData(oldp+561,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__transmitter__DOT__tf_data_out),8);
    bufp->fullIData(oldp+562,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_addr),32);
    bufp->fullIData(oldp+563,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_wdata),32);
    bufp->fullCData(oldp+564,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_wmask),4);
    bufp->fullQData(oldp+565,((((QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_wdata)) 
                                << 4U) | (QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT___cpu_io_lsu_wmask)))),36);
    bufp->fullIData(oldp+567,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__reg_rdata1),32);
    bufp->fullIData(oldp+568,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__reg_rdata2),32);
    bufp->fullIData(oldp+569,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_wdata),32);
    bufp->fullCData(oldp+570,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__mem_mask),4);
    bufp->fullCData(oldp+571,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__sel),2);
    bufp->fullBit(oldp+572,(vlSelf->clock));
    bufp->fullBit(oldp+573,(vlSelf->reset));
    bufp->fullBit(oldp+574,(vlSelf->externalPins_uart_rx));
    bufp->fullBit(oldp+575,(vlSelf->externalPins_uart_tx));
    bufp->fullBit(oldp+576,((1U & ((IData)(vlSelf->ysyxSoCFull__DOT____Vcellinp__flash__ss) 
                                   | ((((2U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__state)) 
                                        & (0U == (IData)(vlSelf->ysyxSoCFull__DOT__flash__DOT__counter)))
                                        ? vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap
                                        : vlSelf->ysyxSoCFull__DOT__flash__DOT__data) 
                                      >> 0x1fU)))));
    bufp->fullBit(oldp+577,((1U & (~ (IData)(vlSelf->clock)))));
    bufp->fullSData(oldp+578,(vlSelf->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__sdram_data_in_w),16);
    bufp->fullIData(oldp+579,(((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT___apbxbar_auto_anon_out_1_psel)
                                ? (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                    << 0x18U) | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                  << 0x10U) 
                                                 | (((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r) 
                                                     << 8U) 
                                                    | (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_dat8_r))))
                                : 0U)),32);
    bufp->fullBit(oldp+580,((((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__cmd_state)) 
                              | (8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__cmd_state))) 
                             & (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__spi_ack))));
    bufp->fullIData(oldp+581,(((8U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT__cmd_state))
                                ? ((vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT___mspi_in_prdata 
                                    << 0x18U) | ((0xff0000U 
                                                  & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT___mspi_in_prdata 
                                                     << 8U)) 
                                                 | ((0xff00U 
                                                     & (vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT___mspi_in_prdata 
                                                        >> 8U)) 
                                                    | (vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT___mspi_in_prdata 
                                                       >> 0x18U))))
                                : vlSelf->ysyxSoCFull__DOT__asic__DOT__lspi__DOT___mspi_in_prdata)),32);
    bufp->fullIData(oldp+582,(((1U == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata
                                : vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r)),32);
    bufp->fullQData(oldp+583,((((QData)((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__rid_reg)) 
                                << 0x23U) | (((QData)((IData)(
                                                              ((1U 
                                                                == (IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__state))
                                                                ? vlSelf->ysyxSoCFull__DOT__asic__DOT___apbdelay_delayer_in_prdata
                                                                : vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__nodeIn_rdata_r))) 
                                              << 3U) 
                                             | (QData)((IData)(
                                                               (1U 
                                                                | ((IData)(vlSelf->ysyxSoCFull__DOT__asic__DOT__axi42apb__DOT__resp_hold) 
                                                                   << 1U))))))),39);
    bufp->fullBit(oldp+585,(vlSelf->ysyxSoCFull__DOT__asic__DOT____Vcellinp__cpu__reset));
    bufp->fullBit(oldp+586,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_we));
    bufp->fullBit(oldp+587,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__reg_re));
    bufp->fullSData(oldp+588,(((vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                                [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom] 
                                << 3U) | (IData)(vlSelf->__VdfgTmp_ha17ae98a__0))),11);
    bufp->fullCData(oldp+589,(vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__rfifo__DOT__ram
                              [vlSelf->ysyxSoCFull__DOT__asic__DOT__luart__DOT__muart__DOT__Uregs__DOT__receiver__DOT__fifo_rx__DOT__bottom]),8);
    bufp->fullIData(oldp+590,(vlSelf->ysyxSoCFull__DOT__flash__DOT__rdata),32);
    bufp->fullIData(oldp+591,(((0xfffffeU & (vlSelf->ysyxSoCFull__DOT__flash__DOT__addr 
                                             << 1U)) 
                               | (IData)(vlSelf->ysyxSoCFull__DOT___asic_spi_mosi))),32);
    bufp->fullIData(oldp+592,(vlSelf->ysyxSoCFull__DOT__flash__DOT__data_bswap),32);
    bufp->fullSData(oldp+593,(vlSelf->ysyxSoCFull__DOT__sdram__DOT___rowReg_ext_R0_data),13);
    bufp->fullCData(oldp+594,(1U),3);
    bufp->fullBit(oldp+595,(0U));
    bufp->fullCData(oldp+596,(0U),2);
    bufp->fullCData(oldp+597,(0U),4);
    bufp->fullCData(oldp+598,(0U),8);
    bufp->fullBit(oldp+599,(1U));
    bufp->fullIData(oldp+600,(0U),32);
    bufp->fullCData(oldp+601,(0U),3);
    bufp->fullIData(oldp+602,(vlSelf->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__debug_x10),32);
    bufp->fullIData(oldp+603,(0x64U),32);
    bufp->fullIData(oldp+604,(0x18U),32);
    bufp->fullIData(oldp+605,(9U),32);
    bufp->fullIData(oldp+606,(2U),32);
    bufp->fullIData(oldp+607,(4U),32);
    bufp->fullIData(oldp+608,(0xdU),32);
    bufp->fullIData(oldp+609,(0x2000U),32);
    bufp->fullIData(oldp+610,(0x2710U),32);
    bufp->fullIData(oldp+611,(0x30cU),32);
    bufp->fullCData(oldp+612,(7U),4);
    bufp->fullCData(oldp+613,(3U),4);
    bufp->fullCData(oldp+614,(5U),4);
    bufp->fullCData(oldp+615,(4U),4);
    bufp->fullCData(oldp+616,(6U),4);
    bufp->fullCData(oldp+617,(2U),4);
    bufp->fullCData(oldp+618,(1U),4);
    bufp->fullSData(oldp+619,(0x21U),13);
    bufp->fullCData(oldp+620,(8U),4);
    bufp->fullCData(oldp+621,(9U),4);
    bufp->fullIData(oldp+622,(0xaU),32);
    bufp->fullIData(oldp+623,(0x10U),32);
    bufp->fullIData(oldp+624,(6U),32);
    bufp->fullIData(oldp+625,(0x11U),32);
    bufp->fullIData(oldp+626,(0x30000000U),32);
    bufp->fullIData(oldp+627,(0x3fffffffU),32);
    bufp->fullIData(oldp+628,(8U),32);
    bufp->fullIData(oldp+629,(1U),32);
    bufp->fullBit(oldp+630,(1U));
    bufp->fullCData(oldp+631,(0xaU),4);
    bufp->fullIData(oldp+632,(0xbU),32);
    bufp->fullIData(oldp+633,(5U),32);
    bufp->fullCData(oldp+634,(2U),3);
    bufp->fullCData(oldp+635,(3U),3);
    bufp->fullCData(oldp+636,(4U),3);
    bufp->fullCData(oldp+637,(5U),3);
}
