#include "Triangle3D.hpp"

Triangle3D::Triangle3D()
{

}

//gets
Point3D Triangle3D::getA() const
{
    return point_a;
}

Point3D Triangle3D::getB() const
{
    return point_b;
}

Point3D Triangle3D::getC() const
{
    return point_c;
}

//sets
void Triangle3D::setA(Point3D point)
{
    point_a = point;
}

void Triangle3D::setB(Point3D point)
{
    point_b = point;
}

void Triangle3D::setC(Point3D point)
{
    point_c = point;
}

void Triangle3D::set(Point3D a, Point3D b, Point3D c)
{
    point_a = a;
    point_b = b;
    point_c = c;
}
