#pragma once

//std lib includes
#include <string>
#include <unordered_map>

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

/*
Description: Enums, strings, and filenames for all natural tiles. This means soil, rough stone, liquid, ore, and gems. No HFS or grass/organic material
*/

enum DF_Material_Type
{
    DF_NATURAL_HIDDEN,
    DF_NATURAL_GEM,
    DF_NATURAL_LIQUID,
    DF_NATURAL_ORE,
    DF_NATURAL_SOIL,
    DF_NATURAL_STONE
};

enum DF_Natural_Tile_Material
{
    //gem start
    DF_ALMANDINE,
    DF_ALEXANDRITE,
    DF_AMBER_OPAL,
    DF_AMETHYST,
    DF_AQUAMARINE,
    DF_AVENTURINE,
    DF_BANDED_AGATE,
    DF_BANDIRE_OPAL,
    DF_BLACK_DIAMOND,
    DF_BLACK_OPAL,
    DF_BLACK_PYROPE,
    DF_BLACK_ZIRCON,
    DF_BLOODSTONE,
    DF_BLUE_DIAMOND,
    DF_BLUE_GARNET,
    DF_BLUE_JADE,
    DF_BONE_OPAL,
    DF_BROWN_JASPER,
    DF_BROWN_ZIRCON,
    DF_CARNELIAN,
    DF_CATS_EYE,
    DF_CHERRY_OPAL,
    DF_CHRYSOBERYL,
    DF_CHRYSOCOLLA,
    DF_CHRYSOPRASE,
    DF_CINNAMON_GROSSULAR,
    DF_CITRINE,
    DF_CLARO_OPAL,
    DF_CLEAR_DIAMOND,
    DF_CLEAR_GARNET,
    DF_CLEAR_GLASS,
    DF_CLEAR_TOURMALINE,
    DF_CLEAR_ZIRCON,
    DF_CRYSTAL_GLASS,
    DF_CRYSTAL_OPAL,
    DF_DEMANTOID,
    DF_DENDRITIC_AGATE,
    DF_EMERALD,
    DF_FAINT_YELLOW_DIAMOND,
    DF_FIRE_AGATE,
    DF_FIRE_OPAL,
    DF_FORTIFICATION_AGATE,
    DF_GOLD_OPAL,
    DF_GOLDEN_BERYL,
    DF_GOSHENITE,
    DF_GRAY_CHALCEDONY,
    DF_GREEN_DIAMOND,
    DF_GREEN_GLASS,
    DF_GREEN_JADE,
    DF_GREEN_TOURMALINE,
    DF_GREEN_ZIRCON,
    DF_HARLEQUIN_OPAL,
    DF_HELIODOR,
    DF_HONEY_YELLOW_BERYL,
    DF_INDIGO_TOURMALINE,
    DF_JASPER_OPAL,
    DF_JELLY_OPAL,
    DF_KUNZITE,
    DF_LACE_AGATE,
    DF_LAPIS_LAZULI,
    DF_LAVENDER_JADE,
    DF_LEVIN_OPAL,
    DF_LIGHT_YELLOW_DIAMOND,
    DF_MELANITE,
    DF_MILK_OPAL,
    DF_MILK_QUARTZ,
    DF_MOONSTONE,
    DF_MORGANITE,
    DF_MORION,
    DF_MOSS_AGATE,
    DF_MOSS_OPAL,
    DF_ONYX,
    DF_ONYX_OPAL,
    DF_PERIDOT,
    DF_PICTURE_JASPER,
    DF_PINEAPPLE_OPAL,
    DF_PINFIRE_OPAL,
    DF_PINK_GARNET,
    DF_PINK_JADE,
    DF_PINK_TOURMALINE,
    DF_PIPE_OPAL,
    DF_PLUME_AGATE,
    DF_PRASE,
    DF_PRASE_OPAL,
    DF_PRECIOUS_FIRE_OPAL,
    DF_PURPLE_SPINEL,
    DF_PYRITE,
    DF_RED_BERYL,
    DF_RED_DIAMOND,
    DF_RED_FLASH_OPAL,
    DF_RED_GROSSULAR,
    DF_RED_PYROPE,
    DF_RED_SPINEL,
    DF_RED_TOURMALINE,
    DF_RED_ZIRCON,
    DF_RESIN_OPAL,
    DF_RHODOLITE,
    DF_ROCK_CRYSTAL,
    DF_ROSE_QUARTZ,
    DF_RUBICELLE,
    DF_RUBY,
    DF_SAPPHIRE,
    DF_SARD,
    DF_SARDONYX,
    DF_SCHORL,
    DF_SHELL_OPAL,
    DF_SMOKY_QUARTZ,
    DF_STAR_RUBY,
    DF_STAR_SAPPHIRE,
    DF_SUNSTONE,
    DF_TANZANITE,
    DF_TIGER_IRON,
    DF_TIGEREYE,
    DF_TOPAZ,
    DF_TOPAZOLITE,
    DF_TSAVORITE,
    DF_TUBE_AGATE,
    DF_TURQUOISE,
    DF_VARISCITE,
    DF_VIOLET_SPESSARTINE,
    DF_WAX_OPAL,
    DF_WHITE_CHALCEDONY,
    DF_WHITE_JADE,
    DF_WHITE_OPAL,
    DF_WOOD_OPAL,
    DF_YELLOW_DIAMOND,
    DF_YELLOW_GROSSULAR,
    DF_YELLOW_JASPER,
    DF_YELLOW_SPESSARTINE,
    DF_YELLOW_ZIRCON,
    //gem end

