#pragma once

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
Class for a generic vertex buffer object

TODO: Change how buffering works. Right now there is not a good way to keep track of how much room we have because you can overwrite some of the buffer. Yet we don't want to waste space saving what is stored where. Not our responsibility
make seperate modify and add command maybe?
*/

class VBO
{
public:
    VBO();

    virtual void addData(size_t count, const void* data) =0;
    virtual void bindVBO() const =0;
    virtual void modifyData(size_t start, size_t count, const void* data) const =0; //void pointer is used to allow anything to be sent to it
    void generateVBOID();
    virtual void createVBO() const =0;
    void destroyVBO();
    virtual void vertexPointer() =0;
    void enableVertexIndex() const;
    void disableVertexIndex() const;
    virtual void unbindVBO() const =0;

    //gets
    unsigned int getID() const;
    size_t getCurrentSize() const;
    size_t getMaximumSize() const;
    size_t getRemainingSize() const;
    int getDimensions() const; //opengl defined as signed int
    unsigned int getBindIndex() const;

    //sets
    void setCurrentSize(size_t byte_size);
    void setMaximumSize(size_t byte_size);
    void setDimensions(int dimension);
    void setBindIndex(unsigned int binding_index);

private:
    unsigned int id;
    size_t maximum_size; //in bytes
    size_t current_size; //in bytes
    int dimensions; //1, 2, 3, or 4
    unsigned int bind_index; //location to bind this buffer to
};

