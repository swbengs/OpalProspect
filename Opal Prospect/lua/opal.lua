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
  [34] = "ONYX",
  [35] = "MORION",
  [36] = "SCHORL",
  [37] = "LACE AGATE",
  [38] = "BLUE JADE",
  [39] = "LAPIS LAZULI",

  [40] = "PRASE",
  [41] = "PRASEOPAL",
  [42] = "BLOODSTONE",
  [43] = "MOSSAGATE",
  [44] = "MOSSOPAL",
  [45] = "VARISCITE",
  [46] = "CHRYSOPRASE",
  [47] = "CHRYSOCOLLA",
  [48] = "SARD",
  [49] = "CARNELIAN",

  [50] = "BANDEDAGATE",
  [51] = "SARDONYX",
  [52] = "CHERRYOPAL",
  [53] = "LAVENDERJADE",
  [54] = "PINKJADE",
  [55] = "TUBEAGATE",
  [56] = "FIREAGATE",
  [57] = "PLUMEAGATE",
  [58] = "BROWNJASPER",
  [59] = "PICTUREJASPER",

  [60] = "SMOKYQUARTZ",
  [61] = "WAXOPAL",
  [62] = "WOODOPAL",
  [63] = "AMBEROPAL",
  [64] = "GOLDOPAL",
  [65] = "CITRINE",
  [66] = "YELLOWJASPER",
  [67] = "TIGEREYE",
  [68] = "TIGERIRON",
  [69] = "SUNSTONE",

  [70] = "RESINOPAL",
  [71] = "PYRITE",
  [72] = "CLEARTOURMALINE",
  [73] = "GRAYCHALCEDONY",
  [74] = "DENDRITICAGATE",
  [75] = "SHELLOPAL",
  [76] = "BONEOPAL",
  [77] = "WHITECHALCEDONY",
  [78] = "FORTIFICATIONAGATE",
  [79] = "MILKQUARTZ",

  [80] = "MOONSTONE",
  [81] = "WHITEJADE",
  [82] = "JASPEROPAL",
  [83] = "PINEAPPLEOPAL",
  [84] = "ONYXOPAL",
  [85] = "MILKOPAL",
  [86] = "PIPEOPAL",
  [87] = "AVENTURINE",
  [88] = "TURQUOISE",
  [89] = "QUARTZ_ROSE",

  [90] = "CRYSTAL_ROCK",
  [91] = "BLACKZIRCON",
  [92] = "BLACKPYROPE",
  [93] = "MELANITE",
  [94] = "INDIGOTOURMALINE",
  [95] = "BLUEGARNET",
  [96] = "TSAVORITE",
  [97] = "GREENTOURMALINE",
  [98] = "DEMANTOID",
  [99] = "GREENZIRCON",

  [100] = "GREENJADE",
  [101] = "HELIODOR",
  [102] = "PERIDOT",
  [103] = "REDZIRCON",
  [104] = "REDTOURMALINE",
  [105] = "REDPYROPE",
  [106] = "ALMANDINE",
  [107] = "REDGROSSULAR",
  [108] = "PINKTOURMALINE",
  [109] = "REDBERYL",

  [110] = "FIREOPAL",
  [111] = "RHODOLITE",
  [112] = "SPINEL_PURPLE",
  [113] = "ALEXANDRITE",
  [114] = "TANZANITE",
  [115] = "MORGANITE",
  [116] = "VIOLETSPESSARTINE",
  [117] = "PINKGARNET",
  [118] = "KUNZITE",
  [119] = "CINNAMONGROSSULAR",

  [120] = "HONEYYELLOWBERYL",
  [121] = "JELLYOPAL",
  [122] = "BROWNZIRCON",
  [123] = "YELLOWZIRCON",
  [124] = "GOLDENBERYL",
  [125] = "YELLOWSPESSARTINE",
  [126] = "TOPAZ",
  [127] = "TOPAZOLITE",
  [128] = "YELLOWGROSSULAR",
  [129] = "RUBICELLE",

  [130] = "CLEARGARNET",
  [131] = "GOSHENITE",
  [132] = "CATS EYE",
  [133] = "CLEARZIRCON",
  [134] = "AMETHYST",
  [135] = "AQUAMARINE",
  [136] = "SPINEL_RED",
  [137] = "CHRYSOBERYL",
  [138] = "OPAL_PFIRE",
  [139] = "OPAL_REDFLASH",

  [140] = "OPAL_BLACK",
  [141] = "OPAL_WHITE",
  [142] = "OPAL_CRYSTAL",
  [143] = "OPAL_CLARO",
  [144] = "OPAL_LEVIN",
  [145] = "OPAL_HARLEQUIN",
  [146] = "OPAL_PINFIRE",
  [147] = "OPAL_BANDFIRE",
  [148] = "DIAMOND_LY",
  [149] = "DIAMOND_FY",

  [150] = "EMERALD",
  [151] = "RUBY",
  [152] = "SAPPHIRE",
  [153] = "DIAMOND_CLEAR",
  [154] = "DIAMOND_RED",
  [155] = "DIAMOND_GREEN",
  [156] = "DIAMOND_BLUE",
  [157] = "DIAMOND_YELLOW",
  [158] = "DIAMOND_BLACK",
  [159] = "SAPPHIRE_STAR",

  [160] = "RUBY_STAR",
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

