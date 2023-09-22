#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
  ifstream banner_file ("./misc/banner.txt");

  if (banner_file.is_open()) {
    string line;

    while (getline(banner_file, line)) {
      cout << line << endl;
    }

    banner_file.close();
  }

  return 0;
}
