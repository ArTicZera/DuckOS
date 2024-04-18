clear

export PATH="$PATH:/usr/local/i386elfgcc/bin"

BIN="Binaries"
CCFLAGS="-ffreestanding -m32 -g"
LDFILES="$BIN/entry.o $BIN/kernel.o $BIN/ports.o $BIN/graphics.o $BIN/text.o $BIN/mem.o $BIN/asmidt.o $BIN/idt.o $BIN/timer.o $BIN/keyboard.o"

# Compiling ASM Files...
echo -e "\n\e[33;40mCompiling ASM Files...\e[0m"
nasm -fbin Bootloader/boot.asm -o $BIN/boot.bin
nasm -fbin Bootloader/stg2.asm -o $BIN/stg2.bin
nasm -felf Kernel/entry.asm    -o $BIN/entry.o
nasm -felf Interrupts/idt.asm  -o $BIN/asmidt.o

# Compiling Kernel Files...
echo -e "\n\e[33;40mCompiling C Files...\e[0m"
i386-elf-gcc $CCFLAGS -c Kernel/kernel.c     -o $BIN/kernel.o
i386-elf-gcc $CCFLAGS -c Graphics/graphics.c -o $BIN/graphics.o
i386-elf-gcc $CCFLAGS -c Interrupts/idt.c    -o $BIN/idt.o
i386-elf-gcc $CCFLAGS -c Memory/mem.c        -o $BIN/mem.o
i386-elf-gcc $CCFLAGS -c Font/text.c         -o $BIN/text.o
i386-elf-gcc $CCFLAGS -c Include/ports.c     -o $BIN/ports.o
i386-elf-gcc $CCFLAGS -c Timer/timer.c       -o $BIN/timer.o
i386-elf-gcc $CCFLAGS -c Drivers/keyboard.c  -o $BIN/keyboard.o

# Linking Kernel Files...
echo -e "\n\e[33;40mLinking Kernel Files...\e[0m"
i386-elf-ld -o $BIN/fullkernel.bin -Ttext 0x1000 $LDFILES --oformat binary

# Mounting FolhaOS
echo -e "\n\e[33;40mMounting DuckOS...\e[0m"
cat $BIN/boot.bin $BIN/stg2.bin > $BIN/bootloader.bin
cat $BIN/bootloader.bin $BIN/fullkernel.bin > DuckOS.img

# Verify if everything was done successfully
if [ $? -eq 0 ]; then
    echo -e "\n\e[36;40mCompiled Successfully!\e[0m"
else
    echo -e "\n\e[31;40mError Compiling!\e[0m"
fi

# Running DuckOS
echo -e "\n\e[34;40mRunning DuckOS...\e[0m"
qemu-system-x86_64 -enable-kvm -m 2048 -smp 4 -drive format=raw,file="DuckOS.img"
