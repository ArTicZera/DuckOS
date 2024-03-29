[BITS    16]
[ORG 0x7E00]

%define KERNELLOCAL 0x1000
%define KERNELSCTRS 0x0025

setup:
        ;ES:BX
        xor     bx, bx
        mov     es, bx

        mov     bx, KERNELLOCAL
        mov     al, KERNELSCTRS

        ;Read Sectors Function
        mov     ah, 0x02

        mov     ch, 0x00 ;Cylinder
        mov     dh, 0x00 ;Head
        mov     cl, 0x04 ;Sector

        int     0x13

        call    LoadGDT

        jmp     CODESEG:pmode

%include "Bootloader/gdt.asm"
%include "Bootloader/pmode.asm"

times 1024 - ($ - $$) db 0x00
