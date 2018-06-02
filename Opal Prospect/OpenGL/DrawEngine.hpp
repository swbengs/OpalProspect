#pragma once

#include <vector>
#include <array>
#include <string>

//shapes and textures
#include "TextureAtlas.hpp"
#include "TextureAtlasController.hpp"
#include "Shapes\ColorRectangle.hpp"
#include "Containers\SortedObjectPool.hpp"

//buffers
#include "OpenGL\Buffers\VertexColorIndexVAO.hpp"
#include "OpenGL\Buffers\VertexUVIndexVAO.hpp"
#include "OpenGL\Buffers\BufferController.hpp"
#include "OpenGL\Buffers\VertexUVNormalIndexVAO3D.hpp"

//programs
#include "OpenGL\Programs\VertexFragmentProgram.hpp"

//glm types
#include "mat4x4.hpp"
#include "vec3.hpp"

#include "DrawEngineStructs.hpp"
#include "Cameras\Camera.hpp"
#include "Shapes\Grid3D.hpp"

//tests
#include "Shapes\ShapeToModel.hpp"
#include "Shapes\ModelIndex.hpp"
#include "ArrayTexture.hpp"

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
Description: Class that takes care of all drawing needs.
*/

class DrawEngine
{
public:
    DrawEngine();

    void draw(const Camera &camera);

    void setup();
    void cleanup();

    //gets
    int getScreenWidth() const;
    int getScreenHeight() const;

    //sets
    void setScreenWidth(int width);
    void setScreenHeight(int height);
    void setScreenWidthHeight(int width, int height);

private:
    BufferController buffers;
    opengl_state state;

    TextureAtlasController atlas;
    VertexFragmentProgram texture_program;
    VertexUVIndexVAO uvVAO;
    VertexUVIndexVAO uvVAO3D;
    Grid3D grid;
    ModelIndex model;
    ArrayTexture test_texture;
    

    int screen_width; //the actual screen resolution
    int screen_height;
    const int game_width = 320; //actual resolution to run at. this will cause largers screens to scale things to be larger
    const int game_height = 240;

    //opengl program uniform location members
    int texture_mvp_id;

    //glm types
    glm::mat4 ortho;
    glm::mat4 persp;

    //position, scale, and rotation can have any coombination of null. null will assign 0, 0, 0 vector to that portion
    //camera and model can NOT be null
    void draw(std::string model_name, const Camera &camera, const glm::vec3 *position, const glm::vec3 *rotate, const glm::vec3 *scale);
    void draw(const model_pod &model_info, const Camera &camera, const glm::vec3 *position, const glm::vec3 *rotate, const glm::vec3 *scale);

    void setupOpenGLContext(); //set the context up and required opengl settings
    void setupOpenGLObjects(); //set up the VBO's, VAO's, and anything else needed for drawing
    void setupOpenGLUniforms(); //get the location of all uniforms
    void setupObjects(); //set up things to draw. testing purposes etc

    void resize(); //called when window is resized
    void calculateOrtho();
    void calculatePersp();

    //tests
    void arrayTextureTest();
    void bufferControlTest();

    
};
