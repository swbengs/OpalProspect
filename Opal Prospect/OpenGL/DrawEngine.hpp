#pragma once

#include <vector>
#include <array>
#include <string>

//shapes and textures
#include "ArrayTextureAtlas.hpp"
#include "ArrayTexture.hpp"
#include "TextureAtlas.hpp"
#include "TextureAtlasController.hpp"
#include "..\Shapes\ColorRectangle.hpp"
#include "..\Containers\SortedObjectPool.hpp"

//buffers
#include "Buffers\InterleavedVAO3D.hpp"

//programs
#include "Programs\VertexFragmentProgram.hpp"

//glm types
#include "mat4x4.hpp"
#include "vec3.hpp"

#include "..\Cameras\Camera.hpp"
#include "..\Shapes\Grid3D.hpp"
#include "..\Shapes\Grid3DYOffset.hpp"
#include "..\Shapes\RightRectanglePyramidNormal.hpp"
#include "..\Shapes\ShapeToModel.hpp"
#include "..\Shapes\ModelIndex.hpp"


#include "DrawEngineStructs.hpp"
#include "..\DwarfFortress\df_constants.hpp"
#include "ArrayTextureController.hpp"
#include "ArrayTextureAtlasController.hpp"
#include "BufferController.hpp"
#include "InterleavedBufferController.hpp"
#include "ModelController.hpp"
#include "..\DwarfFortress\NaturalTerrainModelBuilder.hpp"

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

    void addModel(ModelIndex& model);
    void addInterleavedModel(ModelIndex& model);
    void addInterleavedModel(ModelIndex& model, bool free_model_data);
    void addTexture(const ArrayTextureAtlas& texture);
    void draw(const Camera &camera);

    void setup();
    void cleanup();

    const ModelController& getModelController() const; //returns reference to model controller to be used/sent to other class

    //gets
    int getScreenWidth() const;
    int getScreenHeight() const;

    //sets
    void setScreenWidth(int width);
    void setScreenHeight(int height);
    void setScreenWidthHeight(int width, int height);

private:
    const static float Z_NEAR;
    const static float Z_FAR;
    BufferController buffers;
    InterleavedBufferController interleaved_buffers;
    ArrayTextureAtlasController textures;
    ArrayTextureController main_textures;
    ModelController models;
    opengl_state state;

    VertexFragmentProgram texture_program;
    Grid3D grid;
    Grid3DYOffset grid_off, grid_off2;
    ModelIndex test_model;
    ArrayTextureAtlas test_texture;
    ArrayTexture array_texture;
    InterleavedVAO3D interleave_vao;
    NaturalTerrainModelBuilder terrain;

    int screen_width; //the actual screen resolution
    int screen_height;
    const int game_width = 320; //resolution to run at. this will cause largers screens to scale things to be larger
    const int game_height = 240;

    //opengl program uniform location members
    int uniform_mvp_id;
    int uniform_mv_id;
    int uniform_ambient_color_id;
    int uniform_sun_light_color_id;
    int uniform_sun_light_direction_id;

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
    void loadTextures();
    void loadModels();

    void resize(); //called when window is resized
    void calculateOrtho();
    void calculatePersp();

    //tests
    void bufferControlTest();
    void interleaveTest();
    void interleaveDraw(const Camera &camera);
    void arrayTextureTest();
    void arrayTextureDraw(const Camera &camera);
    void properDrawTest();
    void terrain_3x3x3_test(NaturalTerrain& natural_terrain);
    void terrain_16x16x16_test(NaturalTerrain& natural_terrain);
    void terrain_48x48x48_test(NaturalTerrain& natural_terrain);
    void terrain_48x300x48_test(NaturalTerrain& natural_terrain);
};
