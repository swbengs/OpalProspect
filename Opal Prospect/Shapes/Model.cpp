#include "Model.hpp"

#include "Point3D.hpp"
#include "Point4D.hpp"

Model::Model()
{

}

void Model::addTriangle(const NormalTriangle & triangle)
{
    triangles.push_back(triangle);
}


void Model::fillTriangleVertex(size_t index, std::array<float, 16>& data)  const
{

}

void Model::fillTriangleUV(size_t index, std::array<float, 12>& data)  const
{

}

void Model::fillTriangleNormal(size_t index, std::array<float, 16>& data)  const
{

}

//gets
std::string Model::getModelName() const
{
    return model_name;
}

std::string Model::getTextureName() const
{
    return texture_name;
}

const NormalTriangle & Model::getTriangle(size_t index) const
{
    return triangles[index];
}

size_t Model::getTriangleCount() const
{
    return 0;
}

size_t Model::getPointSize() const
{
    return ((4 + 3 + 4) * sizeof(float)); //4 floats per vertex, 3 floats per uv, 4 floats per normal
}

size_t Model::getTotalSize() const
{
    return getPointSize() * 3 * triangles.size();
}

//sets
void Model::setModelName(std::string name)
{
    model_name = name;
}

void Model::setTextureName(std::string name)
{
    texture_name = name;
}

//protected
void Model::putPointInArray(const Point3D& point, float * data, size_t start)  const
{
    data[start] = point.x;
    data[start + 1] = point.y;
    data[start + 2] = point.z;
}

void Model::putPointInArrayExtra(const Point3D& point, float extra, float * data, size_t start)  const
{
    putPointInArray(point, data, start);
    data[start + 3] = extra; //to make it a vector with 4 dimensions add an extra float
}
