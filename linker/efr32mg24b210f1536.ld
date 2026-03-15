MEMORY { FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1536K  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 256K }
ENTRY(Reset_Handler)
SECTIONS {
    .vectors : { KEEP(*(.vectors)) } > FLASH
    .text    : { *(.text*) *(.rodata*) . = ALIGN(4); _etext = .; } > FLASH
    .init : {
        KEEP(*crti.o(.init))
        KEEP(*(.init))
        KEEP(*crtn.o(.init))
    } > FLASH
    .fini : {
        KEEP(*crti.o(.fini))
        KEEP(*(.fini))
        KEEP(*crtn.o(.fini))
    } > FLASH
    .preinit_array : {
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP (*(.preinit_array*))
        PROVIDE_HIDDEN (__preinit_array_end = .);
    } > FLASH
    .init_array : {
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array*))
        PROVIDE_HIDDEN (__init_array_end = .);
    } > FLASH
    .fini_array : {
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP (*(SORT(.fini_array.*)))
        KEEP (*(.fini_array*))
        PROVIDE_HIDDEN (__fini_array_end = .);
    } > FLASH
    .data    : { _sdata = .; *(.data*) . = ALIGN(4); _edata = .; } > RAM AT > FLASH
    _sidata = LOADADDR(.data);
    .bss (NOLOAD) : { _sbss = .; *(.bss*) *(COMMON) . = ALIGN(4); _ebss = .; } > RAM
    .heap  (NOLOAD) : { . = ALIGN(8); _sheap = .; . += 0x2000; _eheap = .; } > RAM
    .stack (NOLOAD) : { . = ALIGN(8); _sstack = .; . += 0x1000; _estack = .; } > RAM
    /DISCARD/ : { *(.ARM.exidx*) *(.gnu.linkonce.armexidx.*) }
}