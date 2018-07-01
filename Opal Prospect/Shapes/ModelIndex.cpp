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

ModelIndex::ModelIndex()
{
    index_offset = 0;
}

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

    for (unsigned int i = 0; i < getTriangleCount(); i++)
    {
        fillTriangleVertex(i, vector);
    }
}

void ModelIndex::fillUV(std::vector<float>& vector) const
{
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        fillFaceUV(i, vector);
    }

    for (unsigned int i = 0; i < getTriangleCount(); i++)
    {
        fillTriangleUV(i, vector);
    }
}

void ModelIndex::fillNormal(std::vector<float>& vector) const
{
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        fillFaceNormal(i, vector);
    }

    for (unsigned int i = 0; i < getTriangleCount(); i++)
    {
        fillTriangleNormal(i, vector);
    }
}

void ModelIndex::fillIndex(std::vector<unsigned int>& vector) const
{
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        fillFaceIndex(i, vector);
    }

    for (unsigned int i = 0; i < getTriangleCount(); i++)
    {
        fillTriangleIndex(i, vector);
    }
}

void ModelIndex::fillInterleaved(std::vector<float>& vector) const
{
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        fillInterleavedFace(i, vector);
    }

    for (unsigned int i = 0; i < getTriangleCount(); i++)
    {
        fillInterleavedTriangle(i, vector);
    }
}

void ModelIndex::fillTriangleIndex(size_t index, std::vector<unsigned int>& vector) const
{
    unsigned int offset = getIndexOffset();
    const NormalTriangle& triangle = getTriangle(index);
    vector.push_back(triangle.getIndexA() + offset);
    vector.push_back(triangle.getIndexB() + offset);
    vector.push_back(triangle.getIndexC() + offset);
}

void ModelIndex::fillFaceVertex(size_t index, std::vector<float>& vector) const
{
    Point4D point;
    const float extra = 1.0f; //vertex need w to be 1.0 to be properly placed

    point.setXYZW(faces[index].getBottomLeftVertex(), extra);
    point.fillArray4D(vector);

    point.setXYZW(faces[index].getBottomRightVertex(), extra);
    point.fillArray4D(vector);

    point.setXYZW(faces[index].getTopLeftVertex(), extra);
    point.fillArray4D(vector);

    point.setXYZW(faces[index].getTopRightVertex(), extra);
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
    Point4D point;
    const float extra = 0.0f; //normal needs w to be 0.0 to be properly placed

    point.setXYZW(faces[index].getBottomLeftNormal(), extra);
    point.fillArray4D(vector);

    point.setXYZW(faces[index].getBottomRightNormal(), extra);
    point.fillArray4D(vector);

    point.setXYZW(faces[index].getTopLeftNormal(), extra);
    point.fillArray4D(vector);

    point.setXYZW(faces[index].getTopRightNormal(), extra);
    point.fillArray4D(vector);
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

void ModelIndex::fillInterleavedFace(size_t index, std::vector<float>& vector) const
{
    Point3D uvz;
    Point4D xyzw;
    const float vertex_extra = 1.0f;
    const float normal_extra = 0.0f;

    xyzw.setXYZW(faces[index].getBottomLeftVertex(), vertex_extra);
    xyzw.fillArray4D(vector);
    uvz = faces[index].getBottomLeftUV();
    uvz.fillArray3D(vector);
    xyzw.setXYZW(faces[index].getBottomLeftNormal(), normal_extra);
    xyzw.fillArray4D(vector);

    xyzw.setXYZW(faces[index].getBottomRightVertex(), vertex_extra);
    xyzw.fillArray4D(vector);
    uvz = faces[index].getBottomRightUV();
    uvz.fillArray3D(vector);
    xyzw.setXYZW(faces[index].getBottomRightNormal(), normal_extra);
    xyzw.fillArray4D(vector);

    xyzw.setXYZW(faces[index].getTopLeftVertex(), vertex_extra);
    xyzw.fillArray4D(vector);
    uvz = faces[index].getTopLeftUV();
    uvz.fillArray3D(vector);
    xyzw.setXYZW(faces[index].getTopLeftNormal(), normal_extra);
    xyzw.fillArray4D(vector);

    xyzw.setXYZW(faces[index].getTopRightVertex(), vertex_extra);
    xyzw.fillArray4D(vector);
    uvz = faces[index].getTopRightUV();
    uvz.fillArray3D(vector);
    xyzw.setXYZW(faces[index].getTopRightNormal(), normal_extra);
    xyzw.fillArray4D(vector);
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

