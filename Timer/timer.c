#include "../Include/stdint.h"
#include "../Interrupts/idt.h"
#include "../Include/ports.h"
#include "../Font/text.h"

#include "timer.h"

uint64_t ticks = 0;
const DWORD freq = 100;

void PITIRQ0()
{
    ticks += 1;
}

void InitTimer()
{
    IRQInstallHandler(0x00, &PITIRQ0);

    DWORD divisor = 1193180 / freq;

    outb(0x43, 0x36);
    outb(0x40, (BYTE)(divisor & 0xFFFF));
    outb(0x40, (BYTE)((divisor & 0xFFFF) & 0xFF));
}