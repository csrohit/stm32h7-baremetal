# @file Makefile
# @author Rohit Nimkar
# 
# 



TARGET = blink

LDSCRIPT 	= stm32h7_cm4.ld

PREFIX      =   arm-none-eabi
CC          =   ${PREFIX}-gcc
LD 		    =   ${PREFIX}-ld
AS 		    =   ${PREFIX}-as
GDB 	    =   ${PREFIX}-gdb
OBJCOPY     =   ${PREFIX}-objcopy
SIZE     	=   ${PREFIX}-size

SRC_DIRS    = src
BUILD_DIR   = build
INC_DIRS	= include
DEFS 		= -DSTM32H755xx -DCORE_CM4

MCU_FLAGS 	= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -g -gdwarf-2
LDFLAGS     = $(MCU_FLAGS) -nostdlib
CFLAGS      = $(MCU_FLAGS) -nostdlib
CPPFLAGS 	= $(addprefix -I,$(INC_DIRS)) $(DEFS)

SRCS        = $(shell find $(SRC_DIRS) -name '*.c')
OBJS        = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all : bin size
elf : $(BUILD_DIR)/$(TARGET).elf
bin : $(BUILD_DIR)/$(TARGET).bin
size: $(BUILD_DIR)/$(TARGET).size

%.bin: %.elf
	$(OBJCOPY) -Obinary $(*).elf $(*).bin

%.size: %.elf
	$(SIZE) $<

$(BUILD_DIR)/$(TARGET).elf: $(OBJS)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $(OBJS) -T$(LDSCRIPT) -Wl,-Map="$(BUILD_DIR)/$(TARGET).map"

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

flash: elf
	STM32_Programmer_CLI -c port=SWD ap=3 -w $(BUILD_DIR)/$(TARGET).elf -rst

clean:
	rm -rf $(BUILD_DIR)
