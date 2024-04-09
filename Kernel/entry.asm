[BITS     32]
[EXTERN main]

section .text
        global _start

_start:
        call    main

        jmp $

%include "Interrupts/idt.asm"
