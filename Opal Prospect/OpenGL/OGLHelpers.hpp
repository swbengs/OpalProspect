#pragma once
#include <string>

/*
Static class to store anything OpenGL related. Error printing, retrieving things from the card and so on
*/

class OGLHelpers
{
public:
    static void getOpenGLError(std::string location, bool ignoreNoError); //this WILL print anything including GL_NO_ERROR
    static void getOpenGLError(std::string location); //if ignore is set to true, it will not print out GL_NO_ERROR. When false it works like the first getError()
private:
    OGLHelpers() {};
};
