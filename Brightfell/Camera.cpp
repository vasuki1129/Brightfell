#include "Camera.h"

glm::mat4 Camera::getMatrix()
{
    //returns a computed view + projection matrix
    //which is finalized with the model matrix in the shader

    glm::mat4 camMatrix = glm::lookAt(position, lookTarget, glm::vec3(0, 1, 0));

    glm::mat4 projMatrix = glm::perspective(glm::radians(fov), 4.0f / 3.0f, 0.1f, 100.0f);

    glm::mat4 finalMatrix = camMatrix * projMatrix;
    return finalMatrix;

}

void Camera::setPosition(glm::vec3 newPos)
{
    position = newPos;
}

void Camera::setTarget(glm::vec3 newTarget)
{
    lookTarget = newTarget;
}

void Camera::setFov(float newFov)
{
    fov = newFov;
}
