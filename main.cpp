#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "lib/view.h"

#define __KEY_UP 119 // W
#define __KEY_DOWN 115 // S
#define __KEY_CLOSE 27 // ESC
#define __KEY_CONFIRM 10 // ENTER

using namespace std;

int main () {
  bool running = true;

  int c, y;

  int pointer = 0;

  WINDOW *main = initscr();

  curs_set(0);

  vector<string> menu = {
    "start",
    "continue",
    "close"
  };
  
  while (running) {
    clear();

    y = draw_centered_file(main, "misc/banner.txt", 1);

    y = draw_menu(main, pointer, menu, y + 2);

    c = getch();

    switch (c) {
      case __KEY_CLOSE:
        running = false;
        break;

      case __KEY_UP:
        if (pointer > 0) pointer--;
        break;

      case __KEY_DOWN:
        if (pointer < menu.size()) pointer++;
        break;
    }
  }

  endwin();

  return 0;
}
