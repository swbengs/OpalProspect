#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <chrono>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <sstream>
#if defined(WIN32) || defined(_WIN32)
#include <Windows.h>
#include <WinBase.h>
#endif

#include "MainLoop.hpp"
#include "BasicLog.hpp"
#include "zlib.h"

//test includes
#include "OpenGL\ArrayTextureAtlas.hpp"
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
#include "OpenGL\ArrayTexture.hpp"
#include "DwarfFortress\natural_tiles.hpp"
#include "DwarfFortress\NaturalTerrainModelBuilder.hpp"
#include "Shapes\VoxelGrid.hpp"
#include "Huffman.hpp"

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

std::string outputBool(bool boo)
{
    if (boo)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

void offset_grid_test_index(unsigned int index, unsigned int width, unsigned int height, unsigned int length)
{
    std::cout << "index " << index << " is bottom: " << outputBool(Grid3DYOffset::isBottomSide(index, width, height, length)) << "\n";
    std::cout << "index " << index << " is top: " << outputBool(Grid3DYOffset::isTopSide(index, width, height, length)) << "\n";
    std::cout << "index " << index << " is left: " << outputBool(Grid3DYOffset::isLeftSide(index, width, height, length)) << "\n";
    std::cout << "index " << index << " is right: " << outputBool(Grid3DYOffset::isRightSide(index, width, height, length)) << "\n";
    std::cout << "index " << index << " is front: " << outputBool(Grid3DYOffset::isFrontSide(index, width, height, length)) << "\n";
    std::cout << "index " << index << " is back: " << outputBool(Grid3DYOffset::isBackSide(index, width, height, length)) << "\n";
    std::cout << "\n";
    std::cout << "index " << index << " move left: " << Grid3DYOffset::getIndexLeft(index, width, height, length) << "\n";
    std::cout << "index " << index << " move right: " << Grid3DYOffset::getIndexRight(index, width, height, length) << "\n";
    std::cout << "index " << index << " move back: " << Grid3DYOffset::getIndexBack(index, width, height, length) << "\n";
    std::cout << "index " << index << " move forward: " << Grid3DYOffset::getIndexFront(index, width, height, length) << "\n";
    std::cout << "index " << index << " move down: " << Grid3DYOffset::getIndexDown(index, width, height, length) << "\n";
    std::cout << "index " << index << " move up: " << Grid3DYOffset::getIndexUp(index, width, height, length) << "\n";
    std::cout << "\n";
}

//put test functions here but before tests()
void texture_array_test()
{
    ArrayTextureAtlas t2x2;
    ArrayTextureAtlas t2x4;
    ArrayTextureAtlas t4x2;
    ArrayTextureAtlas t4x4;
    ArrayTextureAtlas bad;
    ArrayTextureAtlas terrain;
    ArrayTextureAtlas t6x15;
    ArrayTextureAtlas t15x5;

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

    test.setFilePath("Textures\\soils.png");
    test.loadImage();
    std::cout << "filename: " << test.getFilename() << "\n";
}

void array_texture_test()
{
    ArrayTexture test;
    std::vector<std::string> files;
    test.loadImages(files);

    files.push_back("Textures\\singles\\soils\\white sand 16.png");
    files.push_back("Textures\\singles\\soils\\silty clay loam 16.png");
    test.loadImages(files);

    std::cout << "done\n";
}

void df_natural_tile_enum_test()
{
    //can easily see the string, filename, and enum number for each tile in one place. Easy to check for errors
    DF_Natural_Tile_Material tile;

    for (int i = 0; i < DF_NATURAL_TILE_COUNT; i++)
    {
        tile = static_cast<DF_Natural_Tile_Material>(i);
        std::cout << "\n";
        std::cout << "enum: " << tile << "\n";
        std::cout << "name: " << DFNaturalTileString(tile) << "\n";
        std::cout << "file: " << DFNaturalTileFilename(tile) << "\n";\
        std::cout << "\n";
    }
}

void offset_grid_3x3_test()
{
    /* single layer
    6 7 8
    3 4 5
    0 1 2
    */
    Grid3DYOffset grid;

    unsigned int grid_width = 3;
    unsigned int grid_height = 3;
    unsigned int grid_length = 3;
    float offset = 0.0f;
    float stride = 0.0f;
    float box_width = 1.0f;
    float box_height = 1.0f;
    float box_length = 1.0f;
    unsigned int index;

    grid.setGridWidthLengthHeight(grid_width, grid_height, grid_length);
    grid.setYOffset(offset);
    grid.setYStride(stride);
    grid.setBoxWidthLengthHeight(box_width, box_height, box_length);

    grid.create();

    index = 0;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 8;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 9; //start of mid
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 17; //end of mid
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 18; //start of top row
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 26; //end of top row
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 13; //middle
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    std::cout << "Done\n";
}

void offset_grid_5x3x4_test()
{
    /* single layer
    15 16 17 18 19
    10 11 12 13 14
    5  6  7  8  9
    0  1  2  3  4
    */
    Grid3DYOffset grid;

    unsigned int grid_width = 5;
    unsigned int grid_height = 3;
    unsigned int grid_length = 4;
    float offset = 0.0f;
    float stride = 0.0f;
    float box_width = 1.0f;
    float box_height = 1.0f;
    float box_length = 1.0f;
    unsigned int index;

    grid.setGridWidthLengthHeight(grid_width, grid_height, grid_length);
    grid.setYOffset(offset);
    grid.setYStride(stride);
    grid.setBoxWidthLengthHeight(box_width, box_height, box_length);

    grid.create();

    index = 0;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 4;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 10;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 14;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 45;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 49;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 54;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 59;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 27;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    std::cout << "Done\n";
}

void offset_grid_3x2x4_test()
{
    /* single layer
    9 10 11
    6 7  8
    3 4  5
    0 1  2
    */
    Grid3DYOffset grid;

    unsigned int grid_width = 3;
    unsigned int grid_height = 2;
    unsigned int grid_length = 4;
    float offset = 0.0f;
    float stride = 0.0f;
    float box_width = 1.0f;
    float box_height = 1.0f;
    float box_length = 1.0f;
    unsigned int index;

    grid.setGridWidthLengthHeight(grid_width, grid_height, grid_length);
    grid.setYOffset(offset);
    grid.setYStride(stride);
    grid.setBoxWidthLengthHeight(box_width, box_height, box_length);

    grid.create();

    index = 0;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 2;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 9;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 11;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 12;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 13;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 21;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    index = 23;
    offset_grid_test_index(index, grid_width, grid_height, grid_length);

    //index = 100;
    //offset_grid_test_index(index, grid_width, grid_height, grid_length);

    std::cout << "Done\n";
}

void offset_grid_5x5x5_test()
{
    /* single layer
    20 21 22 23 24
    15 16 17 18 19
    10 11 12 13 14
    5  6  7  8  9
    0  1  2  3  4
    */
    Grid3DYOffset grid;

    unsigned int grid_width = 5;
    unsigned int grid_height = 5;
    unsigned int grid_length = 5;
    float offset = 0.0f;
    float stride = 0.0f;
    float box_width = 1.0f;
    float box_height = 1.0f;
    float box_length = 1.0f;
    unsigned int index;

    grid.setGridWidthLengthHeight(grid_width, grid_height, grid_length);
    grid.setYOffset(offset);
    grid.setYStride(stride);
    grid.setBoxWidthLengthHeight(box_width, box_height, box_length);

    grid.create();

    for (index = 0; index < grid_width * grid_height * grid_length; index++)
    {
        offset_grid_test_index(index, grid_width, grid_height, grid_length);
    }
}

void offset_grid_extreme_test()
{
    //300 deep 5x5 embark test
    const unsigned int embark_width = 5;
    const unsigned int embark_length = 5;
    const unsigned int embark_tile_width = 48 * embark_width ;
    const unsigned int embark_tile_length = 48 * embark_length;
    const unsigned int embark_height = 300;

    Grid3DYOffset grid;
    grid.setYOffset(0.0f);
    grid.setYStride(0.0f);
    grid.setBoxWidthLengthHeight(1.0f, 1.0f, 1.0f);
    grid.setGridWidthLengthHeight(embark_tile_width, embark_height, embark_tile_length);
    grid.create();

    std::cout << "extreme grid test done\n";
}

void natural_terrain_build_test()
{
    NaturalTerrain test;
    NaturalTerrainModelBuilder builder;
    const unsigned int width = 3;
    const unsigned int height = 3;
    const unsigned int length = 3;
    test.setGridDimensions(width, height, length);
    test.create(DF_DRAW_BLOCK, DF_RAW_ADAMANTINE);
    //test.create();

    //test.setLayerDrawType(1, DF_DRAW_AIR);

    builder.debugLoadFromMemory(test);

    std::cout << "natural terrain builder test done\n";
}

void log_test()
{
    auto old_error = std::cerr.rdbuf();
    auto old_log = std::clog.rdbuf();

    std::ofstream error("error.txt");
    std::ofstream log("log.txt");

    std::cerr.rdbuf(error.rdbuf());
    std::clog.rdbuf(log.rdbuf());

    std::cerr << "test 10\n";
    std::clog << "test 20\n";

    std::cerr.rdbuf(old_error);
    std::clog.rdbuf(old_log);
}

void get_digits_test()
{
    unsigned int max_digits = 0;
    const unsigned int layer_count = 10 * 90000 + 1;
    double layer_count_double = static_cast<double>(layer_count); //need to do double math to check for how many digits we should make

    do
    {
        max_digits++;
        layer_count_double /= 10.0;
    } while (layer_count_double > 1.0);

    std::cout << "digit test end\n";
}

void parse_test()
{
    std::string rle = "1000y251d25q1w";

    size_t max_digits = 4;
    std::string single;
    single.resize(max_digits + 1);

    unsigned int single_index = 0;
    for (size_t i = 0; i < rle.size(); i++)
    {
        if (isdigit(rle[i]))
        {
            single[single_index] = rle[i];
            single_index++;
            if (single_index > max_digits)
            {
                std::cout << "number: " << single_index << " exceeds digit max: " << max_digits << "\n";
                return;
            }
        }
        else //add single character, the non number one and seperate the number and character
        {
            single[single_index] = rle[i];
            single_index = 0;
            char* end;
            unsigned long number_long = strtoul(single.data(), &end, 10);
            unsigned int number = static_cast<unsigned int>(number_long);
            unsigned char c = *end;

            std::cout << "number: " << number << "\n";
            std::cout << "character: " << c << "\n";

            if (number == 0)
            {
                std::cout << "rle number is 0. Should be at least 1\n";
                return;
            }

            //reset single
            for (size_t n = 0; n < single.size(); n++)
            {
                single[n] = '\0';
            }
        }
    }
}

void voxel_grid_test()
{
    Grid3DYOffset base_grid;
    VoxelGrid voxel_grid;

    unsigned int test_index = 26;

    unsigned int grid_width = 3;
    unsigned int grid_height = 3;
    unsigned int grid_length = 3;
    float offset = 1.0f;
    float stride = 2.0f;
    float box_width = 1.0f;
    float box_height = 1.0f;
    float box_length = 1.0f;

    base_grid.setGridWidthLengthHeight(grid_width, grid_height, grid_length);
    base_grid.setYOffset(offset);
    base_grid.setYStride(stride);
    base_grid.setBoxWidthLengthHeight(box_width, box_height, box_length);
    base_grid.create();

    voxel_grid.setBoxWidthLengthHeight(box_width, box_height, box_length);
    voxel_grid.setGridWidthLengthHeight(grid_width, grid_height, grid_length);
    voxel_grid.setYOffset(offset);
    voxel_grid.setYStride(stride);

    CenterBox box = base_grid.getBox(test_index);
    Point3D point = voxel_grid.getPosition(test_index);

    std::cout << "box x y z:  " << box.getX() << "  " << box.getY() << "  " << box.getZ() << "\n";
    std::cout << "point x y z:  " << point.x << "  " << point.y << "  " << point.z << "\n";

    if (box.getX() == point.x && box.getY() == point.y && box.getZ() == point.z)
    {
        std::cout << "test index: " << test_index << " passed\n";
    }
    else
    {
        std::cout << "test index: " << test_index << " failed\n";
    }

    std::cout << "Done\n";
}

void voxel_grid_test(unsigned int width, unsigned int height, unsigned int length, float offset, float stride)
{
    Grid3DYOffset base_grid;
    VoxelGrid voxel_grid;

    unsigned int grid_width = width;
    unsigned int grid_height = height;
    unsigned int grid_length = length;
    float box_width = 1.0f;
    float box_height = 1.0f;
    float box_length = 1.0f;

    base_grid.setGridWidthLengthHeight(grid_width, grid_height, grid_length);
    base_grid.setYOffset(offset);
    base_grid.setYStride(stride);
    base_grid.setBoxWidthLengthHeight(box_width, box_height, box_length);
    base_grid.create();

    voxel_grid.setBoxWidthLengthHeight(box_width, box_height, box_length);
    voxel_grid.setGridWidthLengthHeight(grid_width, grid_height, grid_length);
    voxel_grid.setYOffset(offset);
    voxel_grid.setYStride(stride);

    for (size_t i = 0; i < base_grid.getGridCount(); i++)
    {
        CenterBox box = base_grid.getBox(i);
        Point3D point = voxel_grid.getPosition(i);

        if (box.getX() == point.x && box.getY() == point.y && box.getZ() == point.z)
        {
            std::cout << "test index: " << i << " passed\n";
        }
        else
        {
            std::cout << "test index: " << i << " failed\n";
            std::cout << "box x y z:  " << box.getX() << "  " << box.getY() << "  " << box.getZ() << "\n";
            std::cout << "point x y z:  " << point.x << "  " << point.y << "  " << point.z << "\n";
        }
    }

    

    std::cout << "Done\n";
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
    //image_test();
    //array_texture_test();
    //df_natural_tile_enum_test();
    //offset_grid_3x3_test();
    //offset_grid_5x3x4_test();
    //offset_grid_3x2x4_test();
    //offset_grid_5x5x5_test();
    //offset_grid_extreme_test();
    //natural_terrain_test();
    //natural_terrain_build_test();
    //log_test();
    //get_digits_test();
    //parse_test();
    voxel_grid_test(5,4,9, 1.0f, 0.2f);
}

void hoffman(std::string filename)
{
    //Create hash map that has the char and the frequency of it and fill them in from the file
    Huffman huffman;
    std::stringstream stream;
    std::vector<char> characters;
    std::vector<int> freqs;
    std::unordered_map<char, int> frequencies;
    std::ifstream file;
    file.open(filename);

    std::istream_iterator<char> end;
    std::istream_iterator<char> iter = std::istream_iterator<char>(file);
    for (; iter != end; iter++)
    {
        stream << *iter;
        auto search = frequencies.find(*iter);
        if (search != frequencies.end()) //found
        {
            search->second++;
        }
        else
        {
            frequencies[*iter] = 1;
        }
    }
    file.close();

    //print out the frequencies and fill in the two arrays
    for (auto it = frequencies.begin(); it != frequencies.end(); it++)
    {
        std::cout << it->first << ": " << it->second << "\n";
        characters.push_back(it->first);
        freqs.push_back(it->second);
    }
    std::cout << "\n";

    //make the codes
    huffman.generateHuffmanCodes(characters.data(), freqs.data(), characters.size());
    auto codes = huffman.getCodeMap(); // hashmap of all the huffman codes

    //print them out
    for (auto it = codes.begin(); it != codes.end(); it++)
    {
        std::cout << it->first << ": " << it->second << "\n";
    }
    std::cout << "\n";

    //finally print out the entire RLE string as this bit code instead of ascii
    std::stringstream output_stream;
    std::string input = stream.str();
    for (unsigned int i = 0; i < input.size(); i++)
    {
        output_stream << codes[input[i]];
    }
    std::string output = output_stream.str();
    std::cout << "\n";
    std::cout << output;

    //divide the total size by 8 to find number of bytes it would take up
    std::cout << "\n";
    std::cout << "Size in bytes of RLE string: " << input.size() << "\n";
    std::cout << "Size in bytes of hoffman codes: " << output.size() / 8 << "\n";
}

void zlib(std::string filename)
{
    FILE* infile = nullptr;
    fopen_s(&infile, filename.c_str(), "rb");
    gzFile outfile = gzopen("zlib_comp.txt", "wb");

    char inbuffer[128];
    unsigned int num_read = 0;
    while ((num_read = fread(inbuffer, 1, sizeof(inbuffer), infile)) > 0)
    {
        gzwrite(outfile, inbuffer, num_read);
    }

    fclose(infile);
    gzclose(outfile);
}

int main(int argc, char* argv[])
{
    MainLoop loop;
    std::string terrain_filename;

    /*
    Need to get exe CWD but this will change how things must be done. C++11 has no cross platform way of doing this. Also means that Debug and Release
    folders must be kept up to date with the main directory. The exe in those folders will grab from their folders as well. So any change to a DLL, png, 
    .vert/.frag and so on need to be moved there.

    If opal is run from a .cmd file and so on, it instead gets the CWD of where said batch/command/script file is and not where opal prospect.exe is.
    Need to figure out where to place this cwd so everytime a filename is generated it can grab it. ALL file loading must use this or they will break depending
    on where opal is run from.

    Thinking all file loading should use FilePath and it can have a static CWD that contains the exe path
    */

#if defined(WIN32) || defined(_WIN32)
    wchar_t buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    FilePath temp_path;
    char c_buffer[MAX_PATH * 2]; //wchar is 16 bit so double the max path size

    size_t count = 0;
    size_t result = wcstombs_s(&count, c_buffer, buffer, sizeof(c_buffer));
    if (result != 0)
    {
        std::cout << "Error occured while converting CWD\n";
        if (result == EINVAL)
        {
            std::cout << "null was passed in\n";
        }
        else if (result == ERANGE)
        {
            std::cout << "too large to fit in given char[]\n";
        }
        else if (result == EILSEQ)
        {
            std::cout << "couldn't convert a character\n";
        }
        else if (result == STRUNCATE)
        {
            std::cout << "was truncated\n";
        }
    }
    //std::cout << c_buffer << "\n";
    temp_path.setFullPath(std::string(c_buffer)); //make temp string and pass it in
    FilePath::setCWD(temp_path.getPathOnly());
    //std::cout << "path: " << temp_path.getPath() << "\n";
#endif

    std::cout << "exe cwd: " << FilePath::getCWD() << "\n\n";
    //FilePath test;
    //test.setRelativePath("test.txt");
    //std::cout << "test path: " << test.getPath() << "\n";
    //std::cout << "test filename: " << test.getFilename() << "\n";

    if (argc == 2)
    {
        terrain_filename = argv[1];
    }
    else if (argc == 3)
    {
        std::string arg1 = argv[1]; //command
        std::string arg2 = argv[2]; //filename
        if (arg1.compare("-hoffman") == 0)
        {
            //compress the file with hoffman encoding
            hoffman(arg2);
            exit(EXIT_SUCCESS);
        }
        else if (arg1.compare("-zlib") == 0)
        {
            //compress the file with zlib deflate
            zlib(arg2);
            exit(EXIT_SUCCESS);
        }
        else
        {
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        terrain_filename = "";
    }

    loop.startLoop(terrain_filename);
    //tests();

    exit(EXIT_SUCCESS);
}

