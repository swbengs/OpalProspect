#include "Camera.hpp"

#include "gtc\matrix_transform.hpp" //scale, rotate, translate, and more
#include "gtx\io.hpp"

#include <iostream>

/*
Camera class written as a right hand coordinate one.
*/

Camera::Camera()
{
    reset();
}

void Camera::fillCameraMatrix(glm::mat4& matrix) const
{
    fillRotation(matrix);
    fillTranslation(matrix, getPosition());
}

void Camera::fillViewMatrix(glm::mat4& matrix) const
{
    //
    glm::vec3 negate = getPosition();

    fillRotation(matrix);

    //currently only a rotation matrix so the transpose does the reverse rotation
    matrix = glm::transpose(matrix);

    //negate the position and translate by that
    negate[0] *= -1;
    negate[1] *= -1;
    negate[2] *= -1;
    matrix = glm::translate(matrix, negate);
}

void Camera::normalize()
{
    glm::normalize(cam_right);
    glm::normalize(cam_up);
    glm::normalize(cam_forward);
}

void Camera::reset()
{
    resetRotation();
    resetPosition();
}

void Camera::resetPosition()
{
    position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Camera::resetRotation()
{
    cam_forward = glm::vec3(0.0f, 0.0f, 1.0f);
    cam_right = glm::vec3(1.0f, 0.0f, 0.0f);
    cam_up = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Camera::outputCameraMatrix() const
{
    std::cout << "Camera " << getCameraMatrix() << "\n \n";
}

void Camera::outputVectors() const
{
    std::cout << "Right " << getRight() << "\n";
    std::cout << "Up " << getUp() << "\n";
    std::cout << "Forward " << getForward() << "\n \n";
}

//gets
glm::mat4 Camera::getCameraMatrix() const
{
    //RHC system for view goes scale, rotate, translate
    //YZX
    glm::mat4 result;

    fillCameraMatrix(result);

    return result;
}

glm::mat4 Camera::getViewMatrix() const
{
    glm::mat4 result;

    fillViewMatrix(result);

    return result;
}

const glm::vec3& Camera::getRight() const
{
    return cam_right;
}

const glm::vec3& Camera::getUp() const
{
    return cam_up;
}

const glm::vec3& Camera::getForward() const
{
    return cam_forward;
}

const glm::vec3& Camera::getPosition() const
{
    return position;
}

//sets
void Camera::setRight(const glm::vec3& vector)
{
    cam_right = vector;
}

void Camera::setUp(const glm::vec3& vector)
{
    cam_up = vector;
}

void Camera::setForward(const glm::vec3& vector)
{
    cam_forward = vector;
}

void Camera::setPosition(const glm::vec3& location)
{
    position = location;
}

//protected
void Camera::extractVectors(const glm::mat4& matrix)
{
    extractRow(matrix, 0, cam_right);
    extractRow(matrix, 1, cam_up);
    extractRow(matrix, 2, cam_forward);

    cam_right[2] *= -1;
    cam_up[2] *= -1;
    cam_forward[2] *= -1; //z axis must be negated when moving to or from rotation matrix

    normalize();
}

void Camera::fillRotation(glm::mat4& matrix) const
{
    glm::vec3 right = cam_right;
    glm::vec3 up = cam_up;
    glm::vec3 forward = cam_forward;

    fillRow(matrix, 0, right);
    fillRow(matrix, 1, up);
    fillRow(matrix, 2, forward);
}

void Camera::fillTranslation(glm::mat4& matrix, const glm::vec3& translate) const
{
    fillRow(matrix, 3, translate);
}

//private
void Camera::extractRow(const glm::mat4& matrix, int row, glm::vec3& vector) const
{
    /*
    row meanings

    0 = right
    1 = up
    2 = forward
    3 = translation
    */

    if (row < 4 && row > -1) //ensure row isn't out of bounds
    {
        int column = 0;

        vector[0] = matrix[row][column++]; //x
        vector[1] = matrix[row][column++]; //y
        vector[2] = matrix[row][column]; //z
    }
}

void Camera::fillRow(glm::mat4& matrix, int row, const glm::vec3& vector) const
{
    /*
    row meanings

    0 = right
    1 = up
    2 = forward
    3 = translation
    */

    if (row < 4 && row > -1) //ensure row isn't out of bounds
    {
        int column = 0;

        matrix[row][column++] = vector[0]; //x
        matrix[row][column++] = vector[1]; //y
        matrix[row][column] = vector[2]; //z
    }
}
