#ifndef POSITION_H
#define POSITION_H

#define NUM_COLS 8
#define NUM_ROWS 8

#include <string>

#include <QString>
#include <QStringList>

#include "src/game/board_cells.h"
#include "src/game/pieces.h"
#include "src/game/position_fen.h"

using namespace std;

class Position
{
public:
    Position();

    BoardCells board;

    void setFromFEN(string fen);
};

#endif // POSITION_H
