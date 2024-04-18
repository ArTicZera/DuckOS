#include "../Include/stdint.h"
#include "../Graphics/graphics.h"
#include "../Font/text.h"
#include "../Timer/timer.h"
#include "../Drivers/keyboard.h"

#include "../Interrupts/idt.h"

void main(void)
{
    Debug("Kernel Loaded!\n", 0);

    SetupIDT();
    Debug("IDT Loaded!\n", 0);

    InitTimer();
    Debug("PIT Timer Started!\n", 0);

    InitKeyboard();
    Debug("Keyboard Driver Started!\n", 0);
}
