#pragma once
#include "GL\glew.h"

/*
Class for a generic vertex array object. OpenGL 3.0 or higher is required to use this.
*/

class VAO
{
public:
    VAO();

    void bindVAO() const;
    void createVAO();
    void destroyVAO();
    void unbindVAO() const;

    //gets
    unsigned int getID() const;
private:
    unsigned int id;
};

