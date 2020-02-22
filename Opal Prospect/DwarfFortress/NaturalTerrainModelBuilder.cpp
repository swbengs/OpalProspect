//class header
#include "NaturalTerrainModelBuilder.hpp"

//std lib includes
#include <iostream>

//other includes
#include "NaturalTerrainFileLoader.hpp"
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

void NaturalTerrainModelBuilder::loadFromFile(std::string filename, const ModelController& model_controller, ModelIndex& terrain_model)
{
    // TODO: Add a variable to pick which mode to use(merge, no merge, greedy merge, and so on)
    NaturalTerrainFileLoader loader;
    if (loader.loadWorld(filename, terrain))
    {
        std::cout << "world load success\n";
        //checkingLoopNaive();
        //buildModelNaive(model_controller, terrain_model);
        checkingLoopMergeSimple();
        buildModelMergeSimple(model_controller, terrain_model);
    }
    else
    {

    }

    terrain.freeData();
    freeData();
}

void NaturalTerrainModelBuilder::loadFromMemory(const NaturalTerrain& memory, const ModelController& model_controller, ModelIndex& terrain_model)
{
    terrain = memory;
    create(terrain.getGridDimensions());
    checkingLoopNaive();
    buildModelNaive(model_controller, terrain_model);
}

void NaturalTerrainModelBuilder::debugLoadFromMemory(const NaturalTerrain& memory)
{
    terrain = memory;
    create(terrain.getGridDimensions());
    checkingLoopNaive();
}

Point3DUInt NaturalTerrainModelBuilder::getWorldDimensions() const
{
    return terrain.getGridDimensions();
}

//private
void NaturalTerrainModelBuilder::addTile(natural_tile_draw_info block)
{
    tiles.push_back(block);
}

void NaturalTerrainModelBuilder::create(Point3DUInt dimensions)
{
    terrain.setGridDimensions(dimensions.x, dimensions.y, dimensions.z);
    terrain.create();
}

