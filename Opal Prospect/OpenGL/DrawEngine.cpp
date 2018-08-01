#include "DrawEngine.hpp"

#include <iostream>
#include <array>
#include <sstream>

#include "glew.h"
#include "OGLHelpers.hpp"
#include "..\Constants\axis.hpp"

//glm includes
#include "gtc\matrix_transform.hpp" //ortho, rotate, scale, translate
#include "gtx\io.hpp" //output matrix and vectors to std::cout
#include "gtc\type_ptr.hpp" //get pointer for any vec or mat to upload to OpenGL

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

const float DrawEngine::Z_NEAR = 0.1f;
const float DrawEngine::Z_FAR = 50.0f;

void DrawEngine::properDrawTest()
{
    ShapeToModel convert;
    NormalBox box;

    std::string texture_name = "terrain.png";
    box.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    //box.setTextureNumber(1);
    box.setTextureNumber(main_textures.getTextureNumber("white_sand.png"));
    Point3D front, back, left, right, top, bottom;
    front.setXYZ(0, 1, 2);
    back.setXYZ(3, 4, 5);
    left.setXYZ(6, 7, 8);
    right.setXYZ(9, 10, 11);
    top.setXYZ(12, 13, 14);
    bottom.setXYZ(15, 16, 17);
    box.setNormal(front, back, left, right, top, bottom);

    convert.convertToModelIndex(box, test_model);
    test_model.setModelName("test.obj");
    test_model.setTextureName(texture_name);
    addInterleavedModel(test_model);

    ModelIndex mod2, mod3, mod4, mod6;
    //box.setTextureNumber(2);
    box.setTextureNumber(main_textures.getTextureNumber("silty_clay_loam.png"));
    convert.convertToModelIndex(box, mod2);
    mod2.setModelName("test_two");
    mod2.setTextureName(texture_name);
    addInterleavedModel(mod2);

    //box.setTextureNumber(0);
    box.setTextureNumber(main_textures.getTextureNumber("junk.png"));
    convert.convertToModelIndex(box, mod3);
    mod3.setModelName("test_three");
    mod3.setTextureName(texture_name);
    addInterleavedModel(mod3);

    //box.setTextureNumber(19);
    box.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    convert.convertToModelIndex(box, mod4);
    mod4.setModelName("test_four");
    mod4.setTextureName(texture_name);
    addInterleavedModel(mod4);

    RightRectanglePyramidNormal pyramid;
    ModelIndex pyra_mod;
    pyra_mod.setTextureName(texture_name);
    pyra_mod.setModelName("pyramid");
    pyramid.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    pyramid.setNormal(front, back, left, right, bottom);
    //pyramid.setTextureNumber(4);
    pyramid.setTextureNumber(main_textures.getTextureNumber("gabbro.png"));
    convert.convertToModelIndex(pyramid, pyra_mod);
    addInterleavedModel(pyra_mod);

    //box.setTextureNumber(18);
    box.setTextureNumber(main_textures.getTextureNumber("white_sand.png"));
    box.setWidthHeightLength(1.0f, 0.2f, 1.0f);
    convert.convertToModelIndex(box, mod6);
    mod6.setModelName("test_six");
    mod6.setTextureName(texture_name);
    addInterleavedModel(mod6);

    grid_off.setBoxWidthLengthHeight(1.0f, 1.0f, 1.0f);
    grid_off.setGridWidthLengthHeight(3, 3, 3);
    grid_off.setYStride(0.2f);
    grid_off.setYOffset(0.2f);
    grid_off.create();

    grid_off2.setBoxWidthLengthHeight(1.0f, 0.2f, 1.0f);
    grid_off2.setGridWidthLengthHeight(3, 3, 3);
    grid_off2.setYStride(1.0f);
    grid_off2.setYOffset(0.0f);
    grid_off2.create();

    interleave_vao.setIndexOffset(0);
    interleave_vao.setMaximumVertexSize(264 * 3 * sizeof(float));
    interleave_vao.setMaximumIndexSize(36 * 3 * sizeof(unsigned int));
    interleave_vao.create();

    std::vector<float> vertex;
    std::vector<unsigned int> index;
    test_model.fillInterleaved(vertex);
    mod2.fillInterleaved(vertex);
    mod3.fillInterleaved(vertex);

    test_model.setIndexOffset(0);
    test_model.fillIndex(index);
    mod2.setIndexOffset(24);
    mod2.fillIndex(index);
    mod3.setIndexOffset(48);
    mod3.fillIndex(index);

    interleave_vao.bindMainVBO();
    interleave_vao.bufferMainVBO(vertex);
    interleave_vao.bindIndexVBO();
    interleave_vao.bufferIndex(index);

    std::cout << "proper draw test end\n";
}

