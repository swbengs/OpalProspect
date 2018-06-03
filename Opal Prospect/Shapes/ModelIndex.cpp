#include "ModelIndex.hpp"

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

void ModelIndex::addFace(const NormalFace& face)
{
    faces.push_back(face);
}

void ModelIndex::fillVertex(std::vector<float>& vector) const
{
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        fillFaceVertex(i, vector);
    }
}

void ModelIndex::fillUV(std::vector<float>& vector) const
{
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        fillFaceUV(i, vector);
    }
}

void ModelIndex::fillNormal(std::vector<float>& vector) const
{

}

void ModelIndex::fillIndex(std::vector<unsigned int>& vector) const
{
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        fillFaceIndex(i, vector);
    }
}

void ModelIndex::fillTriangleIndex(size_t index, std::vector<unsigned int>& vector) const
{

}

void ModelIndex::fillFaceVertex(size_t index, std::vector<float>& vector) const
{
    Point4D point;
    float extra = 1.0f; //vertex need w to be 1.0 to be properly placed

    point.setXYZW(faces[index].getBottomLeftVertex(), 1.0f);
    point.fillArray4D(vector);

    point.setXYZW(faces[index].getBottomRightVertex(), 1.0f);
    point.fillArray4D(vector);

    point.setXYZW(faces[index].getTopLeftVertex(), 1.0f);
    point.fillArray4D(vector);

    point.setXYZW(faces[index].getTopRightVertex(), 1.0f);
    point.fillArray4D(vector);
}

void ModelIndex::fillFaceUV(size_t index, std::vector<float>& vector) const
{
    Point3D point;

    point = faces[index].getBottomLeftUV();
    point.fillArray3D(vector);

    point = faces[index].getBottomRightUV();
    point.fillArray3D(vector);

    point = faces[index].getTopLeftUV();
    point.fillArray3D(vector);

    point = faces[index].getTopRightUV();
    point.fillArray3D(vector);
}

void ModelIndex::fillFaceNormal(size_t index, std::vector<float>& vector) const
{

}

void ModelIndex::fillFaceIndex(size_t index, std::vector<unsigned int>& vector) const
{
    unsigned int offset = getIndexOffset();
    vector.push_back(faces[index].getBottomLeftIndex() + offset);
    vector.push_back(faces[index].getBottomRightIndex() + offset);
    vector.push_back(faces[index].getTopLeftIndex() + offset);

    vector.push_back(faces[index].getTopLeftIndex() + offset);
    vector.push_back(faces[index].getBottomRightIndex() + offset);
    vector.push_back(faces[index].getTopRightIndex() + offset);
}

//gets
const NormalFace& ModelIndex::getFace(size_t index) const
{
    return faces[index];
}

size_t ModelIndex::getActualPointCount() const
{
    return (getFaceCount() * 6 + getTriangleCount() * 3);
}

size_t ModelIndex::getFaceCount() const
{
    return faces.size();
}

size_t ModelIndex::getUniquePointCount() const
{
    return (getFaceCount() * 4 + getTriangleCount() * 3);
}

size_t ModelIndex::getPointSize() const
{
    return ((4+3+4) * sizeof(float)); //4 vertex floats, 3 uv floats, 4 normal floats, 1 index int
}

size_t ModelIndex::getPointTotalSize() const
{
    return getUniquePointCount() * getPointSize();
}

size_t ModelIndex::getIndexTotalSize() const
{
    return getActualPointCount() * sizeof(unsigned int);
}

size_t ModelIndex::getTotalSize() const
{
    return getPointTotalSize() + getIndexTotalSize();
}

unsigned int ModelIndex::getIndexOffset() const
{
    return index_offset;
}

void ModelIndex::setIndexOffset(unsigned int offset)
{
    index_offset = offset;
}

//private

