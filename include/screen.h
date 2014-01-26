#ifndef _SCREEN_H
#define _SCREEN_H

/* video is memory mapped to ram */
#define VGA_MEMORY 0xB8000

/* Screen end = ram memory + (height * width) */
#define SCREEN_LIMIT 0xB7D0
/* Screen size = height * width * 2 */
#define SCREEN_SIZE WIDTH*HEIGHT*2

/* width and height of the screen 80x25 wide */
#define HEIGHT 25
#define WIDTH 80

/* 15           12 11          8 7           0 */
/* +--------------+-------------+------------+ */
/* | background   | foreground  | character  | */
/* +--------------+-------------+------------+ */

/* foreground and background colors */
enum color {
  black =0,
  blue,
  green,
  cyan,
  red,
  magenta,
  brown,
  light_grey,
  dark_grey,
  light_blue,
  light_green,
  light_cyan,
  light_red,
  light_magenta,
  light_brown,
  white
};

#endif
