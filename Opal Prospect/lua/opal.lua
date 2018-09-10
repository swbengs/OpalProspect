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

Huge shout out to Milo Christiansen and his script at https://github.com/DFHack/dfhack/blob/master/library/lua/tile-material.lua
It was used to speed up development greatly!
]]

TileTypeMaterialTable = 
{
  [df.tiletype_material.AIR] = "aa", --0
  [df.tiletype_material.SOIL] = 1, --1
  [df.tiletype_material.STONE] = 1, --2
  [df.tiletype_material.FEATURE] = "aa", --3
  [df.tiletype_material.LAVA_STONE] = 2,
  [df.tiletype_material.MINERAL] = 3,
  [df.tiletype_material.FROZEN_LIQUID] = "aa",
  [df.tiletype_material.CONSTRUCTION] = 1,
  [df.tiletype_material.GRASS_LIGHT] = "ag", --8
  [df.tiletype_material.GRASS_DARK] = "ah",
  [df.tiletype_material.GRASS_DRY] = "ai",
  [df.tiletype_material.GRASS_DEAD] = "aj",
  [df.tiletype_material.PLANT] = 1,
  [df.tiletype_material.HFS] = "aa",
  [df.tiletype_material.CAMPFIRE] = 1,
  [df.tiletype_material.FIRE] = "aa",
  [df.tiletype_material.ASHES] = "aa",
  [df.tiletype_material.MAGMA] = "aa", --17
  [df.tiletype_material.DRIFTWOOD] = 1,
  [df.tiletype_material.POOL] = "aa",
  [df.tiletype_material.BROOK] = "aa",
  [df.tiletype_material.RIVER] = "aa",
  [df.tiletype_material.ROOT] = "ar",
  [df.tiletype_material.TREE] = "at",
  [df.tiletype_material.MUSHROOM] = 1,
  [df.tiletype_material.UNDERWORLD_GATE] = "aa"
}

