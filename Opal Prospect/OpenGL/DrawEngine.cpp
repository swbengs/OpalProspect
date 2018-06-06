#include "DrawEngine.hpp"

#include <iostream>
#include <array>

#include "GL\glew.h"
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
    //Point3D front, back, left, right, top, bottom;
    //front.setXYZ(0, 0, 0);
    //box.setNormal(front, back, left, right, top, bottom);
    
    convert.convertToModelIndex(box, test_model);
    test_model.setModelName("test.obj");
    test_model.setTextureName(texture_name);

    OGLHelpers::getOpenGLError("pre model add", true);
    addModel(test_model);
    OGLHelpers::getOpenGLError("post model add", true);

    ModelIndex mod2, mod3, mod4;
    box.setTextureNumber(10);
    convert.convertToModelIndex(box, mod2);
    mod2.setModelName("test_two");
    mod2.setTextureName(texture_name);
    addModel(mod2);

    box.setTextureNumber(11);
    convert.convertToModelIndex(box, mod3);
    mod3.setModelName("test_three");
    mod3.setTextureName(texture_name);
    addModel(mod3);

    box.setTextureNumber(12);
    convert.convertToModelIndex(box, mod4);
    mod4.setModelName("test_four");
    mod4.setTextureName(texture_name);
    addModel(mod4);

    std::cout << "\n";
}

void DrawEngine::arrayTextureTest()
{
    //flight_cam.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

    OGLHelpers::getOpenGLError("pre array texture creation");

    test_texture.setFilename("soils.png");
    test_texture.setTextureWidth(16);
    test_texture.setTextureHeight(16);
    test_texture.createTexture();

    OGLHelpers::getOpenGLError("post array texture creation");
    std::cout << "\n";

    ShapeToModel convert;
    NormalBox box;
    Point3D front, back, left, right, top, bottom;

    float offset = 1.0f;
    front.setXYZ(offset, offset + 1.0f, offset + 2.0f);
    offset += 3.0f;
    back.setXYZ(offset, offset + 1.0f, offset + 2.0f);
    offset += 3.0f;
    left.setXYZ(offset, offset + 1.0f, offset + 2.0f);
    offset += 3.0f;
    right.setXYZ(offset, offset + 1.0f, offset + 2.0f);
    offset += 3.0f;
    top.setXYZ(offset, offset + 1.0f, offset + 2.0f);
    offset += 3.0f;
    bottom.setXYZ(offset, offset + 1.0f, offset + 2.0f);

    /*
    box.setFrontTextureNumber(240);
    box.setBackTextureNumber(241);
    box.setLeftTextureNumber(242);
    box.setRightTextureNumber(243);
    box.setTopTextureNumber(244);
    box.setBottomTextureNumber(245);
    */

    box.setFrontTextureNumber(248);
    box.setBackTextureNumber(241);
    box.setLeftTextureNumber(242);
    box.setRightTextureNumber(243);
    box.setTopTextureNumber(244);
    box.setBottomTextureNumber(245);
    //box.setTextureNumber(240);
    //box.setTextureNumber(248);
    box.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    box.setNormal(front, back, left, right, top, bottom);

    test_model.setIndexOffset(0);
    convert.convertToModelIndex(box, test_model);

    OGLHelpers::getOpenGLError("pre vao creation");

    //array texture size
    uvVAO3D.setObjectCount(1);
    uvVAO3D.setObjectVertexSize(96);
    uvVAO3D.setObjectUVSize(72);
    uvVAO3D.setObjectIndexSize(36);
    uvVAO3D.create();

    OGLHelpers::getOpenGLError("post vao creation");

    //model uploads
    std::vector<float> vertex;
    std::vector<float> uv;
    std::vector<unsigned int> index;

    test_model.fillVertex(vertex);
    test_model.fillUV(uv);
    test_model.fillIndex(index);

    OGLHelpers::getOpenGLError("pre buffering");

    uvVAO3D.bindVertex();
    uvVAO3D.bufferVertex(0, vertex);

    uvVAO3D.bindUV();
    uvVAO3D.bufferUV(0, uv);

    uvVAO3D.bindIndex();
    uvVAO3D.bufferIndex(0, index);

    OGLHelpers::getOpenGLError("post buffering");

    std::cout << "done \n";
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

void DrawEngine::addTexture(const ArrayTexture& texture)
{
    textures.addTexture(texture);
}

void DrawEngine::draw(const Camera &camera)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::vec3 first = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 second = glm::vec3(3.0f, 0.0f, 0.0f);
    glm::vec3 third = glm::vec3(0.0f, 3.0f, 0.0f);
    glm::vec3 fourth = glm::vec3(3.0f, 3.0f, 0.0f);

    draw("test.obj", camera, &first, nullptr, nullptr);
    //draw(models.getModelPOD(1), camera, &first, nullptr, nullptr);
    draw(models.getModelPOD(2), camera, &second, nullptr, nullptr);
    draw(models.getModelPOD(3), camera, &third, nullptr, nullptr);
    draw(models.getModelPOD(4), camera, &fourth, nullptr, nullptr);
    //draw("error", camera, &first, nullptr, nullptr);

    /*
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

    uvVAO.unBind();
    uvVAO.destroy();
    uvVAO3D.unBind();
    uvVAO3D.destroy();

    test_texture.unbind();
    test_texture.destroy();

    if (atlas.getSize() > 0) //if at least one texture was created, unbind any that are currently bound and then proceed to delete them all
    {
        atlas.modifyAtlas(0).unbind();
    }

    for (unsigned int n = 0; n < atlas.getSize(); n++)
    {
        atlas.modifyAtlas(n).destroy();
    }

    buffers.destroyBuffers();
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

    if (test_texture.getID() != state.texture_id)
    {
        test_texture.bind();
        state.texture_id = test_texture.getID();
    }

    if (buffers.getVAOID(model_info.vao_reference) != state.vao_id)
    {
        //std::cout << "binding vaoID " << buffers.getVAOID(model_info.vao_reference) << "\n";
        buffers.bindVAO(model_info.vao_reference);
        state.vao_id = buffers.getVAOID(model_info.vao_reference);
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
    //glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
    glDepthRangef(0.0f, 1.0f);

    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
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

    atlas.setIndexSize(24);

    //setup textures
    TextureAtlas text;
    text.setFilename("bad.png");
    //text.createTexture();
    OGLHelpers::getOpenGLError("post texture create", true);

    text.setRectangleWidth(16);
    text.setRectangleHeight(16);
    //text.generateAtlas();

    atlas.addAtlas(text);

    text.setFilename("soils.png");
    //text.createTexture();
    OGLHelpers::getOpenGLError("post texture create2", true);

    text.setRectangleWidth(16);
    text.setRectangleHeight(16);
    //text.generateAtlas();

    //atlas.addAtlas(text);
    /*
    int uv_total_size = 0;

    for (unsigned int n = 0; n < atlas.getSize(); n++)
    {
        uv_total_size += atlas.getAtlas(n).getAtlasSize();
    }
    */
    //setup VAO, VBO
    /*
    uvVAO.setObjectCount(uv_total_size);
    uvVAO.setObjectVertexSize(16);
    uvVAO.setObjectUVSize(8);
    uvVAO.setObjectIndexSize(6);
    uvVAO.create();
    getError("post vao1 create");
    */

    OGLHelpers::getOpenGLError("post vao2 create"), true;
}

