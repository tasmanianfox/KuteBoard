#ifndef GAME_H
#define GAME_H

#include <string>

#include "src/game/position.h"

using namespace std;

class Game
{
public:
    Game();

    void newGame();

    Position position;
};

#endif // GAME_H
