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
  [df.tiletype_material.SOIL] = 1,
  [df.tiletype_material.STONE] = 1,
  [df.tiletype_material.FEATURE] = "a",
  [df.tiletype_material.LAVA_STONE] = "a",
  [df.tiletype_material.MINERAL] = "D",
  [df.tiletype_material.FROZEN_LIQUID] = "a",
  [df.tiletype_material.CONSTRUCTION] = 1,
  [df.tiletype_material.GRASS_LIGHT] = 1,
  [df.tiletype_material.GRASS_DARK] = 1,
  [df.tiletype_material.GRASS_DRY] = 1,
  [df.tiletype_material.GRASS_DEAD] = 1,
  [df.tiletype_material.PLANT] = 1,
  [df.tiletype_material.HFS] = "a",
  [df.tiletype_material.CAMPFIRE] = 1,
  [df.tiletype_material.FIRE] = "a",
  [df.tiletype_material.ASHES] = "a",
  [df.tiletype_material.MAGMA] = "a",
  [df.tiletype_material.DRIFTWOOD] = 1,
  [df.tiletype_material.POOL] = "E",
  [df.tiletype_material.BROOK] = "E",
  [df.tiletype_material.RIVER] = "E",
  [df.tiletype_material.ROOT] = "E",
  [df.tiletype_material.TREE] = 1,
  [df.tiletype_material.MUSHROOM] = 1,
  [df.tiletype_material.UNDERWORLD_GATE] = "a"
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
  [102] = "perido",
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
  [174] = "hornblende",
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

NaturalMaterialsTable = 
{
  ["a"] = "hidden", --defaults and test values
  ["D"] = "tetrahedrite",
  ["E"] = "aluminum"
}

next_material_letter = "a"
opal_prospect_file = 0
--end globals

local function materialLocation(table, material)
  for key, value in pairs(table) do
    if(value == material) then
      return key
    end
  end

  return nil --failed to find material
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

  local letter = materialLocation(table, name)
  if letter ~= nil then --we already have this material in the table so return the key
    return letter
  else --make new key and add this material name to the table
    next_material_letter = CharacterTable[next_material_letter]
    table[next_material_letter] = name
    return next_material_letter
  end
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
end

local function main()
local world_x, world_y, world_z
world_x, world_y, world_z = dfhack.maps.getTileSize()
print("world size x: "..world_x.." y: "..world_y.." z: "..world_z)

local block_x_count = world_x / 16 --blocks are 16x16x1 pieces of the map. Each embark tile is 3x3 of these
local block_y_count = world_y / 16
local embark_x_count = world_x / 48
local embark_y_count = world_y / 48

local block_cache_table = {} --hold a line of blocks to save looking them up multiple times
local biome_cache_table = {} --hold all embark biomes
local tile_type_material = {} --same as shape but for material
local tile_type_shape = {} --tile type value to shape letter. tile type numbers are duplicated since both tables have one

opal_prospect_file = io.open("opal.txt", "w")
io.output(opal_prospect_file)
writeHeader("v0.2", world_x, world_z, world_y) --z and y need to be swapped for opal prospect

for embark_y = embark_y_count - 1, 0, -1 do
  for embark_x = 0, embark_x_count - 1, 1 do
    biome_cache_table[embark_x + embark_y * embark_x_count] = df.world_geo_biome.find(dfhack.maps.getRegionBiome(dfhack.maps.getTileBiomeRgn(48 * embark_x, 48 * embark_y, 0)).geo_index)
  end
end

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
            local designations = block_cache_table[x_block].designation[x][y]
            local current_material
            local current_shape
            --set defaults for a hidden block which is WALL and HIDDEN
            if designations.hidden then
              current_material = "a"
              current_shape = "w"
            else
              local tile_type = dfhack.maps.getTileType(x + 16 * x_block, y + 16 * y_block, z)
              current_material = tile_type_material[tile_type]
              current_shape =  tile_type_shape[tile_type]
              if current_shape == nil then --if shape is missing then material is also
                local tile_attributes = df.tiletype.attrs[tile_type]
                tile_type_shape[tile_type] = TileTypeShapeTable[tile_attributes.shape]

                if TileTypeMaterialTable[tile_attributes.material] == 1 then --get layer material
                  local biome = biome_cache_table[math.floor(x_block / 3) + math.floor(y_block / 3)]
                  local material = biome.layers[designations.geolayer_index].mat_index
                  current_material = addMaterial(0, material)
                  tile_type_material[tile_type] = current_material
                else
                  tile_type_material[tile_type] = TileTypeMaterialTable[tile_attributes.material]
                end

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

end

main()
