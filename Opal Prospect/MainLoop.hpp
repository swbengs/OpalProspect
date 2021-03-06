#pragma once

#include <glew.h>

#define GLFW_DLL
#include <glfw3.h>

#include "OpenGL\DrawEngine.hpp"
#include "Cameras\FlightCamera.hpp"

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
Description: Class that does the main loop. Has callbacks as C functions to interface with GLFW that call C++ class methods.
*/

class MainLoop
{
public:
    void startLoop(std::string terrain_filename);
    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void framebufferResize(int width, int height);
    void loadTerrain(std::string filename);

private:
    DrawEngine draw_engine;
    FlightCamera camera;
    NaturalTerrainModelBuilder terrain;
};
