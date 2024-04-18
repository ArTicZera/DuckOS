#include "../Include/stdint.h"

#include "mem.h"

void* memset(void* dst, char val, DWORD num)
{
    LPBYTE tmp = (LPBYTE) dst;

    for (DWORD i = 0; i < num; i++)
    {
        tmp[i] = (BYTE) val;
    }

    return dst;
}
