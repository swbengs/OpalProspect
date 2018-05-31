#pragma once

#include "Point2D.hpp"

/*
Class for a rectangle
*/

class Rectangle
{
public:
    Rectangle();
    Rectangle(float width, float height);

    //gets
    float getWidth() const;
    float getHeight() const;
    const Point2D& getWidthHeight() const;

    Point2D getBottomLeft() const;
    Point2D getBottomRight() const;
    Point2D getTopLeft() const;
    Point2D getTopRight() const;

    //sets
    void setWidth(float width);
    void setHeight(float height);
    void setWidthHeight(float width, float height);
    void setWidthHeight(const Point2D& point);

private:
    Point2D hw;
};