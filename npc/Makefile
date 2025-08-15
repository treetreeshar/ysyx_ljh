TOPNAME = top
VERILATOR = verilator
INC_PATH ?=  #可添加自定义头文件路径

VERILATOR_CFLAGS += --cc --build --x-assign fast --x-initial fast
#VERILATOR_CFLAGS += -O3 --noassert
#VERILATOR_CFLAGS += --trace   波形跟踪
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

#默认HEX文件路径
HEX_FILE ?= ./logisim-bin/mem.hex
BASE_ADDR ?= 0x00000000

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

run: $(BIN)
	@$< $(HEX_FILE) $(BASE_ADDR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default run clean

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

#include ../Makefile