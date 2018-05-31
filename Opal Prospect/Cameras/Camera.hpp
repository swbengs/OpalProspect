#pragma once

#include "vec3.hpp"
#include "mat4x4.hpp"

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
