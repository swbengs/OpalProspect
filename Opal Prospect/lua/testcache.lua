
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
  ["Z"] = "!",
  --special characters
  ["!"] = "\"",
  ["\""] = "#",
  ["#"] = "$",
  ["$"] = "%",
  ["%"] = "&",
  ["&"] = "\'",
  ["\'"] = "(",
  ["("] = ")",
  [")"] = "*",
  ["*"] = "+",
  ["+"] = ",",
  [","] = "-",
  ["-"] = ".",
  ["."] = "/",
  ["/"] = ":",
  [":"] = ";",
  [";"] = "<",
  ["<"] = "=",
  ["="] = ">",
  [">"] = "?",
  ["?"] = "@",
  ["@"] = "[",
  ["["] = "\\",
  ["\\"] = "]",
  ["]"] = "^",
  ["^"] = "_",
  ["_"] = "`",
  ["`"] = "{",
  ["{"] = "|",
  ["|"] = "}",
  ["}"] = "~",
  ["~"] = nil
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

NaturalMaterialsTable = 
{
  ["aa"] = "hidden", --defaults and test values
  ["ab"] = "root"
}

next_material_sequence = "a~"

--end globals

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

local function cacheSetup(xy_cache, layer_cache, lavastone_cache, world_x, world_y, world_z)
  for z = 0, world_z - 1, 1 do
    for y = 0, world_y - 1, 1 do
      for x = 0, world_x - 1, 1 do
        local region_x, region_y = dfhack.maps.getTileBiomeRgn(x, y, z)
        if region_x == nil then
          --error("Layer :"..z.." returned nil for region_x")
          return --appears that at or around the added air spot it just gives nils for the region coords. So just return
        elseif region_y == nil then
          --error("Layer :"..z.." returned nil for region_y")
          return
        end
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
        else --sanity check to see if z changes what biome this points to. Grab this blocks biome index anyways and make sure it matches
          local test_biome_index = dfhack.maps.getRegionBiome(region_x, region_y).geo_index
          local test_biome = df.world_geo_biome.find(biome_index)
          if test_biome.index ~= biome_index then
            error("Biome indexs do not match for region x,y: "..region_x..", "..region_y)
          end
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
end

local function printXYCache(cache)
  for region_x, y_table in pairs(cache) do
    for region_y, biome_index in pairs(y_table) do
      print("region x, y: "..region_x..", "..region_y.." | biome index: "..biome_index)
    end
  end
end

local function printLayerCache(cache)
  for biome_index, layers in pairs(cache) do
    print("biome #: "..biome_index)
    for layer_index, material_sequence in pairs(layers) do
      print("layer_index: "..layer_index.." | layer material_sequence: "..material_sequence)
    end
  end
end

local function printLavastoneCache(cache)
  for biome_index, material_sequence in pairs(cache) do
    print("biome #: "..biome_index.." | lavastone material_sequence: "..material_sequence)
  end
end

local function printMaterialsTable()
  for sequence, name in pairs(NaturalMaterialsTable) do
    print("material sequence: "..sequence.." | material name: "..name)
  end
end

function main()
local world_x, world_y, world_z
world_x, world_y, world_z = dfhack.maps.getTileSize()
print("world size x: "..world_x.." y: "..world_y.." z: "..world_z)

local biome_xy_cache = {}
local biome_layer_cache = {}
local biome_lavastone_cache = {}

cacheSetup(biome_xy_cache, biome_layer_cache, biome_lavastone_cache, world_x, world_y, world_z)
--cacheSetup(biome_xy_cache, biome_layer_cache, biome_lavastone_cache, world_x, world_y, 1)

printXYCache(biome_xy_cache)
print("")
printLayerCache(biome_layer_cache)
print("")
printLavastoneCache(biome_lavastone_cache)
print("")
printMaterialsTable()
print("")


end

main()

