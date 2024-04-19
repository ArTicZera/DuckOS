#include "stdint.h"

void outb(WORD port, BYTE value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

char inb(WORD port)
{
    char ret;
    asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
    
    return ret;
}

void outl(WORD port, DWORD value)
{
    asm volatile ("outl %0, %1" : : "a" (value), "Nd" (port));
}

DWORD inl(WORD port)
{
    DWORD ret;
    asm volatile ("inl %1, %0" : "=a" (ret) : "Nd" (port));
    
    return ret;
}
