#include <vector>
#include <string>

#ifndef _CONTROL_H
#define _CONTROL_H

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

#endif

