#pragma once

#include "Camera.hpp"

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

class FlightCamera : public Camera
{
public:
    virtual void rotateUp(float radians);
    virtual void rotateDown(float radians);
    virtual void rotateRight(float radians);
    virtual void rotateLeft(float radians);
    virtual void rollRight(float radians);
    virtual void rollLeft(float radians);

    virtual void moveUp(float rate);
    virtual void moveDown(float rate);
    virtual void moveRight(float rate);
    virtual void moveLeft(float rate);
    virtual void moveForward(float rate);
    virtual void moveBackward(float rate);

private:
    void moveVector(float rate, const glm::vec3& axis);
    void rotateVectors(float radians, const glm::vec3& axis);
    glm::vec3 rotateVector(const glm::mat4& matrix, const glm::vec3& vector);
};
