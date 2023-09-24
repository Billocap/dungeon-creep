#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "lib/control.h"
#include "lib/menus.h"
#include "lib/view.h"

#define __KEY_UP 119 // W
#define __KEY_DOWN 115 // S
#define __KEY_CLOSE 27 // ESC
#define __KEY_CONFIRM 10 // ENTER

using namespace std;

int main () {
  Game game;

  int c, y, w, h;

  WINDOW *main = initscr();
  MenuManager manager;

  curs_set(0);
  
  while (game.running) {
    clear();

    getmaxyx(main, h, w);

    y = draw_centered_file(main, "misc/banner", 1);

    y = draw_menu(main, manager.get_current()->pointer, manager.get_current()->get_labels(), y + 2);

    draw_centered_line(main, "Use 'W' and 'S' to move cursor.", h - 3);
    draw_centered_line(main, "Press 'Enter' to select.", h - 2);

    c = getch();

    switch (c) {
      case __KEY_CLOSE:
        game.stop();
        break;

      case __KEY_UP:
        manager.get_current()->pointer_up();
        break;

      case __KEY_DOWN:
        manager.get_current()->pointer_down();
        break;

      case __KEY_CONFIRM:
        manager.get_current()->select(&game);
        break;
    }
  }

  endwin();

  return 0;
}
