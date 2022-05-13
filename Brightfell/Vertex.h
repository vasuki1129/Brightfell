#pragma once
struct Vertex
{
	//position
	float xPosition;
	float yPosition;
	float zPosition;
	
	//tex coord
	float xUv;
	float yUv;


	Vertex(float x, float y, float z, float u, float v);
	~Vertex();
};

