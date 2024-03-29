# 🦆 About DuckOS
DuckOS is a small protected mode operating system made in C and x86 Assembly. This project is being developed as a way to learn more about OSs.

# 🛠️ Current Progress
- ✅ **Global Descriptor Table (GDT)**
- ✅ **Entering Protected Mode**
- ✅ **Fonts and Print Functions**
- ❌ **Interrupts (IDT, ISR, IRQ)**
- ❌ **Memory Management**
- ❌ **FAT Filesystem**
- ❌ **Shell**
- ❌ **User Documentation**
- ❌ **Graphical Interface (GUI)**
- ❌ **Multitasking**

# ⚙️ Building
### 🧰 Necessary Components
i386 elf gcc and nasm
### 📄 Compiling
Run the make.sh script using <br /> `chmod +x ./make.sh` <br /> `./make.sh`
### 🚀 Running
use `qemu-system-x86_64 -drive format=raw,file="DuckOS.img"`

# 🤝 Contribute
For those who want to contribute to FolhaOS, you can help me starring/forking this project or help with code using pull requests.

# 🗂️ Resources
- https://wiki.osdev.org/Main_Page
- http://www.jamesmolloy.co.uk/tutorial_html/1.-Environment%20setup.html
- http://www.brokenthorn.com/Resources/OSDevIndex.html
- https://www.tutorialspoint.com/operating_system/index.htm
- https://ldemetrio.com.br/Livros/Livros_TI/segunda_unid/Sistemas%20Operacionais%20Modernos%20-%20Tanenbaum%20-%204%20Edi%C3%A7%C3%A3o.pdf
