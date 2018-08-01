//class header
#include "NaturalTerrainModelBuilder.hpp"

//std lib includes
#include <iostream>

//other includes

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

NaturalTerrainModelBuilder::NaturalTerrainModelBuilder()
{

}

void NaturalTerrainModelBuilder::loadFromFile(std::string filename)
{

}

void NaturalTerrainModelBuilder::loadFromMemory(const NaturalTerrain& memory, const ModelController& model_controller, ModelIndex& terrain_model)
{
    terrain = memory;
    create(terrain.getGridDimensions());
    checkingLoop();
    buildModel(model_controller, terrain_model);
}

void NaturalTerrainModelBuilder::debugLoadFromMemory(const NaturalTerrain& memory)
{
    terrain = memory;
    create(terrain.getGridDimensions());
    checkingLoop();
}

//private
void NaturalTerrainModelBuilder::addBlock(natural_tile_draw_info block)
{
    blocks.push_back(block);
}

void NaturalTerrainModelBuilder::addFloor(natural_tile_draw_info floor)
{
    floors.push_back(floor);
}

void NaturalTerrainModelBuilder::create(Point3DUInt dimensions)
{
    terrain.setGridDimensions(dimensions.x, dimensions.y, dimensions.z);
    terrain.create();
}

bool NaturalTerrainModelBuilder::isSolid(DF_Draw_Tile_Type type) const
{
    if (type == DF_DRAW_BLOCK || type == DF_DRAW_FLOOR)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool NaturalTerrainModelBuilder::shouldDraw(const natural_tile_draw_info& info, bool is_floor) const
{
    if (info.back || info.bottom || info.front || info.left || info.right || info.top)
    {
        if (is_floor)
        {
            DF_Draw_Tile_Type draw = terrain.getFloor(info.tile_index).getDrawType();
            if (draw != DF_DRAW_AIR)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            DF_Draw_Tile_Type draw = terrain.getBlock(info.tile_index).getDrawType();
            if (draw != DF_DRAW_AIR)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

void NaturalTerrainModelBuilder::addBoxFace(NormalFace face, const Point3D& offset, ModelIndex& terrain_model) const
{
    Point3D bottom_left, bottom_right, top_left, top_right;
    bottom_left = face.getBottomLeftVertex();
    bottom_right = face.getBottomRightVertex();
    top_left = face.getTopLeftVertex();
    top_right = face.getTopRightVertex();

    bottom_left.setXYZ(bottom_left.x + offset.x, bottom_left.y + offset.y, bottom_left.z + offset.z);
    bottom_right.setXYZ(bottom_right.x + offset.x, bottom_right.y + offset.y, bottom_right.z + offset.z);
    top_left.setXYZ(top_left.x + offset.x, top_left.y + offset.y, top_left.z + offset.z);
    top_right.setXYZ(top_right.x + offset.x, top_right.y + offset.y, top_right.z + offset.z);

    face.setVertex(bottom_left, bottom_right, top_left, top_right);

    terrain_model.addFace(face);
}

void NaturalTerrainModelBuilder::addBoxFaces(unsigned int index, const ModelIndex& box_model, ModelIndex& terrain_model, bool is_floor) const
{
    //check each face and if the bool is true, add it to model with the vertex offset by position from the proper grid
    /* order they are added
    model.addFace(front_face); 0
    model.addFace(back_face); 1
    model.addFace(left_face); 2
    model.addFace(right_face); 3
    model.addFace(top_face); 4
    model.addFace(bottom_face); 5
    */

    Point3D position;
    if (is_floor)
    {
        position = terrain.getFloorPosition(index);
    }
    else //block
    {
        position = terrain.getBlockPosition(index);
    }

    if (blocks[index].front)
    {
        addBoxFace(box_model.getFace(0), position, terrain_model);
    }

    if (blocks[index].back)
    {
        addBoxFace(box_model.getFace(1), position, terrain_model);
    }

    if (blocks[index].left)
    {
        addBoxFace(box_model.getFace(2), position, terrain_model);
    }

    if (blocks[index].right)
    {
        addBoxFace(box_model.getFace(3), position, terrain_model);
    }

    if (blocks[index].top)
    {
        addBoxFace(box_model.getFace(4), position, terrain_model);
    }

    if (blocks[index].bottom)
    {
        addBoxFace(box_model.getFace(5), position, terrain_model);
    }
}

void NaturalTerrainModelBuilder::buildModel(const ModelController& model_controller, ModelIndex& terrain_model)
{
    for (size_t i = 0; i < blocks.size(); i++)
    {
        NaturalTile tile = terrain.getBlock(blocks[i].tile_index);
        std::string name;

        switch (tile.getDrawType()) //pick what type of block it is and give proper name to add to material
        {
        case DF_DRAW_BLOCK:
            name = DFNaturalTileString(tile.getTileMaterial()).append(" block");
            break;
        case DF_DRAW_LIQUID:
            break;
            //and so on
        }

        const ModelIndex& model = model_controller.getModel(model_controller.getModelReference(name)); //TODO add assert to modelcontroller so we make sure it's always a proper reference
        addBoxFaces(i, model, terrain_model, false);
    }
}

void NaturalTerrainModelBuilder::checkingLoop()
{
    /*
    Single pass that does both floors and blocks at the same time
    */
    for (size_t index = 0; index < terrain.getCount(); index++)
    {
        natural_tile_draw_info block, floor;
        //block
        block.tile_index = index;
        checkNeighbors(block, false); //fills in our bools based on the tiles around this one
        if (shouldDraw(block, false))
        {
            blocks.push_back(block);
        }

        //floor
        floor.tile_index = index;
        checkNeighbors(floor, true);
        if (shouldDraw(floor, true))
        {
            floors.push_back(floor);
        }
    }
}

void NaturalTerrainModelBuilder::checkNeighbors(natural_tile_draw_info& info, bool is_floor)
{
    NaturalTile tile;
    unsigned int index = info.tile_index;
    if (is_floor)
    {
        Point3DUInt xyz = terrain.getGridDimensions();
        tile = terrain.getFloor(index);
        const unsigned int up = Grid3DYOffset::getIndexUp(index, xyz.x, xyz.y, xyz.z);
        const unsigned int down = Grid3DYOffset::getIndexDown(index, xyz.x, xyz.y, xyz.z);
        const unsigned int left = Grid3DYOffset::getIndexLeft(index, xyz.x, xyz.y, xyz.z);
        const unsigned int right = Grid3DYOffset::getIndexRight(index, xyz.x, xyz.y, xyz.z);
        const unsigned int back = Grid3DYOffset::getIndexBack(index, xyz.x, xyz.y, xyz.z);
        const unsigned int front = Grid3DYOffset::getIndexFront(index, xyz.x, xyz.y, xyz.z);

        checkTile(info.top, index, up, false); //if we go up or down we need to check the block above/below us instead of floors
        checkTile(info.bottom, index, down, false);
        checkTile(info.left, index, left, true);
        checkTile(info.right, index, right, true);
        checkTile(info.front, index, back, true); //reversed on purpose. The model's front face points to the camera, but is the back face for the grid
        checkTile(info.back, index, front, true); //reversed on purpose
    }
    else //is a block
    {
        Point3DUInt xyz = terrain.getGridDimensions();
        tile = terrain.getBlock(index);
        const unsigned int up = Grid3DYOffset::getIndexUp(index, xyz.x, xyz.y, xyz.z);
        const unsigned int down = Grid3DYOffset::getIndexDown(index, xyz.x, xyz.y, xyz.z);
        const unsigned int left = Grid3DYOffset::getIndexLeft(index, xyz.x, xyz.y, xyz.z);
        const unsigned int right = Grid3DYOffset::getIndexRight(index, xyz.x, xyz.y, xyz.z);
        const unsigned int back = Grid3DYOffset::getIndexBack(index, xyz.x, xyz.y, xyz.z);
        const unsigned int front = Grid3DYOffset::getIndexFront(index, xyz.x, xyz.y, xyz.z);

        checkTile(info.top, index, up, true); //if we go up/down we need to read from the floors and not blocks
        checkTile(info.bottom, index, down, true);
        checkTile(info.left, index, left, false);
        checkTile(info.right, index, right, false);
        checkTile(info.front, index, back, false); //reversed on purpose. Read comment from floor above
        checkTile(info.back, index, front, false); //reversed on purpose
    }
}

void NaturalTerrainModelBuilder::checkTile(bool& side, unsigned int start_index, unsigned int check_index, bool is_floor)
{
    side = true;
    /*
    if (is_floor)
    {
        if (start_index != check_index)
        {
            NaturalTile tile = terrain.getFloor(check_index);
            if (isSolid(tile.getDrawType()))
            {
                side = false;
            }
            else
            {
                side = true;
            }
        }
        else //if equal we can't move in the direction wanted so this block/floor must be drawn
        {
            side = true;
        }
    }
    else
    {
        if (start_index != check_index)
        {
            NaturalTile tile = terrain.getBlock(check_index);
            if (isSolid(tile.getDrawType()))
            {
                side = false;
            }
            else
            {
                side = true;
            }
        }
        else //if equal we can't move in the direction wanted so this block/floor must be drawn
        {
            side = true;
        }
    }
    */
}

