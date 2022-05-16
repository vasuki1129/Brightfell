#pragma once
//holds the window handles


#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <vector>
#include "Drawable.h"
#include "Camera.h"
#include "Shader.h"


class Drawable;
class Camera;

class GraphicsContext
{
private:

	const char* vertexShaderSource =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec3 position;\n"
		"uniform mat4 model;\n"
		"uniform mat4 cam;\n"
		"void main() {\n"
		"\n"
		"	gl_Position = cam * model* vec4(position, 1.0);\n"
		"}\n"
		;

	const char* fragShaderSource =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main() {\n"
		"	color = vec4(0.0,1.0,0.0,1.0);\n"
		"}\n"
		;


public:

	unsigned int vao;
	unsigned int vbo;
	unsigned int ibo;

	double lastMousePositionX = 0.0;
	double lastMousePositionY = 0.0;


	std::vector<Drawable*> renderQueue;
	Shader* defaultShader;

	Camera* currentCam;

	GLFWwindow* window;
	void processFrame();
	GraphicsContext(int width, int height, void (*inputHandler)(GLFWwindow*, int, int, int, int), void (*inputHandlerMouse)(GLFWwindow*, int, int, int));
	~GraphicsContext();

	void registerDrawable(Drawable* drawable);

	void focus();
	void unfocus();


};

