#include <iostream>
#include <fstream>
#include <vector>

#include "Shader.hpp"
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
