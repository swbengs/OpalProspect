#include "Model.hpp"

#include "Point3D.hpp"
#include "Point4D.hpp"

/*
MIT License

Copyright (c) 2018 Scott Bengs

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

Model::Model()
{
    model_name = "not filled in";
    texture_name = "not filled in";
}

void Model::addTriangle(const NormalTriangle & triangle)
{
    triangles.push_back(triangle);
}


void Model::fillTriangleVertex(size_t index, std::vector<float>& data)  const
{

}

void Model::fillTriangleUV(size_t index, std::vector<float>& data)  const
{

}

void Model::fillTriangleNormal(size_t index, std::vector<float>& data)  const
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
    return triangles.size();
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
void Model::putPointInArray(const Point3D& point, float* data, size_t start)  const
{
    data[start] = point.x;
    data[start + 1] = point.y;
    data[start + 2] = point.z;
}

void Model::putPointInArrayExtra(const Point3D& point, float extra, float* data, size_t start)  const
{
    putPointInArray(point, data, start);
    data[start + 3] = extra; //to make it a vector with 4 dimensions add an extra float
}
