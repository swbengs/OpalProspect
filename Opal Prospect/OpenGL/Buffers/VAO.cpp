#include "VAO.hpp"

VAO::VAO()
{
    id = 0;
}

void VAO::bindVAO() const
{
    glBindVertexArray(id);
}

void VAO::createVAO()
{
    glGenVertexArrays(1, &id);
}

void VAO::destroyVAO()
{
    glDeleteVertexArrays(1, &id);
}

void VAO::unbindVAO() const
{
    glBindVertexArray(0);
}

unsigned int VAO::getID() const
{
    return id;
}
