#pragma once
//holds the window handles


#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <vector>
#include "Drawable.h"
#include "Camera.h"

class Drawable;
class Camera;

class GraphicsContext
{
public:


	std::vector<Drawable*> renderQueue;


	Camera* currentCam;

	GLFWwindow* window;
	void processFrame();
	GraphicsContext(int width, int height, void (*inputHandler)(GLFWwindow*, int, int, int, int));
	~GraphicsContext();

};

