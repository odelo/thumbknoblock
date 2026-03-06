MEMORY { FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1536K  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 256K }
ENTRY(Reset_Handler)
SECTIONS {
    .vectors : { KEEP(*(.vectors)) } > FLASH
    .text    : { *(.text*) *(.rodata*) . = ALIGN(4); _etext = .; } > FLASH
    .data    : { _sdata = .; *(.data*) . = ALIGN(4); _edata = .; } > RAM AT > FLASH
    _sidata = LOADADDR(.data);
    .bss (NOLOAD) : { _sbss = .; *(.bss*) *(COMMON) . = ALIGN(4); _ebss = .; } > RAM
    .heap  (NOLOAD) : { . = ALIGN(8); _sheap = .; . += 0x2000; _eheap = .; } > RAM
    .stack (NOLOAD) : { . = ALIGN(8); _sstack = .; . += 0x1000; _estack = .; } > RAM
    /DISCARD/ : { *(.ARM.exidx*) *(.gnu.linkonce.armexidx.*) }
}