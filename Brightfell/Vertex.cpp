#include "Vertex.h"

Vertex::Vertex(float x, float y, float z, float u, float v)
{
	xPosition = x;
	yPosition = y;
	zPosition = z;

	xUv = u;
	yUv = v;
}

Vertex::~Vertex()
{

}
