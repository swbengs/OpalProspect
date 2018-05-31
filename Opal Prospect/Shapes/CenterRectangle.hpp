#pragma once

#include "Rectangle.hpp"

//Rectangle with a center

class CenterRectangle : public Rectangle
{
public:
    CenterRectangle();
    CenterRectangle(float X, float Y);

    //gets
    float getX() const;
    float getY() const;
    const Point2D& getXY() const;

    //these gets are based on where the center is. So if the center is at 100, 0, you would add 100 to the x value and 0 to the y value
    Point2D getLiteralBottomLeft() const;
    Point2D getLiteralBottomRight() const;
    Point2D getLiteralTopLeft() const;
    Point2D getLiteralTopRight() const;

    //sets
    void setX(float X);
    void setY(float Y);
    void setXY(float X, float Y);
    void setXY(const Point2D& point);

private:
    Point2D center;
};
