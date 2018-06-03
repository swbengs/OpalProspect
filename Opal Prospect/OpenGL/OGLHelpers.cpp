#include "OGLHelpers.hpp"

#include <iostream>
#include "GL\glew.h"

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

void OGLHelpers::getOpenGLError(std::string location, bool ignoreNoError)
{
    /*
    GL_NO_ERROR
    No error has been recorded. The value of this symbolic constant is guaranteed to be 0.

    GL_INVALID_ENUM
    An unacceptable value is specified for an enumerated argument. The offending command is ignored and has no other side effect than to set the error flag.

    GL_INVALID_VALUE
    A numeric argument is out of range. The offending command is ignored and has no other side effect than to set the error flag.

    GL_INVALID_OPERATION
    The specified operation is not allowed in the current state. The offending command is ignored and has no other side effect than to set the error flag.

    GL_INVALID_FRAMEBUFFER_OPERATION
    The framebuffer object is not complete. The offending command is ignored and has no other side effect than to set the error flag.

    GL_OUT_OF_MEMORY
    There is not enough memory left to execute the command. The state of the GL is undefined, except for the state of the error flags, after this error is recorded.

    GL_STACK_UNDERFLOW
    An attempt has been made to perform an operation that would cause an internal stack to underflow.

    GL_STACK_OVERFLOW
    An attempt has been made to perform an operation that would cause an internal stack to overflow.
    */

    std::string output = "";
    GLenum error = GL_NO_ERROR;

    do
    {
        error = glGetError();

        if (error == GL_NO_ERROR)
        {
            output = "GL_NO_ERROR";
        }
        else if (error == GL_INVALID_ENUM)
        {
            output = "GL_INVALID_ENUM";
        }
        else if (error == GL_INVALID_VALUE)
        {
            output = "GL_INVALID_VALUE";
        }
        else if (error == GL_INVALID_OPERATION)
        {
            output = "GL_INVALID_OPERATION";
        }
        else if (error == GL_INVALID_FRAMEBUFFER_OPERATION)
        {
            output = "GL_INVALID_FRAMEBUFFER_OPERATION";
        }
        else if (error == GL_OUT_OF_MEMORY)
        {
            output = "GL_OUT_OF_MEMORY";
        }
        else if (error == GL_STACK_UNDERFLOW)
        {
            output = "GL_STACK_UNDERFLOW";
        }
        else if (error == GL_STACK_OVERFLOW)
        {
            output = "GL_STACK_OVERFLOW";
        }


        if (!(ignoreNoError && error == GL_NO_ERROR))
        {
            //display anything including GL_NO_ERROR
            std::cout << location << " " << output << "\n";
        }

    } while (error != GL_NO_ERROR);
}

void OGLHelpers::getOpenGLError(std::string location)
{
    getOpenGLError(location, false);
}
