--[[
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
]]

--[[
opal
=================
First version of script to pull data from DFHack
]]

TileTypeMaterialTable = 
{
    [df.tiletype_material.AIR] = 1,
    [df.tiletype_material.SOIL] = 2,
    [df.tiletype_material.STONE] = 3,
    [df.tiletype_material.FEATURE] = 4,
    [df.tiletype_material.LAVA_STONE] = 5,
    [df.tiletype_material.MINERAL] = 6,
    [df.tiletype_material.FROZEN_LIQUID] = 7,
    [df.tiletype_material.CONSTRUCTION] = 8,
    [df.tiletype_material.GRASS_LIGHT] = 9,
    [df.tiletype_material.GRASS_DARK] = 10,
    [df.tiletype_material.GRASS_DRY] = 11,
    [df.tiletype_material.GRASS_DEAD] = 12,
    [df.tiletype_material.PLANT] = 13,
    [df.tiletype_material.HFS] = 14,
    [df.tiletype_material.CAMPFIRE] = 15,
    [df.tiletype_material.FIRE] = 16,
    [df.tiletype_material.ASHES] = 17,
    [df.tiletype_material.MAGMA] = 18,
    [df.tiletype_material.DRIFTWOOD] = 19,
    [df.tiletype_material.POOL] = 20,
    [df.tiletype_material.BROOK] = 21,
    [df.tiletype_material.RIVER] = 22,
    [df.tiletype_material.ROOT] = 23,
    [df.tiletype_material.TREE] = 24,
    [df.tiletype_material.MUSHROOM] = 25,
    [df.tiletype_material.UNDERWORLD_GATE] = 26
}

TileTypeShapeTable = 
{
    [df.tiletype_shape.EMPTY] = "a",
    [df.tiletype_shape.FLOOR] = "f",
    [df.tiletype_shape.BOULDER] = "f",
    [df.tiletype_shape.PEBBLES] = "f",
    [df.tiletype_shape.WALL] = "w",
    [df.tiletype_shape.FORTIFICATION] = "w",
    [df.tiletype_shape.STAIR_UP] = "a",
    [df.tiletype_shape.STAIR_DOWN ] = "a",
    [df.tiletype_shape.STAIR_UPDOWN] = "a",
    [df.tiletype_shape.RAMP] = "a",
    [df.tiletype_shape.RAMP_TOP] = "a",
    [df.tiletype_shape.BROOK_BED] = "a",
    [df.tiletype_shape.BROOK_TOP] = "a",
    [df.tiletype_shape.BRANCH] = "a",
    [df.tiletype_shape.TRUNK_BRANCH] = "a",
    [df.tiletype_shape.TWIG] = "a",
    [df.tiletype_shape.SAPLING] = "a",
    [df.tiletype_shape.SHRUB] = "a",
    [df.tiletype_shape.ENDLESS_PIT] = "a"
}

local function main()
--printall(TileTypeMaterialTable)
--printall(TileTypeShapeTable)

local world_x, world_y, world_z
world_x, world_y, world_z = dfhack.maps.getTileSize()
print("world size x: "..world_x.." y: "..world_y.." z: "..world_z)



local block_x_count = world_x / 16
local block_y_count = world_y / 16
print("block_x_count: "..block_x_count)
print("block_y_count: "..block_y_count)

local count = 0
local block_table = {}
local tile_type_shape = {} --tile type value to shape letter
  for z = 0, world_z - 1, 1 do
    for y_block = block_y_count - 1, 0, -1 do
      for index = 0, block_x_count - 1, 1 do
        block_table[index] = dfhack.maps.getBlock(index, y_block, z)
      end
      for y = 15, 0, -1 do
        for x_block = 0, block_x_count - 1, 1 do
          for x = 0, 15, 1 do
            local hidden = block_table[x_block].designation[x%16][y%16].hidden
            if hidden then
              count = count + 1
            else
              local tile_type = dfhack.maps.getTileType(x, y, z)
              local shape_letter = tile_type_shape[tile_type]
              if shape_letter == nil then
                tile_type_shape[tile_type] = TileTypeShapeTable[df.tiletype.attrs[tile_type].shape]
              end
            end
          end
        end
      end
    end
  end

print("count: "..count)
print("tile_type_shape")
printall(tile_type_shape)
print("")
end

main()