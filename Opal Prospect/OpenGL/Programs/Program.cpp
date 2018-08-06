#include <iostream>

#include "Program.hpp"
#include "glew.h"

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

void Program::createProgramID()
{
    setID(glCreateProgram()); //create program returns an unsigned int
}

void Program::destroyProgram()
{
    if (id > 0)
    {
        glDeleteProgram(id);
    }
}

void Program::useProgram() const
{
    glUseProgram(id);
}

void Program::unUseProgram() const
{
    glUseProgram(0);
}

void Program::attach(unsigned int shader_id) const
{
    glAttachShader(getID(), shader_id);
}

void Program::detach(unsigned int shader_id) const
{
    glDetachShader(getID(), shader_id);
}

void Program::link() const
{
    glLinkProgram(getID());
    int linked;
    glGetProgramiv(getID(), GL_LINK_STATUS, &linked);
    
    if (linked == GL_FALSE)
    {
        checkProgramLog();
    }
    else
    {
        std::cout << "Linking of " << getName() << " was a success! \n \n";
        checkProgramLog();
    }
}

//gets
unsigned int Program::getID() const
{
    return id;
}

std::string Program::getName() const
{
    return name;
}

//sets
void Program::setName(std::string program_name)
{
    name = program_name;
}

//private
void Program::setID(unsigned int program_id)
{
    id = program_id;
}

void Program::checkProgramLog() const
{
    const int size = 500; //max length of the log
    int length; //the command below returns how long the actual log is
    char c_log[size]; //the actual returned log

    glGetProgramInfoLog(getID(), size, &length, c_log);

    std::string log(c_log);

    std::cout << "log begin \n \n";
    std::cout << log << "\n";
    std::cout << "log end \n";
}
