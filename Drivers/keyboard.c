#include "../Include/stdint.h"
#include "../Include/ports.h"
#include "../Interrupts/idt.h"
#include "../Font/text.h"

#include "keyboard.h"

int allowInput = 1;
int shift = 0;
int caps = 0;

const char* lowercase[] =
{
    " ", " ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
    "-", "=", "\b", " ", "q", "w", "e", "r", "t", "y", "u", "i",
    "o", "p", "[", "]", "\n", " ", "a", "s", "d", "f", "g", "h",
    "j", "k", "l", ";", "'", "`", " ", "\\", "z", "x", "c", "v",
    "b", "n", "m", ",", ".", "/", " ", "*", " ", " "
};

const char* uppercase[] =
{
    " ", " ", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")",
    "_", "+", "\b", " ", "Q", "W", "E", "R", "T", "Y", "U", "I",
    "O", "P", "{", "}", "\n", " ", "A", "S", "D", "F", "G", "H",
    "J", "K", "L", ":", "\"", "~", " ", "|", "Z", "X", "C", "V",
    "B", "N", "M", "<", ">", "?", " ", " ", " ", " "
};

void KeyboardHandler()
{
    char scan = inb(0x60) & 0x7F;
    char isPress = inb(0x60) & 0x80;

    if (allowInput)

    switch (scan)
    {
        //Shift
        case 42:
            if (isPress == 0)
            {
                shift = 1;
            }
            else
            {
                shift = 0;
            }
            break;

        //Caps lock
        case 58:
            if (!caps && isPress == 0)
            {
                caps = 1;
            }
            else if (caps && isPress == 0)
            {
                caps = 0;
            }

            break;

        default:
            if (isPress == 0)
            {
                if (shift || caps) 
                {
                    Print(uppercase[scan], 0x0F);
                }
                else 
                {
                    Print(lowercase[scan], 0x0F);
                }
            }
            break;
    }
}

void InitKeyboard()
{
    IRQInstallHandler(0x01, &KeyboardHandler);
}