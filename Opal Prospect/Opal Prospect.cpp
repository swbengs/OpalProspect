#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <chrono>

#include "MainLoop.hpp"

//test includes
#include "OpenGL\ArrayTexture.hpp"
#include "Shapes\NormalFace.hpp"
#include "Shapes\NormalBox.hpp"
#include "Shapes\ModelIndex.hpp"
#include "Shapes\ShapeToModel.hpp"
#include "Shapes\Point1D.hpp"
#include "Shapes\Point2D.hpp"
#include "Shapes\Point3D.hpp"
#include "Shapes\Point3DInt.hpp"
#include "Shapes\Point4D.hpp"
#include "Shapes\Grid3DYOffset.hpp"
#include "OpenGL\Image.hpp"

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

//put test functions here but before tests()
void texture_array_test()
{
    ArrayTexture t2x2;
    ArrayTexture t2x4;
    ArrayTexture t4x2;
    ArrayTexture t4x4;
    ArrayTexture bad;
    ArrayTexture terrain;
    ArrayTexture t6x15;
    ArrayTexture t15x5;

    std::vector<unsigned char> data_t2x2;
    std::vector<unsigned char> data_t2x4;
    std::vector<unsigned char> data_t4x2;
    std::vector<unsigned char> data_t4x4;
    std::vector<unsigned char> data_t6x15;
    std::vector<unsigned char> data_t15x5;

    t2x2.setFilename("test\\2x2test.png");
    t2x2.setTextureWidth(1);
    t2x2.setTextureHeight(1);
    t2x2.testLoading(data_t2x2);
    std::cout << "\n";

    t2x4.setFilename("test\\2x4test.png");
    t2x4.setTextureWidth(2);
    t2x4.setTextureHeight(2);
    t2x4.testLoading(data_t2x4);
    std::cout << "\n";

    t4x2.setFilename("test\\4x2test.png");
    t4x2.setTextureWidth(2);
    t4x2.setTextureHeight(2);
    t4x2.testLoading(data_t4x2);
    std::cout << "\n";

    t4x4.setFilename("test\\4x4test.png");
    t4x4.setTextureWidth(2);
    t4x4.setTextureHeight(2);
    t4x4.testLoading(data_t4x4);
    std::cout << "\n";

    bad.setFilename("bad.png");
    terrain.setFilename("soils.png");

    t6x15.setFilename("test\\6x15test.png");
    t6x15.setTextureWidth(3);
    t6x15.setTextureHeight(5);
    t6x15.testLoading(data_t6x15);
    std::cout << "\n";

    t15x5.setFilename("test\\15x5test.png");
    t15x5.setTextureWidth(3);
    t15x5.setTextureHeight(5);
    t15x5.testLoading(data_t15x5);
    std::cout << "\n";

    std::cout << "done\n";
}

void normalFaceTest()
{
    std::cout << "start \n";

    NormalFace test;
    Point3D bottom_left_vertex, bottom_right_vertex, top_left_vertex, top_right_vertex;
    Point3D bottom_left_uv, bottom_right_uv, top_left_uv, top_right_uv;
    Point3D bottom_left_normal, bottom_right_normal, top_left_normal, top_right_normal;

    test.setBottomLeftIndex(1);
    test.setBottomRightIndex(2);
    test.setTopLeftIndex(3);
    test.setTopRightIndex(4);

    bottom_left_vertex.setXYZ(1.0f, 2.0f, 3.0f);
    bottom_left_uv.setXYZ(4.0f, 5.0f, 6.0f);
    bottom_left_normal.setXYZ(7.0f, 8.0f, 9.0f);
    test.setBottomLeftNormal(bottom_left_normal);
    test.setBottomLeftUV(bottom_left_uv);
    test.setBottomLeftVertex(bottom_left_vertex);

    bottom_right_vertex.setXYZ(10.0f, 11.0f, 12.0f);
    bottom_right_uv.setXYZ(13.0f, 14.0f, 15.0f);
    bottom_right_normal.setXYZ(16.0f, 17.0f, 18.0f);
    test.setBottomRightNormal(bottom_right_normal);
    test.setBottomRightUV(bottom_right_uv);
    test.setBottomRightVertex(bottom_right_vertex);

    top_left_vertex.setXYZ(19.0f, 20.0f, 21.0f);
    top_left_uv.setXYZ(22.0f, 23.0f, 24.0f);
    top_left_normal.setXYZ(25.0f, 26.0f, 27.0f);
    test.setTopLeftNormal(top_left_normal);
    test.setTopLeftUV(top_left_uv);
    test.setTopLeftVertex(top_left_vertex);

    top_right_vertex.setXYZ(28.0f, 29.0f, 30.0f);
    top_right_uv.setXYZ(31.0f, 32.0f, 33.0f);
    top_right_normal.setXYZ(34.0f, 35.0f, 36.0f);
    test.setTopRightNormal(top_right_normal);
    test.setTopRightUV(top_right_uv);
    test.setTopRightVertex(top_right_vertex);

    bottom_left_vertex.setXYZ(1.0f + 36.0f, 2.0f + 36.0f, 3.0f + 36.0f);
    bottom_left_uv.setXYZ(4.0f + 36.0f, 5.0f + 36.0f, 6.0f + 36.0f);
    bottom_left_normal.setXYZ(7.0f + 36.0f, 8.0f + 36.0f, 9.0f + 36.0f);
    bottom_right_vertex.setXYZ(10.0f + 36.0f, 11.0f + 36.0f, 12.0f + 36.0f);
    bottom_right_uv.setXYZ(13.0f + 36.0f, 14.0f + 36.0f, 15.0f + 36.0f);
    bottom_right_normal.setXYZ(16.0f + 36.0f, 17.0f + 36.0f, 18.0f + 36.0f);
    top_left_vertex.setXYZ(19.0f + 36.0f, 20.0f + 36.0f, 21.0f + 36.0f);
    top_left_uv.setXYZ(22.0f + 36.0f, 23.0f + 36.0f, 24.0f + 36.0f);
    top_left_normal.setXYZ(25.0f + 36.0f, 26.0f + 36.0f, 27.0f + 36.0f);
    top_right_vertex.setXYZ(28.0f + 36.0f, 29.0f + 36.0f, 30.0f + 36.0f);
    top_right_uv.setXYZ(31.0f + 36.0f, 32.0f + 36.0f, 33.0f + 36.0f);
    top_right_normal.setXYZ(34.0f + 36.0f, 35.0f + 36.0f, 36.0f + 36.0f);

    test.setIndex(5, 6, 7, 8);
    test.setVertex(bottom_left_vertex, bottom_right_vertex, top_left_vertex, top_right_vertex);
    test.setUV(bottom_left_uv, bottom_right_uv, top_left_uv, top_right_uv);
    test.setNormal(bottom_left_normal, bottom_right_normal, top_left_normal, top_right_normal);
    std::cout << "done \n \n";
}

