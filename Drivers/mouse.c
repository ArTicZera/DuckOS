#include "../Include/stdint.h"
#include "../Include/ports.h"
#include "../Graphics/graphics.h"
#include "../Interrupts/idt.h"
#include "../Font/text.h"
#include "../Timer/timer.h"

#include "cursor.h"

BYTE MouseArea[WCURSOR * HCURSOR];
BYTE MouseCursorAfter[WCURSOR * HCURSOR];

BYTE mouseData;
BYTE mouseCycle;
BYTE mousePacket[4];

int prevMouseX = 0;
int prevMouseY = 0;

int mouseX = 0;
int mouseY = 0;

void DrawMouse(BYTE color)
{
    for (int y = 0; y < HCURSOR; y++)
    {
        int x = 0;

        for (int i = 0; i < 2; i++)
        {
            BYTE byte = cursor[y * 2 + i];

            for (int j = 7; j >= 0; j--)
            {
                if (byte & (1 << j))
                {
                    SetPixel(mouseX + x, mouseY + y, color);
                }
                x++;
            }
        }
    }
}

void SaveMouseArea()
{
    for (int y = 0; y < HCURSOR; y++)
    {
        for (int x = 0; x < WCURSOR; x++)
        {
            MouseArea[y * WCURSOR + x] = GetPixel(mouseX + x, mouseY + y);
        }
    }
}

void RestorePreviousCursor()
{
    for (int y = 0; y < HCURSOR; y++)
    {
        for (int x = 0; x < WCURSOR; x++)
        {
            SetPixel(mouseX + x, mouseY + y, MouseArea[y * WCURSOR + x]);
        }
    }
}

void MouseWait()
{
    //for (int i = -9000000; i < 9000000; i++);

    //Someone kill me
    for (int i = -30000000; i < 30000000; i++);
}

void MouseHandler()
{
    mouseData = inb(0x60);

    mousePacket[mouseCycle++] = mouseData;

    if (mouseCycle == 3)
    {
        mouseX += (int)((char)mousePacket[1]);
        mouseY -= (int)((char)mousePacket[2]);

        mouseX = (mouseX < 0) ? 0 : ((mouseX > WSCREEN - 16) ? WSCREEN - 16 : mouseX);
        mouseY = (mouseY < 0) ? 0 : ((mouseY > HSCREEN - 16) ? HSCREEN - 16 : mouseY);

        mouseCycle = 0;

        SaveMouseArea();
        DrawMouse(0x0F);
        MouseWait();
        RestorePreviousCursor();
    }
}

void InitMouse()
{
    outb(0x64, 0xA7);
    outb(0x64, 0xA8);

    IRQInstallHandler(12, &MouseHandler);

    //Enabling Mouse Interruptions
    outb(0x64, 0x20);
    BYTE status = (inb(0x60) | 2);
    outb(0x64, 0x60);
    outb(0x60, status);

    //Command to Enable Mouse
    outb(0x64, 0xD4);
    outb(0x60, 0xF4);
}
