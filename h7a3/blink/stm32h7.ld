

/* Entry Point */
ENTRY(Reset_Handler)

/* value of stack pointer */
_estack = ORIGIN(RAM) + LENGTH(RAM);

/* Memories definition */
MEMORY
{
  ITCMRAM (xrw)  : ORIGIN = 0x00000000, LENGTH = 64K
  FLASH (rx)     : ORIGIN = 0x08000000, LENGTH = 2048K
  DTCMRAM1 (xrw) : ORIGIN = 0x20000000, LENGTH = 64K
  DTCMRAM2 (xrw) : ORIGIN = 0x20010000, LENGTH = 64K
  RAM (xrw)      : ORIGIN = 0x24000000, LENGTH = 1024K
  RAM_CD (xrw)   : ORIGIN = 0x30000000, LENGTH = 128K
  RAM_SRD (xrw)  : ORIGIN = 0x38000000, LENGTH = 32K
}

/* Sections */
SECTIONS
{
  .isr_vector :
  {
    . = ALIGN(4);
    KEEP(*(.isr_vector))
    . = ALIGN(4);
  } >FLASH

  .text :
  {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    . = ALIGN(4);
    _etext = .;
  } >FLASH

  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
  } >FLASH


  /* load memory address for .data section*/
  _la_data = LOADADDR(.data);

  .data :
  {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */

    . = ALIGN(4);
    _edata = .;        /* define a global symbol at data end */

  } >RAM AT> FLASH

  . = ALIGN(4);
  .bss :
  {
    _sbss = .;         /* define a global symbol at bss start */
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
  } >RAM

  /* Remove information from the compiler libraries */
  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }

}
