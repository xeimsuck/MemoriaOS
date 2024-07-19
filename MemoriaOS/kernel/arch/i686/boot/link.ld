ENTRY(_start)

SECTIONS
{
	. = 0x080000;

	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

    .init BLOCK(4K) : ALIGN(4K)
    {
        crtbegin.o (.init) crtend.o (.init)
    }

    .fini BLOCK(4K) : ALIGN(4K)
    {
        crtbegin.o (.fini) crtend.o (.fini)
    }

	.rodata BLOCK(4K) : ALIGN(4K)
	{
	    start_ctors = .;
    	KEEP (*(SORT(.ctors*)))
    	end_ctors = .;
    	KEEP (*(SORT(.dtors*)))
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
