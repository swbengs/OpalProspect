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
  [df.tiletype_material.AIR] = "a",
  [df.tiletype_material.SOIL] = "b",
  [df.tiletype_material.STONE] = "c",
  [df.tiletype_material.FEATURE] = "a",
  [df.tiletype_material.LAVA_STONE] = "a",
  [df.tiletype_material.MINERAL] = "d",
  [df.tiletype_material.FROZEN_LIQUID] = "a",
  [df.tiletype_material.CONSTRUCTION] = "a",
  [df.tiletype_material.GRASS_LIGHT] = "e",
  [df.tiletype_material.GRASS_DARK] = "e",
  [df.tiletype_material.GRASS_DRY] = "e",
  [df.tiletype_material.GRASS_DEAD] = "e",
  [df.tiletype_material.PLANT] = "e",
  [df.tiletype_material.HFS] = "a",
  [df.tiletype_material.CAMPFIRE] = "a",
  [df.tiletype_material.FIRE] = "a",
  [df.tiletype_material.ASHES] = "a",
  [df.tiletype_material.MAGMA] = "a",
  [df.tiletype_material.DRIFTWOOD] = "a",
  [df.tiletype_material.POOL] = "e",
  [df.tiletype_material.BROOK] = "e",
  [df.tiletype_material.RIVER] = "e",
  [df.tiletype_material.ROOT] = "e",
  [df.tiletype_material.TREE] = "e",
  [df.tiletype_material.MUSHROOM] = "e",
  [df.tiletype_material.UNDERWORLD_GATE] = "a"
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

NaturalMaterialsTable = {}

local function getLayerMaterial(biome_table)

end

--all writes will need to made into actual file writes and not just print to console
local function writeHeader(version, width, height, length)
  print(version)
  print(width.." "..height.." "..length)
end

local function writeMaterialTable()
  print("natural_materials")
  for key, value in pairs() do
    print(key.." "..value)
  end
    print("natural_materials_end")
end

local function writeShapeTable()
  print("natural_types")
  print("a air")
  print("w block")
  print("f floor")
  print("natural_types_end")
end

local function writeLayer(material, shape)
  print(material)
  print(shape)
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
local tile_type_material = {} --same as shape but for material
local tile_type_shape = {} --tile type value to shape letter. tile type numbers are duplicated since both tables have one

local count = 0

  for z = 160, world_z - 1, 1 do --start at 0 and go until world_z - 1. changes here are just for testing such as starting at higher height
    --set defaults
    local material_count = 0
    local shape_count = 0
    local material_letter = " "
    local shape_letter = " "
    local material_output = ""
    local shape_output = ""

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
                tile_type_material[tile_type] = TileTypeMaterialTable[tile_attributes.material]
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

--local tile_type_shape_count = 0
--for _ in pairs(tile_type_shape) do
--  tile_type_shape_count = tile_type_shape_count + 1
--end
--print("tile_type_material")
--printall(tile_type_material)
--print("tile_type_shape")
--printall(tile_type_shape)
--print("tile_type_shape count: "..tile_type_shape_count)
--print("")
--print("count: "..count)
local version = "v0.2"

writeHeader(version, world_x, world_z, world_y) --z and y need to be swapped for opal prospect

writeShapeTable()
end

main()