#pragma once
#include "natural_tiles.hpp"

//std lib includes
#include <string>

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
Description: Enums, strings, and filenames for all natural tiles. This means soil, rough stone, liquid, ore, and gems.
*/

std::string DFNaturalTileString(DF_Natural_Tile_Material e)
{
    switch (e)
    {
        //gem start
    case DF_ALMANDINE:
        return "almandine";
    case DF_ALEXANDRITE:
        return "alexandrite";
    case DF_AMBER_OPAL:
        return "amber_opal";
    case DF_AMETHYST:
        return "amethyst";
    case DF_AQUAMARINE:
        return "aquamarine";
    case DF_AVENTURINE:
        return "aventurine";
    case DF_BANDED_AGATE:
        return "banded_agate";
    case DF_BANDIRE_OPAL:
        return "bandfire_opal";
    case DF_BLACK_DIAMOND:
        return "black_diamond";
    case DF_BLACK_OPAL:
        return "black_opal";
    case DF_BLACK_PYROPE:
        return "black_pyrope";
    case DF_BLACK_ZIRCON:
        return "black_zircon";
    case DF_BLOODSTONE:
        return "bloodstone";
    case DF_BLUE_DIAMOND:
        return "blue_diamond";
    case DF_BLUE_GARNET:
        return "blue_garnet";
    case DF_BLUE_JADE:
        return "blue_jade";
    case DF_BONE_OPAL:
        return "bone_opal";
    case DF_BROWN_JASPER:
        return "brown_jasper";
    case DF_BROWN_ZIRCON:
        return "brown_zircon";
    case DF_CARNELIAN:
        return "carnelian";
    case DF_CATS_EYE:
        return "cats_eye";
    case DF_CHERRY_OPAL:
        return "cherry_opal";
    case DF_CHRYSOBERYL:
        return "chrysoberyl";
    case DF_CHRYSOCOLLA:
        return "chrysocolla";
    case DF_CHRYSOPRASE:
        return "chrysoprase";
    case DF_CINNAMON_GROSSULAR:
        return "cinnamon_grossular";
    case DF_CITRINE:
        return "citrine";
    case DF_CLARO_OPAL:
        return "claro_opal";
    case DF_CLEAR_DIAMOND:
        return "clear_diamond";
    case DF_CLEAR_GARNET:
        return "clear_garnet";
    case DF_CLEAR_GLASS:
        return "clear_glass";
    case DF_CLEAR_TOURMALINE:
        return "clear_tourmaline";
    case DF_CLEAR_ZIRCON:
        return "clear_zircon";
    case DF_CRYSTAL_GLASS:
        return "crystal_glass";
    case DF_CRYSTAL_OPAL:
        return "crystal_opal";
    case DF_DEMANTOID:
        return "demantoid";
    case DF_DENDRITIC_AGATE:
        return "dendritic_agate";
    case DF_EMERALD:
        return "emerald";
    case DF_FAINT_YELLOW_DIAMOND:
        return "faint_yellow_diamond";
    case DF_FIRE_AGATE:
        return "fire_agate";
    case DF_FIRE_OPAL:
        return "fire_opal";
    case DF_FORTIFICATION_AGATE:
        return "fortification_agate";
    case DF_GOLD_OPAL:
        return "gold_opal";
    case DF_GOLDEN_BERYL:
        return "golden_beryl";
    case DF_GOSHENITE:
        return "goshenite";
    case DF_GRAY_CHALCEDONY:
        return "gray_chalcedony";
    case DF_GREEN_DIAMOND:
        return "green_diamond";
    case DF_GREEN_GLASS:
        return "green_glass";
    case DF_GREEN_JADE:
        return "green_jade";
    case DF_GREEN_TOURMALINE:
        return "green_tourmaline";
    case DF_GREEN_ZIRCON:
        return "green_zircon";
    case DF_HARLEQUIN_OPAL:
        return "harlequin_opal";
    case DF_HELIODOR:
        return "heliodor";
    case DF_HONEY_YELLOW_BERYL:
        return "honey_yellow_beryl";
    case DF_INDIGO_TOURMALINE:
        return "indigo_tourmaline";
    case DF_JASPER_OPAL:
        return "jasper_opal";
    case DF_JELLY_OPAL:
        return "jelly_opal";
    case DF_KUNZITE:
        return "kunzite";
    case DF_LACE_AGATE:
        return "lace_agate";
    case DF_LAPIS_LAZULI:
        return "lapis_lazuli";
    case DF_LAVENDER_JADE:
        return "lavender_jade";
    case DF_LEVIN_OPAL:
        return "levin_opal";
    case DF_LIGHT_YELLOW_DIAMOND:
        return "light_yellow_diamond";
    case DF_MELANITE:
        return "melanite";
    case DF_MILK_OPAL:
        return "milk_opal";
    case DF_MILK_QUARTZ:
        return "milk_quartz";
    case DF_MOONSTONE:
        return "moonstone";
    case DF_MORGANITE:
        return "morganite";
    case DF_MORION:
        return "morion";
    case DF_MOSS_AGATE:
        return "moss_agate";
    case DF_MOSS_OPAL:
        return "moss_opal";
    case DF_ONYX:
        return "onyx";
    case DF_ONYX_OPAL:
        return "onyx_opal";
    case DF_PERIDOT:
        return "peridot";
    case DF_PICTURE_JASPER:
        return "picture_jasper";
    case DF_PINEAPPLE_OPAL:
        return "pineapple_opal";
    case DF_PINFIRE_OPAL:
        return "pinfire_opal";
    case DF_PINK_GARNET:
        return "pink_garnet";
    case DF_PINK_JADE:
        return "pink_jade";
    case DF_PINK_TOURMALINE:
        return "pink_tourmaline";
    case DF_PIPE_OPAL:
        return "pipe_opal";
    case DF_PLUME_AGATE:
        return "plume_agate";
    case DF_PRASE:
        return "prase";
    case DF_PRASE_OPAL:
        return "prase_opal";
    case DF_PRECIOUS_FIRE_OPAL:
        return "precious_fire_opal";
    case DF_PURPLE_SPINEL:
        return "purple_spinel";
    case DF_PYRITE:
        return "pyrite";
    case DF_RED_BERYL:
        return "red_beryl";
    case DF_RED_DIAMOND:
        return "red_diamond";
    case DF_RED_FLASH_OPAL:
        return "red_flash_opal";
    case DF_RED_GROSSULAR:
        return "red_grossular";
    case DF_RED_PYROPE:
        return "red_pyrope";
    case DF_RED_SPINEL:
        return "red_spinel";
    case DF_RED_TOURMALINE:
        return "red_tourmaline";
    case DF_RED_ZIRCON:
        return "red_zircon";
    case DF_RESIN_OPAL:
        return "resin_opal";
    case DF_RHODOLITE:
        return "rhodolite";
    case DF_ROCK_CRYSTAL:
        return "rock_crystal";
    case DF_ROSE_QUARTZ:
        return "rose_quartz";
    case DF_RUBICELLE:
        return "rubicelle";
    case DF_RUBY:
        return "ruby";
    case DF_SAPPHIRE:
        return "sapphire";
    case DF_SARD:
        return "sard";
    case DF_SARDONYX:
        return "sardonyx";
    case DF_SCHORL:
        return "schorl";
    case DF_SHELL_OPAL:
        return "shell_opal";
    case DF_SMOKY_QUARTZ:
        return "smoky_quartz";
    case DF_STAR_RUBY:
        return "star_ruby";
    case DF_STAR_SAPPHIRE:
        return "star_sapphire";
    case DF_SUNSTONE:
        return "sunstone";
    case DF_TANZANITE:
        return "tanzanite";
    case DF_TIGER_IRON:
        return "tiger_iron";
    case DF_TIGEREYE:
        return "tigereye";
    case DF_TOPAZ:
        return "topaz";
    case DF_TOPAZOLITE:
        return "topazolite";
    case DF_TSAVORITE:
        return "tsavorite";
    case DF_TUBE_AGATE:
        return "tube_agate";
    case DF_TURQUOISE:
        return "turquoise";
    case DF_VARISCITE:
        return "variscite";
    case DF_VIOLET_SPESSARTINE:
        return "violet_spessartine";
    case DF_WAX_OPAL:
        return "wax_opal";
    case DF_WHITE_CHALCEDONY:
        return "white_chalcedony";
    case DF_WHITE_JADE:
        return "white_jade";
    case DF_WHITE_OPAL:
        return "white_opal";
    case DF_WOOD_OPAL:
        return "wood_opal";
    case DF_YELLOW_DIAMOND:
        return "yellow_diamond";
    case DF_YELLOW_GROSSULAR:
        return "yellow_grossular";
    case DF_YELLOW_JASPER:
        return "yellow_jasper";
    case DF_YELLOW_SPESSARTINE:
        return "yellow_spessartine";
    case DF_YELLOW_ZIRCON:
        return "yellow_zircon";
        //gem end

        //liquid start
    case DF_MAGMA_MATERIAL:
        return "magma";
    case DF_WATER_MATERIAL:
        return "water";
            //liquid end

        //ore start
    case DF_RAW_ADAMANTINE:
        return "raw_adamantine";
    case DF_NATIVE_ALUMINUM:
        return "native_aluminum";
    case DF_BISMUTHINITE:
        return "bismuthinite";
    case DF_CASSITERITE:
        return "cassiterite";
    case  DF_NATIVE_COPPER:
        return "native_copper";
    case  DF_GALENA:
        return "galena";
    case  DF_GARNIERITE:
        return "garnierite";
    case  DF_NATIVE_GOLD:
        return "native_gold";
    case  DF_HEMATITE:
        return "hematite";
    case  DF_HORN_SILVER:
        return "horn_silver";
    case  DF_LIMONITE:
        return "limonite";
    case  DF_MAGNETITE:
        return "magnetite";
    case  DF_MALACHITE:
        return "malachite";
    case  DF_NATIVE_PLATINUM:
        return "native_platinum";
    case  DF_NATIVE_SILVER:
        return "native_silver";
    case  DF_SPHALERITE:
        return "sphalerite";
    case  DF_TETRAHEDRITE:
        return "tetrahedrite";
        //ore end

        //soil start
    case DF_BLACK_SAND:
        return "black_sand";
    case DF_CALCAREOUS_OOZE:
        return "calcareous_ooze";
    case DF_CLAY:
        return "clay";
    case DF_CLAY_LOAM:
        return "clay_loam";
    case DF_FIRE_CLAY:
        return "fire_clay";
    case DF_LOAM:
        return "loam";
    case DF_LOAMY_SAND:
        return "loamy_sand";
    case DF_PEAT:
        return "peat";
    case DF_PELAGIC_CLAY:
        return "pelagic_clay";
    case DF_RED_SAND:
        return "red_sand";
    case DF_SAND:
        return "sand";
    case DF_SANDY_CLAY:
        return "sandy_clay";
    case DF_SANDY_CLAY_LOAM:
        return "sandy_clay_loam";
    case DF_SANDY_LOAM:
        return "sandy_loam";
    case DF_SILLICEOUS_OOZE:
        return "silliceous_ooze";
    case DF_SILT:
        return "silt";
    case DF_SILT_LOAM:
        return "silt_loam";
    case DF_SILTY_CLAY:
        return "silty_clay";
    case DF_SILTY_CLAY_LOAM:
        return "silty_clay_loam";
    case DF_WHITE_SAND:
        return "white_sand";
    case DF_YELLOW_SAND:
        return "yellow_sand";
        //soil end

        //stone start
    case DF_ALABASTER:
        return "alabaster";
    case DF_ALUNITE:
        return "alunite";
    case DF_ANDESITE:
        return "andesite";
    case DF_ANHYDRITE:
        return "anhydrite";
    case DF_BASALT:
        return "basalt";
    case DF_BAUXITE:
        return "bauxite";
    case DF_BITUMINOUS_COAL:
        return "bituminous_coal";
    case DF_BORAX:
        return "borax";
    case DF_BRIMSTONE:
        return "brimstone";
    case DF_CALCITE:
        return "calcite";
    case DF_CHALK:
        return "chalk";
    case DF_CHERT:
        return "chert";
    case DF_CHROMITE:
        return "chromite";
    case DF_CINNABAR:
        return "cinnabar";
    case DF_CLAYSTONE:
        return "claystone";
    case DF_COBALTITE:
        return "cobaltite";
    case DF_CONGLOMERATE:
        return "conglomerate";
    case DF_CRYOLITE:
        return "cryolite";
    case DF_DACITE:
        return "dacite";
    case DF_DIORITE:
        return "diorite";
    case DF_DOLOMITE:
        return "dolomite";
    case DF_GABBRO:
        return "gabbro";
    case DF_GNEISS:
        return "gneiss";
    case DF_GRANITE:
        return "granite";
    case DF_GRAPHITE:
        return "graphite";
    case DF_GYPSUM:
        return "gypsum";
    case DF_HORNBLENDE:
        return "hornblende";
    case DF_JET:
        return "jet";
    case DF_KAOLINITE:
        return "kaolinite";
    case DF_KIMBERLITE:
        return "kimberlite";
    case DF_LIGNITE:
        return "lignite";
    case DF_LIMESTONE:
        return "limestone";
    case DF_ILMENITE:
        return "ilmenite";
    case DF_MARBLE:
        return "marble";
    case DF_MARCASITE:
        return "marcasite";
    case DF_MICA:
        return "mica";
    case DF_MICROCLINE:
        return "microcline";
    case DF_MUDSTONE:
        return "mudstone";
    case DF_OBSIDIAN:
        return "obsidian";
    case DF_OLIVINE:
        return "olivine";
    case DF_ORPIMENT:
        return "orpiment";
    case DF_ORTHOCLASE:
        return "orthoclase";
    case DF_PERICLASE:
        return "periclase";
    case DF_PETRIFIED_WOOD:
        return "petrified_wood";
    case DF_PHYLLITE:
        return "phyllite";
    case DF_PITCHBLENDE:
        return "pitchblende";
    case DF_PUDDINGSTONE:
        return "puddingstone";
    case DF_PYROLUSITE:
        return "pyrolusite";
    case DF_QUARTZITE:
        return "quartzite";
    case DF_REALGAR:
        return "realgar";
    case DF_RHYOLITE:
        return "rhyolite";
    case DF_ROCK_SALT:
        return "rock_salt";
    case DF_RUTILE:
        return "rutile";
    case DF_SALTPETER:
        return "saltpeter";
    case DF_SANDSTONE:
        return "sandstone";
    case DF_SATINSPAR:
        return "satinspar";
    case DF_SCHIST:
        return "schist";
    case DF_SELENITE:
        return "selenite";
    case DF_SERPENTINE:
        return "serpentine";
    case DF_SHALE:
        return "shale";
    case DF_SILTSTONE:
        return "siltstone";
    case DF_SLADE:
        return "slade";
    case DF_SLATE:
        return "slate";
    case DF_STIBNITE:
        return "stibnite";
    case DF_SYLVITE:
        return "sylvite";
    case DF_TALC:
        return "talc";
        //stone end
    case DF_RAW_ROOT:
        return "root";
    case DF_HIDDEN:
        return "hidden";
    case DF_LIGHT_GRASS:
        return "light_grass";
    case DF_DARK_GRASS:
        return "dark_grass";
    case DF_DRY_GRASS:
        return "dry_grass";
    case DF_DEAD_GRASS:
        return "dead_grass";
    case DF_TRUNK:
        return "trunk";
    case DF_ICE:
        return "ice";
    default:
        return "bad DF_Natural_Tile enum ";
    }
}

