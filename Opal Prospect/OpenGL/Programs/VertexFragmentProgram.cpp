#include <iostream>

#include "VertexFragmentProgram.hpp"
#include "GL\glew.h"

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
