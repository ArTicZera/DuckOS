#include "../Include/stdint.h"
#include "../Memory/mem.h"

#include "idt.h"

extern "C" void LoadIDT();

struct IDT_GateDescriptor idt[TOTALGATES];
struct IDT_Descriptor idtr;

void SetupIDTGate(BYTE entry, DWORD isr, WORD selector, BYTE flags)
{
    idt[entry].selector = selector;
    idt[entry].reserved = 0x00;
    idt[entry].flags = flags;

    idt[entry].offset  = isr & 0xFFFF; //Low 16 bits
    idt[entry].offset2 = (isr >> 16) & 0xFFFF; //High 16 bits
}

void SetupIDT(void)
{
    int IDTSize = sizeof(struct IDT_GateDescriptor) * TOTALGATES;

    idtr.size   = IDTSize - 1;
    idtr.offset = (DWORD) &idt;

    memset(&idt, 0, IDTSize);

    LoadIDT();
}
