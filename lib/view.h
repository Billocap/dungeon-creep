#include <ncurses.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void draw_centered_line(WINDOW *window, string line, int y = 0) {
  int w, h;

  getmaxyx(window, h, w);

  int x = w / 2;

  move(y, x - (line.length() / 2));

  printw(line.c_str());
}

/**
 * Draws the contents of the file to the screen.
 * The `x` coordinate is realtive to half the line's length.
 *
 * @returns the `y` position.
 */
int draw_centered_file(WINDOW *window, string file_name, int y = 0) {
  ifstream file (file_name);

  if (file.is_open()) {
    string line;

    int n = y;

    while (getline(file, line)) {
      draw_centered_line(window, line, n);

      n++;
    }

    file.close();

    return n;
  }

  return y;
}

int draw_menu(WINDOW *window, int pointer, vector<string> options, int y) {
  int i;

  for (i = 0; i < options.size(); i++) {
    string r = i == pointer ? "[" : "";
    string l = i == pointer ? "]" : "";

    draw_centered_line(window, r + options[i] + l, y + i);
  }

  return y + i;
}

