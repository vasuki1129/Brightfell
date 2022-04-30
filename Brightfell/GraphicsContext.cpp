#include "GraphicsContext.h"


void GraphicsContext::processFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Render here

	glfwSwapBuffers(window);
	glfwPollEvents();
}

GraphicsContext::GraphicsContext(int width, int height, void (*inputHandler)(GLFWwindow*, int, int, int, int))
{
	if (!glfwInit())
	{
		std::cout << "GLFW init failed!\n";
		return;
	}

	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

	window = glfwCreateWindow(width, height, "Brightfell v0.0.1 \"Ur\"", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);

	GLenum error = glewInit();
	if (GLEW_OK != error)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(error));
	}
	
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, inputHandler);
}

GraphicsContext::~GraphicsContext()
{
}
