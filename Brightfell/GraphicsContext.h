#pragma once
//holds the window handles


#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>







class GraphicsContext
{
public:
	GLFWwindow* window;
	void processFrame();
	GraphicsContext(int width, int height, void (*inputHandler)(GLFWwindow*, int, int, int, int));
	~GraphicsContext();

};

