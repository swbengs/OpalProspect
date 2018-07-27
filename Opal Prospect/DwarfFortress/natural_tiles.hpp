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
    DF_YELLOW_SAND
    //soil end

    //stone start

    //stone end
};

std::string DFNaturalTileString(DF_Natural_Tile e)
{
    switch (e)
    {
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
    default:
        return "bad DF_Natural_Tile enum ";
    }
}

std::string DFNaturalTileFile(DF_Natural_Tile e)
{
    switch (e)
    {
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
    default:
        return "bad DF_Natural_Tile enum ";
    }
}

