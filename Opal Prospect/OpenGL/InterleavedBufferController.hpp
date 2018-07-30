#pragma once

//std lib includes
#include <vector>
#include <unordered_map>

//other includes
#include "..\Shapes\ModelIndex.hpp"
#include "Buffers\InterleavedVAO3D.hpp"

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
Description: Class that stores and maintains all interleaved buffers and their model info required to be drawn.
*/

//class delcaration
class InterleavedBufferController
{
public:
    InterleavedBufferController();

    unsigned int addModel(ModelIndex &model);
    void bindVAO(unsigned int reference) const;
    void destroyBuffers();

    //gets
    size_t getVAOCount() const;
    unsigned int getVAOID(unsigned int reference) const; //returns actual id to bind
    unsigned int getModelVAOReference(std::string model_name) const;
    unsigned int getIndexByteOffset(std::string model_name) const;
    unsigned int getIndexCount(std::string model_name) const;

    //sets

private:
    struct model_info_pod
    {
        unsigned int vao_reference; //reference to what vao this model is in
        unsigned int index_byte_offset; //index_count * sizeof(unsigned int). used in draw call to know how many bytes of offset for index buffer
        unsigned int index_count; //how many indicies this model has(actual not unique)
    };

    //const static size_t MAXIMUM_VERTEX_BUFFER_SIZE = 264 * 6 * sizeof(float); //size the vertex data buffer in bytes. specification reccomends data size in the MB range. Lower numbers are being used right now for testing this class
    const static size_t MAXIMUM_VERTEX_BUFFER_SIZE = 4 * 1024 * 1024;
    const static size_t MAXIMUM_INDEX_BUFFER_SIZE = static_cast<size_t>(MAXIMUM_VERTEX_BUFFER_SIZE * 0.13636363 + 0.5); //size of the index buffer.
    //worst case 1/11th of vertex size(all triangles with index), best case 0.13636363 between 1/7 and 1/8 (all faces with index)
    std::vector<InterleavedVAO3D> vaos;
    std::vector<unsigned int> index_byte_offset_totals; //one per vao
    std::unordered_map<std::string, model_info_pod> model_infos;

    int findSuitableBuffer(size_t vertex_size, size_t index_size) const; //used to find a buffer with enough room for our model
    void bufferModel(int index, ModelIndex &model);
    void makeBuffer(); //used when all the current buffers are full or the new model won't fit in them

    bool inBounds(unsigned int reference) const;
};

