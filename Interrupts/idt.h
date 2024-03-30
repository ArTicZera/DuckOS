#define TOTALGATES 256
#define CODESEG 0x08

struct IDT_GateDescriptor
{
    WORD offset;   //offset (0 - 15)
    WORD selector; //code segment selector (16 - 31)
    BYTE reserved; //reserved (32 - 39)
    BYTE flags;    //gatetype, dpl, p, 0 (40 - 47)
    WORD offset2;  //offset (48 - 63)
} __attribute__((packed));

struct IDT_Descriptor
{
    WORD  size;   //IDT size in bytes
    DWORD offset; //linear addr to IDT
} __attribute__((packed));

void SetupIDTGate(BYTE entry, DWORD isr, WORD selector, BYTE flags);
void SetupIDT(void);
