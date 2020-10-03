#ifndef POSITION_H
#define POSITION_H

#define EMPTY_SQUARE -1

#define NUM_COLS 8
#define NUM_ROWS 8

#define PIECE_WHITE_PAWN 1
#define PIECE_WHITE_KNIGHT 2
#define PIECE_WHITE_BISHOP 3
#define PIECE_WHITE_ROOK 4
#define PIECE_WHITE_QUEEN 5
#define PIECE_WHITE_KING 6

#define PIECE_BLACK_PAWN 11
#define PIECE_BLACK_KNIGHT 12
#define PIECE_BLACK_BISHOP 13
#define PIECE_BLACK_ROOK 14
#define PIECE_BLACK_QUEEN 15
#define PIECE_BLACK_KING 16

// chess_position[0][0] = a1; // chess_position[7][0] = a8;
// chess_position[0][7] = h1; // chess_position[7][7] = h8;
typedef short int Position[8][8];

class CellName
{
public:
    short int col;
    short int row;

    CellName();
    CellName(short int row, short int col);
};

#endif // POSITION_H
