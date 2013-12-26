OUTPUT_FORMAT("binary")
ENTRY(start)

SECTIONS {
. = 0x00100000;
.text : {
code = .;
*(.text)
*(.rodata)
. = ALIGN(4096);
}

.data : {
data = .;
*(.data)
. = ALIGN(4096);
}

.bss : {
bss = .;
*(.bss)
. = ALIGN(4096);
}

end = .;
}