InorganicMaterialNumberToString = 
{
  [34] = "onyx",
  [35] = "morion",
  [36] = "schorl",
  [37] = "lace_agate",
  [38] = "blue_jade",
  [39] = "lapis_lazuli",
  [40] = "prase",
  [41] = "prase_opal",
  [42] = "bloodstone",
  [43] = "moss_agate",
  [44] = "moss_opal",
  [45] = "variscite",
  [46] = "chrysoprase",
  [47] = "chrysocolla",
  [48] = "sard",
  [49] = "carnelian",
  [50] = "banded_agate",
  [51] = "sardonyx",
  [52] = "cherry_opal",
  [53] = "lavender_jade",
  [54] = "pink_jade",
  [55] = "tube_agate",
  [56] = "fire_agate",
  [57] = "plume_agate",
  [58] = "brown_jasper",
  [59] = "picture_jasper",
  [60] = "smoky_quartz",
  [61] = "wax_opal",
  [62] = "wood_opal",
  [63] = "amber_opal",
  [64] = "gold_opal",
  [65] = "citrine",
  [66] = "yellow_jasper",
  [67] = "tigereye",
  [68] = "tiger_iron",
  [69] = "sunstone",
  [70] = "resin_opal",
  [71] = "pyrite",
  [72] = "clear_tourmaline",
  [73] = "gray_chalcedony",
  [74] = "dendritic_agate",
  [75] = "shell_opal",
  [76] = "bone_opal",
  [77] = "white_chalcedony",
  [78] = "fortification_agate",
  [79] = "milk_quartz",
  [80] = "moonstone",
  [81] = "white_jade",
  [82] = "jasper_opal",
  [83] = "pineapple_opal",
  [84] = "onyx_opal",
  [85] = "milk_opal",
  [86] = "pipe_opal",
  [87] = "aventurine",
  [88] = "turquoise",
  [89] = "rose_quartz",
  [90] = "rock_crystal",
  [91] = "black_zircon",
  [92] = "black_pyrope",
  [93] = "melanite",
  [94] = "indigo_tourmaline",
  [95] = "blue_garnet",
  [96] = "tsavorite",
  [97] = "green_tourmaline",
  [98] = "demantoid",
  [99] = "green_zircon",
  [100] = "green_jade",
  [101] = "heliodor",
  [102] = "peridot",
  [103] = "red_zircon",
  [104] = "red_tourmaline",
  [105] = "red_pyrope",
  [106] = "almandine",
  [107] = "red_grossular",
  [108] = "pink_tourmaline",
  [109] = "red_beryl",
  [110] = "fire_opal",
  [111] = "rhodolite",
  [112] = "purple_spinel",
  [113] = "alexandrite",
  [114] = "tanzanite",
  [115] = "morganite",
  [116] = "violet_spessartine",
  [117] = "pink_garnet",
  [118] = "kunzite",
  [119] = "cinnamon_grossular",
  [120] = "honey_yellow_beryl",
  [121] = "jelly_opal",
  [122] = "brown_zircon",
  [123] = "yellow_zircon",
  [124] = "golden_beryl",
  [125] = "yellow_spessartine",
  [126] = "topaz",
  [127] = "topazolite",
  [128] = "yellow_grossular",
  [129] = "rubicelle",
  [130] = "clear_garnet",
  [131] = "goshenite",
  [132] = "cats_eye",
  [133] = "clear_zircon",
  [134] = "amethyst",
  [135] = "aquamarine",
  [136] = "red_spinel",
  [137] = "chrysoberyl",
  [138] = "pinfire_opal",
  [139] = "red_flash_opal",
  [140] = "black_opal",
  [141] = "white_opal",
  [142] = "crystal_opal",
  [143] = "claro_opal",
  [144] = "levin_opal",
  [145] = "harlequin_opal",
  [146] = "pinfire_opal",
  [147] = "bandire_opal",
  [148] = "light_yellow_diamond",
  [149] = "faint_yellow_diamond",
  [150] = "emerald",
  [151] = "ruby",
  [152] = "sapphire",
  [153] = "clear_diamond",
  [154] = "red_diamond",
  [155] = "green_diamond",
  [156] = "blue_diamond",
  [157] = "yellow_diamond",
  [158] = "black_diamond",
  [159] = "star_sapphire",
  [160] = "star_ruby",
  [161] = "sandstone",
  [162] = "siltstone",
  [163] = "mudstone",
  [164] = "shale",
  [165] = "claystone",
  [166] = "rock_salt",
  [167] = "limestone",
  [168] = "conglomerate",
  [169] = "dolomite",
  [170] = "chert",
  [171] = "chalk",
  [172] = "granite",
  [173] = "diorite",
  [174] = "gabbro",
  [175] = "rhyolite",
  [176] = "basalt",
  [177] = "andesite",
  [178] = "dacite",
  [179] = "obsidian",
  [180] = "quartzite",
  [181] = "slate",
  [182] = "phyllite",
  [183] = "schist",
  [184] = "gneiss",
  [185] = "marble",
  [186] = "hematite",
  [187] = "limonite",
  [188] = "garnierite",
  [189] = "native_gold",
  [190] = "native_silver",
  [191] = "native_copper",
  [192] = "malachite",
  [193] = "galena",
  [194] = "sphalerite",
  [195] = "cassiterite",
  [196] = "bituminous_coal",
  [197] = "lignite",
  [198] = "native_platinum",
  [199] = "cinnabar",
  [200] = "cobaltite",
  [201] = "tetrahedrite",
  [202] = "horn_silver",
  [203] = "gypsum",
  [204] = "talc",
  [205] = "jet",
  [206] = "puddingstone",
  [207] = "petrified_wood",
  [208] = "graphite",
  [209] = "brimstone",
  [210] = "kimberlite",
  [211] = "bismuthinite",
  [212] = "realgar",
  [213] = "orpiment",
  [214] = "stibnite",
  [215] = "marcasite",
  [216] = "sylvite",
  [217] = "cryolite",
  [218] = "periclase",
  [219] = "llmenite",
  [220] = "rutile",
  [221] = "magnetite",
  [222] = "chromite",
  [223] = "pyrolusite",
  [224] = "pitchblende",
  [225] = "bauxite",
  [226] = "native_aluminum",
  [227] = "borax",
  [228] = "olivine",
  [229] = "hornblende",
  [230] = "kaolinite",
  [231] = "serpentine",
  [232] = "orthoclase",
  [233] = "microcline",
  [234] = "mica",
  [235] = "calcite",
  [236] = "saltpeter",
  [237] = "alabaster",
  [238] = "selenite",
  [239] = "satinspar",
  [240] = "anhydrite",
  [241] = "alunite",
  [242] = "raw_adamantine",
  [243] = "slade",
  [244] = "clay",
  [245] = "silty_clay",
  [246] = "sandy_clay",
  [247] = "clay_loam",
  [248] = "sandy_clay_loam",
  [249] = "silty_clay_loam",
  [250] = "loam",
  [251] = "sandy_loam",
  [252] = "silt_loam",
  [253] = "loamy_sand",
  [254] = "silt",
  [255] = "tan_sand",
  [256] = "yellow_sand",
  [257] = "white_sand",
  [258] = "black_sand",
  [259] = "red_sand",
  [260] = "peat",
  [261] = "pelagic_clay",
  [262] = "calcareous_ooze",
  [263] = "silliceous_ooze",
  [264] = "fire_clay"
}

