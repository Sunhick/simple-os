#include <time.h>
#include <io.h>


struct time get_current_time()
{
  struct time tm;

  /* make sure cmos update isn't in progess */
  while(CMOS_UPDATE_IN_PROGRESS);
 
  /******************************************/
  /* Reading Current date and time from RTC */
  /* Register  Contents			    */
  /*  0x00      Seconds			    */
  /*  0x02      Minutes			    */
  /*  0x04      Hours			    */
  /*  0x06      Weekday			    */
  /*  0x07      Day of Month		    */
  /*  0x08      Month			    */
  /*  0x09      Year			    */
  /*  0x32      Century (maybe)		    */
  /*  0x0A      Status Register A	    */
  /*  0x0B      Status Register B	    */
  /******************************************/
  tm.seconds      = CMOS_READ(0x0);
  tm.minutes      = CMOS_READ(0x2);
  tm.hours        = CMOS_READ(0x4);
  tm.weekday      = CMOS_READ(0x6);
  tm.day_of_month = CMOS_READ(0x7);
  tm.month        = CMOS_READ(0x8);
  tm.year         = CMOS_READ(0x9);

  /* int rega = CMOS_READ(0x0A); */
  /* int regb = CMOS_READ(0x0B); */

  BCD_TO_BIN(tm.seconds);
  BCD_TO_BIN(tm.minutes);
  BCD_TO_BIN(tm.hours);
  BCD_TO_BIN(tm.weekday);
  BCD_TO_BIN(tm.day_of_month);
  BCD_TO_BIN(tm.month);
  BCD_TO_BIN(tm.year);

  return tm;
}
