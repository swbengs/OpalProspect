#pragma once

#include "VertexTriangle.hpp"

class TextureTriangle : public VertexTriangle
{
public:

    TextureTriangle();

    //gets
    Point3D getA() const;
    Point3D getB() const;
    Point3D getC() const;

    //sets
    void setA(Point3D point);
    void setB(Point3D point);
    void setC(Point3D point);
    void set(Point3D a, Point3D b, Point3D c);

private:
    Point3D point_a;
    Point3D point_b;
    Point3D point_c;
};
