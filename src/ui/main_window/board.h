#ifndef BOARD_H
#define BOARD_H

#include <algorithm>
#include <map>

#include <QApplication>
#include <QMessageBox>
#include <QGLWidget>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>

#include "src/game/game.h"
#include "src/game/position.h"
#include "src/ui/geometry.h"
#include "src/ui/opengl_utils.h"

#define TEXTURE_BOARD 0
#define TEXTURE_WHITE_PAWN 1
#define TEXTURE_WHITE_KNIGHT 2
#define TEXTURE_WHITE_BISHOP 3
#define TEXTURE_WHITE_ROOK 4
#define TEXTURE_WHITE_QUEEN 5
#define TEXTURE_WHITE_KING 6
#define TEXTURE_BLACK_PAWN 7
#define TEXTURE_BLACK_KNIGHT 8
#define TEXTURE_BLACK_BISHOP 9
#define TEXTURE_BLACK_ROOK 10
#define TEXTURE_BLACK_QUEEN 11
#define TEXTURE_BLACK_KING 12

#define TEXTURE_COUNT 13

using namespace std;

class Board : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    Board(QWidget *parent);

    Game *game;
protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
private:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    void loadTextures();
    int getTextureForPiece(short int piece);

    void calculateCellCoordinates(Rectangle bounds);

    void paintBoard(Rectangle bounds);
    void paintCellSelection();
    void paintPieces();

    bool isCellSelected();

    GLuint textures[TEXTURE_COUNT];
    Rectangle cellCoordinates[NUM_ROWS][NUM_COLS];
    CellName activeCell;
};


#endif // BOARD_H
