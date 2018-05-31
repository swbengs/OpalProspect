#include <iostream>

#include "Program.hpp"
#include "GL\glew.h"

void Program::createProgramID()
{
    setID(glCreateProgram()); //create program returns an unsigned int
}

void Program::destroyProgram()
{
    glDeleteProgram(id);
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