void DrawEngine::setupOpenGLUniforms()
{
    texture_mvp_id = glGetUniformLocation(texture_program.getID(), "MVP");
}

void DrawEngine::setupObjects()
{
    std::array<float, 16> vertex;
    std::array<float, 8> uv;
    //std::array<float, 16> color;
    std::array<unsigned int, 6> index;
    int total;

    uvVAO.bind();

    uvVAO.bindVertex();
    total = 0;
    for (unsigned int n = 0; n < atlas.getSize(); n++)
    {
        atlas.getAtlas(n).getVertexRectangle().fillVertexIndexed(vertex); //the vertex are all the same for each rectangle in an atlas
        for (int m = 0; m < atlas.getAtlas(n).getAtlasSize(); m++)
        {
            //uvVAO.bufferVertex(total, vertex.size(), vertex.data());
            total++;
        }
    }

    uvVAO.bindUV();
    total = 0;
    for (unsigned int n = 0; n < atlas.getSize(); n++)
    {
        for (int m = 0; m < atlas.getAtlas(n).getAtlasSize(); m++)
        {
            atlas.getAtlas(n).fillUVIndexedRectangle(m, uv);
            //uvVAO.bufferUV(total, uv.size(), uv.data());
            total++;
        }
    }

    uvVAO.bindIndex();
    for (int n = 0; n < uvVAO.getObjectCount(); n++)
    {
        atlas.getAtlas(0).getVertexRectangle().fillIndex(n, index);
        //uvVAO.bufferIndex(n, index.size(), index.data());
    }

    //arrayTextureTest();
    bufferControlTest();
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
