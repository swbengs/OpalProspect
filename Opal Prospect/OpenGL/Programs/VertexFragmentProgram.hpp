#pragma once

#include "VertexShader.hpp"
#include "FragmentShader.hpp"
#include "Program.hpp"

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