void DrawEngine::arrayTextureTest()
{
    OGLHelpers::getOpenGLError("pre array texture creation", true);

    std::string texture_name = "terrain.png";
    std::vector<std::string> files;
    files.push_back("Textures\\bad.png");
    files.push_back("Textures\\soils\\white_sand.png");
    files.push_back("Textures\\soils\\silty_clay_loam.png");

    array_texture.setTextureName(texture_name);
    array_texture.loadImages(files);
    array_texture.createTexture();
    main_textures.addTexture(array_texture);

    OGLHelpers::getOpenGLError("post array texture creation", true);

    ShapeToModel convert;
    NormalBox box;

    box.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    //box.setTextureNumber(1);
    box.setTextureNumber(main_textures.getTextureNumber("white_sand.png"));
    Point3D front, back, left, right, top, bottom;
    front.setXYZ(0, 1, 2);
    back.setXYZ(3, 4, 5);
    left.setXYZ(6, 7, 8);
    right.setXYZ(9, 10, 11);
    top.setXYZ(12, 13, 14);
    bottom.setXYZ(15, 16, 17);
    box.setNormal(front, back, left, right, top, bottom);

    convert.convertToModelIndex(box, test_model);
    test_model.setModelName("test.obj");
    test_model.setTextureName(texture_name);

    ModelIndex mod2, mod3;
    //box.setTextureNumber(2);
    box.setTextureNumber(main_textures.getTextureNumber("silty_clay_loam.png"));
    convert.convertToModelIndex(box, mod2);
    mod2.setModelName("test_two");
    mod2.setTextureName(texture_name);

    //box.setTextureNumber(0);
    box.setTextureNumber(main_textures.getTextureNumber("junk.png"));
    convert.convertToModelIndex(box, mod3);
    mod3.setModelName("test_three");
    mod3.setTextureName(texture_name);

    interleave_vao.setIndexOffset(0);
    interleave_vao.setMaximumVertexSize(264 * 3 * sizeof(float));
    interleave_vao.setMaximumIndexSize(36 * 3 * sizeof(unsigned int));
    interleave_vao.create();

    std::vector<float> vertex;
    std::vector<unsigned int> index;
    test_model.fillInterleaved(vertex);
    mod2.fillInterleaved(vertex);
    mod3.fillInterleaved(vertex);

    test_model.setIndexOffset(0);
    test_model.fillIndex(index);
    mod2.setIndexOffset(24);
    mod2.fillIndex(index);
    mod3.setIndexOffset(48);
    mod3.fillIndex(index);

    interleave_vao.bindMainVBO();
    interleave_vao.bufferMainVBO(vertex);
    interleave_vao.bindIndexVBO();
    interleave_vao.bufferIndex(index);

    std::cout << "texture number for silty_clay_loam: " << array_texture.getTextureNumberReference("silty_clay_loam.png") << "\n";
    std::cout << "texture number for white_sand: " << array_texture.getTextureNumberReference("white_sand.png") << "\n";
    std::cout << "texture number for bad: " << array_texture.getTextureNumberReference("bad.png") << "\n";
    std::cout << "texture number for junk: " << array_texture.getTextureNumberReference("junk") << "\n";
    std::cout << "array texture test end\n";
}

