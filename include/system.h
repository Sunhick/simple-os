#ifndef _SYSTEM_H
#define _SYSTEM_H

#define cli() __asm__("cli" ::)	/* disable interrupt */
#define sti() __asm__("sti" ::)	/* enable interrupt */
#define nop() __asm__("nop" ::) /* no operation */

#endif
