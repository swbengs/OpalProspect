//class header
#include "NaturalTerrain.hpp"

//std lib includes
#include <assert.h>

//other includes
#include "df_constants.hpp"

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

//class code

NaturalTerrain::NaturalTerrain()
{
    //setup the boxes within the grids. Don't create or set the # of them yet
    block_grid.setBoxWidthLengthHeight(DF_BLOCK_WIDTH, DF_BLOCK_HEIGHT, DF_BLOCK_LENGTH);
    block_grid.setYOffset(DF_FLOOR_HEIGHT);
    block_grid.setYStride(DF_FLOOR_HEIGHT);

    floor_grid.setBoxWidthLengthHeight(DF_FLOOR_WIDTH, DF_FLOOR_HEIGHT, DF_FLOOR_LENGTH);
    floor_grid.setYOffset(0.0f);
    floor_grid.setYStride(DF_BLOCK_HEIGHT);
}

void NaturalTerrain::create()
{
    block_grid.create();
    floor_grid.create();
    const size_t count = block_grid.getGridCount();
    blocks.resize(count);
    const NaturalTile floor(DF_DRAW_FLOOR, DF_ALEXANDRITE);
    floors.resize(count, floor);
}

void NaturalTerrain::create(DF_Draw_Tile_Type block_draw_type, DF_Draw_Tile_Type floor_draw_type, DF_Natural_Tile_Material material)
{
    block_grid.create();
    floor_grid.create();
    const size_t count = block_grid.getGridCount();
    const NaturalTile block(block_draw_type, material);
    const NaturalTile floor(floor_draw_type, material);
    blocks.resize(count, block);
    floors.resize(count, floor);
}

NaturalTile NaturalTerrain::getBlock(unsigned int index) const
{
    assert(index < block_grid.getGridCount());
    return blocks[index];
}

Point3D NaturalTerrain::getBlockPosition(unsigned int index) const
{
    return block_grid.getBox(index).getXYZ();
}

NaturalTile NaturalTerrain::getFloor(unsigned int index) const
{
    assert(index < floor_grid.getGridCount());
    return floors[index];
}

Point3D NaturalTerrain::getFloorPosition(unsigned int index) const
{
    return floor_grid.getBox(index).getXYZ();
}

const std::vector<NaturalTile>& NaturalTerrain::getBlocks() const
{
    return blocks;
}

const std::vector<NaturalTile>& NaturalTerrain::getFloors() const
{
    return floors;
}

Point3DUInt NaturalTerrain::getGridDimensions() const
{
    return Point3DUInt(block_grid.getGridWidth(), block_grid.getGridHeight(), block_grid.getGridLength());
}

size_t NaturalTerrain::getCount() const
{
    return block_grid.getGridCount();
}

void NaturalTerrain::setGridDimensions(unsigned int width, unsigned int height, unsigned int length)
{
    block_grid.setGridWidthLengthHeight(width, height, length);
    floor_grid.setGridWidthLengthHeight(width, height, length);
}

void NaturalTerrain::setIndexDrawType(unsigned int index, DF_Draw_Tile_Type draw_type)
{
    setIndexDrawType(index, draw_type, draw_type);
}

void NaturalTerrain::setIndexDrawType(unsigned int index, DF_Draw_Tile_Type block_draw_type, DF_Draw_Tile_Type floor_draw_type)
{
    assert(index < block_grid.getGridCount());
    blocks[index].setDrawType(block_draw_type);
    floors[index].setDrawType(floor_draw_type);
}

void NaturalTerrain::setIndexDrawTypeN(unsigned int index, unsigned int count, DF_Draw_Tile_Type block_draw, DF_Draw_Tile_Type floor_draw, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    setIndexDrawType(index, block_draw, floor_draw);
    unsigned int current_index = index;

    for (unsigned int i = 0; i < count; i++)
    {
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
        setIndexDrawType(current_index, block_draw, floor_draw);
    }
}