void DrawEngine::interleaveTest()
{
    OGLHelpers::getOpenGLError("pre array texture creation", true);

    std::string texture_name = "Textures\\soils.png";
    test_texture.setFilename(texture_name);
    test_texture.setTextureWidth(16);
    test_texture.setTextureHeight(16);
    test_texture.createTexture();
    addTexture(test_texture);

    OGLHelpers::getOpenGLError("post array texture creation", true);

    ShapeToModel convert;
    NormalBox box;

    box.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    box.setTextureNumber(19);
    Point3D front, back, left, right, top, bottom;
    front.setXYZ(0, 1, 2);
    back.setXYZ(3, 4, 5);
    left.setXYZ(6, 7, 8);
    right.setXYZ(9, 10, 11);
    top.setXYZ(12, 13, 14);
    bottom.setXYZ(15, 16, 17);
    box.setNormal(front, back, left, right, top, bottom);

    convert.convertToModelIndex(box, test_model);
    test_model.setModelName("test.obj");
    test_model.setTextureName(texture_name);
    addInterleavedModel(test_model);

    ModelIndex mod2, mod3, mod4, mod6;
    box.setTextureNumber(18);
    convert.convertToModelIndex(box, mod2);
    mod2.setModelName("test_two");
    mod2.setTextureName(texture_name);
    addInterleavedModel(mod2);

    box.setTextureNumber(19);
    box.setWidthHeightLength(1.0f, 0.2f, 1.0f);
    convert.convertToModelIndex(box, mod3);
    mod3.setModelName("test_three");
    mod3.setTextureName(texture_name);
    addInterleavedModel(mod3);

    box.setTextureNumber(19);
    box.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    convert.convertToModelIndex(box, mod4);
    mod4.setModelName("test_four");
    mod4.setTextureName(texture_name);
    addInterleavedModel(mod4);

    RightRectanglePyramidNormal pyramid;
    ModelIndex pyra_mod;
    pyra_mod.setTextureName(texture_name);
    pyra_mod.setModelName("pyramid");
    pyramid.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    pyramid.setNormal(front, back, left, right, bottom);
    pyramid.setTextureNumber(4);
    /*
    pyramid.setFrontTextureNumber(100);
    pyramid.setBackTextureNumber(110);
    pyramid.setLeftTextureNumber(120);
    pyramid.setRightTextureNumber(130);
    pyramid.setBottomTextureNumber(140);
    */
    convert.convertToModelIndex(pyramid, pyra_mod);
    addInterleavedModel(pyra_mod);

    mod4.setModelName("junk");
    addInterleavedModel(mod4);

    box.setTextureNumber(18);
    box.setWidthHeightLength(1.0f, 0.2f, 1.0f);
    convert.convertToModelIndex(box, mod6);
    mod6.setModelName("test_six");
    mod6.setTextureName(texture_name);
    addInterleavedModel(mod6);

    grid_off.setBoxWidthLengthHeight(1.0f, 1.0f, 1.0f);
    grid_off.setGridWidthLengthHeight(3, 3, 3);
    grid_off.setYStride(0.2f);
    grid_off.setYOffset(0.2f);
    grid_off.create();

    grid_off2.setBoxWidthLengthHeight(1.0f, 0.2f, 1.0f);
    grid_off2.setGridWidthLengthHeight(3, 3, 3);
    grid_off2.setYStride(1.0f);
    grid_off2.setYOffset(0.0f);
    grid_off2.create();

    /*
    interleave_vao.setIndexOffset(0);
    interleave_vao.setMaximumVertexSize(264 * 2 * sizeof(float));
    interleave_vao.setMaximumIndexSize(36 * 2 * sizeof(unsigned int));
    interleave_vao.create();

    std::vector<float> vertex;
    std::vector<unsigned int> index;
    test_model.fillInterleaved(vertex);
    mod2.fillInterleaved(vertex);

    test_model.setIndexOffset(0);
    test_model.fillIndex(index);
    mod2.setIndexOffset(24);
    mod2.fillIndex(index);

    interleave_vao.bindMainVBO();
    interleave_vao.bufferMainVBO(vertex);
    interleave_vao.bindIndexVBO();
    interleave_vao.bufferIndex(index);
    */

    std::cout << "\n";
}

void DrawEngine::bufferControlTest()
{
    OGLHelpers::getOpenGLError("pre array texture creation", true);

    std::string texture_name = "Textures\\soils.png";
    test_texture.setFilename(texture_name);
    test_texture.setTextureWidth(16);
    test_texture.setTextureHeight(16);
    test_texture.createTexture();
    addTexture(test_texture);

    OGLHelpers::getOpenGLError("post array texture creation", true);

    ShapeToModel convert;
    NormalBox box;

    box.setFrontTextureNumber(0);
    box.setBackTextureNumber(1);
    box.setLeftTextureNumber(2);
    box.setRightTextureNumber(3);
    box.setTopTextureNumber(4);
    box.setBottomTextureNumber(5);
    box.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    Point3D front, back, left, right, top, bottom;
    front.setXYZ(0, 1, 2);
    back.setXYZ(3, 4, 5);
    left.setXYZ(6, 7, 8);
    right.setXYZ(9, 10, 11);
    top.setXYZ(12, 13, 14);
    bottom.setXYZ(15, 16, 17);
    //box.setNormal(front, back, left, right, top, bottom);
    
    convert.convertToModelIndex(box, test_model);
    test_model.setModelName("test.obj");
    test_model.setTextureName(texture_name);

    OGLHelpers::getOpenGLError("pre model add", true);
    addModel(test_model);
    OGLHelpers::getOpenGLError("post model add", true);

    ModelIndex mod2, mod3, mod4, mod6;
    box.setTextureNumber(18);
    convert.convertToModelIndex(box, mod2);
    mod2.setModelName("test_two");
    mod2.setTextureName(texture_name);
    addModel(mod2);

    box.setTextureNumber(19);
    box.setWidthHeightLength(1.0f, 0.2f, 1.0f);
    convert.convertToModelIndex(box, mod3);
    mod3.setModelName("test_three");
    mod3.setTextureName(texture_name);
    addModel(mod3);

    box.setTextureNumber(19);
    box.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    convert.convertToModelIndex(box, mod4);
    mod4.setModelName("test_four");
    mod4.setTextureName(texture_name);
    addModel(mod4);

    RightRectanglePyramidNormal pyramid;
    ModelIndex pyra_mod;
    pyra_mod.setTextureName(texture_name);
    pyra_mod.setModelName("pyramid");
    pyramid.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    pyramid.setNormal(front, back, left, right, bottom);
    pyramid.setTextureNumber(4);
    /*
    pyramid.setFrontTextureNumber(100);
    pyramid.setBackTextureNumber(110);
    pyramid.setLeftTextureNumber(120);
    pyramid.setRightTextureNumber(130);
    pyramid.setBottomTextureNumber(140);
    */
    convert.convertToModelIndex(pyramid, pyra_mod);
    addModel(pyra_mod);

    mod4.setModelName("junk");
    addModel(mod4);

    box.setTextureNumber(18);
    box.setWidthHeightLength(1.0f, 0.2f, 1.0f);
    convert.convertToModelIndex(box, mod6);
    mod6.setModelName("test_six");
    mod6.setTextureName(texture_name);
    addModel(mod6);

    grid_off.setBoxWidthLengthHeight(1.0f, 1.0f, 1.0f);
    grid_off.setGridWidthLengthHeight(3, 3, 3);
    grid_off.setYStride(0.2f);
    grid_off.setYOffset(0.2f);
    grid_off.create();

    grid_off2.setBoxWidthLengthHeight(1.0f, 0.2f, 1.0f);
    grid_off2.setGridWidthLengthHeight(3, 3, 3);
    grid_off2.setYStride(1.0f);
    grid_off2.setYOffset(0.0f);
    grid_off2.create();

    std::cout << "\n";
}

