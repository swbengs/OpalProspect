//class header
#include "FilePath.hpp"

//std lib includes
#include <iostream>

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

const char os_seperator = 
#if defined(WIN32) || defined(_WIN32)
'\\';
#else
'/';
#endif

FilePath::FilePath()
{
    full_path = "";
}

std::string FilePath::getFilename() const
{
    return filename;
}

std::string FilePath::getPath() const
{
    return full_path;
}

char FilePath::getOSSeperator() const
{
    return os_seperator;
}

void FilePath::setFullPath(std::string path)
{
    full_path = path;
    size_t filename_start = 0;

    for (size_t i = path.size() - 1; i > 0; i--)
    {
        if (path.at(i) == os_seperator)
        {
            filename_start = i + 1; //we just found serpator at i, so add 1 to get the start
            break; //exit loop
        }
    }

    filename = path.substr(filename_start);
}
