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