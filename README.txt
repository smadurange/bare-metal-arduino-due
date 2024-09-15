Set GPNVM bits to boot from flash0:

# openocd -f openocd-due.cfg
$ telnet localhost 4444
  > halt
  > at91sam3 gpnvm set 1
  > at91sam3 gpnvm show

Compile and flash

$ arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -T script.ld -nostartfiles -nostdlib -o a.elf main.c
# openocd -f openocd-due.cfg -c "program a.elf verify reset exit"