TileTypeShapeTable = 
{
  [df.tiletype_shape.EMPTY] = "a", --0
  [df.tiletype_shape.FLOOR] = "f",
  [df.tiletype_shape.BOULDER] = "f",
  [df.tiletype_shape.PEBBLES] = "f",
  [df.tiletype_shape.WALL] = "w", --4
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
  ["A"] = "B",
  ["B"] = "C",
  ["C"] = "D",
  ["D"] = "E",
  ["E"] = "F",
  ["F"] = "G",
  ["G"] = "H",
  ["H"] = "I",
  ["I"] = "J",
  ["J"] = "K",
  ["K"] = "L",
  ["L"] = "M",
  ["M"] = "N",
  ["N"] = "O",
  ["O"] = "P",
  ["P"] = "Q",
  ["Q"] = "R",
  ["R"] = "S",
  ["S"] = "T",
  ["T"] = "U",
  ["U"] = "V",
  ["V"] = "W",
  ["W"] = "X",
  ["X"] = "Y",
  ["Y"] = "Z",
  ["Z"] = nil
}

NaturalMaterialsTable = 
{
  ["aa"] = "hidden", --defaults and test values
  ["ag"] = "grass_light",
  ["ah"] = "grass_dark",
  ["ai"] = "grass_dry",
  ["aj"] = "grass_dead",
  ["ar"] = "root",
  ["at"] = "tree"
}

--next_material_letter = "a"
--next_material_letter to next_material_sequence
--a_ are reserved for predefined materials like hidden
--aka aa, ab, az and so on
next_material_sequence = "aZ"
opal_prospect_file = 0
layer_write_count = 0
--end globals

local function materialLocation(table, material)
  for key, value in pairs(table) do
    if(value == material) then
      return key
    end
  end

  return nil --failed to find material
end

--get the next two char string for a material
local function getNextSequence()
  local char_a = string.sub(next_material_sequence, 1, 1)
  local char_b = string.sub(next_material_sequence, 2, 2)
  char_b = CharacterTable[char_b]
  if char_b == nil then
    char_a = CharacterTable[char_a]
    char_b = "a"
  end

  return char_a..char_b
end

local function addMaterial(type_index, material_index)
  local name
  local table
  if type_index == 0 then
    name = InorganicMaterialNumberToString[material_index]
    if name == nil then
      print(dfhack.matinfo.decode(type_index, material_index))
      error("unknown inorganic material index")
    end
    table = NaturalMaterialsTable
  else
    error("unknown type index")
  end

  local sequence = materialLocation(table, name)
  if sequence ~= nil then --we already have this material in the table so return the key
    return sequence
  else --make new key and add this material name to the table
    next_material_sequence = getNextSequence()
    if next_material_sequence == nil then
      error("Next letter table returned nil. Bug or too many natural tile types")
    end
    table[next_material_sequence] = name
    return next_material_sequence
  end
end

--assumes that table is the top level cache
local function addBiomeLayers(table, biome)
  local index = biome.index
  local cache = table[index]
  if cache == nil then
    cache = {}
    for key, layer in ipairs(table) do
      cache[key] = addMaterial(0, layer.mat_index)
    end
  end
end

