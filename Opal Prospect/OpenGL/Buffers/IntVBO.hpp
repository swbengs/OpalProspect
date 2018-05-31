#pragma once

#include "VBO.hpp"


/*
Class for and int VBO that is used for element data. Vertex pointers are NOT used with element buffers and so that method does nothing for this class.
*/

class IntVBO : public VBO
{
public:
    virtual void addData(size_t count, const void* data);
    virtual void bindVBO() const;
    virtual void unbindVBO() const;
    virtual void createVBO() const;
    virtual void vertexPointer();
    virtual void modifyData(size_t start, size_t count, const void* data) const;
};

