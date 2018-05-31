#include "Point4D.hpp"

Point4D::Point4D(float X, float Y, float Z, float W)
{
    x = X;
    y = Y;
    z = Z;
    w = W;
}

void Point4D::fillArray4D(std::vector<float>& vector) const
{
    vector.push_back(x);
    vector.push_back(y);
    vector.push_back(z);
    vector.push_back(w);
}

void Point4D::fillArray4D(size_t start, std::vector<float>& vector) const
{
    vector[start] = x;
    vector[start + 1] = y;
    vector[start + 2] = z;
    vector[start + 3] = w;
}

void Point4D::setXYZW(float X, float Y, float Z, float W)
{
    x = X;
    y = Y;
    z = Z;
    w = W;
}

void Point4D::setXYZW(Point3D point3, float W)
{
    x = point3.x;
    y = point3.y;
    z = point3.z;
    w = W;
}

