#pragma once

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

enum DF_Natural_Tile
{
    //gem start
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
    DF_DEMATOID,
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
    DF_MORGANITE,
    DF_MORION,
    DF_MOSS_AGATE,
    DF_MOSS_OPAL,
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
    DF_RED_GRSSULAR,
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
    DF_MAGMA,
    DF_WATER,
    //liquid end

    //ore start
    DF_ADAMANTINE,
    DF_ALUMINUM,
    DF_BISMUTHINITE,
    DF_CASSITERITE,
    DF_COPPER,
    DF_GALENA,
    DF_GARNIERITE,
    DF_GOLD,
    DF_HEMATITE,
    DF_HORN_SILVER,
    DF_LIMONITE,
    DF_MAGNETITE,
    DF_MALACHITE,
    DF_PLATINUM,
    DF_SILVER,
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
    DF_LLMENITE,
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
    DF_SLATE,
    DF_STIBNITE,
    DF_SYLVITE,
    DF_TALC
    //stone end
};

std::string DFNaturalTileString(DF_Natural_Tile e)
{
    switch (e)
    {
        //liquid start
    case DF_MAGMA:
        return "magma";
    case DF_WATER:
        return "water";
            //liquid end

        //ore start
    case DF_ADAMANTINE:
        return "adamantine";
    case DF_ALUMINUM:
        return "aluminum";
    case DF_BISMUTHINITE:
        return "bismuthinite";
    case DF_CASSITERITE:
        return "cassiterite";
    case  DF_COPPER:
        return "copper";
    case  DF_GALENA:
        return "galena";
    case  DF_GARNIERITE:
        return "garnierite";
    case  DF_GOLD:
        return "gold";
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
    case  DF_PLATINUM:
        return "platinum";
    case  DF_SILVER:
        return "silver";
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
    case DF_LLMENITE:
        return "llmenite";
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
    case DF_SLATE:
        return "slate";
    case DF_STIBNITE:
        return "stibnite";
    case DF_SYLVITE:
        return "sylvite";
    case DF_TALC:
        return "talc";
        //stone end

    default:
        return "bad DF_Natural_Tile enum ";
    }
}

std::string DFNaturalTileFile(DF_Natural_Tile e)
{
    switch (e)
    {
        //liquid start
    case DF_MAGMA:
        return "magma.png";
    case DF_WATER:
        return "water.png";
        //liquid end

        //ore start
    case DF_ADAMANTINE:
        return "adamantine.png";
    case DF_ALUMINUM:
        return "aluminum.png";
    case DF_BISMUTHINITE:
        return "bismuthinite.png";
    case DF_CASSITERITE:
        return "cassiterite.png";
    case  DF_COPPER:
        return "copper.png";
    case  DF_GALENA:
        return "galena.png";
    case  DF_GARNIERITE:
        return "garnierite.png";
    case  DF_GOLD:
        return "gold.png";
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
    case  DF_PLATINUM:
        return "platinum.png";
    case  DF_SILVER:
        return "silver.png";
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
    case DF_LLMENITE:
        return "llmenite.png";
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
    case DF_SLATE:
        return "slate.png";
    case DF_STIBNITE:
        return "stibnite.png";
    case DF_SYLVITE:
        return "sylvite.png";
    case DF_TALC:
        return "talc.png";
        //stone end

    default:
        return "bad DF_Natural_Tile enum ";
    }
}

