#pragma once

#include <vector>

#include "Model.hpp"
#include "NormalFace.hpp"

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

/*
Class that stores any generic model with indicies
*/

class ModelIndex : public Model
{
public:
    void addFace(const NormalFace& face);

    void fillVertex(std::vector<float>& vector) const;
    void fillUV(std::vector<float>& vector) const;
    void fillNormal(std::vector<float>& vector) const;
    void fillIndex(std::vector<unsigned int>& vector) const;
    //vertex 4 floats each * 4 points
    //uv 3 floats * 4 points
    //index 6 ints 2 triangles 3 index each
    //normal 4 floats * 4 points

    //index refers to a given faces array position. start is where to start adding into the vector. vector is modified
    void fillTriangleIndex(size_t index, std::vector<unsigned int>& vector) const;
    void fillFaceVertex(size_t index, std::vector<float>& vector) const;
    void fillFaceUV(size_t index, std::vector<float>& vector) const;
    void fillFaceNormal(size_t index, std::vector<float>& vector) const;
    void fillFaceIndex(size_t index, std::vector<unsigned int>& vector) const;

    //gets
    const NormalFace& getFace(size_t index) const;
    size_t getActualPointCount() const; //returns how many unsigned ints are used for this model. Example is that a 3D box has 36 actual indicies.
    size_t getUniquePointCount() const; //returns how many unique indicies are used for this model. Example is that a 3D box has 24 unique indicies.
    virtual size_t getPointSize() const; //size of just vertex, uv, and normals for each point
    size_t getPointTotalSize() const; //total size of vertex+uv+normal of this model combined in bytes
    size_t getIndexTotalSize() const; //total size of index of this model in bytes
    virtual size_t getTotalSize() const; //total size in bytes

    size_t getFaceCount() const;
    unsigned int getIndexOffset() const; //this is a uint on purpose because it has to stay 4 bytes for OGL purposes

    //sets
    void setIndexOffset(unsigned int offset);

private:
    std::vector<NormalFace> faces;

    unsigned int index_offset;
};
