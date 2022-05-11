#pragma once
#include <glm.hpp>
#include <ext.hpp>
class Camera
{
public:
	glm::vec3 position;
	glm::vec3 lookTarget;
	float fov;

	glm::mat4 getMatrix();
	
	void setPosition(glm::vec3 newPos);
	void setTarget(glm::vec3 newTarget);

	void setFov(float newFov);

};

