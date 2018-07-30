#pragma once

//std lib includes
#include <vector>

//other includes
#include "NaturalTerrain.hpp"
#include "..\Shapes\ModelIndex.hpp"

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
Description: Class to convert natural terrain class into a model that can be drawn. We only store the blocks/floors that have at least one face to be drawn.
*/

class NaturalTerrainModelBuilder
{
public:
    NaturalTerrainModelBuilder();

    void loadFromFile(std::string filename);
    void loadFromMemory(const NaturalTerrain& memory); //good for testing and debugging

    //gets

    //sets

private:
    struct natural_tile_draw_info //struct for what needs to be added to the model, as in what is drawn. 
    {
        //sides that should be drawn
        bool left;
        bool right;
        bool bottom;
        bool top;
        bool front;
        bool back;
        unsigned int tile_index; //what natural tile to grab from. blocks and floors kept seperate so we know if it's a floor or a block
    };

    std::vector<natural_tile_draw_info> blocks; //only blocks that have at least one side to be drawn are added here
    std::vector<natural_tile_draw_info> floors; //same as above except for floors
    NaturalTerrain terrain;

    void addBlock(natural_tile_draw_info block);
    void addFloor(natural_tile_draw_info floor);
    void create(Point3DUInt dimensions);
    
    bool isSolid(DF_Draw_Tile_Type type) const; //check if the type is solid
    bool shouldDraw(const natural_tile_draw_info& info, bool is_floor) const; //final check to see if we should add this tile to be drawn

    //methods to build the model
    void buildModel(ModelIndex& model); //takes the natural tile draw info and uses that to access the models data directly along with the coordinates to place and rotate the face(s) correctly. And those faces are added to the model
    void checkingLoop(); //method that contains the main loop to check all terrain for what should be drawn
    void checkNeighbors(natural_tile_draw_info& tile, bool is_floor); //takes index of current block and will handle cases for all neighbors. Modifies given tile info pod
    void checkTile(bool& side, unsigned int start_index, unsigned int check_index, bool is_floor); //check given tile side in vs the index passed in. Sets the boolean
};

