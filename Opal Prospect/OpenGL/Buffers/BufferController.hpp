#pragma once

#include <vector>
#include <unordered_map>

#include "Shapes\ModelIndex.hpp"
#include "OpenGL\Buffers\VertexUVNormalIndexVAO3D.hpp"

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
   Class that stores all VAO, VBO, and so on. Will create them as needed or remove them. Adds incoming models into the proper buffer that has enough room.
*/

class BufferController
{
public:
    BufferController();

    unsigned int addModel(ModelIndex &model);
    void bindVAO(unsigned int reference) const;
    void destroyBuffers();

    //gets
    unsigned int getVAOID(unsigned int reference) const;
    unsigned int getModelVAOReference(std::string model_name) const;
    unsigned int getModelIndexOffset(std::string model_name) const;

    //sets

private:
    const static size_t MAXIMUM_BUFFER_SIZE = 4096; //size of an individual buffer in bytes. specification reccomends data size in the MB range. Lower numbers are being used right now for testing this class
    std::vector<VertexUVNormalIndexVAO3D> vaos;
    std::unordered_map<std::string, unsigned int> references;

    int findSuitableBuffer(size_t total_size, size_t index_size) const; //used to find a buffer with enough room for our model
    void bufferModel(int index, ModelIndex &model);
    void makeBuffer(); //used when all the current buffers are full or the new model won't fit in them

    bool inBounds(unsigned int reference) const;
};

