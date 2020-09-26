#include "board.h"

Board::Board(QWidget *parent): QOpenGLWidget(parent)
{

}

void Board::initializeGL()
{
    initializeOpenGLFunctions();

    QImage image;
    if(!image.load("../../resources/images/boards/board_white_black_1.png"))
    {
        qDebug("load image fail");
        return;
    }

    glEnable(GL_TEXTURE_2D); // Enable texturing

    glGenTextures(1, &this->textureID); // Obtain an id for the texture
    glBindTexture(GL_TEXTURE_2D, this->textureID); // Set as the current texture

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    this->tex = QGLWidget::convertToGLFormat(image);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glDisable(GL_TEXTURE_2D);
}

void Board::paintGL()
{
    glClearColor(0.4f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->textureID);

    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-1, -1, -1);
        glTexCoord2f(1,0); glVertex3f(1, -1, -1);
        glTexCoord2f(1,1); glVertex3f(1, 1, -1);
        glTexCoord2f(0,1); glVertex3f(-1, 1, -1);

    glEnd();

    glDisable(GL_TEXTURE_2D);

}
