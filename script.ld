MEMORY
{
	rom (rx)  : ORIGIN = 0x00080000, LENGTH = 512K
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
}

_sp = ORIGIN(ram) + LENGTH(ram);

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
		_sdata = . ;
		*(.data*)
		_edata = . ;
	} > ram AT > rom

	_sidata = LOADADDR(.data);

	.bss (NOLOAD) :
	{
		_sbss = . ;
		*(.bss*)
		*(COMMON)
		_ebss = . ;
	} > ram
}
