MEMORY
{
	rom (rx)  : ORIGIN = 0x00080000, LENGTH = 512K
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
}

sp = ORIGIN(ram) + LENGTH(ram);

SECTIONS
{
	.text :
	{
		KEEP(*(.vtor))
		*(.text*)
		*(.rodata*)
	} > rom

	.data :
	{
		*(.data*)
	} > ram AT >rom

	.bss (NOLOAD) :
	{
		__bss_start__ = . ;
		*(.bss*)
		*(COMMON)
		__bss_end__ = . ;
	} > ram
}