DrawEngine::DrawEngine()
{
    screen_width = 1;
    screen_height = 1;
    resize();
}

/*
Method to properly add a model and update all important references it needs to be drawn. This means the texture it wants must already have been added prior to adding said model.
*/
void DrawEngine::addModel(ModelIndex& model)
{
    size_t current;
    models.addModel(model);
    current = models.getCount();
    buffers.addModel(models.modifyModel(current));
    //texture name, model name, and index count are already entered
    model_pod& pod = models.modifyModelPOD(current);
    pod.texture_reference = textures.getTextureReference(pod.texture_name);
    pod.index_offset_bytes = buffers.getIndexByteOffset(pod.model_name);
    pod.vao_reference = buffers.getModelVAOReference(pod.model_name);
}

/*
Method to properly add a model interleaved and update all important references it needs to be drawn. This means the texture it wants must already have been added prior to adding said model.
*/
void DrawEngine::addInterleavedModel(ModelIndex& model)
{
    size_t current;
    models.addModel(model);
    current = models.getCount();
    interleaved_buffers.addModel(models.modifyModel(current));
    //texture name, model name, and index count are already entered
    model_pod& pod = models.modifyModelPOD(current);
    pod.texture_reference = main_textures.getTextureReference(pod.texture_name);
    pod.index_offset_bytes = interleaved_buffers.getIndexByteOffset(pod.model_name);
    pod.vao_reference = interleaved_buffers.getModelVAOReference(pod.model_name);
}

void DrawEngine::addTexture(const ArrayTextureAtlas& texture)
{
    textures.addTexture(texture);
}

void DrawEngine::arrayTextureDraw(const Camera &camera)
{
    OGLHelpers::getOpenGLError("pre draw", true);

    glm::vec3 first = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 second = glm::vec3(3.0f, 0.0f, 0.0f);
    glm::vec3 third = glm::vec3(6.0f, 0.0f, 0.0f);

    texture_program.use();
    main_textures.bindTexture(1);
    interleave_vao.bindVAO();

    glm::mat4 view;
    camera.fillViewMatrix(view);

    glm::mat4 model;
    model = glm::translate(model, first);
    glm::mat4 mvp = persp * view * model;
    glUniformMatrix4fv(texture_mvp_id, 1, false, glm::value_ptr(mvp));
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)(1 * 36 * sizeof(unsigned int)));

    model = glm::mat4();
    model = glm::translate(model, second);
    mvp = glm::mat4();
    mvp = persp * view * model;
    glUniformMatrix4fv(texture_mvp_id, 1, false, glm::value_ptr(mvp));
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)(0 * 36 * sizeof(unsigned int)));

    model = glm::mat4();
    model = glm::translate(model, third);
    mvp = glm::mat4();
    mvp = persp * view * model;
    glUniformMatrix4fv(texture_mvp_id, 1, false, glm::value_ptr(mvp));
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)(2 * 36 * sizeof(unsigned int)));

    OGLHelpers::getOpenGLError("post draw", true);
}

