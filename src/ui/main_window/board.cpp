#include "board.h"

static map<int, string> textureMapping = {
    { TEXTURE_BOARD, "../../resources/images/boards/board_white_black_1.png" },
    { TEXTURE_PAWN_WHITE, "../../resources/images/pieces/standard1/pawn_w.png" },
    { TEXTURE_KNIGHT_WHITE, "../../resources/images/pieces/standard1/knight_w.png" },
    { TEXTURE_BISHOP_WHITE, "../../resources/images/pieces/standard1/bishop_w.png" },
    { TEXTURE_ROOK_WHITE, "../../resources/images/pieces/standard1/rook_w.png" },
    { TEXTURE_QUEEN_WHITE, "../../resources/images/pieces/standard1/queen_w.png" },
    { TEXTURE_KING_WHITE, "../../resources/images/pieces/standard1/king_w.png" },
    { TEXTURE_PAWN_BLACK, "../../resources/images/pieces/standard1/pawn_b.png" },
    { TEXTURE_KNIGHT_BLACK, "../../resources/images/pieces/standard1/knight_b.png" },
    { TEXTURE_BISHOP_BLACK, "../../resources/images/pieces/standard1/bishop_b.png" },
    { TEXTURE_ROOK_BLACK, "../../resources/images/pieces/standard1/rook_b.png" },
    { TEXTURE_QUEEN_BLACK, "../../resources/images/pieces/standard1/queen_b.png" },
    { TEXTURE_KING_BLACK, "../../resources/images/pieces/standard1/king_b.png" },
};

Board::Board(QWidget *parent): QOpenGLWidget(parent)
{

}

void Board::loadTextures()
{
    map<int, string>::iterator it;
    for (it = textureMapping.begin(); it != textureMapping.end(); it++)
    {
        QImage image;
        if(!image.load(it->second.c_str()))
        {
            QMessageBox::critical(NULL, "Error", QString("Cannot load a texture: ") + QString(it->second.c_str()));
            exit(-1);
        }
        QImage tex = QGLWidget::convertToGLFormat(image);

        glBindTexture(GL_TEXTURE_2D, this->textures[it->first]); // Set as the current texture

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    }
}

void Board::initializeGL()
{
    initializeOpenGLFunctions();

    glEnable(GL_TEXTURE_2D); // Enable texturing
    glGenTextures(13, this->textures); // Obtain an id for the texture

    loadTextures();

    glDisable(GL_TEXTURE_2D);
}

void Board::paintGL()
{
    glClearColor(0.16f, 0.16f, 0.16f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->textures[TEXTURE_BOARD]);

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

    // Temporary: just for test
    glBindTexture(GL_TEXTURE_2D, this->textures[TEXTURE_KNIGHT_WHITE]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(left/8, top/8, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(right/8, top/8, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(right/8, bottom/8, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(left/8, bottom/8, -1);
    glEnd();

    glDisable(GL_TEXTURE_2D);

}
