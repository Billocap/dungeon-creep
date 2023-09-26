#include <string>
#include <ncurses.h>
#include <vector>

#include "control.h"

using namespace std;

#ifndef _UI_H
#define _UI_H

class UINode;
class UIInteraction;

class UINode {
  public:
    bool visible;
    string content;
    vector<UINode> children;

    UINode(string content = "") {
      this->visible = true;
      this->content = content;
    }

    void add_node(UINode node) {
      this->children.push_back(node);
    }

    void add_text(string text) {
      UINode node (text);

      this->children.push_back(node);
    }

    UINode* get_node(int node) {
      return &(this->children[node]);
    }

    void remove_node(int node) {
      this->children.erase(this->children.begin() + node);
    }
};

class UIInteraction : public UINode {
  public:
    void (*action)(Game *, UIInteraction *);

    UIInteraction(string content = "", void (*action)(Game *, UIInteraction *) = [] (Game *game, UIInteraction *interaction) {}) {
      this->visible = true;
      this->content = content;
      this->action = action;
    }

    void interact(Game *game) {
      this->action(game, this);
    }

    void add_interaction(string label, void (*action)(Game *, UIInteraction *)) {
      UIInteraction interaction (label, action);

      this->children.push_back(interaction);
    }
};

#endif

