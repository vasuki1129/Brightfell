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
	const char* vertexShaderSourceOL =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"layout(location = 1) in vec2 texCoord;\n"
		"//layout(location = 2) out vec2 tCoord;\n"
		"\n"
		"uniform mat4 model;\n"
		"uniform mat4 cam;\n"
		"void main() {\n"
		"\n"
		"	gl_Position = cam * model * position;\n"
		"}\n"
		;

	const char* vertexShaderSource =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec3 position;\n"
		"\n"
		"void main() {\n"
		"\n"
		"	gl_Position = vec4(position, 1.0);\n"
		"}\n"
		;


	const char* fragShaderSourceOL =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"//layout(location = 1) in vec3 tCoord;\n"
		"\n"
		"void main() {\n"
		"	color = vec4(0.0,1.0,0.0,1.0);\n"
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



	std::vector<Drawable*> renderQueue;
	Shader* defaultShader;

	Camera* currentCam;

	GLFWwindow* window;
	void processFrame();
	GraphicsContext(int width, int height, void (*inputHandler)(GLFWwindow*, int, int, int, int));
	~GraphicsContext();

	void registerDrawable(Drawable* drawable);


};