local function veinValue(flags)
  if flags.cluster then
    return 1
  elseif flags.vein then
    return 2
  elseif flags.cluster_small then
    return 3
  elseif flags.cluster_one then
    return 4
  else
    error("unknown vein flag")
  end
end

local function getVeinMaterial(vein_cache, x, y) --vein cache table with all veins for this map block, full x and y value x_block * 16 + x and y_block * 16 + y
  local tile_vein
  local vein_value = 0
  local saved_key

  for key, vein in ipairs(vein_cache.veins) do
    if dfhack.maps.getTileAssignment(vein.tile_bitmask, x, y) then
      local temp = veinValue(vein.flags)
      if temp >= vein_value then
        vein_value = temp
        tile_vein = vein
        saved_key = key
      end
    end
  end

  if tile_vein == nil then
    --error("Tile vein is nil at :"..x..", "..y)
    return nil
  end

  local result = vein_cache.letters[saved_key]
  if result == nil then
    result = addMaterial(0, tile_vein.inorganic_mat)
    vein_cache.letters[saved_key] = result
  end

  return result
end

local function writeHeader(version, width, height, length)
  io.write(version.." "..width.." "..height.." "..length.."\n\n")
end

local function writeMaterialTable()
  io.write("natural_materials\n")
  for key, value in pairs(NaturalMaterialsTable) do
    io.write(key.." "..value.."\n")
  end
  io.write("natural_materials_end\n")
end

local function writeShapeTable()
  io.write("natural_types\n")
  io.write("a air\n")
  io.write("w block\n")
  io.write("f floor\n")
  io.write("natural_types_end\n")
end

local function writeLayer(material, shape)
  io.write(material.."\n")
  io.write(shape.."\n")
  layer_write_count = layer_write_count + 1
end

--assumes that table is the top level cache
local function addBiomeLayers(layer_cache, biome)
  local index = biome.index
  local cache = layer_cache[index]
  if cache == nil then
    layer_cache[index] = {}
    cache = layer_cache[index]
    for key, layer in ipairs(biome.layers) do
      cache[key] = addMaterial(0, layer.mat_index)
    end
  end
end

local function addRegionXY(xy_cache, region_x, region_y, new_biome_index)
  local table = xy_cache[region_x]
  if table == nil then
    xy_cache[region_x] = {}
  end

  local biome_index = xy_cache[region_x][region_y]
  if biome_index == nil then
    xy_cache[region_x][region_y] = new_biome_index
  end
end

--without first check may get nil error. must check first table to see if nil and then can try the next layer
local function getBiomeIndex(xy_cache, region_x, region_y)
  if xy_cache[region_x] == nil then 
    return nil
  else 
    return xy_cache[region_x][region_y]
  end
end

local function cacheSetup(xy_cache, layer_cache, lavastone_cache, world_x, world_y)
  for y = 0, world_y - 1, 1 do
    for x = 0, world_x - 1, 1 do
      local region_x, region_y = dfhack.maps.getTileBiomeRgn(x, y, 0)
      local biome_index = getBiomeIndex(xy_cache, region_x, region_y)
      local regions
      --see if we already have this index. if not add it with the biome index
      if biome_index == nil then
        biome_index = dfhack.maps.getRegionBiome(region_x, region_y).geo_index
        addRegionXY(xy_cache, region_x, region_y, biome_index)
      end

      --check if we have this biome already
      local biome = layer_cache[biome_index]
      if biome == nil then
        biome = df.world_geo_biome.find(biome_index)
        addBiomeLayers(layer_cache, biome)
      end

      local lava_stone = lavastone_cache[biome_index]
      if lava_stone == nil then
        regions = df.global.world.world_data.region_details
        for _, region in ipairs(regions) do
          if region.pos.x == region_x and region.pos.y == region_y then
            lavastone_cache[biome_index] = addMaterial(0, region.lava_stone)
            break
          end
        end
      end
    end
  end
end

local function main(filename)
--printall(TileTypeMaterialTable)
local world_x, world_y, world_z
world_x, world_y, world_z = dfhack.maps.getTileSize()
print("world size x: "..world_x.." y: "..world_y.." z: "..world_z)

