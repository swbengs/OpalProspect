#pragma once

//std lib includes
#include <string>
#include <fstream>

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
Description: This class can log messages and errors. Meant to be a singleton and not be thread safe at all. Error messages go to cerr and log messages go to clog. For cout messages just use good ole cout
*/

class BasicLog
{
public:
    BasicLog();
    ~BasicLog();

    BasicLog(BasicLog const&) = delete;
    void operator=(BasicLog const&) = delete;

    static const BasicLog& getInstance();
    void writeError(std::string error) const;
    void writeLog(std::string log) const;

private:
    std::ofstream error_log;
    std::ofstream my_log;

    std::streambuf* old_error;
    std::streambuf* old_log;
};

