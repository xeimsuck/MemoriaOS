// Constants
.set ALIGN, 1<<0
.set MEMINFO, 1<<1
.set MAGIC, 0x1BADB002
.set FLAGS, ALIGN | MEMINFO
.set CHECKSUM, 0x0-(MAGIC + FLAGS)

// Header
.section .multiboot
.align 4
mb_header_start:
    .long MAGIC
    .long FLAGS
    .long CHECKSUM
mb_header_end: