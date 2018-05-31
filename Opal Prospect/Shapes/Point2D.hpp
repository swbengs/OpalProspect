#pragma once

#include "Point1D.hpp"

/* 
Class representing a 2d coordinate
*/

struct Point2D : public Point1D
{
public:

    Point2D() = default;
    Point2D(float X, float Y);

    //sets
    void setXY(float X, float Y);

    float y;
};