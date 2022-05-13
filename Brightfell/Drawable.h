#pragma once

#include <vector>

#include <glm.hpp>
#include <ext.hpp>
#include "Vertex.h"



class Drawable
{
public:
	glm::vec3 position;
	glm::quat rotation;
	glm::vec3 scale;

	std::vector<Vertex> geometry;
	std::vector<unsigned int> indices;

public:

	glm::mat4 getMatrix();

	
};

