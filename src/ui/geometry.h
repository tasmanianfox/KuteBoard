#ifndef GEOMETRY_H
#define GEOMETRY_H

class Rectangle
{
public:
    Rectangle();
    Rectangle(float x0, float y0, float x1, float y1);

    float x0; // left
    float x1; // right
    float y0; // bottom
    float y1; // top
};

#endif // GEOMETRY_H
