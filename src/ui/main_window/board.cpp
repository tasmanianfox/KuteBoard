#include "board.h"

static map<int, string> textureMapping = {
    { TEXTURE_BOARD, "../../resources/images/boards/board2.png" },
    { TEXTURE_WHITE_PAWN, "../../resources/images/pieces/standard1/pawn_w.png" },
    { TEXTURE_WHITE_KNIGHT, "../../resources/images/pieces/standard1/knight_w.png" },
    { TEXTURE_WHITE_BISHOP, "../../resources/images/pieces/standard1/bishop_w.png" },
    { TEXTURE_WHITE_ROOK, "../../resources/images/pieces/standard1/rook_w.png" },
    { TEXTURE_WHITE_QUEEN, "../../resources/images/pieces/standard1/queen_w.png" },
    { TEXTURE_WHITE_KING, "../../resources/images/pieces/standard1/king_w.png" },
    { TEXTURE_BLACK_PAWN, "../../resources/images/pieces/standard1/pawn_b.png" },
    { TEXTURE_BLACK_KNIGHT, "../../resources/images/pieces/standard1/knight_b.png" },
    { TEXTURE_BLACK_BISHOP, "../../resources/images/pieces/standard1/bishop_b.png" },
    { TEXTURE_BLACK_ROOK, "../../resources/images/pieces/standard1/rook_b.png" },
    { TEXTURE_BLACK_QUEEN, "../../resources/images/pieces/standard1/queen_b.png" },
    { TEXTURE_BLACK_KING, "../../resources/images/pieces/standard1/king_b.png" },
};

Board::Board(QWidget *parent): QOpenGLWidget(parent)
{

}

void Board::loadTextures()
{
    map<int, string>::iterator it;
    for (it = textureMapping.begin(); it != textureMapping.end(); it++)
    {
        QImage tex;
        if(!tex.load(it->second.c_str()))
        {
            QMessageBox::critical(NULL, "Error", QString("Cannot load a texture: ") + QString(it->second.c_str()));
            exit(-1);
        }
        tex = QGLWidget::convertToGLFormat(tex);

        glBindTexture(GL_TEXTURE_2D, this->textures[it->first]); // Set as the current texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    }
}

void Board::initializeGL()
{
    initializeOpenGLFunctions();

    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
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
    BoardGlBounds bounds;
    bounds.right = 0.9 / ratioH;
    bounds.left = -1.0 * bounds.right;
    bounds.top = 0.9 / ratioW;
    bounds.bottom = -1.0 * bounds.top;

    glEnable(GL_TEXTURE_2D);
    paintBoard(bounds);
    paintPieces(bounds);
    glDisable(GL_TEXTURE_2D);
}

void Board::paintBoard(BoardGlBounds bounds)
{
    glBindTexture(GL_TEXTURE_2D, this->textures[TEXTURE_BOARD]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0); glVertex3f(bounds.left, bounds.top, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(bounds.right, bounds.top, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(bounds.right, bounds.bottom, -1);
    glTexCoord2f(0.0, 0.0); glVertex3f(bounds.left, bounds.bottom, -1);
    glEnd();
}

void Board::paintPieces(BoardGlBounds bounds)
{
    float colWidth = (bounds.right - bounds.left) / NUM_COLS;
    float rowHeight = (bounds.top - bounds.bottom) / NUM_ROWS;
    for (int y = 0; y < NUM_COLS; y++)
    {
        float rowStart = bounds.bottom + (y * rowHeight);
        float rowEnd = bounds.bottom + ((y+1) * rowHeight);
        for (int x = 0; x < NUM_ROWS; x++)
        {
            float colStart = bounds.left + (x * colWidth);
            float colEnd = bounds.left + ((x+1) * colWidth);
            int texture = -1;
            switch(this->game->position[y][x])
            {
            case PIECE_WHITE_ROOK:
                texture = TEXTURE_WHITE_ROOK; break;
            case PIECE_WHITE_KNIGHT:
                texture = TEXTURE_WHITE_KNIGHT; break;
            case PIECE_WHITE_BISHOP:
                texture = TEXTURE_WHITE_BISHOP; break;
            case PIECE_WHITE_QUEEN:
                texture = TEXTURE_WHITE_QUEEN; break;
            case PIECE_WHITE_KING:
                texture = TEXTURE_WHITE_KING; break;
            case PIECE_WHITE_PAWN:
                texture = TEXTURE_WHITE_PAWN; break;
            case PIECE_BLACK_ROOK:
                texture = TEXTURE_BLACK_ROOK; break;
            case PIECE_BLACK_KNIGHT:
                texture = TEXTURE_BLACK_KNIGHT; break;
            case PIECE_BLACK_BISHOP:
                texture = TEXTURE_BLACK_BISHOP; break;
            case PIECE_BLACK_QUEEN:
                texture = TEXTURE_BLACK_QUEEN; break;
            case PIECE_BLACK_KING:
                texture = TEXTURE_BLACK_KING; break;
            case PIECE_BLACK_PAWN:
                texture = TEXTURE_BLACK_PAWN; break;
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
}
