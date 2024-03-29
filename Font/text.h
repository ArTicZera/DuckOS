int cursorX = 0;
int cursorY = 0;

void DrawChar(BYTE* c, BYTE color)
{
    int i = 0;

    for (int y = 0; y < HFONT; y++)
    {
        for (int x = WFONT - 1; x >= 0; x--)
        {
            if (c[y] & (1 << x))
            {
                SetPixel(i + cursorX, y + cursorY, color);
            }
            i++;
        }
        i = 0;
    }

    cursorX += 8;

    if (cursorX >= 8 * 40)
    {
        cursorX = 0;
        cursorY += 9;
    }
}

void PrintString(const CHAR* str, BYTE color)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            cursorX = -8;
            cursorY += 9;
        }

        DrawChar(ProggyCleanTT+(str[i]*8), color);
    }
}

void Debug(const CHAR* str, int debug)
{
    switch (debug)
    {
        case 0:
            PrintString("[+] ", 0x0A);    
            break;
        case 1:
            PrintString("[-] ", 0x0C);
            break;
    }

    PrintString(str, 0x0F);
}