std::string DFNaturalTileFilename(DF_Natural_Tile_Material e)
{
    switch (e)
    {
        //gem start
    case DF_ALMANDINE:
        return "almandine.png";
    case DF_ALEXANDRITE:
        return "alexandrite.png";
    case DF_AMBER_OPAL:
        return "amber_opal.png";
    case DF_AMETHYST:
        return "amethyst.png";
    case DF_AQUAMARINE:
        return "aquamarine.png";
    case DF_AVENTURINE:
        return "aventurine.png";
    case DF_BANDED_AGATE:
        return "banded_agate.png";
    case DF_BANDIRE_OPAL:
        return "bandfire_opal.png";
    case DF_BLACK_DIAMOND:
        return "black_diamond.png";
    case DF_BLACK_OPAL:
        return "black_opal.png";
    case DF_BLACK_PYROPE:
        return "black_pyrope.png";
    case DF_BLACK_ZIRCON:
        return "black_zircon.png";
    case DF_BLOODSTONE:
        return "bloodstone.png";
    case DF_BLUE_DIAMOND:
        return "blue_diamond.png";
    case DF_BLUE_GARNET:
        return "blue_garnet.png";
    case DF_BLUE_JADE:
        return "blue_jade.png";
    case DF_BONE_OPAL:
        return "bone_opal.png";
    case DF_BROWN_JASPER:
        return "brown_jasper.png";
    case DF_BROWN_ZIRCON:
        return "brown_zircon.png";
    case DF_CARNELIAN:
        return "carnelian.png";
    case DF_CATS_EYE:
        return "cats_eye.png";
    case DF_CHERRY_OPAL:
        return "cherry_opal.png";
    case DF_CHRYSOBERYL:
        return "chrysoberyl.png";
    case DF_CHRYSOCOLLA:
        return "chrysocolla.png";
    case DF_CHRYSOPRASE:
        return "chrysoprase.png";
    case DF_CINNAMON_GROSSULAR:
        return "cinnamon_grossular.png";
    case DF_CITRINE:
        return "citrine.png";
    case DF_CLARO_OPAL:
        return "claro_opal.png";
    case DF_CLEAR_DIAMOND:
        return "clear_diamond.png";
    case DF_CLEAR_GARNET:
        return "clear_garnet.png";
    case DF_CLEAR_GLASS:
        return "clear_glass.png";
    case DF_CLEAR_TOURMALINE:
        return "clear_tourmaline.png";
    case DF_CLEAR_ZIRCON:
        return "clear_zircon.png";
    case DF_CRYSTAL_GLASS:
        return "crystal_glass.png";
    case DF_CRYSTAL_OPAL:
        return "crystal_opal.png";
    case DF_DEMANTOID:
        return "demantoid.png";
    case DF_DENDRITIC_AGATE:
        return "dendritic_agate.png";
    case DF_EMERALD:
        return "emerald.png";
    case DF_FAINT_YELLOW_DIAMOND:
        return "faint_yellow_diamond.png";
    case DF_FIRE_AGATE:
        return "fire_agate.png";
    case DF_FIRE_OPAL:
        return "fire_opal.png";
    case DF_FORTIFICATION_AGATE:
        return "fortification_agate.png";
    case DF_GOLD_OPAL:
        return "gold_opal.png";
    case DF_GOLDEN_BERYL:
        return "golden_beryl.png";
    case DF_GOSHENITE:
        return "goshenite.png";
    case DF_GRAY_CHALCEDONY:
        return "gray_chalcedony.png";
    case DF_GREEN_DIAMOND:
        return "green_diamond.png";
    case DF_GREEN_GLASS:
        return "green_glass.png";
    case DF_GREEN_JADE:
        return "green_jade.png";
    case DF_GREEN_TOURMALINE:
        return "green_tourmaline.png";
    case DF_GREEN_ZIRCON:
        return "green_zircon.png";
    case DF_HARLEQUIN_OPAL:
        return "harlequin_opal.png";
    case DF_HELIODOR:
        return "heliodor.png";
    case DF_HONEY_YELLOW_BERYL:
        return "honey_yellow_beryl.png";
    case DF_INDIGO_TOURMALINE:
        return "indigo_tourmaline.png";
    case DF_JASPER_OPAL:
        return "jasper_opal.png";
    case DF_JELLY_OPAL:
        return "jelly_opal.png";
    case DF_KUNZITE:
        return "kunzite.png";
    case DF_LACE_AGATE:
        return "lace_agate.png";
    case DF_LAPIS_LAZULI:
        return "lapis_lazuli.png";
    case DF_LAVENDER_JADE:
        return "lavender_jade.png";
    case DF_LEVIN_OPAL:
        return "levin_opal.png";
    case DF_LIGHT_YELLOW_DIAMOND:
        return "light_yellow_diamond.png";
    case DF_MELANITE:
        return "melanite.png";
    case DF_MILK_OPAL:
        return "milk_opal.png";
    case DF_MILK_QUARTZ:
        return "milk_quartz.png";
    case DF_MOONSTONE:
        return "moonstone.png";
    case DF_MORGANITE:
        return "morganite.png";
    case DF_MORION:
        return "morion.png";
    case DF_MOSS_AGATE:
        return "moss_agate.png";
    case DF_MOSS_OPAL:
        return "moss_opal.png";
    case DF_ONYX:
        return "onyx.png";
    case DF_ONYX_OPAL:
        return "onyx_opal.png";
    case DF_PERIDOT:
        return "peridot.png";
    case DF_PICTURE_JASPER:
        return "picture_jasper.png";
    case DF_PINEAPPLE_OPAL:
        return "pineapple_opal.png";
    case DF_PINFIRE_OPAL:
        return "pinfire_opal.png";
    case DF_PINK_GARNET:
        return "pink_garnet.png";
    case DF_PINK_JADE:
        return "pink_jade.png";
    case DF_PINK_TOURMALINE:
        return "pink_tourmaline.png";
    case DF_PIPE_OPAL:
        return "pipe_opal.png";
    case DF_PLUME_AGATE:
        return "plume_agate.png";
    case DF_PRASE:
        return "prase.png";
    case DF_PRASE_OPAL:
        return "prase_opal.png";
    case DF_PRECIOUS_FIRE_OPAL:
        return "precious_fire_opal.png";
    case DF_PURPLE_SPINEL:
        return "purple_spinel.png";
    case DF_PYRITE:
        return "pyrite.png";
    case DF_RED_BERYL:
        return "red_beryl.png";
    case DF_RED_DIAMOND:
        return "red_diamond.png";
    case DF_RED_FLASH_OPAL:
        return "red_flash_opal.png";
    case DF_RED_GROSSULAR:
        return "red_grossular.png";
    case DF_RED_PYROPE:
        return "red_pyrope.png";
    case DF_RED_SPINEL:
        return "red_spinel.png";
    case DF_RED_TOURMALINE:
        return "red_tourmaline.png";
    case DF_RED_ZIRCON:
        return "red_zircon.png";
    case DF_RESIN_OPAL:
        return "resin_opal.png";
    case DF_RHODOLITE:
        return "rhodolite.png";
    case DF_ROCK_CRYSTAL:
        return "rock_crystal.png";
    case DF_ROSE_QUARTZ:
        return "rose_quartz.png";
    case DF_RUBICELLE:
        return "rubicelle.png";
    case DF_RUBY:
        return "ruby.png";
    case DF_SAPPHIRE:
        return "sapphire.png";
    case DF_SARD:
        return "sard.png";
    case DF_SARDONYX:
        return "sardonyx.png";
    case DF_SCHORL:
        return "schorl.png";
    case DF_SHELL_OPAL:
        return "shell_opal.png";
    case DF_SMOKY_QUARTZ:
        return "smoky_quartz.png";
    case DF_STAR_RUBY:
        return "star_ruby.png";
    case DF_STAR_SAPPHIRE:
        return "star_sapphire.png";
    case DF_SUNSTONE:
        return "sunstone.png";
    case DF_TANZANITE:
        return "tanzanite.png";
    case DF_TIGER_IRON:
        return "tiger_iron.png";
    case DF_TIGEREYE:
        return "tigereye.png";
    case DF_TOPAZ:
        return "topaz.png";
    case DF_TOPAZOLITE:
        return "topazolite.png";
    case DF_TSAVORITE:
        return "tsavorite.png";
    case DF_TUBE_AGATE:
        return "tube_agate.png";
    case DF_TURQUOISE:
        return "turquoise.png";
    case DF_VARISCITE:
        return "variscite.png";
    case DF_VIOLET_SPESSARTINE:
        return "violet_spessartine.png";
    case DF_WAX_OPAL:
        return "wax_opal.png";
    case DF_WHITE_CHALCEDONY:
        return "white_chalcedony.png";
    case DF_WHITE_JADE:
        return "white_jade.png";
    case DF_WHITE_OPAL:
        return "white_opal.png";
    case DF_WOOD_OPAL:
        return "wood_opal.png";
    case DF_YELLOW_DIAMOND:
        return "yellow_diamond.png";
    case DF_YELLOW_GROSSULAR:
        return "yellow_grossular.png";
    case DF_YELLOW_JASPER:
        return "yellow_jasper.png";
    case DF_YELLOW_SPESSARTINE:
        return "yellow_spessartine.png";
    case DF_YELLOW_ZIRCON:
        return "yellow_zircon.png";
        //gem end

        //liquid start
    case DF_MAGMA_MATERIAL:
        return "magma.png";
    case DF_WATER_MATERIAL:
        return "water.png";
        //liquid end

        //ore start
    case DF_RAW_ADAMANTINE:
        return "raw_adamantine.png";
    case DF_NATIVE_ALUMINUM:
        return "native_aluminum.png";
    case DF_BISMUTHINITE:
        return "bismuthinite.png";
    case DF_CASSITERITE:
        return "cassiterite.png";
    case  DF_NATIVE_COPPER:
        return "native_copper.png";
    case  DF_GALENA:
        return "galena.png";
    case  DF_GARNIERITE:
        return "garnierite.png";
    case  DF_NATIVE_GOLD:
        return "native_gold.png";
    case  DF_HEMATITE:
        return "hematite.png";
    case  DF_HORN_SILVER:
        return "horn_silver.png";
    case  DF_LIMONITE:
        return "limonite.png";
    case  DF_MAGNETITE:
        return "magnetite.png";
    case  DF_MALACHITE:
        return "malachite.png";
    case  DF_NATIVE_PLATINUM:
        return "native_platinum.png";
    case  DF_NATIVE_SILVER:
        return "native_silver.png";
    case  DF_SPHALERITE:
        return "sphalerite.png";
    case  DF_TETRAHEDRITE:
        return "tetrahedrite.png";
        //ore end

        //soil start
    case DF_BLACK_SAND:
        return "black_sand.png";
    case DF_CALCAREOUS_OOZE:
        return "calcareous_ooze.png";
    case DF_CLAY:
        return "clay.png";
    case DF_CLAY_LOAM:
        return "clay_loam.png";
    case DF_FIRE_CLAY:
        return "fire_clay.png";
    case DF_LOAM:
        return "loam.png";
    case DF_LOAMY_SAND:
        return "loamy_sand.png";
    case DF_PEAT:
        return "peat.png";
    case DF_PELAGIC_CLAY:
        return "pelagic_clay.png";
    case DF_RED_SAND:
        return "red_sand.png";
    case DF_SAND:
        return "sand.png";
    case DF_SANDY_CLAY:
        return "sandy_clay.png";
    case DF_SANDY_CLAY_LOAM:
        return "sandy_clay_loam.png";
    case DF_SANDY_LOAM:
        return "sandy_loam.png";
    case DF_SILLICEOUS_OOZE:
        return "silliceous_ooze.png";
    case DF_SILT:
        return "silt.png";
    case DF_SILT_LOAM:
        return "silt_loam.png";
    case DF_SILTY_CLAY:
        return "silty_clay.png";
    case DF_SILTY_CLAY_LOAM:
        return "silty_clay_loam.png";
    case DF_WHITE_SAND:
        return "white_sand.png";
    case DF_YELLOW_SAND:
        return "yellow_sand.png";
        //soil end

        //stone start
    case DF_ALABASTER:
        return "alabaster.png";
    case DF_ALUNITE:
        return "alunite.png";
    case DF_ANDESITE:
        return "andesite.png";
    case DF_ANHYDRITE:
        return "anhydrite.png";
    case DF_BASALT:
        return "basalt.png";
    case DF_BAUXITE:
        return "bauxite.png";
    case DF_BITUMINOUS_COAL:
        return "bituminous_coal.png";
    case DF_BORAX:
        return "borax.png";
    case DF_BRIMSTONE:
        return "brimstone.png";
    case DF_CALCITE:
        return "calcite.png";
    case DF_CHALK:
        return "chalk.png";
    case DF_CHERT:
        return "chert.png";
    case DF_CHROMITE:
        return "chromite.png";
    case DF_CINNABAR:
        return "cinnabar.png";
    case DF_CLAYSTONE:
        return "claystone.png";
    case DF_COBALTITE:
        return "cobaltite.png";
    case DF_CONGLOMERATE:
        return "conglomerate.png";
    case DF_CRYOLITE:
        return "cryolite.png";
    case DF_DACITE:
        return "dacite.png";
    case DF_DIORITE:
        return "diorite.png";
    case DF_DOLOMITE:
        return "dolomite.png";
    case DF_GABBRO:
        return "gabbro.png";
    case DF_GNEISS:
        return "gneiss.png";
    case DF_GRANITE:
        return "granite.png";
    case DF_GRAPHITE:
        return "graphite.png";
    case DF_GYPSUM:
        return "gypsum.png";
    case DF_HORNBLENDE:
        return "hornblende.png";
    case DF_JET:
        return "jet.png";
    case DF_KAOLINITE:
        return "kaolinite.png";
    case DF_KIMBERLITE:
        return "kimberlite.png";
    case DF_LIGNITE:
        return "lignite.png";
    case DF_LIMESTONE:
        return "limestone.png";
    case DF_ILMENITE:
        return "ilmenite.png";
    case DF_MARBLE:
        return "marble.png";
    case DF_MARCASITE:
        return "marcasite.png";
    case DF_MICA:
        return "mica.png";
    case DF_MICROCLINE:
        return "microcline.png";
    case DF_MUDSTONE:
        return "mudstone.png";
    case DF_OBSIDIAN:
        return "obsidian.png";
    case DF_OLIVINE:
        return "olivine.png";
    case DF_ORPIMENT:
        return "orpiment.png";
    case DF_ORTHOCLASE:
        return "orthoclase.png";
    case DF_PERICLASE:
        return "periclase.png";
    case DF_PETRIFIED_WOOD:
        return "petrified_wood.png";
    case DF_PHYLLITE:
        return "phyllite.png";
    case DF_PITCHBLENDE:
        return "pitchblende.png";
    case DF_PUDDINGSTONE:
        return "puddingstone.png";
    case DF_PYROLUSITE:
        return "pyrolusite.png";
    case DF_QUARTZITE:
        return "quartzite.png";
    case DF_REALGAR:
        return "realgar.png";
    case DF_RHYOLITE:
        return "rhyolite.png";
    case DF_ROCK_SALT:
        return "rock_salt.png";
    case DF_RUTILE:
        return "rutile.png";
    case DF_SALTPETER:
        return "saltpeter.png";
    case DF_SANDSTONE:
        return "sandstone.png";
    case DF_SATINSPAR:
        return "satinspar.png";
    case DF_SCHIST:
        return "schist.png";
    case DF_SELENITE:
        return "selenite.png";
    case DF_SERPENTINE:
        return "serpentine.png";
    case DF_SHALE:
        return "shale.png";
    case DF_SILTSTONE:
        return "siltstone.png";
    case DF_SLADE:
        return "slade.png";
    case DF_SLATE:
        return "slate.png";
    case DF_STIBNITE:
        return "stibnite.png";
    case DF_SYLVITE:
        return "sylvite.png";
    case DF_TALC:
        return "talc.png";
        //stone end
    case DF_RAW_ROOT:
        return "root.png";
    case DF_HIDDEN:
        return "hidden.png";
    case DF_LIGHT_GRASS:
        return "light_grass.png";
    case DF_DARK_GRASS:
        return "dark_grass.png";
    case DF_DRY_GRASS:
        return "dry_grass.png";
    case DF_DEAD_GRASS:
        return "dead_grass.png";
    case DF_TRUNK:
        return "trunk.png";
    case DF_ICE:
        return "ice.png";
    default:
        return "bad DF_Natural_Tile enum ";
    }
}

