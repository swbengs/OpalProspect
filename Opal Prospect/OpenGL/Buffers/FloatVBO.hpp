#pragma once

#include "VBO.hpp"

/*
A float buffer VBO that is used for vertex array data.
*/

class FloatVBO : public VBO
{
public:
    virtual void addData(size_t count, const void* data);
    virtual void bindVBO() const;
    virtual void unbindVBO() const;
    virtual void createVBO() const;
    virtual void vertexPointer();
    virtual void modifyData(size_t start, size_t count, const void* data) const;
};

