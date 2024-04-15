#include "../Include/stdint.h"

#include "graphics.h"

void SetPixel(int x, int y, BYTE color)
{
    LPBYTE vidmem = (LPBYTE) VIDEOMEM;
    
    vidmem[y * WSCREEN + x] = color;
}
