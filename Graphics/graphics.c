#include "../Include/stdint.h"

#include "graphics.h"

void SetPixel(int x, int y, BYTE color)
{
    LPBYTE vidmem = (LPBYTE) VIDEOMEM;
    
    vidmem[y * WSCREEN + x] = color;
}

BYTE GetPixel(int x, int y)
{
    LPBYTE vidmem = (LPBYTE) VIDEOMEM;

    return vidmem[y * WSCREEN + x];
}