local block_x_count = world_x / 16 --blocks are 16x16x1 pieces of the map. Each embark tile is 3x3 of these
local block_y_count = world_y / 16

--caches
local block_cache = {} --hold a line of blocks to save looking them up multiple times
local vein_cache = {} -- same as block cache but this holds the veins for the current blocks and their material letter
local biome_xy_cache = {} --holds the region x and region y values we find. they are used to find region biome and the index to the actual biome. saves this index so we can look up in layer_cache
local biome_layer_cache = {} --hold all embark biome's layer letters. These already have their material known and added to the proper table. give the geolayer_index and it gives the letter
local biome_lava_stone_cache = {} --holds each embark biome's lava letter. give lava_stone to get the letter
local tile_type_shape_cache = {} --tile type value to shape letter
local tile_type_material_cache = {} --tile type value to material enum. These are contained in TileTypeMaterialTable
--end caches

if filename == nil then
  filename = "opal.txt"
end

print("saving to file named: "..filename)
opal_prospect_file = io.open(filename, "w")
io.output(opal_prospect_file)
--debug stuff
--world_z = 22
--end debug stuff
writeHeader("v0.2", world_x, world_z, world_y) --z and y need to be swapped for opal prospect

--setup caches
--per embark tile caches
--change to be biome caches instead. Add as we find them. region.geo_index is the same as the biome.index so use this as a unique id
--so have a table of [region x][region y] that contains the geolayer index, filled in as you find nils
--another table of each biome of this index, so geolayer_index of 10 means there is a biome with an index of 10. each biome has a lava stone, and a table of layers which can be turned into letters
--z shouldnt matter so run getTileBiomeRgn for each x and y at z of 0, and make the list of biomes from this. Then for each lava/layer needed later run just getTileBiomeRgn to see what biome index we need to pull from. can fill this in before
--the first run but make sure we can add more biomes later if a x,y,z returns one not found. getRegionBiome(regionx, regiony).geo_index has the unique id
--Reason for the change is that what biome each tile points to does not change on the 16x16x1 range. Can go 10 tiles to the right and then switch which biome they contain. causes nils when the biomes contain different number of layers
  cacheSetup(biome_xy_cache, biome_layer_cache, biome_lava_stone_cache, world_x, world_y)
  local tile_count = 0

