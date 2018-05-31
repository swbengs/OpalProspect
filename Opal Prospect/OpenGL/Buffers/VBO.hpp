#pragma once

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

