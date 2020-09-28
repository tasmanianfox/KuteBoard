#ifndef POSITION_H
#define POSITION_H

#define EMPTY_SQUARE 0

#define WHITE_PAWN 1
#define WHITE_KNIGHT 2
#define WHITE_BISHOP 3
#define WHITE_ROOK 4
#define WHITE_QUEEN 5
#define WHITE_KING 6

#define BLACK_PAWN 11
#define BLACK_KNIGHT 12
#define BLACK_BISHOP 13
#define BLACK_ROOK 14
#define BLACK_QUEEN 15
#define BLACK_KING 16

// chess_position[0][0] = a1; // chess_position[7][0] = a8;
// chess_position[0][7] = h1; // chess_position[7][7] = h8;
typedef unsigned short int Position[8][8];

#endif // POSITION_H
