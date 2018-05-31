#pragma once

#include <array>

#include "Rectangle.hpp"

/*
Class for a rectangle with vertex points and an element array for indexed drawing
*/

class VertexRectangle : public Rectangle
{
public:
    VertexRectangle();
    VertexRectangle(bool isCCW);

    //4 points * 4 floats each
    void fillVertexIndexed(std::array<float, 16> &data) const; //fills in 4d coordinates z is always 0.0 and w is 1.0
    //2 triangles * 3 index each
    void fillIndex(size_t start, std::array<unsigned int, 6> &data) const;

    //gets
    bool getIsCCW() const;
    //sets
    void setIsCCW(bool isCCW);
private:
    bool is_CCW;
};
