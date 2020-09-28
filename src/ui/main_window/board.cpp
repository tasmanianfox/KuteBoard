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
    QImage tex = QGLWidget::convertToGLFormat(image);

    this->boardTexture = Texture();
    this->boardTexture.height = tex.height();
    this->boardTexture.width = tex.width();

    glEnable(GL_TEXTURE_2D); // Enable texturing

    glGenTextures(1, &this->boardTexture.textureID); // Obtain an id for the texture
    glBindTexture(GL_TEXTURE_2D, this->boardTexture.textureID); // Set as the current texture

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glDisable(GL_TEXTURE_2D);
}

void Board::paintGL()
{
    glClearColor(0.16f, 0.16f, 0.16f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->boardTexture.textureID);

    glBegin(GL_QUADS);

    float minDimension = std::min(this->width(), this->height());
    float ratioH = std::max((double)((float)this->width() / minDimension), 1.0);
    float ratioW = std::max((double)((float)this->height() / minDimension), 1.0);
    float right = 0.9 / ratioH;
    float left = -1.0 * right;
    float bottom = 0.9 / ratioW;
    float top = -1.0 * bottom;

    glTexCoord2f(0.0, 0.0); glVertex3f(left, top, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(right, top, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(right, bottom, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(left, bottom, -1);

    glEnd();

    glDisable(GL_TEXTURE_2D);

}
