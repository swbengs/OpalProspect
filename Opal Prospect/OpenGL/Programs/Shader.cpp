#include <iostream>
#include <fstream>
#include <vector>

#include "Shader.hpp"
#include "GL\glew.h"

void Shader::destroyShader()
{
    glDeleteShader(getID());
}

void Shader::compile() const
{
    glCompileShader(getID());

    int is_compiled;
    glGetShaderiv(getID(), GL_COMPILE_STATUS, &is_compiled);
    if (is_compiled == GL_FALSE)
    {
        checkShaderLog();
    }
    else
    {
        std::cout << "Compiling of " << getName() << " was a success! \n \n";
    }
}

void Shader::loadShader(std::string filename)
{
    //loadShaderFromFileCStyle(filename);
    loadShaderFromFileCPPStyle(filename);

    const char* cstring = data.c_str();
    glShaderSource(getID(), 1, &cstring, NULL);
}

//gets
std::string Shader::getName() const
{
    return name;
}

unsigned int Shader::getID() const
{
    return id;
}

std::string Shader::getData() const
{
    return data;
}

//sets
void Shader::setName(std::string shader_name)
{
    name = shader_name;
}

//protected
void Shader::setID(unsigned int shader_id)
{
    id = shader_id;
}

//private
void Shader::loadShaderFromFileCStyle(std::string filename)
{
    std::ifstream file;

    std::vector<char> c_string;
    char c;

    file.open(filename);

    if (file.good())
    {
        while (file.get(c))
        {
            c_string.push_back(c);
        }

        c_string.push_back('\0'); //add null charcter to terminate

        data.append(c_string.data());
    }
    else
    {
        std::cout << "error reading file " << filename << "\n";
    }

    file.close();
}

void Shader::loadShaderFromFileCPPStyle(std::string filename)
{
    std::ifstream file;

    std::vector<std::string> temp;
    std::string s;

    file.open(filename);

    if (file.good())
    {
        while (getline(file, s))
        {
            temp.push_back(s);
            temp.push_back("\n");
        }

        //now append each individual string, which is a line each, to the final string
        for (unsigned int n = 0; n < temp.size(); n++)
        {
            data.append(temp.at(n));
        }
        
    }
    else
    {
        std::cout << "error reading file " << filename << "\n";
    }

    file.close();
}

void Shader::checkShaderLog() const
{
    const int size = 500; //max length of the log
    int length; //the command returns how long the actual log is
    char c_log[size]; //the actual returned log

    glGetShaderInfoLog(getID(), size, &length, c_log);

    std::string log(c_log);

    std::cout << "log begin \n \n";
    std::cout << log << "\n";
    std::cout << "log end \n";
}
