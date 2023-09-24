#include <string>
#include <vector>

#include "control.h"

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
      int size = this->options.size();

      if (this->pointer < size - 1) this->pointer++;
    }
};

Menu::Menu(MenuManager *manager) {
  this->manager = manager;
}

class MenuManager {
  public:
    MenuManager();
    Menu* get_current();
    void go_to(int menu);
    
  private:
    int current = 0;

    vector<Menu> menus;
};

void does_nothing(Game *game, Menu *menu) {}

void close_game_action(Game *game, Menu *menu) {
  game->stop();
}

void go_to_main(Game *game, Menu *menu) {
  menu->manager->go_to(0);
}

void go_to_diff(Game *game, Menu *menu) {
  menu->manager->go_to(1);
}

MenuManager::MenuManager() {
  MenuOption new_game ("new game", go_to_diff);
  MenuOption continue_game ("continue", does_nothing);
  MenuOption close_game ("close game", close_game_action);

  Menu main_menu (this);

  main_menu.options = {
    new_game,
    continue_game,
    close_game
  };

  this->menus.push_back(main_menu);

  MenuOption diff_easy ("easy", does_nothing);
  MenuOption diff_med ("medium", does_nothing);
  MenuOption diff_hard ("hard", does_nothing);
  MenuOption back_to_main ("back", go_to_main);

  Menu diff_menu (this);

  diff_menu.options = {
    diff_easy,
    diff_med,
    diff_hard,
    back_to_main
  };

  this->menus.push_back(diff_menu);
}

Menu* MenuManager::get_current() {
  return &(this->menus[this->current]);
}

void MenuManager::go_to(int menu) {
  this->current = menu;
}

#endif

