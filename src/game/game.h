#ifndef GAME_H
#define GAME_H

#include "position.h"

class Game
{
public:
    Game();

    void newGame();
    void setPosition(Position position);

    Position position;
};

#endif // GAME_H
