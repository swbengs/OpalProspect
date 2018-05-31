#pragma once

#include <GL\glew.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>

#include "OpenGL\DrawEngine.hpp"
#include "Cameras\FlightCamera.hpp"

class MainLoop
{
public:
    void startLoop();
    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
    DrawEngine draw_engine;
    FlightCamera camera;
};
