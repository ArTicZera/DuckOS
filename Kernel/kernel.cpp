#include "../Include/stdint.h"
#include "../Graphics/graphics.h"
#include "../Font/text.h"

#include "../Interrupts/idt.h"

void main(void)
{
    Debug("Kernel loaded!\n", 0);

    SetupIDT();
    Debug("IDT Loaded!", 0);
}
