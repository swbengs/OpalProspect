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
Description: Class to store generic filename and path that should work on any OS.
*/

class FilePath
{
public:
    FilePath();

    //gets
    std::string getFilename() const;
    std::string getPath() const; //path and file
    std::string getPathOnly() const; //just path
    //sets
    void setFullPath(std::string path); //set the full path. Should be a full path and not relative. Only use with user given input such as terrain file.
    //don't use full path for things like texture files, settings files, and so on. Use relative path
    void setRelativePath(std::string path); //uses CWD(current working directory) of the .exe file in front of the path/file you give

    static char getOSSeperator();
    static std::string getCWD();
    static void setCWD(std::string cwd);

private:
    std::string full_path;
    std::string filename;
    static std::string exe_cwd;
};