void NaturalTerrain::setIndexDrawTypeAround(unsigned int index, DF_Draw_Tile_Type block_draw, DF_Draw_Tile_Type floor_draw)
{
    Point3DUInt xyz = getGridDimensions();
    const unsigned int up = Grid3DYOffset::getIndexUp(index, xyz.x, xyz.y, xyz.z);
    const unsigned int down = Grid3DYOffset::getIndexDown(index, xyz.x, xyz.y, xyz.z);
    const unsigned int left = Grid3DYOffset::getIndexLeft(index, xyz.x, xyz.y, xyz.z);
    const unsigned int right = Grid3DYOffset::getIndexRight(index, xyz.x, xyz.y, xyz.z);
    const unsigned int back = Grid3DYOffset::getIndexBack(index, xyz.x, xyz.y, xyz.z);
    const unsigned int front = Grid3DYOffset::getIndexFront(index, xyz.x, xyz.y, xyz.z);

    if (index != up)
    {
        blocks[up].setDrawType(block_draw);
        floors[up].setDrawType(floor_draw);
    }

    if (index != down)
    {
        blocks[down].setDrawType(block_draw);
        floors[down].setDrawType(floor_draw);
    }

    if (index != left)
    {
        blocks[left].setDrawType(block_draw);
        floors[left].setDrawType(floor_draw);
    }

    if (index != right)
    {
        blocks[right].setDrawType(block_draw);
        floors[right].setDrawType(floor_draw);
    }

    if (index != back)
    {
        blocks[back].setDrawType(block_draw);
        floors[back].setDrawType(floor_draw);
    }

    if (index != front)
    {
        blocks[front].setDrawType(block_draw);
        floors[front].setDrawType(floor_draw);
    }
}

void NaturalTerrain::setIndexDrawTypeAroundN(unsigned int index, unsigned int count, DF_Draw_Tile_Type block_draw, DF_Draw_Tile_Type floor_draw, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    setIndexDrawTypeAround(index, block_draw, floor_draw);
    unsigned int current_index = index;

    for (unsigned int i = 0; i < count; i++)
    {
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
        setIndexDrawTypeAround(current_index, block_draw, floor_draw);
    }
}

void NaturalTerrain::setIndexDrawTypeAroundToEdge(unsigned int index, DF_Draw_Tile_Type block_draw, DF_Draw_Tile_Type floor_draw, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    unsigned int current_index = index;
    unsigned int previous_index;

    setIndexDrawTypeAround(current_index, block_draw, floor_draw);
    previous_index = current_index;
    current_index = function(current_index, xyz.x, xyz.y, xyz.z);

    while (current_index != previous_index)
    {
        setIndexDrawTypeAround(current_index, block_draw, floor_draw);
        previous_index = current_index;
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
    }
}

void NaturalTerrain::setIndexMaterial(unsigned int index, DF_Natural_Tile_Material material)
{
    assert(index < block_grid.getGridCount());
    blocks[index].setTileMaterial(material);
    floors[index].setTileMaterial(material);
}

void NaturalTerrain::setIndexMaterial(unsigned int index, DF_Natural_Tile_Material block_material, DF_Natural_Tile_Material floor_material)
{
    assert(index < block_grid.getGridCount());
    blocks[index].setTileMaterial(block_material);
    floors[index].setTileMaterial(floor_material);
}

void NaturalTerrain::setIndexMaterialN(unsigned int index, unsigned int count, DF_Natural_Tile_Material block_material, DF_Natural_Tile_Material floor_material, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    setIndexMaterial(index, block_material, floor_material);
    unsigned int current_index = index;

    for (unsigned int i = 0; i < count; i++)
    {
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
        setIndexMaterial(current_index, block_material, floor_material);
    }
}

void NaturalTerrain::setIndexMaterialAround(unsigned int index, DF_Natural_Tile_Material block_material, DF_Natural_Tile_Material floor_material)
{
    Point3DUInt xyz = getGridDimensions();
    const unsigned int up = Grid3DYOffset::getIndexUp(index, xyz.x, xyz.y, xyz.z);
    const unsigned int down = Grid3DYOffset::getIndexDown(index, xyz.x, xyz.y, xyz.z);
    const unsigned int left = Grid3DYOffset::getIndexLeft(index, xyz.x, xyz.y, xyz.z);
    const unsigned int right = Grid3DYOffset::getIndexRight(index, xyz.x, xyz.y, xyz.z);
    const unsigned int back = Grid3DYOffset::getIndexBack(index, xyz.x, xyz.y, xyz.z);
    const unsigned int front = Grid3DYOffset::getIndexFront(index, xyz.x, xyz.y, xyz.z);

    if (index != up)
    {
        blocks[up].setTileMaterial(block_material);
        floors[up].setTileMaterial(floor_material);
    }

    if (index != down)
    {
        blocks[down].setTileMaterial(block_material);
        floors[down].setTileMaterial(floor_material);
    }

    if (index != left)
    {
        blocks[left].setTileMaterial(block_material);
        floors[left].setTileMaterial(floor_material);
    }

    if (index != right)
    {
        blocks[right].setTileMaterial(block_material);
        floors[right].setTileMaterial(floor_material);
    }

    if (index != back)
    {
        blocks[back].setTileMaterial(block_material);
        floors[back].setTileMaterial(floor_material);
    }

    if (index != front)
    {
        blocks[front].setTileMaterial(block_material);
        floors[front].setTileMaterial(floor_material);
    }
}

