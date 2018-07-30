#pragma once

//std lib includes

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
Description: This structure is still not fully decided on. Give a basic description of what this class does at a minimum. More detail is always welcome.
*/

const unsigned int DF_EMBARK_WIDTH = 48; //per 1 embark region. so 4x4 embark would be 48x48 * 16 blocks and floors. The height depends on how tall the world is at that spot. can be 200+ levels deep
const unsigned int DF_EMBARK_LENGTH = 48;
//height varies depending on the local terrain features

const float DF_BLOCK_WIDTH = 1.0f;
const float DF_BLOCK_HEIGHT = 1.0f;
const float DF_BLOCK_LENGTH = 1.0f;

const float DF_FLOOR_WIDTH = 1.0f;
const float DF_FLOOR_HEIGHT = 0.2f;
const float DF_FLOOR_LENGTH = 1.0f;

