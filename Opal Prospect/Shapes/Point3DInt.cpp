#include "Point3DInt.hpp"

Point3DInt::Point3DInt(int X, int Y, int Z)
{
    x = X;
    y = Y;
    z = Z;
}

void Point3DInt::fillArray(std::vector<int>& vector) const
{
    vector.push_back(x);
    vector.push_back(y);
    vector.push_back(z);
}

void Point3DInt::fillArray(size_t start, std::vector<int>& vector) const
{
    vector[start] = x;
    vector[start + 1] = y;
    vector[start + 2] = z;
}

//sets
void Point3DInt::setXYZ(int X, int Y, int Z)
{
    x = X;
    y = Y;
    z = Z;
}