void DrawEngine::interleaveDraw(const Camera &camera)
{
    OGLHelpers::getOpenGLError("pre draw", true);

    glm::vec3 first = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 second = glm::vec3(3.0f, 0.0f, 0.0f);

    texture_program.use();
    test_texture.bind();
    interleave_vao.bindVAO();

    glm::mat4 view;
    camera.fillViewMatrix(view);

    glm::mat4 model;
    model = glm::translate(model, first);
    glm::mat4 mvp = persp * view * model;
    glUniformMatrix4fv(texture_mvp_id, 1, false, glm::value_ptr(mvp));
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)(1 * 36 * sizeof(unsigned int)));

    model = glm::mat4();
    model = glm::translate(model, second);
    mvp = glm::mat4();
    mvp = persp * view * model;
    glUniformMatrix4fv(texture_mvp_id, 1, false, glm::value_ptr(mvp));
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)(0 * 36 * sizeof(unsigned int)));

    OGLHelpers::getOpenGLError("post draw", true);
}

void DrawEngine::draw(const Camera &camera)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::vec3 first = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 second = glm::vec3(3.0f, 0.0f, 0.0f);
    glm::vec3 third = glm::vec3(0.0f, 3.0f, 0.0f);
    glm::vec3 fourth = glm::vec3(3.0f, 3.0f, 0.0f);
    glm::vec3 fifth = glm::vec3(0.0f, 0.0f, -2.0f);
    glm::vec3 sixth = glm::vec3(6.0f, 3.0f, 0.0f);
    glm::vec3 terrain_position = glm::vec3(15.0f, 0.0f, 0.0f);
    glm::vec3 test = glm::vec3(-1.0f, -1.0f, -1.0f);

    draw("test.obj", camera, &first, nullptr, nullptr);
    //draw(models.getModelPOD(1), camera, &first, nullptr, nullptr);
    draw(models.getModelPOD(2), camera, &second, nullptr, nullptr);
    draw(models.getModelPOD(3), camera, &third, nullptr, nullptr);
    draw(models.getModelPOD(4), camera, &fourth, nullptr, nullptr);
    //draw(models.getModelPOD(5), camera, &fifth, nullptr, nullptr);
    draw("pyramid", camera, &fifth, nullptr, nullptr);
    draw(models.getModelPOD(6), camera, &sixth, nullptr, nullptr);
    //draw("error", camera, &first, nullptr, nullptr);

    //draw("gabbro block", camera, &test, nullptr, nullptr);
    //draw("gabbro floor", camera, &test, nullptr, nullptr);
    draw("terrain", camera, &terrain_position, nullptr, nullptr);

    //draw grid
    Point3D start(6.0f, 6.0f, 6.0f);
    CenterBox grid_box;
    glm::vec3 grid_pos;
    for (unsigned int i = 0; i < grid_off.getGridCount(); i++)
    {
        grid_box = grid_off.getBox(i);
        grid_pos = glm::vec3(grid_box.getX() + start.x, grid_box.getY() + start.y, grid_box.getZ() + start.z);
        draw(models.getModelPOD(2), camera, &grid_pos, nullptr, nullptr);
    }

    start.setXYZ(6.0f, 6.0f, 6.0f);
    for(unsigned int i = 0; i < grid_off2.getGridCount(); i++)
    {
        grid_box = grid_off2.getBox(i);
        grid_pos = glm::vec3(grid_box.getX() + start.x, grid_box.getY() + start.y, grid_box.getZ() + start.z);
        draw(models.getModelPOD(6), camera, &grid_pos, nullptr, nullptr);
    }

    /* older code. soon can be removed entirely
    draw("test.obj", camera, &first, nullptr, nullptr);

    model_pod junk;
    junk.vao_reference = buffers.getModelVAOReference("test_two");
    junk.texture_reference = 0;
    junk.index_offset_bytes = 1 * 36 * sizeof(unsigned int);
    junk.index_count = 36;
    junk.texture_name = "soils.png";
    junk.model_name = "test_two";
    draw(junk, camera, &second, nullptr, nullptr);

    model_pod junk3;
    junk3.vao_reference = buffers.getModelVAOReference("test_three");
    junk3.texture_reference = 0;
    junk3.index_offset_bytes = 2 * 36 * sizeof(unsigned int);
    junk3.index_count = 36;
    junk3.texture_name = "soils.png";
    junk3.model_name = "test_three";
    draw(junk3, camera, &third, nullptr, nullptr);

    model_pod junk4;
    junk4.vao_reference = buffers.getModelVAOReference("test_four");
    junk4.texture_reference = 0;
    junk4.index_offset_bytes = 0 * 36 * sizeof(unsigned int);
    junk4.index_count = 36;
    junk4.texture_name = "soils.png";
    junk4.model_name = "test_four";
    draw(junk4, camera, &fourth, nullptr, nullptr);
    */

    //interleaveDraw(camera);
    //arrayTextureDraw(camera);
}

void DrawEngine::setup()
{
    setupOpenGLContext();
    setupOpenGLObjects();
    setupOpenGLUniforms();
    setupObjects();
}

