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
#include <QDebug>

#define TEXTURE_BOARD 0
#define TEXTURE_PAWN_WHITE 1
#define TEXTURE_KNIGHT_WHITE 2
#define TEXTURE_BISHOP_WHITE 3
#define TEXTURE_ROOK_WHITE 4
#define TEXTURE_QUEEN_WHITE 5
#define TEXTURE_KING_WHITE 6
#define TEXTURE_PAWN_BLACK 7
#define TEXTURE_KNIGHT_BLACK 8
#define TEXTURE_BISHOP_BLACK 9
#define TEXTURE_ROOK_BLACK 10
#define TEXTURE_QUEEN_BLACK 11
#define TEXTURE_KING_BLACK 12

#define TEXTURE_COUNT 13

using namespace std;

class Board : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    Board(QWidget *parent);
protected:
    void initializeGL();
    void paintGL() Q_DECL_OVERRIDE;
private:
    void loadTextures();
    GLuint textures[13];
};

#endif // BOARD_H
