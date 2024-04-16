#include "stdint.h"

void outb(WORD Port, BYTE Value)
{
    asm volatile ("outb %1, %0" : : "dN" (Port), "a" (Value));
}

char inb(WORD port)
{
    char ret;
    asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));   
    return ret;
}