void DrawEngine::cleanup()
{
    texture_program.unUse();
    texture_program.destroy();

    test_texture.unbind();
    test_texture.destroy();
    main_textures.destroyTextures();

    buffers.destroyBuffers();
    interleaved_buffers.destroyBuffers();
    OGLHelpers::getOpenGLError("post cleanup", false);
}

//gets
int DrawEngine::getScreenWidth() const
{
    return screen_width;
}

int DrawEngine::getScreenHeight() const
{
    return screen_height;
}


//sets
void DrawEngine::setScreenWidth(int width)
{
    screen_width = width;
    resize();
}

void DrawEngine::setScreenHeight(int height)
{
    screen_height = height;
    resize();
}

void DrawEngine::setScreenWidthHeight(int width, int height)
{
    screen_width = width;
    screen_height = height;
    resize();
}

//private
void DrawEngine::draw(std::string model_name, const Camera &camera, const glm::vec3 *position, const glm::vec3 *rotate, const glm::vec3 *scale)
{
    unsigned int reference = models.getModelReference(model_name);
    if (reference > 0)
    {
        draw(models.getModelPOD(reference), camera, position, rotate, scale);
    }
    else
    {
        std::cout << "model named: " << model_name << " does not exist. From draw(model_name)\n";
    }
}

void DrawEngine::draw(const model_pod &model_info, const Camera &camera, const glm::vec3 *position, const glm::vec3 *rotate, const glm::vec3 *scale)
{
    OGLHelpers::getOpenGLError("pre draw", true);

    if (texture_program.getID() != state.program_id)
    {
        texture_program.use();
        state.program_id = texture_program.getID();
    }

    if (main_textures.getTextureID(model_info.texture_reference) != state.texture_id)
    {
        //std::cout << "binding textureid: " << main_textures.getTextureID(model_info.texture_reference) << "\n";
        main_textures.bindTexture(model_info.texture_reference);
        state.texture_id = main_textures.getTextureID(model_info.vao_reference);
    }

    if (interleaved_buffers.getVAOID(model_info.vao_reference) != state.vao_id)
    {
        //std::cout << "binding vaoID: " << buffers.getVAOID(model_info.vao_reference) << "\n";
        interleaved_buffers.bindVAO(model_info.vao_reference);
        state.vao_id = interleaved_buffers.getVAOID(model_info.vao_reference);
    }

    glm::mat4 view;
    camera.fillViewMatrix(view);

    glm::mat4 model;

    if (scale != nullptr)
    {
        model = glm::scale(model, *scale);
    }

    if (rotate != nullptr)
    {
        model = glm::rotate(model, rotate[0][1], Y_AXIS); //left right
        //model = glm::rotate(model, (*rotate)[1], Y_AXIS); //left right
        model = glm::rotate(model, rotate[0][0], X_AXIS); //up down
        model = glm::rotate(model, rotate[0][2], Z_AXIS); //rolling
    }

    if (position != nullptr)
    {
        model = glm::translate(model, *position);
    }

    glm::mat4 mvp = persp * view * model;
    glUniformMatrix4fv(texture_mvp_id, 1, false, glm::value_ptr(mvp));
    glDrawElements(GL_TRIANGLES, model_info.index_count, GL_UNSIGNED_INT, (void*)(model_info.index_offset_bytes));
    //uvVAO3D.getObjectIndexSize() * sizeof(unsigned int) * wanted_drawable;

    OGLHelpers::getOpenGLError("post draw", true);
}

void DrawEngine::setupOpenGLContext()
{
    //default OpenGL settings we use

    //glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
    glDepthRangef(0.0f, 1.0f);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    //glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    //glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
}

void DrawEngine::setupOpenGLObjects()
{
    //setup programs individually
    texture_program.setName("texture");
    //texture_program.create("2dtexturebasic.vert", "2dtexturebasic.frag");
    //texture_program.create("Texture2D.vert", "Texture2D.frag");
    texture_program.create("arrayTexture.vert", "arrayTexture.frag");
}

void DrawEngine::setupOpenGLUniforms()
{
    texture_mvp_id = glGetUniformLocation(texture_program.getID(), "MVP");
}

void DrawEngine::setupObjects()
{
    //arrayTextureAtlasTest();
    //bufferControlTest();
    //interleaveTest();
    //arrayTextureTest();

    loadTextures();
    properDrawTest();
    loadModels();
    loadTerrain();
}

