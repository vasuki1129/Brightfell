#pragma once
#include <glm.hpp>
#include "Texture.h"
#include "Drawable.h"

class Texture;
class TestQuad : public Drawable
{
public:

	std::vector<Vertex> vertData = {
		Vertex(-1.0f,-1.0f,0.0f,0.0f,0.0f),
		Vertex(1.0f,-1.0f,0.0f,1.0f,0.0f),
		Vertex(1.0f,1.0f,0.0f,1.0f,1.0f),
		Vertex(-1.0f,1.0f,0.0f,0.0f,1.0f)
	};

	std::vector<unsigned int> indexData = {
		0,1,2,
		0,2,3
	};
	Texture* texture;

	TestQuad();
	~TestQuad();
};