DF_Material_Type DFNaturalType(DF_Natural_Tile_Material e)
{
    if (e >= DF_ALMANDINE && e <= DF_YELLOW_ZIRCON)
    {
        return DF_NATURAL_GEM;
    }
    else if (e == DF_WATER_MATERIAL || e == DF_MAGMA_MATERIAL)
    {
        return DF_NATURAL_LIQUID;
    }
    else if (e >= DF_RAW_ADAMANTINE && e <= DF_TETRAHEDRITE)
    {
        return DF_NATURAL_ORE;
    }
    else if (e >= DF_BLACK_SAND && e <= DF_YELLOW_SAND)
    {
        return DF_NATURAL_SOIL;
    }
    else if(e >= DF_ALABASTER && e <= DF_TALC)
    {
        return DF_NATURAL_STONE;
    }
    else if (e == DF_NATURAL_ROOT)
    {
        return DF_NATURAL_ROOT;
    }
    else if (e == DF_ICE)
    {
        return DF_NATURAL_ICE;
    }
    else if (e == DF_LIGHT_GRASS || e == DF_DARK_GRASS || e == DF_DRY_GRASS || e == DF_DEAD_GRASS)
    {
        return DF_NATURAL_GRASS;
    }
    else if (e == DF_TRUNK)
    {
        return DF_NATURAL_TRUNK;
    }
    else //actual hidden and if somehow someone passes in the count enum
    {
        return DF_NATURAL_HIDDEN;
    }
}

std::unordered_map<std::string, DF_Natural_Tile_Material> getReverseOfDFNaturalStringTable()
{
    std::unordered_map<std::string, DF_Natural_Tile_Material> temp;
    temp.reserve(DF_NATURAL_TILE_COUNT);

    for (size_t i = 0; i < DF_NATURAL_TILE_COUNT; i++)
    {
        DF_Natural_Tile_Material m = static_cast<DF_Natural_Tile_Material>(i); //so we only have to do one cast
        temp[DFNaturalTileString(m)] = m; //get string and put into table
    }

    return temp;
}

