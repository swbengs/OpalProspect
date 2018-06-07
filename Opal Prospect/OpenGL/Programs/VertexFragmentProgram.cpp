#include <iostream>

#include "VertexFragmentProgram.hpp"
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

void VertexFragmentProgram::use() const
{
    program.useProgram();
}

void VertexFragmentProgram::unUse() const
{
    program.unUseProgram();
}

void VertexFragmentProgram::create(std::string vertex_filename, std::string fragment_filename)
{
    program.unUseProgram(); //ensure no program is bound and being modified

    //create all ID's
    program.createProgramID();
    vertex.createShaderID();
    fragment.createShaderID();

    //load shaders from their files, compile, attach, and link
    vertex.loadShader(vertex_filename);
    fragment.loadShader(fragment_filename);

    vertex.compile();
    fragment.compile();

    program.attach(vertex.getID());
    program.attach(fragment.getID());

    program.link();
}

void VertexFragmentProgram::destroy()
{
    program.detach(vertex.getID());
    vertex.destroyShader();

    program.detach(fragment.getID());
    fragment.destroyShader();

    program.destroyProgram();
}

//gets
std::string VertexFragmentProgram::getName() const
{
    return name;
}

unsigned int VertexFragmentProgram::getID() const
{
    return program.getID();
}

//sets
void VertexFragmentProgram::setName(std::string program_name)
{
    name = program_name;

    std::string v = name;
    std::string f = name;
    std::string p = name;

    v.append(" vertex");
    f.append(" fragment");
    p.append(" program");

    vertex.setName(v);
    fragment.setName(f);
    program.setName(p);
}
