MEMORY
{
	rom (rx)  : ORIGIN = 0x00080000, LENGTH = 0x00080000
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00010000
}

SECTIONS
{
	. = ALIGN(4);
	.text :
	{
		KEEP(*(.vectors .vectors.*))
		*(.text*)
		*(.rodata*)
	} > rom

	. = ALIGN(4);
	.data :
	{
		*(.data*);
	} > ram AT >rom

	. = ALIGN(4);
	.bss (NOLOAD) :
	{
		__bss_start__ = . ;
		*(.bss*)
		*(COMMON)
		__bss_end__ = . ;
	} > ram

	_end = . ;
	__end__ = _end ;
	end = _end;
}
