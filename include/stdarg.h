#ifndef _STDARG_H
#define _STDARG_H

#include <types.h>

typedef void * va_list;

#define va_start(list, param) list = (char *)&param + sizeof (param);	

#define va_arg(list, type) *(type *)((char *)(list = (char *)list + sizeof(type)) - sizeof(type));

#define va_end(list) //list = (void *)0;

#endif
