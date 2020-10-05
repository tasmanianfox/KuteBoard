#include "position.h"

Position::Position()
{

}

void Position::setFromFEN(string fen)
{
    QString qFen = QString(fen.c_str());
    QStringList parts = qFen.split(" ");
    QString pieces = parts[0];

    int row = NUM_ROWS - 1;
    int col = 0;
    for (const char c: pieces.toStdString())
    {
        int cell = PIECE_UNDEFINED;
        switch(c)
        {
            case FEN_BLACK_ROOK:
                cell = PIECE_BLACK_ROOK;break;
            case FEN_BLACK_KNIGHT:
                cell = PIECE_BLACK_KNIGHT;break;
            case FEN_BLACK_BISHOP:
                cell = PIECE_BLACK_BISHOP;break;
            case FEN_BLACK_QUEEN:
                cell = PIECE_BLACK_QUEEN;break;
            case FEN_BLACK_KING:
                cell = PIECE_BLACK_KING;break;
            case FEN_BLACK_PAWN:
                cell = PIECE_BLACK_PAWN;break;
            case FEN_WHITE_ROOK:
                cell = PIECE_WHITE_ROOK;break;
            case FEN_WHITE_KNIGHT:
                cell = PIECE_WHITE_KNIGHT;break;
            case FEN_WHITE_BISHOP:
                cell = PIECE_WHITE_BISHOP;break;
            case FEN_WHITE_QUEEN:
                cell = PIECE_WHITE_QUEEN;break;
            case FEN_WHITE_KING:
                cell = PIECE_WHITE_KING;break;
            case FEN_WHITE_PAWN:
                cell = PIECE_WHITE_PAWN;break;
            case '/':
                row--;
                col = 0;
                break;
            default:
                int num = atoi(&c);
                for (int i = 0; i < num; i++)
                {
                    this->board[row][col] = PIECE_EMPTY_SQUARE;
                    col++;
                }
        }

        if (cell != PIECE_UNDEFINED)
        {
            this->board[row][col] = cell;
            col++;
        }
    }
}