void DrawEngine::loadTextures()
{
    std::vector<std::string> files;
    files.push_back("Textures\\bad.png");

    files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(DF_WHITE_SAND)));
    files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(DF_SILTY_CLAY_LOAM)));
    files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(DF_GABBRO)));
    files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(DF_WHITE_SAND)));

    files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(DF_DEMATOID)));
    files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(DF_TANZANITE)));
    files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(DF_GARNIERITE)));
    files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(DF_TETRAHEDRITE)));
    files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(DF_CHROMITE)));
    files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(DF_OLIVINE)));

    /*
    for (size_t i = 0; i < DF_NATURAL_TILE_COUNT; i++)
    {
        files.push_back(NaturalTile::DFMaterialFullPath(DF_Natural_Tile_Material(i)));
    }
    */

    array_texture.setTextureName("terrain.png");
    array_texture.loadImages(files);
    array_texture.createTexture();
    main_textures.addTexture(array_texture);

    state.texture_id = 0;
    array_texture.unbind(); //test binding
}

void DrawEngine::loadModels()
{
    ShapeToModel convert;
    NormalBox block, floor;

    std::string texture_name = "terrain.png";
    block.setWidthHeightLength(DF_BLOCK_WIDTH, DF_BLOCK_HEIGHT, DF_BLOCK_LENGTH);
    Point3D front, back, left, right, top, bottom;
    front.setXYZ(0, 1, 2);
    back.setXYZ(3, 4, 5);
    left.setXYZ(6, 7, 8);
    right.setXYZ(9, 10, 11);
    top.setXYZ(12, 13, 14);
    bottom.setXYZ(15, 16, 17);
    block.setNormal(front, back, left, right, top, bottom);

    floor.setWidthHeightLength(DF_FLOOR_WIDTH, DF_FLOOR_HEIGHT, DF_FLOOR_LENGTH);
    floor.setNormal(front, back, left, right, top, bottom);

    for (size_t i = 0; i < DF_NATURAL_TILE_COUNT; i++)
    {
        ModelIndex model; //model classes should not be reused
        block.setTextureNumber(main_textures.getTextureNumber(DFNaturalTileFilename(DF_Natural_Tile_Material(i))));
        convert.convertToModelIndex(block, model);
        model.setModelName(DFNaturalTileString(DF_Natural_Tile_Material(i)).append(" block"));
        model.setTextureName(texture_name);
        addInterleavedModel(model);
    }

    for (size_t i = 0; i < DF_NATURAL_TILE_COUNT; i++)
    {
        ModelIndex model; //model classes should not be reused
        floor.setTextureNumber(main_textures.getTextureNumber(DFNaturalTileFilename(DF_Natural_Tile_Material(i))));
        convert.convertToModelIndex(floor, model);
        model.setModelName(DFNaturalTileString(DF_Natural_Tile_Material(i)).append(" floor"));
        model.setTextureName(texture_name);
        addInterleavedModel(model);
    }
}

void DrawEngine::loadTerrain()
{
    ModelIndex terrain_model;
    NaturalTerrain terrain_test;
    terrain_model.setTextureName("terrain.png");
    terrain_model.setModelName("terrain");

    //terrain_test stuff here

    //terrain_3x3x3_test(terrain_test);
    terrain_16x16x16_test(terrain_test);
    //terrain_48x48x48_test(terrain_test);
    //terrain_test and not after here

    terrain.loadFromMemory(terrain_test, models, terrain_model);
    addInterleavedModel(terrain_model);

    //model_pod result = models.getModelPOD(models.getModelReference("terrain"));
    std::cout << "after terrain load\n";
}

void DrawEngine::terrain_3x3x3_test(NaturalTerrain& natural_terrain)
{
    const unsigned int width = 3;
    const unsigned int height = 3;
    const unsigned int length = 3;
    natural_terrain.setGridDimensions(width, height, length);
    natural_terrain.create(DF_DRAW_BLOCK, DF_DRAW_FLOOR, DF_GABBRO);

    natural_terrain.setLayerBlockMaterial(0, DF_SILTY_CLAY_LOAM);

    natural_terrain.setLayerFloorMaterial(0, DF_WHITE_SAND);
    natural_terrain.setLayerFloorMaterial(1, DF_WHITE_SAND);
    natural_terrain.setLayerFloorMaterial(2, DF_SILTY_CLAY_LOAM);
}

