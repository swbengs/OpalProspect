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
Description: Class that takes care of all drawing needs.

Design details:



TODO:
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
