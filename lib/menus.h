#include <string>
#include <vector>

#include "control.h"
#include "ui.h"

#ifndef _MENUS_H
#define _MENUS_H

enum Menus {
  MAIN,
  DIFFICULTY,
  LOAD_GAME
};

class MenuOption;
class Menu;
class MenuManager;

class MenuOption : public UIInteraction {
  public:
    void (*action)(Game *, MenuOption *);
    Menu *menu;

    MenuOption(string label, void (*action)(Game *, MenuOption *), Menu *menu) {
      this->visible = true;
      this->content = label;
      this->action = action;
      this->menu = menu;
    }

    void interact(Game *game) {
      this->action(game, this);
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
        labels.push_back(this->options[i].content);
      }

      return labels;
    }

    void add_option(string label, void (*action)(Game *, MenuOption *)) {
      MenuOption option (label, action, this);

      this->options.push_back(option);
    }

    void select(Game *game) {
      this->options[this->pointer].interact(game);
    }

    void pointer_up() {
      if (this->pointer > 0) this->pointer--;
    }

    void pointer_down() {
      int size = this->options.size();

      if (this->pointer < size - 1) this->pointer++;
    }
};

Menu::Menu(MenuManager *manager) {
  this->manager = manager;
}

class MenuManager {
  public:
    Menu* get_current();

    MenuManager();

    void go_to(int menu);
    void add_menu(Menu menu);
    
  private:
    int current;
    vector<Menu> menus;
};

MenuManager::MenuManager() {
  this->current = 0;
}

Menu* MenuManager::get_current() {
  return &(this->menus[this->current]);
}

void MenuManager::go_to(int menu) {
  this->current = menu;
}

void MenuManager::add_menu(Menu menu) {
  this->menus.push_back(menu);
}

#endif

