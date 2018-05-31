#pragma once

#include <string>

/*
Class for a generic OpenGL shader program.
*/

class Program
{
public:
    void createProgramID();
    void destroyProgram();
    void useProgram() const;
    void unUseProgram() const;

    void attach(unsigned int shader_id) const;
    void detach(unsigned int shader_id) const;
    void link() const;

    //gets
    unsigned int getID() const;
    std::string getName() const;
    //sets
    void setName(std::string program_name);

private:
    unsigned int id;
    std::string name;

    void setID(unsigned int program_id);
    void checkProgramLog() const;
};