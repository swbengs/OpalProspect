#pragma once

#include <vector>
#include <string>

#include "NormalTriangle.hpp"

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

class Model
{
public:
    Model();

    void addTriangle(const NormalTriangle& triangle);

    void fillTriangleVertex(size_t index, std::vector<float>& data) const;
    void fillTriangleUV(size_t index, std::vector<float>& data) const;
    void fillTriangleNormal(size_t index, std::vector<float>& data) const;

    //gets
    std::string getModelName() const;
    std::string getTextureName() const;
    const NormalTriangle& getTriangle(size_t index) const;

    size_t getTriangleCount() const;
    virtual size_t getPointSize() const;
    virtual size_t getTotalSize() const; //total size in bytes

    //sets
    void setModelName(std::string name);
    void setTextureName(std::string name);

protected:
    void putPointInArray(const Point3D& point, float* data, size_t start)  const;
    void putPointInArrayExtra(const Point3D& point, float extra, float* data, size_t start)  const;

private:
    std::vector<NormalTriangle> triangles;
    std::string model_name;
    std::string texture_name;
};
