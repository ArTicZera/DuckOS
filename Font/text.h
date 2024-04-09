int cursorX = 0;
int cursorY = 0;

void DrawChar(BYTE* bitmap, BYTE color)
{
    int x = 0;

    for (int i = 0; i < 24; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            for (int k = 7; k >= 0; k--) 
            {
                if ((bitmap[i * 2 + j] >> k) & 0x01) 
                {
                    SetPixel(x + cursorX, i + cursorY, color);
                }
                x++;
            }
        }
        x = 0;
    }

    cursorX += 12;

    if (cursorX >= 790)
    {
        cursorX = 0;
        cursorY += 24;
    }

}

void Print(const char* str, BYTE color)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            cursorX = 0;
            cursorY += 24;

            continue;
        }

        DrawChar(font + (2 * 24) * str[i], color);
    }
}

void Debug(const CHAR* str, int debug)
{
    switch (debug)
    {
        case 0:
            Print("[+] ", 0x0A);    
            break;
        case 1:
            Print("[-] ", 0x0C);
            break;
    }

    Print(str, 0x0F);
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
    Print(buffer, color);
}
