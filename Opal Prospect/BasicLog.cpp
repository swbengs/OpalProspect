//class header
#include "BasicLog.hpp"

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

BasicLog::BasicLog()
{
    old_error = std::cerr.rdbuf();
    old_log = std::clog.rdbuf();

    error_log = std::ofstream("error.txt");
    my_log = std::ofstream("log.txt");

    std::cerr.rdbuf(error_log.rdbuf());
    std::clog.rdbuf(my_log.rdbuf());

    std::cout << "basic log created\n";
}

BasicLog::~BasicLog()
{
    std::cerr.rdbuf(old_error);
    std::clog.rdbuf(old_log);

    std::cout << "basic log destroyed\n";
}

const BasicLog & BasicLog::getInstance()
{
    static BasicLog log;
    return log;
}

void BasicLog::writeError(std::string error) const
{
    std::cerr << error;
    std::cout << error;
}

void BasicLog::writeLog(std::string log) const
{
    std::clog << log;
    std::cout << log;
}

