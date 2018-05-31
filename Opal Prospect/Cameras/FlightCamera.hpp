#pragma once

#include "Camera.hpp"

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
