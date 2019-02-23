#include "MainLoop.hpp"

#include <iostream>
#include <chrono>

#include "OpenGL\OGLHelpers.hpp"
#include "gtc\matrix_transform.hpp"
#include "BasicLog.hpp"

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

//helper c functions
void error_callback(int error, const char* description)
{
    fputs(description, stderr);
    exit(8888);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    void* user_pointer = glfwGetWindowUserPointer(window);
    MainLoop* loop_pointer = static_cast<MainLoop*>(user_pointer);

    loop_pointer->keyCallback(window, key, scancode, action, mods);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    void* user_pointer = glfwGetWindowUserPointer(window);
    MainLoop* loop_pointer = static_cast<MainLoop*>(user_pointer);

    loop_pointer->framebufferResize(width, height);
}

//public
void MainLoop::startLoop(std::string terrain_filename)
{
    const int screen_width = 640;
    const int screen_height = 480;
    const char* name = "Opal Prospect v0.15";

    if (terrain_filename.compare("") == 0)
    {
        std::cout << "Please enter a terrain filename to load\n";
        std::getline(std::cin, terrain_filename);
        std::cout << "Loading " << terrain_filename << "\n\n";
    }

    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        BasicLog::getInstance().writeError("Failed to start glfw\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(screen_width, screen_height, name, NULL, NULL);

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    //window = glfwCreateWindow(mode->width, mode->height, "My Title", glfwGetPrimaryMonitor(), NULL);
    //window = glfwCreateWindow(screen_width, screen_height, "My Title", glfwGetPrimaryMonitor(), NULL);
    if (!window)
    {
        glfwTerminate();
        BasicLog::getInstance().writeError("Failed to create glfw window\n");
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    //glfwSwapInterval(0);
    glfwSwapInterval(1);

    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //set user pointer so we can later call ourselves again in helper functions
    glfwSetWindowUserPointer(window, this);

    int major = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
    int minor = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);

    std::cout << "version major: " << major << " minor: " << minor << "\n";

    //start glew after window creation
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }

    OGLHelpers::getOpenGLError("first");

    draw_engine.setScreenWidth(screen_width);
    draw_engine.setScreenHeight(screen_height);
    draw_engine.setup();
    loadTerrain(terrain_filename);

    Point3DUInt world_xyz = terrain.getWorldDimensions();
    const float x_start = DF_BLOCK_WIDTH * 0.5f * world_xyz.x;
    const float y_start = (DF_BLOCK_HEIGHT + DF_FLOOR_HEIGHT) * world_xyz.y;
    const float z_start = -5.0f;

    std::cout << "\n";

    const unsigned int target_fps = 60;
    const unsigned int fps_print_skip = 15;
    //camera.setPosition(glm::vec3(0.0f, 0.0f, -10.0f));
    camera.setPosition(glm::vec3(x_start, y_start, z_start));

    unsigned int frames = target_fps;
    unsigned int skips = 0;
    std::chrono::high_resolution_clock::time_point original_start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point start = original_start;

    while (!glfwWindowShouldClose(window))
    {
        if (frames == target_fps)
        {
            skips++;
            if (skips == fps_print_skip)
            {
                std::chrono::duration<double> seconds = std::chrono::high_resolution_clock::now() - start;
                frames *= skips;

                std::cout << "seconds: " << seconds.count() << "\n";
                std::cout << "fps: " << (static_cast<double>(frames) / seconds.count()) << "\n";
                
                skips = 0;
                start = std::chrono::high_resolution_clock::now();
            }
            frames = 0;
        }

        draw_engine.draw(camera);

        glfwSwapBuffers(window);
        glfwPollEvents();

        frames++;
    }

    std::cout << "\n";
    //std::cout << "total time: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - original_start).count() << "us \n";
    //std::cout << "total time: " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - original_start).count() << "s \n";

    draw_engine.cleanup();

    OGLHelpers::getOpenGLError("pre quit");

    glfwDestroyWindow(window);
    glfwTerminate();
}

void MainLoop::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    float rot_rate = glm::radians(5.0f);
    float move_rate = 1.0f;

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.rotateUp(rot_rate);
    }
    else if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.rotateDown(rot_rate);
    }
    else if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.rotateRight(rot_rate);
    }
    else if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.rotateLeft(rot_rate);
    }
    else if (key == GLFW_KEY_E && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.rollRight(rot_rate);
    }
    else if (key == GLFW_KEY_Q && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.rollLeft(rot_rate);
    }

    if (key == GLFW_KEY_SPACE && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.moveUp(move_rate);
    }
    else if (key == GLFW_KEY_C && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.moveDown(move_rate);
    }
    else if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.moveRight(move_rate);
    }
    else if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.moveLeft(move_rate);
    }
    else if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.moveForward(move_rate);
    }
    else if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        camera.moveBackward(move_rate);
    }

    if (key == GLFW_KEY_P && (action == GLFW_PRESS))
    {
        camera.outputCameraMatrix();
        camera.outputVectors();
    }
}

void MainLoop::framebufferResize(int width, int height)
{
    draw_engine.setScreenWidthHeight(width, height);
}

void MainLoop::loadTerrain(std::string filename)
{
    ModelIndex terrain_model;
    //NaturalTerrain terrain_test;
    terrain_model.setTextureName("terrain.png");
    terrain_model.setModelName("terrain");
    //std::string filename;
    //filename = "Test\\test_maps\\5x5x5_simple.txt";
    //filename = "Test\\test_maps\\5x5x5.txt";
    //filename = "Test\\test_maps\\16x16x16.txt";
    //filename = "Test\\test_maps\\16x16x16_simple.txt";
    //filename = "Test\\test_maps\\df_real.txt";
    //filename = "Test\\test_maps\\df_real_short.txt";

    //terrain_test stuff here

    //terrain_3x3x3_test(terrain_test);
    //terrain_16x16x16_test(terrain_test);
    //terrain_48x48x48_test(terrain_test);
    //terrain_48x300x48_test(terrain_test);
    //terrain_test and not after here

    //terrain.loadFromMemory(terrain_test, models, terrain_model);
    terrain.loadFromFile(filename, draw_engine.getModelController(), terrain_model);

    std::cout << "terrain face count: " << terrain_model.getFaceCount() << "\n";
    //std::cout << "face total size: " << terrain_model.getTotalSize() / terrain_model.getFaceCount() << "\n";
    std::cout << "terrain model total size: " << terrain_model.getTotalSize() << "\n";
    draw_engine.addInterleavedModel(terrain_model, true);

    std::cout << "after terrain load\n";
}

