#include "TestQuad.h"

TestQuad::TestQuad()
{
	texture = new Texture("res/grass.png");
	geometry = vertData;
	indices = indexData;


}

TestQuad::~TestQuad()
{
	delete texture;
}
