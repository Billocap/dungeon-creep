#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>

#include "lib/view.h"

#define __KEY_CLOSE 27

using namespace std;

int main () {
  bool running = true;

  int c, w, h;

  WINDOW *main = initscr();
  
  while (running) {
    clear();

    draw_file("misc/banner.txt");

    c = getch();

    getmaxyx(main, h, w);

    running = false;
  }

  endwin();

  cout << endl << w << endl << h;

  return 0;
}
