TOPNAME = ysyxSoCFull
VERILATOR = verilator
INC_PATH ?=  #可添加自定义头文件路径
SOC_HOME = $(NPC_HOME)/../ysyxSoC

VERILATOR_CFLAGS += --cc --build --x-assign fast --x-initial fast --timescale "1ns/1ns" --no-timing
#VERILATOR_CFLAGS += -O3 --noassert
VERILATOR_CFLAGS += --trace  # 波形跟踪
BUILD_DIR = ./build
OBJ_DIR = ./obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

#默认HEX文件路径
FILE ?= ./logisim-bin/dummy-minirv-npc.bin
BASE_ADDR ?= 0x30000000

default: $(BIN)

$(shell mkdir -p $(OBJ_DIR))

VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
VSRCS += $(shell find $(SOC_HOME)/perip -name "*.v")
VSRCS += $(SOC_HOME)/ready-to-run/D-stage/ysyxSoCFull.v
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
INVFLAGS += -I$(SOC_HOME)/perip/uart16550/rtl
INVFLAGS += -I$(SOC_HOME)/perip/spi/rtl

INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
CXXFLAGS += -DTOP_NAME="\"V$(TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		$(INVFLAGS) \
		--exe -o $(abspath $(BIN))

run: $(BIN)
	@$< $(FILE) $(BASE_ADDR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default run clean

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

#include ../Makefile