void NaturalTerrain::setIndexMaterialAroundN(unsigned int index, unsigned int count, DF_Natural_Tile_Material block_material, DF_Natural_Tile_Material floor_material, unsigned int (*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    setIndexMaterialAround(index, block_material, floor_material);
    unsigned int current_index = index;

    for (unsigned int i = 0; i < count; i++)
    {
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
        setIndexMaterialAround(current_index, block_material, floor_material);
    }
}

void NaturalTerrain::setIndexMaterialAroundToEdge(unsigned int index, DF_Natural_Tile_Material block_material, DF_Natural_Tile_Material floor_material, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    unsigned int current_index = index;
    unsigned int previous_index;

    setIndexMaterialAround(current_index, block_material, floor_material);
    previous_index = current_index;
    current_index = function(current_index, xyz.x, xyz.y, xyz.z);

    while (current_index != previous_index)
    {
        setIndexMaterialAround(current_index, block_material, floor_material);
        previous_index = current_index;
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
    }
}

void NaturalTerrain::setLayerBlockMaterial(unsigned int layer, DF_Natural_Tile_Material material)
{
    assert(layer < block_grid.getGridHeight());
    unsigned int layer_size = block_grid.getGridWidth() * block_grid.getGridLength();
    unsigned int start = layer_size*layer;
    for (unsigned int i = layer_size*layer; i < start + layer_size; i++)
    {
        blocks[i].setTileMaterial(material);
    }
}

void NaturalTerrain::setLayerFloorMaterial(unsigned int layer, DF_Natural_Tile_Material material)
{
    assert(layer < block_grid.getGridHeight());
    unsigned int layer_size = block_grid.getGridWidth() * block_grid.getGridLength();
    unsigned int start = layer_size*layer;
    for (unsigned int i = layer_size*layer; i < start + layer_size; i++)
    {
        floors[i].setTileMaterial(material);
    }
}

void NaturalTerrain::setLayerDrawType(unsigned int layer, DF_Draw_Tile_Type draw_type)
{
    assert(layer < block_grid.getGridHeight());
    unsigned int layer_size = block_grid.getGridWidth() * block_grid.getGridLength();
    unsigned int start = layer_size*layer;
    for (unsigned int i = layer_size*layer; i < start + layer_size; i++)
    {
        blocks[i].setDrawType(draw_type);
        floors[i].setDrawType(draw_type);
    }
}

void NaturalTerrain::setLayerDrawType(unsigned int layer, DF_Draw_Tile_Type block_draw_type, DF_Draw_Tile_Type floor_draw_type)
{
    assert(layer < block_grid.getGridHeight());
    unsigned int layer_size = block_grid.getGridWidth() * block_grid.getGridLength();
    unsigned int start = layer_size*layer;
    for (unsigned int i = layer_size*layer; i < start + layer_size; i++)
    {
        blocks[i].setDrawType(block_draw_type);
        floors[i].setDrawType(floor_draw_type);
    }
}

void NaturalTerrain::setLayerMaterial(unsigned int layer, DF_Natural_Tile_Material material)
{
    assert(layer < block_grid.getGridHeight());
    unsigned int layer_size = block_grid.getGridWidth() * block_grid.getGridLength();
    unsigned int start = layer_size*layer;
    for (unsigned int i = layer_size*layer; i < start + layer_size; i++)
    {
        blocks[i].setTileMaterial(material);
        floors[i].setTileMaterial(material);
    }
}

