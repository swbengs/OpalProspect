#pragma once

#include <string>

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
Generic class for a shader. Subclasses detain the type
*/

class Shader
{
public:
    virtual void createShaderID() =0;
    void destroyShader();
    void compile() const;
    void loadShader(std::string filename);

    //gets
    std::string getName() const;
    unsigned int getID() const;
    std::string getData() const;

    //sets
    void setName(std::string shader_name);
protected:
    void setID(unsigned int shader_id);
private:
    std::string name;
    std::string data; //string containing the shader
    unsigned int id;

    void loadShaderFromFileCStyle(std::string filename);
    void loadShaderFromFileCPPStyle(std::string filename);
    void checkShaderLog() const;
};
