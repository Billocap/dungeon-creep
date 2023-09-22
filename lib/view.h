#include <ncurses.h>
#include <fstream>
#include <string>

using namespace std;

void draw_file(string file_name) {
  ifstream file (file_name);

  if (file.is_open()) {
    string line;

    while (getline(file, line)) {
      printw(line.c_str());
      printw("\n");
    }

    file.close();
  }
}

