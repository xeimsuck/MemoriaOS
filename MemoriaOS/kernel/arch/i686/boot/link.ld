ENTRY(_start)

SECTIONS
{
	. = 0x080000;

	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

    .crt BLOCK(4K) : ALIGN(4K)
    {
        crtbegin.o crtend.o
    }

	.rodata BLOCK(4K) : ALIGN(4K)
	{
	    mos_start_ctors = .;
    	KEEP (*(SORT(.ctors*)))
    	mos_end_ctors = .;
    	mos_start_dtors = .;
    	KEEP (*(SORT(.dtors*)))
    	mos_end_dtors = .;
		*(.rodata)
	}

	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	.bss BLOCK(4K) : ALIGN(4K)
	{
	    *(COMMON)
		*(.bss)
	}
}
