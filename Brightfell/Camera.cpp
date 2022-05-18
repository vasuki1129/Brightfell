#include "Camera.h"



glm::mat4 Camera::getMatrix()
{
    //returns a computed view + projection matrix
    //which is finalized with the model matrix in the shader

    glm::mat4 camMatrix = glm::translate(glm::mat4(1.0f), position);
    camMatrix = glm::toMat4(rotation) * camMatrix;

    glm::mat4 projMatrix = glm::perspective(glm::radians(fov), 4.0f / 3.0f, 0.01f, 1000.0f);

    glm::mat4 finalMatrix = projMatrix * camMatrix;
    return finalMatrix;

}

void Camera::setPosition(glm::vec3 newPos)
{
    position = newPos;
}



void Camera::movePosition(glm::vec3 addPos)
{
    position = position + addPos;

}

void Camera::setFov(float newFov)
{
    fov = newFov;
}

void Camera::logicTick(float dTime)
{
    glm::vec3 tickMvt(0.0f, 0.0f, 0.0f);
    float moveSpeed = 50.0f;

    if (bMoveLeft)
        tickMvt.x += moveSpeed * dTime;
    if (bMoveRight)
        tickMvt.x -= moveSpeed * dTime;
    if (bMoveForward)
        tickMvt.z += moveSpeed * dTime;
    if (bMoveBack)
        tickMvt.z -= moveSpeed * dTime;
    if (bMoveUp)
        tickMvt.y -= moveSpeed * dTime;
    if (bMoveDown)
        tickMvt.y += moveSpeed * dTime;
        

    movePosition(tickMvt);

}

void Camera::rotate(glm::vec3 amt)
{
    rotation = rotation + glm::quat(amt);
}

glm::vec3 Camera::getForwardVector()
{
    return glm::vec3();
}

glm::vec3 Camera::getUpVector()
{
    return glm::vec3();
}

glm::vec3 Camera::getRightVector()
{
    return glm::vec3();
}

void Camera::HStartMoveRight()
{
    bMoveRight = true;
}

void Camera::HStopMoveRight()
{
    bMoveRight = false;
}

void Camera::HStartMoveLeft()
{
    bMoveLeft = true;
}

void Camera::HStopMoveLeft()
{
    bMoveLeft = false;
}

void Camera::HStartMoveUp()
{
    bMoveUp = true;
}

void Camera::HStopMoveUp()
{
    bMoveUp = false;
}

void Camera::HStartMoveDown()
{
    bMoveDown = true;
}

void Camera::HStopMoveDown()
{
    bMoveDown = false;
}

void Camera::HStartMoveForward()
{
    bMoveForward = true;
}

void Camera::HStopMoveForward()
{
    bMoveForward = false;
}

void Camera::HStartMoveBack()
{
    bMoveBack = true;
}

void Camera::HStopMoveBack()
{
    bMoveBack = false;
}
