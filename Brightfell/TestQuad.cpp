#include "TestQuad.h"

TestQuad::TestQuad()
{
	texture = new Texture("res/grass.png");

}

TestQuad::~TestQuad()
{
	delete texture;
}
