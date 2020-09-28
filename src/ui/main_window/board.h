#ifndef BOARD_H
#define BOARD_H

#include <algorithm>

#include <QGLWidget>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QDebug>

#include "src/ui/texture.h"

class Board : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    Board(QWidget *parent);
protected:
    void initializeGL();
    void paintGL() Q_DECL_OVERRIDE;
private:
    Texture boardTexture;
};

#endif // BOARD_H
