#define PCI_CONFIG_ADDRESS 0xCF8
#define PCI_CONFIG_DATA 0xCFC

DWORD PCIConfigReadWord(BYTE bus, BYTE slot, BYTE func, BYTE offset);
void ShowPCIDevices();
