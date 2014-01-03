#ifndef _TIME_H
#define _TIME_H

#define NMI_DISABLE (0x01 << 7)

#define CMOS_ADDRESS 0x70
#define CMOS_DATA 0x71

/* read from CMOS */
#define CMOS_READ(register) ({				\
      outb(CMOS_ADDRESS, NMI_DISABLE | register);	\
      inb(CMOS_DATA);					\
    })

/* check if CMOS update is in progress */
#define CMOS_UPDATE_IN_PROGRESS ({		\
      outb(CMOS_ADDRESS, 0x0A);			\
      inb(CMOS_DATA) & NMI_DISABLE;		\
    })

/* convert binary coded decimal to binary */
#define BCD_TO_BIN(val) ((val) = ((val) & 0x0F) + ((val) >> 4) * 10)

struct time {
  int seconds;
  int minutes;
  int hours;
  int weekday;
  int day_of_month;
  int month;
  int year;
};

extern struct time get_current_time();

#endif
