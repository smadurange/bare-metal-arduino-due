ENTRY(main)

MEMORY
{
	rom (rx)  : ORIGIN = 0x00080000, LENGTH = 0x00080000
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00010000
}

SECTIONS
{
	.text :
	{
		KEEP(*(.vtor))

		*(.text*)
		*(.rodata*)

		. = ALIGN(4);
		__end_of_text__ = .;
	} > rom

	.data :
	{
		__data_start_src__ = __end_of_text__;
		__data_start__ = .;

		*(.data*)

		. = ALIGN(4);
		__data_end__ = .;
	} > ram AT >rom

	.bss (NOLOAD) :
	{
		__bss_start__ = . ;
		*(.bss*)
		*(COMMON)
		__bss_end__ = . ;
	} > ram

	sp = ORIGIN(ram) + LENGTH(ram);
}