bool NaturalTerrainModelBuilder::isSolid(DF_Draw_Tile_Type type) const
{
    if (type == DF_DRAW_BLOCK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool NaturalTerrainModelBuilder::shouldDraw(const natural_tile_draw_info& info) const
{
    if (info.back || info.bottom || info.front || info.left || info.right || info.top)
    {
        DF_Draw_Tile_Type draw = terrain.getTile(info.tile_index).getDrawType();
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
        return false;
    }
}

void NaturalTerrainModelBuilder::freeData()
{
    tiles = std::vector<natural_tile_draw_info>();
    merged_tiles = std::vector<natural_merge_tile_draw_info>();
}

void NaturalTerrainModelBuilder::addBoxFace(NormalFace face, const Point3D& offset, ModelIndex& terrain_model) const
{
    //face is not pass by reference because we need to modify it
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

    terrain_model.addFace(std::move(face));
}

void NaturalTerrainModelBuilder::addBoxMergeFace(natural_merge_tile_draw_info info, const ModelIndex& box_model, ModelIndex& terrain_model)
{
    Point3D position;
    NormalFace face;

    if (info.shape == DF_DRAW_FLOOR)
    {
        position = terrain.getFloorPosition(info.tile_index);

        // Offset position even more
        position.x += DF_FLOOR_WIDTH * 0.5f * info.width;
        position.x += DF_FLOOR_HEIGHT * 0.5f * info.height;
        position.z += DF_FLOOR_LENGTH * 0.5f * info.length;
    }
    else //block
    {
        position = terrain.getBlockPosition(info.tile_index);

        // Offset position even more
        position.x += DF_BLOCK_WIDTH * 0.5f * info.width;
        position.x += DF_BLOCK_HEIGHT * 0.5f * info.height;
        position.z += DF_BLOCK_LENGTH * 0.5f * info.length;
    }

    switch (info.side)
    {
    case DF_FRONT_SIDE:
        face = box_model.getFace(0);
        break;
    case DF_BACK_SIDE:
        face = box_model.getFace(1);
        break;
    case DF_LEFT_SIDE:
        face = box_model.getFace(2);
        break;
    case DF_RIGHT_SIDE:
        face = box_model.getFace(3);
        break;
    case DF_TOP_SIDE:
        face = box_model.getFace(4);
        break;
    case DF_BOTTOM_SIDE:
        face = box_model.getFace(5);
        break;
    }

    addBoxFace(face, position, terrain_model);
}

void NaturalTerrainModelBuilder::addBoxFaces(unsigned int current_index, unsigned int tile_position_index, const ModelIndex& box_model, ModelIndex& terrain_model, bool is_floor) const
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

    //current_index is for what block or floor we are working with to get the proper sides to draw. tile_position_index is used to grab the proper position from the tile array
    Point3D position;
    if (is_floor)
    {
        position = terrain.getFloorPosition(tile_position_index);
    }
    else //block
    {
        position = terrain.getBlockPosition(tile_position_index);
    }

    // Only draw the face if it can be visible
    if (tiles[current_index].front)
    {
        addBoxFace(box_model.getFace(0), position, terrain_model);
    }

    if (tiles[current_index].back)
    {
        addBoxFace(box_model.getFace(1), position, terrain_model);
    }

    if (tiles[current_index].left)
    {
        addBoxFace(box_model.getFace(2), position, terrain_model);
    }

    if (tiles[current_index].right)
    {
        addBoxFace(box_model.getFace(3), position, terrain_model);
    }

    if (tiles[current_index].top)
    {
        addBoxFace(box_model.getFace(4), position, terrain_model);
    }

    if (tiles[current_index].bottom)
    {
        addBoxFace(box_model.getFace(5), position, terrain_model);
    }
}

// Build the model by passing over all visible tiles and making a face per tile(horribly innefficient but easy to do)
void NaturalTerrainModelBuilder::buildModelNaive(const ModelController& model_controller, ModelIndex& terrain_model)
{
    for (size_t i = 0; i < tiles.size(); i++)
    {
        const unsigned int tile_index = tiles[i].tile_index;
        bool is_floor = false;
        NaturalTile tile = terrain.getTile(tile_index);
        std::string name;

        switch (tile.getDrawType()) //pick what type of block it is and give proper name to add to material
        {
        case DF_DRAW_BLOCK:
            name = DFNaturalTileString(tile.getTileMaterial()).append(" block");
            break;
        case DF_DRAW_FLOOR:
            name = DFNaturalTileString(tile.getTileMaterial()).append(" floor");
            is_floor = true;
            break;
        case DF_DRAW_LIQUID:
            break;
            //and so on
        }

        const ModelIndex& model = model_controller.getModel(model_controller.getModelReference(name)); //TODO add assert to modelcontroller so we make sure it's always a proper reference
        addBoxFaces(i, tile_index, model, terrain_model, is_floor);
    }
}

void NaturalTerrainModelBuilder::buildModelMergeSimple(const ModelController& model_controller, ModelIndex& terrain_model)
{
    for (size_t i = 0; i < merged_tiles.size(); i++)
    {
        const unsigned int tile_index = merged_tiles[i].tile_index;
        bool is_floor = false;
        NaturalTile tile = terrain.getTile(tile_index);
        std::string name;

        switch (tile.getDrawType()) //pick what type of block it is and give proper name to add to material
        {
        case DF_DRAW_BLOCK:
            name = DFNaturalTileString(tile.getTileMaterial()).append(" block");
            break;
        case DF_DRAW_FLOOR:
            name = DFNaturalTileString(tile.getTileMaterial()).append(" floor");
            is_floor = true;
            break;
        case DF_DRAW_LIQUID:
            break;
            //and so on
        }

        const ModelIndex& model = model_controller.getModel(model_controller.getModelReference(name));
    }
}

void NaturalTerrainModelBuilder::checkingLoopNaive()
{
    for (size_t index = 0; index < terrain.getCount(); index++)
    {
        natural_tile_draw_info tile;
        tile.shape = terrain.getTile(index).getDrawType();

        tile.tile_index = index;
        checkNeighbors(tile, (tile.shape == DF_DRAW_FLOOR)); //fills in our bools based on the tiles around this one
        if (shouldDraw(tile))
        {
            tiles.push_back(tile);
        }
    }
}

void NaturalTerrainModelBuilder::checkingLoopMergeSimple()
{
    // Do one side per loop
    Point3DUInt dimensions = terrain.getGridDimensions();
    unsigned int next_index;
    unsigned int current_index;
    unsigned int start_index; // Last visible index to be merged with
    unsigned int merged_count; // Counter for number of tiles merged

    // Front

    // Back
    // Outer layer only for now
    // For each layer start at relative bottom left and move right until the end, then move up a row and repeat
    for (unsigned int y = 0; y < dimensions.y; y++)
    {
        current_index = y * dimensions.x * dimensions.z;
        merged_count = 0;
        start_index = 0;

        for (unsigned int x = 0; x < dimensions.x; x++)
        {
            bool visible;
            checkHorizontalTile(visible, current_index, terrain.getIndexBack(current_index), terrain.getTile(current_index).getDrawType());
            if (visible) // Compare to previous visible
            {
                NaturalTile current_tile = terrain.getTile(current_index);

                if (merged_count == 0) // First visible on this row
                {
                    start_index = current_index;
                    merged_count = 1;
                }
                else // Compare to start index. If material or shape are different save the old one
                {
                    NaturalTile start_tile = terrain.getTile(start_index);

                    if (current_tile.getDrawType() == start_tile.getDrawType() && current_tile.getTileMaterial() == start_tile.getTileMaterial()) // Are equal
                    {
                        merged_count++; // Just increment merge count
                    }
                    else // Not so add old sequence and start new one
                    {
                        natural_merge_tile_draw_info info;
                        info.width = merged_count;
                        info.height = 0;
                        info.length = 0;
                        info.shape = start_tile.getDrawType();
                        info.side = DF_BACK_SIDE;
                        info.tile_index = start_index;

                        merged_tiles.push_back(info);

                        // New
                        start_index = current_index;
                        merged_count = 1;
                    }
                }
            }
            else // Not visible so if prior start index has a value end the sequence for it
            {
                if (merged_count > 0)
                {
                    NaturalTile start_tile = terrain.getTile(start_index);
                    natural_merge_tile_draw_info info;
                    info.width = merged_count;
                    info.height = 0;
                    info.length = 0;
                    info.shape = start_tile.getDrawType();
                    info.side = DF_BACK_SIDE;
                    info.tile_index = start_index;

                    merged_tiles.push_back(info);

                    // New
                    start_index = current_index;
                    merged_count = 1;
                }
            }

            // Setup next increment
            next_index = terrain.getIndexRight(current_index);
            current_index++;
        }
    }


    // Left

    // Right
}

void NaturalTerrainModelBuilder::checkNeighbors(natural_tile_draw_info& info, bool is_floor)
{
    unsigned int index = info.tile_index;
    const unsigned int up = terrain.getIndexUp(index);
    const unsigned int down = terrain.getIndexDown(index);
    const unsigned int left = terrain.getIndexLeft(index);
    const unsigned int right = terrain.getIndexRight(index);
    const unsigned int back = terrain.getIndexBack(index);
    const unsigned int front = terrain.getIndexFront(index);

    if (is_floor)
    {
        checkVerticalTile(info.top, index, up, true, true);
        checkVerticalTile(info.bottom, index, down, true, false);
        checkHorizontalTile(info.left, index, left, info.shape);
        checkHorizontalTile(info.right, index, right, info.shape);
        checkHorizontalTile(info.front, index, back, info.shape); //reversed on purpose. The model's front face points to the camera, but is the back face for the grid
        checkHorizontalTile(info.back, index, front, info.shape); //reversed on purpose
    }
    else //is a block
    {
        checkVerticalTile(info.top, index, up, false, true);
        checkVerticalTile(info.bottom, index, down, false, false);
        checkHorizontalTile(info.left, index, left, info.shape);
        checkHorizontalTile(info.right, index, right, info.shape);
        checkHorizontalTile(info.front, index, back, info.shape); //reversed on purpose. Read comment from floor above
        checkHorizontalTile(info.back, index, front, info.shape); //reversed on purpose
    }
}

void NaturalTerrainModelBuilder::checkHorizontalTile(bool& side, unsigned int start_index, unsigned int check_index, DF_Draw_Tile_Type current_shape)
{
    NaturalTile tile;

    if (start_index == check_index) //same so we can't move on the x/z axis so draw this face
    {
        side = true;
    }
    else //check if solid and get proper tile to check. Also check if they are the same shape. Two floors touching means that side doesn't get drawn
    {
        tile = terrain.getTile(check_index);

        if (isSolid(tile.getDrawType()) || current_shape == tile.getDrawType())
        {
            side = false;
        }
        else
        {
            side = true;
        }
    }
}

void NaturalTerrainModelBuilder::checkVerticalTile(bool& side, unsigned int start_index, unsigned int check_index, bool is_floor, bool checking_up)
{
    NaturalTile tile;

    // This happens if this face is on the side of the grid so it's always visible
    if (start_index == check_index)
    {
        side = true;
    }
    else if (is_floor)
    {
        if (checking_up)
        {
            side = true; // For a floor it always has empty space in its own space
        }
        else
        {
            tile = terrain.getTile(check_index);
            if (isSolid(tile.getDrawType()))
            {
                side = false;
            }
            else
            {
                side = true;
            }
        }
    }
    else // Block
    {
        tile = terrain.getTile(check_index);
        if (checking_up && tile.getDrawType() == DF_DRAW_FLOOR)
        {
            side = false; // If checking up and the tile above is a floor our top isn't visible
        }
        else if (isSolid(tile.getDrawType())) // Otherwise it is visible unless another block is there
        {
            side = false;
        }
        else
        {
            side = true;
        }
    }
}

