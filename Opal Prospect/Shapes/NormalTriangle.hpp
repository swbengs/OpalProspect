#pragma once

#include "TextureTriangle.hpp"

class NormalTriangle : public TextureTriangle
{
public:

    NormalTriangle();

    //gets
    Point3D getANormal() const;
    Point3D getBNormal() const;
    Point3D getCNormal() const;

    //sets
    void setANormal(Point3D point);
    void setBNormal(Point3D point);
    void setCNormal(Point3D point);
    void setNormal(Point3D a, Point3D b, Point3D c);

private:
    Point3D normal_a;
    Point3D normal_b;
    Point3D normal_c;
};
