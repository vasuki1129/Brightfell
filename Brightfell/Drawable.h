#pragma once

#include <vector>

#include <glm.hpp>
#include <ext.hpp>
#include "Vertex.h"



class Drawable
{
public:
	glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f);
	glm::quat rotation = glm::quat(glm::vec3(0.0f, 0.0f, 0.0f));
	glm::vec3 scale = glm::vec3(1.0f,1.0f,1.0f);

	std::vector<Vertex> geometry;

	float verts[12] =
	{
		-0.7f,-0.7f,0.0f,
		-0.7f,0.7f,0.0f,
		0.7f,0.7f,0.0f,
		0.7f,-0.7f,0.0f
	};
	unsigned int testIdx[6] =
	{
		0,1,2,
		0,2,3
	};

	std::vector<unsigned int> indices;

public:

	virtual glm::mat4 getMatrix();

	
};

