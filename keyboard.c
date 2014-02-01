#include <io.h>
#include <screen.h>
#include <isr.h>

unsigned char keyboard[] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
  '\t', 'q', 'w', 'e', 'r', 't','y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0,
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';','\'', '`', 0, '\\', 'z', 
  'x', 'c', 'v', 'b', 'n','m', ',', '.', '/', 0,'*', 0,' ', 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 254, 0, '-', 252, 0, 253, '+', 0, 255, 0, 0, 0, 0, 0, 0, 0,
  0, 0,
};


void keyboard_handler(registers_t r)
{
  unsigned char scancode = inb(0x60);
  unsigned char key = 'p';

  if(scancode & 0x80) {
    return;
  }
  
  key = keyboard[scancode];
  putchar(key);
}

void install_keyboard()
{
  register_interrupt_handler(IRQ1, &keyboard_handler);  
}
