#include "VertexTriangle.hpp"

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

VertexTriangle::VertexTriangle()
{
    setIndexABC(0, 0, 0);
}

VertexTriangle::VertexTriangle(unsigned int a, unsigned int b, unsigned int c)
{
    setIndexABC(a, b, c);
}

unsigned int VertexTriangle::getIndexA() const
{
    return index_a;
}

unsigned int VertexTriangle::getIndexB() const
{
    return index_b;
}

unsigned int VertexTriangle::getIndexC() const
{
    return index_c;
}

void VertexTriangle::setIndexA(unsigned int a)
{
    index_a = a;
}

void VertexTriangle::setIndexB(unsigned int b)
{
    index_b = b;
}

void VertexTriangle::setIndexC(unsigned int c)
{
    index_c = c;
}

void VertexTriangle::setIndexABC(unsigned int a, unsigned int b, unsigned int c)
{
    index_a = a;
    index_b = b;
    index_c = c;
}