--end setup caches

  for z = 0, world_z - 1, 1 do --start at 0 and go until world_z - 1. changes here are just for testing such as starting at higher height
    --set defaults
    local wall_material_count = 0
    local shape_count = 0
    local current_wall_material = " "
    local current_shape = " "
    local wall_material_output = ""
    local shape_output = ""

    for y_block = block_y_count - 1, 0, -1 do
      for index = 0, block_x_count - 1, 1 do
        block_cache[index] = dfhack.maps.getBlock(index, y_block, z)
        --block_cache[index] = dfhack.maps.ensureTileBlock(index, y_block, z)
        vein_cache[index] = { ["veins"] = {}, ["letters"] = {} } --each map block two tables. one table of the vein events and one table of the letter for each. don't populate the letters unless they are accessed
        --so vein 1(the start) would have a vein_cache[same x_block location].letters[1]. if this is nil it has not been accessed or added yet. vein 2 vein_cache[same x_block location].letters[2]

        for _, event in ipairs(block_cache[index].block_events) do
          if getmetatable(event) == "block_square_event_mineralst" then
            table.insert(vein_cache[index].veins, event)
          end
        end
      end
      for y = 15, 0, -1 do
        for x_block = 0, block_x_count - 1, 1 do
          for x = 0, 15, 1 do
            --check if hidden. if not get the shape and update tiletype to shape cache. then lookup material based on tiletype
            local designations = block_cache[x_block].designation[x][y]
            local wall_material
            local shape
            local tile_material_enum --holds number or letter if it's predefined
            --set defaults for a hidden block which is WALL and HIDDEN
            if designations.hidden then
              wall_material = "aa"
              shape = "w"
            else
              local tile_type = dfhack.maps.getTileType(x_block * 16 + x, y_block * 16 + y, z)
              local region_x, region_y = dfhack.maps.getTileBiomeRgn(x_block * 16 + x, y_block * 16 + y, 0)
              local biome_index = biome_xy_cache[region_x][region_y]
              --print("tiletype "..tile_type.." at "..16 * x_block + x..", "..16 * y_block + y..", "..z)
              tile_material_enum = tile_type_material_cache[tile_type]
              shape =  tile_type_shape_cache[tile_type]

              if shape == nil then --update tile type caches
                local tile_attributes = df.tiletype.attrs[tile_type]
                tile_type_shape_cache[tile_type] = TileTypeShapeTable[tile_attributes.shape]
                tile_type_material_cache[tile_type] = tile_attributes.material
                tile_material_enum = tile_type_material_cache[tile_type]
                shape =  tile_type_shape_cache[tile_type]
                if tile_material_enum == nil then
                  error("Bug at update tile cache. wall material nil at x, y, z "..x_block * 16 + x..", "..y_block * 16 + y..", "..z)
                end
                if shape == nil then
                  error("Bug at update tile cache. shape nil at x, y, z "..x_block * 16 + x..", "..y_block * 16 + y..", "..z)
                end
              end

              if shape == "a" then
                wall_material = "aa"
              elseif shape == "f" then
                --wall_material = "aa" --set wall to this, later on when there is a wall and floor material we will deal with the floor material
                wall_material = TileTypeMaterialTable[tile_material_enum] --wall material has the enum so put that into the material table to see what to do
                if wall_material == 1 then --layer material
                  wall_material = biome_layer_cache[biome_index][designations.geolayer_index]
                elseif wall_material == 2 then --lava stone
                  wall_material = biome_lava_stone_cache[biome_index]
                elseif wall_material == 3 then --vein
                  wall_material = getVeinMaterial(vein_cache[x_block], x_block * 16 + x, y_block * 16 + y) --floors CAN be natural vein materials
                  if wall_material == nil then
                    error("floor tile vein is nil at :"..x + 16 * x_block..", "..y + 16 * y_block..", "..z)
                  end
                end
              elseif shape == "w" then
                --print(wall_material)
                wall_material = TileTypeMaterialTable[tile_material_enum] --wall material has the enum so put that into the material table to see what to do
                if wall_material == 1 then --layer material
                  wall_material = biome_layer_cache[biome_index][designations.geolayer_index]
                elseif wall_material == 2 then --lava stone
                  wall_material = biome_lava_stone_cache[biome_index]
                elseif wall_material == 3 then --vein
                  wall_material = getVeinMaterial(vein_cache[x_block], x_block * 16 + x, y_block * 16 + y)
                  if wall_material == nil then
                    error("wall tile vein is nil at :"..x + 16 * x_block..", "..y + 16 * y_block..", "..z)
                  end
                end
                --can't use else above because if it's not one of those it must have a pre defined material
              else
                error("Bug. unknown shape letter")
              end
            end

            --check if any of the letters have changed and deal with it
            if wall_material ~= current_wall_material then --material and shape must be done seperate
              if current_wall_material ~= " " then --if not default append
                wall_material_output = wall_material_output..wall_material_count..current_wall_material
                --print(wall_material_count..current_wall_material)
                --tile_count = tile_count + wall_material_count
              end
              current_wall_material = wall_material
              wall_material_count = 1
            else
              wall_material_count = wall_material_count + 1
            end

            if shape ~= current_shape then
              if current_shape ~= " " then
                shape_output = shape_output..shape_count..current_shape
              end
              current_shape = shape
              shape_count = 1
            else
              shape_count = shape_count + 1
            end
            --tile_count = tile_count + 1
          end
        end
      end
    end
    wall_material_output = wall_material_output..wall_material_count..current_wall_material --append the last letter and count to proper string
    --tile_count = tile_count + wall_material_count
    shape_output = shape_output..shape_count..current_shape
    writeLayer(wall_material_output, shape_output) --write current output then reset both outputs and all counts and letters
  end

writeMaterialTable()
writeShapeTable()
opal_prospect_file.close()

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
--print("inorganic table")
--printall(InorganicMaterialNumberToString)
printall(NaturalMaterialsTable)
--print("tile count: "..tile_count)
print("layer write count: "..layer_write_count)

end

args = {...}
--printall(args) --script name is ignored. starting at 1 you see what you typed after the script name

main(args[1])
