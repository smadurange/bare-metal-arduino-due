CC = arm-none-eabi-gcc
CPU = cortex-m3
TARGET = due

SRC = main.c
OBJ = $(SRC:.c=.o)

CFLAGS = -std=gnu99
CFLAGS += -Os
CFLAGS += -Wall
CFLAGS += -mcpu=$(CPU)
CFLAGS += -mthumb

LDFLAGS = -mcpu=$(CPU)
LDFLAGS += -Wl,--gc-sections

HEX_FLAGS = -O ihex
HEX_FLAGS += -j .text -j .data

%.o: %.c
	 $(CC) $(CFLAGS) -c -o $@ $<

elf: $(OBJ)
	 $(CC) $(LDFLAGS) $(OBJ) -o $(TARGET).elf

hex: elf
	 arm-none-eabi-objcopy $(HEX_FLAGS) $(TARGET).elf $(TARGET).hex

#upload: hex
#     openocd -f openocd-due.cfg -c "program $(TARGET) verify reset exit"

.PHONY: clean

clean:
	 rm *.o *.elf *.hex 
