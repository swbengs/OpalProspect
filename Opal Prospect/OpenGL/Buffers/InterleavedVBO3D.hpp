#pragma once

//std lib includes
#include <vector>

//other includes

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
Description: This class contains 3 VBO in one. Vertex, UV, and Normals. Buffer is XYZW,UVZ,Normals for each 3D point.
*/

class InterleavedVBO
{
public:
    InterleavedVBO();

    void bindVBO() const;
    void unbindVBO() const;

    void addData(const std::vector<float>& data);
    void modifyData(size_t start, const std::vector<float>& data);

    void generateVBOID();
    void createVBO() const;
    void destroyVBO();

    void vertexPointerSetup() const;
    void enableVertexIndex() const;
    void disableVertexIndex() const;

    //gets
    unsigned int getID() const;
    size_t getCurrentSize() const;
    size_t getMaximumSize() const;
    size_t getRemainingSize() const;

    //sets
    void setCurrentSize(size_t byte_size);
    void setMaximumSize(size_t byte_size);

private:
    const static int vertex_dimmensions = 4; //maybe make these a define or static variable included from a file
    const static int uv_dimmensions = 3;
    const static int normal_dimmensions = 4;
    const static int vertex_bind = 0;
    const static int uv_bind = 1;
    const static int normal_bind = 2;

    unsigned int id;
    size_t maximum_size; //in bytes
    size_t current_size; //in bytes

    void addData(size_t count, const void *data); //raw pointer here so we don't expose them to public interface. OpenGL uses only void pointers so that is why we do it this way
    void modifyData(size_t start, size_t count, const void *data);
};

