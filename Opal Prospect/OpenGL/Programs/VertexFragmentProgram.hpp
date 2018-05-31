#pragma once

#include "VertexShader.hpp"
#include "FragmentShader.hpp"
#include "Program.hpp"

/*
Class that uses a vertex and fragment shader. It combines it with a program to create a ready to use OpenGL program for drawing with.
*/

class VertexFragmentProgram
{
public:
    void use() const;
    void unUse() const;

    void create(std::string vertex_filename, std::string fragment_filename);
    void destroy();

    //gets
    std::string getName() const;
    unsigned int getID() const;
    //sets
    void setName(std::string program_name);
private:
    std::string name;

    Program program;
    VertexShader vertex;
    FragmentShader fragment;
};