--all writes will need to made into actual file writes and not just print to console
local function writeHeader(version, width, height, length)
  --print(version)
  --print(width.." "..height.." "..length)
  io.write(version.." "..width.." "..height.." "..length.."\n\n")
end

local function writeMaterialTable()
  --print("natural_materials")
  io.write("natural_materials\n")
  for key, value in pairs(NaturalMaterialsTable) do
    --print(key.." "..value)
    io.write(key.." "..value.."\n")
  end
  --print("natural_materials_end")
  io.write("natural_materials_end\n")
end

local function writeShapeTable()
  --print("natural_types")
  --print("a air")
  --print("w block")
  --print("f floor")
  --print("natural_types_end")
  io.write("natural_types\n")
  io.write("a air\n")
  io.write("w block\n")
  io.write("f floor\n")
  io.write("natural_types_end\n")
end

local function writeLayer(material, shape)
  --print(material)
  --print(shape)
  io.write(material.."\n")
  io.write(shape.."\n")
end

local function main()
--printall(TileTypeMaterialTable)
--printall(TileTypeShapeTable)

local world_x, world_y, world_z
world_x, world_y, world_z = dfhack.maps.getTileSize()
print("world size x: "..world_x.." y: "..world_y.." z: "..world_z)

local block_x_count = world_x / 16 --blocks are 16x16x1 pieces of the map. Each embark tile is 3x3 of these
local block_y_count = world_y / 16
print("block_x_count: "..block_x_count)
print("block_y_count: "..block_y_count)
local embark_x_count = world_x / 48
local embark_y_count = world_y / 48
print("embark_x_count: "..embark_x_count)
print("embark_y_count: "..embark_y_count)

local block_cache_table = {} --hold a line of blocks to save looking them up multiple times
local biome_cache_table = {} --hold all embark biomes
local tile_type_material = {} --same as shape but for material
local tile_type_shape = {} --tile type value to shape letter. tile type numbers are duplicated since both tables have one

local count = 0
local version = "v0.2"
opal_prospect_file = io.open("opal.txt", "w")
io.output(opal_prospect_file)
writeHeader(version, world_x, world_z, world_y) --z and y need to be swapped for opal prospect

for embark_y = embark_y_count - 1, 0, -1 do
  for embark_x = 0, embark_x_count - 1, 1 do
    biome_cache_table[embark_x + embark_y * embark_x_count] = df.world_geo_biome.find(dfhack.maps.getRegionBiome(dfhack.maps.getTileBiomeRgn(48 * embark_x, 48 * embark_y, 0)).geo_index)
  end
end

--for key, value in pairs(biome_cache_table) do
--  print(key)
--  print(value)
--end

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

writeMaterialTable()
writeShapeTable()
opal_prospect_file.close()
end

main()