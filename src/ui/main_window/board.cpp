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

    float minDimension = std::min(this->width(), this->height());
    float ratioH = std::max((double)((float)this->width() / minDimension), 1.0);
    float ratioW = std::max((double)((float)this->height() / minDimension), 1.0);
    float right = 0.9 / ratioH;
    float left = -1.0 * right;
    float top = 0.9 / ratioW;
    float bottom = -1.0 * top;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->textures[TEXTURE_BOARD]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0); glVertex3f(left, top, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(right, top, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(right, bottom, -1);
    glTexCoord2f(0.0, 0.0); glVertex3f(left, bottom, -1);
    glEnd();

    float colWidth = (right - left) / NUM_COLS;
    float rowHeight = (top - bottom) / NUM_ROWS;
    for (int y = 0; y < NUM_COLS; y++)
    {
        float rowStart = bottom + (y * rowHeight);
        float rowEnd = bottom + ((y+1) * rowHeight);
        for (int x = 0; x < NUM_ROWS; x++)
        {
            float colStart = left + (x * colWidth);
            float colEnd = left + ((x+1) * colWidth);
            int texture = -1;
            switch(this->game->position[y][x])
            {
            case PIECE_WHITE_ROOK:
                texture = TEXTURE_ROOK_WHITE; break;
            case PIECE_WHITE_KNIGHT:
                texture = TEXTURE_KNIGHT_WHITE; break;
            case PIECE_WHITE_BISHOP:
                texture = TEXTURE_BISHOP_WHITE; break;
            case PIECE_WHITE_QUEEN:
                texture = TEXTURE_QUEEN_WHITE; break;
            case PIECE_WHITE_KING:
                texture = TEXTURE_KING_WHITE; break;
            case PIECE_WHITE_PAWN:
                texture = TEXTURE_PAWN_WHITE; break;
            case PIECE_BLACK_ROOK:
                texture = TEXTURE_ROOK_BLACK; break;
            case PIECE_BLACK_KNIGHT:
                texture = TEXTURE_KNIGHT_BLACK; break;
            case PIECE_BLACK_BISHOP:
                texture = TEXTURE_BISHOP_BLACK; break;
            case PIECE_BLACK_QUEEN:
                texture = TEXTURE_QUEEN_BLACK; break;
            case PIECE_BLACK_KING:
                texture = TEXTURE_KING_BLACK; break;
            case PIECE_BLACK_PAWN:
                texture = TEXTURE_PAWN_BLACK; break;
            }

            if (0 > texture) continue;

            glBindTexture(GL_TEXTURE_2D, this->textures[texture]);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 1.0); glVertex2f(colStart, rowEnd);
            glTexCoord2f(1.0, 1.0); glVertex2f(colEnd, rowEnd);
            glTexCoord2f(1.0, 0.0); glVertex2f(colEnd, rowStart);
            glTexCoord2f(0.0, 0.0); glVertex2f(colStart, rowStart);
            glEnd();
        }
    }

    glDisable(GL_TEXTURE_2D);

}
