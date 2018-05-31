#pragma once

#include <string>

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
