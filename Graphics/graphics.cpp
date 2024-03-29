#include "../Include/stdint.h"

#include "graphics.h"

void SetPixel(int x, int y, BYTE color)
{
    LPBYTE vidmem = (LPBYTE) 0xA0000;
    
    vidmem[y * WSCREEN + x] = color;
}
