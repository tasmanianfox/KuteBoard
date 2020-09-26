#ifndef BOARD_H
#define BOARD_H

#include <QGLWidget>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QDebug>

class Board : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    Board(QWidget *parent);
protected:
    void initializeGL();
    void paintGL() Q_DECL_OVERRIDE;
private:
    QImage tex;
    GLuint textureID;
};

#endif // BOARD_H