void DrawEngine::terrain_16x16x16_test(NaturalTerrain& natural_terrain)
{
    const unsigned int width = 16;
    const unsigned int height = 16;
    const unsigned int length = 16;
    natural_terrain.setGridDimensions(width, height, length);
    natural_terrain.create(DF_DRAW_BLOCK, DF_DRAW_FLOOR, DF_GABBRO);

    for (unsigned int i = 0; i < height; i++)
    {
        if (i % 2)
        {
            natural_terrain.setLayerBlockMaterial(i, DF_SILTY_CLAY_LOAM);
        }
        natural_terrain.setLayerFloorMaterial(i, DF_WHITE_SAND);
    }

    //natural_terrain.setLayerDrawType(3, DF_DRAW_AIR, DF_DRAW_FLOOR);
    //natural_terrain.setLayerDrawType(4, DF_DRAW_BLOCK, DF_DRAW_AIR);
    unsigned int first = 3 * 16;
    unsigned int next = Grid3DYOffset::getIndexRight(first, width, height, length);
    natural_terrain.setIndexDrawType(first, DF_DRAW_AIR, DF_DRAW_FLOOR);
    natural_terrain.setIndexMaterialAround(first, DF_DEMATOID, DF_GARNIERITE);

    natural_terrain.setIndexDrawType(next, DF_DRAW_AIR, DF_DRAW_FLOOR);
    natural_terrain.setIndexMaterialAround(next, DF_OLIVINE, DF_CHROMITE);

    next = Grid3DYOffset::getIndexRight(next, width, height, length);
    natural_terrain.setIndexDrawType(next, DF_DRAW_AIR, DF_DRAW_FLOOR);
    natural_terrain.setIndexMaterialAround(next, DF_OLIVINE, DF_CHROMITE);

    next = Grid3DYOffset::getIndexRight(next, width, height, length);
    natural_terrain.setIndexDrawType(next, DF_DRAW_AIR, DF_DRAW_FLOOR);
    natural_terrain.setIndexMaterialAround(next, DF_OLIVINE, DF_CHROMITE);

    next = Grid3DYOffset::getIndexRight(next, width, height, length);
    natural_terrain.setIndexDrawType(next, DF_DRAW_AIR, DF_DRAW_FLOOR);
    natural_terrain.setIndexMaterialAround(next, DF_OLIVINE, DF_CHROMITE);

    next = Grid3DYOffset::getIndexUp(next, width, height, length);
    natural_terrain.setIndexDrawType(next, DF_DRAW_AIR, DF_DRAW_AIR);
    natural_terrain.setIndexMaterialAround(next, DF_TANZANITE, DF_TETRAHEDRITE);

    next = Grid3DYOffset::getIndexUp(next, width, height, length);
    natural_terrain.setIndexDrawType(next, DF_DRAW_AIR, DF_DRAW_AIR);
    natural_terrain.setIndexMaterialAround(next, DF_TANZANITE, DF_TETRAHEDRITE);

    next = Grid3DYOffset::getIndexUp(next, width, height, length);
    natural_terrain.setIndexDrawType(next, DF_DRAW_AIR, DF_DRAW_AIR);
    natural_terrain.setIndexMaterialAround(next, DF_TANZANITE, DF_TETRAHEDRITE);

    next = Grid3DYOffset::getIndexBack(next, width, height, length);
    natural_terrain.setIndexDrawType(next, DF_DRAW_AIR, DF_DRAW_FLOOR);
    natural_terrain.setIndexMaterialAround(next, DF_TANZANITE, DF_TETRAHEDRITE);

    next = Grid3DYOffset::getIndexBack(next, width, height, length);
    natural_terrain.setIndexDrawType(next, DF_DRAW_AIR, DF_DRAW_FLOOR);
    natural_terrain.setIndexMaterialAround(next, DF_TANZANITE, DF_TETRAHEDRITE);

    next = Grid3DYOffset::getIndexBack(next, width, height, length);
    natural_terrain.setIndexDrawType(next, DF_DRAW_AIR, DF_DRAW_FLOOR);
    natural_terrain.setIndexMaterialAround(next, DF_TANZANITE, DF_TETRAHEDRITE);
}

void DrawEngine::terrain_48x48x48_test(NaturalTerrain & natural_terrain)
{
    const unsigned int width = 48;
    const unsigned int height = 48;
    const unsigned int length = 48;
    natural_terrain.setGridDimensions(width, height, length);
    natural_terrain.create(DF_DRAW_BLOCK, DF_DRAW_FLOOR, DF_GABBRO);

    for (unsigned int i = 0; i < height; i++)
    {
        if (i % 2)
        {
            natural_terrain.setLayerBlockMaterial(i, DF_SILTY_CLAY_LOAM);
        }
        natural_terrain.setLayerFloorMaterial(i, DF_WHITE_SAND);
    }

    natural_terrain.setLayerDrawType(3, DF_DRAW_AIR, DF_DRAW_FLOOR);
    natural_terrain.setLayerDrawType(4, DF_DRAW_BLOCK, DF_DRAW_AIR);
}

void DrawEngine::resize()
{
    calculateOrtho();
    calculatePersp();
}

void DrawEngine::calculateOrtho()
{
    float x_scale = float(game_width) / float(screen_width);
    float y_scale = float(game_height) / float(screen_height);

    float width = screen_width * x_scale;
    float height = screen_height * y_scale;

    ortho = glm::ortho(width * -0.5f, width * 0.5f, height * -0.5f, height * 0.5f, Z_NEAR, Z_FAR);
}

void DrawEngine::calculatePersp()
{
    persp = glm::perspectiveLH(glm::radians(60.0f), 4.0f / 3.0f, Z_NEAR, Z_FAR);
}
