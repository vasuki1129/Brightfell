#pragma once
#include <glm.hpp>
#include "Texture.h"
#include "Drawable.h"

class Texture;
class TestQuad : public Drawable
{
public:

	float vertData[5*4] = {
		-1.0f,-1.0f,0.0f,0.0f,0.0f,
		1.0f,-1.0f,0.0f,1.0f,0.0f,
		1.0f,1.0f,0.0f,1.0f,1.0f,
		-1.0f,1.0f,0.0f,0.0f,1.0f
	};

	unsigned int indexData[3 * 2] = {
		0,1,2,
		0,2,3
	};

	glm::mat4 position;

	Texture* texture;

	TestQuad();
	~TestQuad();
};

