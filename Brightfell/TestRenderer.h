#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm.hpp>
#include <ext.hpp>


#include "Shader.h"
class TestRenderer
{
public:

	Shader* s;

	float verts[12] =
	{
		-0.7f,-0.7f,0.0f,
		0.7f,-0.7f,0.0f,
		0.7f,0.7f,0.0f,
		-0.7f,0.7f,0.0f
		
	};


	unsigned int indices[6] =
	{
		0,1,2,
		0,2,3
	};

	const char* vertexShSrc =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec3 position;\n"
		"\n"
		"uniform mat4 model;\n"
		"void main() {\n"
		"	gl_Position = model * vec4(position,1.0);\n"
		"}\n"
		;

	const char* fragShSrc =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"void main() {\n"
		"	color = vec4(1.0,0.0,0.0,1.0);\n"
		"}\n"
		;

	TestRenderer(void (*inputHandler)(GLFWwindow*, int, int, int, int));
	void initialize(void(*inputHandler)(GLFWwindow*, int, int, int, int));
	void render();
	GLFWwindow* window;

	unsigned int vao;
	unsigned int vbo;
	unsigned int ibo;
};

