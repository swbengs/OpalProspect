//class header
#include "FilePath.hpp"

//std lib includes
#include <iostream>
#include <sstream>

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

std::string FilePath::exe_cwd = ".";
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
    std::stringstream stream;
    stream << full_path << filename;
    return stream.str();
}

std::string FilePath::getPathOnly() const
{
    return full_path;
}

char FilePath::getOSSeperator()
{
    return os_seperator;
}

std::string FilePath::getCWD()
{
    return exe_cwd;
}

void FilePath::setCWD(std::string cwd)
{
    exe_cwd = cwd;
}

void FilePath::setFullPath(std::string path)
{
    size_t filename_start = 0;

    if (path.size() > 0)
    {
        for (size_t i = path.size() - 1; i > 0; i--)
        {
            if (path.at(i) == os_seperator)
            {
                filename_start = i + 1; //we just found serpator at i, so add 1 to get the start
                break; //exit loop
            }
        }
    }

    full_path = path.substr(0, filename_start);
    filename = path.substr(filename_start);
}

void FilePath::setRelativePath(std::string path)
{
    std::stringstream stream;
    stream << FilePath::getCWD() << path; //exe's cwd already contains the os_seperator
    setFullPath(stream.str());
}