void shapeToModelTest()
{
    std::cout << "start \n";

    ShapeToModel convert;
    ModelIndex model;
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

    box.setFrontTextureNumber(100);
    box.setBackTextureNumber(101);
    box.setLeftTextureNumber(102);
    box.setRightTextureNumber(103);
    box.setTopTextureNumber(104);
    box.setBottomTextureNumber(105);
    //box.setTextureNumber(255);
    box.setWidthHeightLength(1.0f, 1.0f, 1.0f);
    box.setNormal(front, back, left, right, top, bottom);

    convert.convertToModelIndex(box, model);

    std::cout << "done \n \n";
}

void trivialTests()
{
    std::cout << std::boolalpha; //bools show true or false not 1 or 0

    std::cout << "is Point1D trivial: " << std::is_trivial<Point1D>::value << "\n";
    std::cout << "is Point2D trivial: " << std::is_trivial<Point2D>::value << "\n";
    std::cout << "is Point3D trivial: " << std::is_trivial<Point3D>::value << "\n";
    std::cout << "is Point3DInt trivial: " << std::is_trivial<Point3DInt>::value << "\n";
    std::cout << "is Point4D trivial: " << std::is_trivial<Point4D>::value << "\n";
    std::cout << "\n\n";
}

void podTest()
{
    std::cout << std::boolalpha; //bools show true or false not 1 or 0

    std::cout << "is Point1D a pod: " << std::is_pod<Point1D>::value << "\n";
    std::cout << "is Point2D a pod: " << std::is_pod<Point2D>::value << "\n";
    std::cout << "is Point3D a pod: " << std::is_pod<Point3D>::value << "\n";
    std::cout << "is Point3DInt a pod: " << std::is_pod<Point3DInt>::value << "\n";
    std::cout << "is Point4D a pod: " << std::is_pod<Point4D>::value << "\n";
    std::cout << "\n\n";
}

void pointConversion()
{
    Point3D point3;
    Point4D point4;

    point3.setXYZ(1.0f, 2.0f, 3.0f);
    point4.setXYZW(0.0f, 0.0f, 0.0f, 4.0f);

    point4.setXYZW(point3, 5.0f);
    std::cout << "\n";
}

void offest_grid_test()
{
    Grid3DYOffset grid;

    unsigned int grid_width = 3;
    unsigned int grid_height = 2;
    unsigned int grid_length = 3;
    float offset = 100.0f;
    float box_width = 1.0f;
    float box_height = 1.0f;
    float box_length = 1.0f;

    grid.setGridWidthLengthHeight(grid_width, grid_height, grid_length);
    grid.setYOffset(offset);
    grid.setBoxWidthLengthHeight(box_width, box_height, box_length);

    grid.create();

    std::cout << "Done\n";
}

void image_test()
{
    Image test;
    test.setFilePath("test.png");
    std::cout << "filename: " << test.getFilename() << "\n";

    test.setFilePath("C:\\test.png");
    std::cout << "filename: " << test.getFilename() << "\n";

    test.setFilePath("C:\\junk\\a.png");
    std::cout << "filename: " << test.getFilename() << "\n";
}

void tests()
{
    //texture_array_test();
    //normalFaceTest();
    //shapeToModelTest();
    //trivialTests();
    //podTest();
    //pointConversion();
    //offest_grid_test();
    image_test();
}

int main(void)
{
    MainLoop loop;
    //loop.startLoop();
    tests();

    exit(EXIT_SUCCESS);
}

