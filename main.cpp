#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "lib/control.h"
#include "lib/view.h"

#define __KEY_UP 119 // W
#define __KEY_DOWN 115 // S
#define __KEY_CLOSE 27 // ESC
#define __KEY_CONFIRM 10 // ENTER

using namespace std;

int main () {
  bool running = true;

  int c, y, w, h;

  WINDOW *main = initscr();

  curs_set(0);

  Menu main_menu;

  main_menu.options = {
    "start",
    "continue",
    "close"
  };
  
  while (running) {
    clear();

    getmaxyx(main, h, w);

    y = draw_centered_file(main, "misc/banner", 1);

    y = draw_menu(main, main_menu.pointer, main_menu.options, y + 2);

    draw_centered_line(main, "Use 'W' asd 'S' to move cursor.", h - 3);
    draw_centered_line(main, "Use 'Enter' to select.", h - 2);

    c = getch();

    switch (c) {
      case __KEY_CLOSE:
        running = false;
        break;

      case __KEY_UP:
        main_menu.pointer_up();
        break;

      case __KEY_DOWN:
        main_menu.pointer_down();
        break;
    }
  }

  endwin();

  return 0;
}
