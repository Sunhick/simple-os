mkdir -p isodir
mkdir -p isodir/boot
cp kernel.bin isodir/boot/kernel.bin
mkdir -p isodir/boot/grub
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o kernel.iso isodir
