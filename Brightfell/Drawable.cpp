#include "Drawable.h"
#include <ext/quaternion_common.hpp>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>
#include <common.hpp>
glm::mat4 Drawable::getMatrix()
{
    glm::mat4 translate= glm::translate(glm::mat4(), position);
    glm::mat4 rotate = glm::toMat4(rotation);
    glm::mat4 scl = glm::scale(glm::mat4(), scale);

    return translate * rotate * scl;

}
