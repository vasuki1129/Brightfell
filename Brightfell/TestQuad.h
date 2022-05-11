#pragma once
#include <glm.hpp>
#include "Texture.h"
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

	glm::mat4 position;

	Texture* texture;

	TestQuad();
	~TestQuad();
};

