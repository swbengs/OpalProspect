#include "FlightCamera.hpp"

#include "gtc\matrix_transform.hpp"
#include "..\Constants\axis.hpp"

#include "gtx\io.hpp"
#include <iostream>

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

void FlightCamera::rotateUp(float radians)
{
    rotateVectors(-1 * radians, getRight());
}

void FlightCamera::rotateDown(float radians)
{
    rotateVectors(radians, getRight());
}

void FlightCamera::rotateRight(float radians)
{
    rotateVectors(radians, getUp());
}

void FlightCamera::rotateLeft(float radians)
{
    rotateVectors(-1 * radians, getUp());
}

void FlightCamera::rollRight(float radians)
{
    rotateVectors(-1 * radians, getForward());
}

void FlightCamera::rollLeft(float radians)
{
    rotateVectors(radians, getForward());
}

void FlightCamera::moveUp(float rate)
{
    moveVector(rate, getUp());
}

void FlightCamera::moveDown(float rate)
{
    moveVector(rate, -getUp());
}

void FlightCamera::moveRight(float rate)
{
    moveVector(rate, getRight());
}

void FlightCamera::moveLeft(float rate)
{
    moveVector(rate, -getRight());
}

void FlightCamera::moveForward(float rate)
{
    moveVector(rate, getForward());
}

void FlightCamera::moveBackward(float rate)
{
    moveVector(rate, -getForward());
}

//privates

void FlightCamera::moveVector(float rate, const glm::vec3& axis)
{
    setPosition(getPosition() + (axis * rate));
}

void FlightCamera::rotateVectors(float radians, const glm::vec3& axis)
{
    glm::mat4 matrix;

    matrix = glm::rotate(matrix, radians, axis);

    setRight(rotateVector(matrix, getRight()));
    setUp(rotateVector(matrix, getUp()));
    setForward(rotateVector(matrix, getForward()));
}

glm::vec3 FlightCamera::rotateVector(const glm::mat4& matrix, const glm::vec3& vector)
{
    glm::vec4 vec4;
    glm::vec3 result;

    vec4 = glm::vec4(vector, 1.0f);
    vec4 = matrix * vec4;

    result[0] = vec4[0];
    result[1] = vec4[1];
    result[2] = vec4[2];

    return result;
}
