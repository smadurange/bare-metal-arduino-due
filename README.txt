Compile and upload

$ arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -o a.elf main.c
$ arm-none-eabi-objcopy -O ihex -j .text -j .data a.elf a.hex
$ avrdude -c arduino -p atmel_sam3x8e -v -b 115200 -U flash:w:a.hex
