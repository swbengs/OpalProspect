#pragma once

#include "vec3.hpp"
#include "mat4x4.hpp"

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

class Camera
{
public:
    Camera();

    void fillCameraMatrix(glm::mat4& matrix) const;
    void fillViewMatrix(glm::mat4& matrix) const;
    void normalize();

    void reset();
    void resetPosition();
    void resetRotation();

    virtual void rotateUp(float radians) = 0;
    virtual void rotateDown(float radians) = 0;
    virtual void rotateRight(float radians) = 0;
    virtual void rotateLeft(float radians) = 0;
    virtual void rollRight(float radians) = 0;
    virtual void rollLeft(float radians) = 0;

    virtual void moveUp(float rate) = 0;
    virtual void moveDown(float rate) = 0;
    virtual void moveRight(float rate) = 0;
    virtual void moveLeft(float rate) = 0;
    virtual void moveForward(float rate) = 0;
    virtual void moveBackward(float rate) = 0;

    void outputCameraMatrix() const;
    void outputVectors() const;


    //gets
    glm::mat4 getCameraMatrix() const; //matrix for the camera's rotation and location
    glm::mat4 getViewMatrix() const; //transpose inverse of the camera matrix. Can be used directly to simulate the viewpoint of this camera

    const glm::vec3& getRight() const;
    const glm::vec3& getUp() const;
    const glm::vec3& getForward() const;
    const glm::vec3& getPosition() const;

    //sets
    void setRight(const glm::vec3& vector);
    void setUp(const glm::vec3& vector);
    void setForward(const glm::vec3& vector);
    void setPosition(const glm::vec3& location);

protected:
    void extractVectors(const glm::mat4& matrix); //gets the vectors right, up, and forward from a transform matrix and sets them
    void fillRotation(glm::mat4& matrix) const; //fills in ONLY the rotation part of a transform matrix
    void fillTranslation(glm::mat4& matrix, const glm::vec3& translate) const; //fills in ONLY the translation part of a transform matrix

private:
    //RHC system
    glm::vec3 cam_forward;
    glm::vec3 cam_right;
    glm::vec3 cam_up;

    glm::vec3 position;

    void extractRow(const glm::mat4& matrix, int row, glm::vec3& vector) const;
    void fillRow(glm::mat4& matrix, int row, const glm::vec3& vector) const; //takes a vector and inserts it into the specified row in a 4x4 matrix
};
