[BITS    16]
[ORG 0x7C00]

%define STAGE2LOCAL 0x7E00
%define STAGE2SCTRS 0x0002

setup:
        cli

        ;Setup Data Segments
	xor     ax, ax
	mov     ds, ax
	mov     es, ax

        ;Setup Stack
	mov     sp, 0x7C00
	mov     ss, ax

        sti

        ;Setup Mode 13h
        mov     ax, 0x13
        int     0x10

        call    ReadSectors

        jmp     0x0000:STAGE2LOCAL

ReadSectors:
        mov     bx, STAGE2LOCAL
        mov     al, STAGE2SCTRS

        ;Read Sectors function
        mov     ah, 0x02

        mov     ch, 0x00 ;Cylinder
        mov     dh, 0x00 ;Head
        mov     cl, 0x02 ;Sector

        int     0x13

        ret

times 510 - ($ - $$) db 0x00
dw 0xAA55
