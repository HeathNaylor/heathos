# Compile bootloader
i686-elf-as boot.s -o boot.o

# Compile Kernel
i686-elf-g++ -c kernel.cpp -o kernel.o -ffreestanding -O2 -Wextra -fno-exceptions  -Wall -fno-rtti

#Link kernel and bootloader into binary
i686-elf-gcc -T linker.ld -o isodir/boot/heathos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

# Convert binary to iso
/Users/heathnaylor/git/grub/build/grub-mkrescue -o heathos.iso isodir
