#include "opengl_utils.h"

void drawTextureAtRectangle(GLuint textureID, Rectangle rectangle)
{
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0); glVertex2f(rectangle.x0, rectangle.y1);
    glTexCoord2f(1.0, 1.0); glVertex2f(rectangle.x1, rectangle.y1);
    glTexCoord2f(1.0, 0.0); glVertex2f(rectangle.x1, rectangle.y0);
    glTexCoord2f(0.0, 0.0); glVertex2f(rectangle.x0, rectangle.y0);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}
