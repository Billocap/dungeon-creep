#include <vector>
#include <string>

using namespace std;

class Game {
  public:
    bool running = true;

    void run(void (*loop)(Game *)) {
      while (this->running) loop(this);
    }

    void stop() {
      this->running = false;
    }
};

class Menu;
class MenuManager;

class MenuOption {
  public:
    string label;
    
    void (*action)(Game *, Menu *);
    
    MenuOption(string label, void (*action)(Game *, Menu *)) {
      this->label = label;
      this->action = action;
    }
};

class Menu {
  public:
    vector<MenuOption> options;
    int pointer = 0;
    Menu(MenuManager *manager);
    MenuManager *manager;

    vector<string> get_labels() {
      vector<string> labels;

      for (int i = 0; i < this->options.size(); i++) {
        labels.push_back(this->options[i].label);
      }

      return labels;
    }

    void select(Game *game) {
      this->options[this->pointer].action(game, this);
    }

    void pointer_up() {
      if (this->pointer > 0) this->pointer--;
    }

    void pointer_down() {
      if (this->pointer < this->options.size()) this->pointer++;
    }
};

Menu::Menu(MenuManager *manager) {
  this->manager = manager;
}

