#ifndef GAME_H
#define GAME_H

#include "position.h"

class Game
{
public:
    Game();

    void newGame();
private:
    Position position;
};

#endif // GAME_H