    //liquid start
    DF_MAGMA_MATERIAL,
    DF_WATER_MATERIAL,
    //liquid end

    //ore start
    DF_RAW_ADAMANTINE,
    DF_NATIVE_ALUMINUM,
    DF_BISMUTHINITE,
    DF_CASSITERITE,
    DF_NATIVE_COPPER,
    DF_GALENA,
    DF_GARNIERITE,
    DF_NATIVE_GOLD,
    DF_HEMATITE,
    DF_HORN_SILVER,
    DF_LIMONITE,
    DF_MAGNETITE,
    DF_MALACHITE,
    DF_NATIVE_PLATINUM,
    DF_NATIVE_SILVER,
    DF_SPHALERITE,
    DF_TETRAHEDRITE,
    //ore end

    //soils start
    DF_BLACK_SAND,
    DF_CALCAREOUS_OOZE,
    DF_CLAY,
    DF_CLAY_LOAM,
    DF_FIRE_CLAY,
    DF_LOAM,
    DF_LOAMY_SAND,
    DF_PEAT,
    DF_PELAGIC_CLAY,
    DF_RED_SAND,
    DF_SAND,
    DF_SANDY_CLAY,
    DF_SANDY_CLAY_LOAM,
    DF_SANDY_LOAM,
    DF_SILLICEOUS_OOZE,
    DF_SILT,
    DF_SILT_LOAM,
    DF_SILTY_CLAY,
    DF_SILTY_CLAY_LOAM,
    DF_WHITE_SAND,
    DF_YELLOW_SAND,
    //soil end

    //stone start
    DF_ALABASTER,
    DF_ALUNITE,
    DF_ANDESITE,
    DF_ANHYDRITE,
    DF_BASALT,
    DF_BAUXITE,
    DF_BITUMINOUS_COAL,
    DF_BORAX,
    DF_BRIMSTONE,
    DF_CALCITE,
    DF_CHALK,
    DF_CHERT,
    DF_CHROMITE,
    DF_CINNABAR,
    DF_CLAYSTONE,
    DF_COBALTITE,
    DF_CONGLOMERATE,
    DF_CRYOLITE,
    DF_DACITE,
    DF_DIORITE,
    DF_DOLOMITE,
    DF_GABBRO,
    DF_GNEISS,
    DF_GRANITE,
    DF_GRAPHITE,
    DF_GYPSUM,
    DF_HORNBLENDE,
    DF_JET,
    DF_KAOLINITE,
    DF_KIMBERLITE,
    DF_LIGNITE,
    DF_LIMESTONE,
    DF_ILMENITE,
    DF_MARBLE,
    DF_MARCASITE,
    DF_MICA,
    DF_MICROCLINE,
    DF_MUDSTONE,
    DF_OBSIDIAN,
    DF_OLIVINE,
    DF_ORPIMENT,
    DF_ORTHOCLASE,
    DF_PERICLASE,
    DF_PETRIFIED_WOOD,
    DF_PHYLLITE,
    DF_PITCHBLENDE,
    DF_PUDDINGSTONE,
    DF_PYROLUSITE,
    DF_QUARTZITE,
    DF_REALGAR,
    DF_RHYOLITE,
    DF_ROCK_SALT,
    DF_RUTILE,
    DF_SALTPETER,
    DF_SANDSTONE,
    DF_SATINSPAR,
    DF_SCHIST,
    DF_SELENITE,
    DF_SERPENTINE,
    DF_SHALE,
    DF_SILTSTONE,
    DF_SLADE,
    DF_SLATE,
    DF_STIBNITE,
    DF_SYLVITE,
    DF_TALC,
    //stone end
    DF_HIDDEN,
    DF_NATURAL_TILE_COUNT //never add below this one only above it
};

std::string DFNaturalTileString(DF_Natural_Tile_Material e);
std::string DFNaturalTileFilename(DF_Natural_Tile_Material e);
DF_Material_Type DFNaturalType(DF_Natural_Tile_Material e);
std::unordered_map <std::string, DF_Natural_Tile_Material> getReverseOfDFNaturalStringTable(); //get a table that has the strings point to which enum they are from. Does the opposite of df natural tile string(enum) does. String to enum

