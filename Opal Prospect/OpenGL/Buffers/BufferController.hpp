#pragma once

#include <vector>
#include <unordered_map>

#include "Shapes\ModelIndex.hpp"
#include "OpenGL\Buffers\VertexUVNormalIndexVAO3D.hpp"

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
    const static size_t MAXIMUM_BUFFER_SIZE = 4096; //size of an individual buffer in bytes. specification reccomends data size in the MB range
    std::vector<VertexUVNormalIndexVAO3D> vaos;
    std::unordered_map<std::string, unsigned int> references;

    int findSuitableBuffer(size_t total_size, size_t index_size) const; //used to find a buffer with enough room for our model
    void bufferModel(int index, ModelIndex &model);
    void makeBuffer(); //used when all the current buffers are full or the new model won't fit in them

    bool inBounds(unsigned int reference) const;
};

