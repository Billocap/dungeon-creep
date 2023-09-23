#include <vector>
#include <string>

using namespace std;

class MenuOption {
  public:
    string label;
};

class Menu {
  public:
    vector<string> options;
    int pointer = 0;

    void pointer_up() {
      if (this->pointer > 0) this->pointer--;
    }

    void pointer_down() {
      if (this->pointer < this->options.size()) this->pointer++;
    }
};

