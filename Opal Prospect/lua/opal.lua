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
  [df.tiletype_shape.RAMP] = "f",
  [df.tiletype_shape.RAMP_TOP] = "a",
  [df.tiletype_shape.BROOK_BED] = "w",
  [df.tiletype_shape.BROOK_TOP] = "f",
  [df.tiletype_shape.BRANCH] = "a",
  [df.tiletype_shape.TRUNK_BRANCH] = "a",
  [df.tiletype_shape.TWIG] = "a",
  [df.tiletype_shape.SAPLING] = "f",
  [df.tiletype_shape.SHRUB] = "f",
  [df.tiletype_shape.ENDLESS_PIT] = "a"
}

CharacterTable = 
{
  ["a"] = "b", --give it the current letter and it will return the next one
  ["b"] = "c",
  ["c"] = "d",
  ["d"] = "e",
  ["e"] = "f",
  ["f"] = "g",
  ["g"] = "h",
  ["h"] = "i",
  ["i"] = "j",
  ["j"] = "k",
  ["k"] = "l",
  ["l"] = "m",
  ["m"] = "n",
  ["n"] = "o",
  ["o"] = "p",
  ["p"] = "q",
  ["q"] = "r",
  ["r"] = "s",
  ["s"] = "t",
  ["t"] = "u",
  ["u"] = "v",
  ["v"] = "w",
  ["w"] = "x",
  ["x"] = "y",
  ["y"] = "z",
  ["z"] = "A",
  ["A"] = "B"
}

local function writeLayer(material, shape)
  print(material)
  print(shape)
  --print("")
end

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

local block_cache_table = {} --hold a line of blocks to save looking them up multiple times
local tile_type_material = { ["a"] = "white_sand", ["b"] = "gabbro" } --same as shape but for material
local tile_type_shape = {} --tile type value to shape letter. tile type numbers are duplicated since both tables have one

local material_count = world_z --default will be used to save having to check for nil every loop
local shape_count = world_y --instead these are written out right away
local material_letter
local shape_letter

local material_output--strings that get written in one go
local shape_output
local count = 0

  for z = 0, world_z - 1, 1 do
    --set defaults
    material_count = 0
    shape_count = 0

    material_letter = " " 
    shape_letter = " "

    material_output = ""
    shape_output = ""

    for y_block = block_y_count - 1, 0, -1 do
      for index = 0, block_x_count - 1, 1 do
        block_cache_table[index] = dfhack.maps.getBlock(index, y_block, z)
      end
      for y = 15, 0, -1 do
        for x_block = 0, block_x_count - 1, 1 do
          for x = 0, 15, 1 do
            local hidden = block_cache_table[x_block].designation[x][y].hidden
            local current_material
            local current_shape
            --set defaults for a hidden block which is WALL and HIDDEN
            if hidden then
              current_material = "a"
              current_shape = "w"
            else
              local tile_type = dfhack.maps.getTileType(x + 16 * x_block, y + 16 * y_block, z)
              current_material = tile_type_material[tile_type]
              current_shape =  tile_type_shape[tile_type]
              if current_shape == nil then --if shape is missing then material is also
                local tile_attributes = df.tiletype.attrs[tile_type]
                tile_type_material[tile_type] = "b" --set to gabbro for test purpose
                tile_type_shape[tile_type] = TileTypeShapeTable[tile_attributes.shape]

                current_material = tile_type_material[tile_type]
                current_shape = tile_type_shape[tile_type]
              end
            end

            if current_material ~= material_letter then --material and shape must be done seperate
              if material_letter ~= " " then --if not default append
                material_output = material_output..material_count..material_letter
              end
              material_letter = current_material
              material_count = 1
            else
              material_count = material_count + 1
            end

            if current_shape ~= shape_letter then
              if shape_letter ~= " " then
                shape_output = shape_output..shape_count..shape_letter
              end
              shape_letter = current_shape
              shape_count = 1
            else
              shape_count = shape_count + 1
            end

          end
        end
      end
    end
    material_output = material_output..material_count..material_letter --append the last letter and count to proper string
    shape_output = shape_output..shape_count..shape_letter
    writeLayer(material_output, shape_output) --write current output then reset both outputs and all counts and letters
  end

local tile_type_shape_count = 0
for _ in pairs(tile_type_shape) do
  tile_type_shape_count = tile_type_shape_count + 1
end
--print("tile_type_material")
--printall(tile_type_material)
--print("tile_type_shape")
--printall(tile_type_shape)
--print("tile_type_shape count: "..tile_type_shape_count)
--print("")
--print("count: "..count)
end

main()