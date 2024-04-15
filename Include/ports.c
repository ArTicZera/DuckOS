#include "stdint.h"

void outb(WORD Port, BYTE Value)
{
    asm volatile ("outb %1, %0" : : "dN" (Port), "a" (Value));
}