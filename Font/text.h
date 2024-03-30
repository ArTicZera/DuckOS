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

void IntToString(int value, char* buffer)
{
    char temp[11];
    int i = 0;
    int isNegative = 0;

    if (value < 0) 
    {
        isNegative = 1;
        value = -value;
    }

    do 
    {
        temp[i++] = (value % 10) + '0';
        value /= 10;
    } while (value > 0);

    if (isNegative) 
    {
        temp[i++] = '-';
    }

    temp[i] = '\0';

    int j;

    for (j = 0; j < i; j++) 
    {
        buffer[j] = temp[i - j - 1];
    }

    buffer[j] = '\0';
}

void PrintInt(int value, BYTE color) 
{
    char buffer[11];
    IntToString(value, buffer);
    PrintString(buffer, color);
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
