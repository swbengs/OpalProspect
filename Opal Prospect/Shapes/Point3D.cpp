#include "Point3D.hpp"

Point3D::Point3D(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

void Point3D::fillArray3D(std::vector<float>& vector) const
{
    vector.push_back(x);
    vector.push_back(y);
    vector.push_back(z);
}

void Point3D::fillArray3D(size_t start, std::vector<float>& vector) const
{
    vector[start] = x;
    vector[start + 1] = y;
    vector[start + 2] = z;
}

//sets
void Point3D::setXYZ(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}
