#include "GraphicsContext.h"


void GraphicsContext::processFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//Render all the drawables in the queue
	for (Drawable* currentDraw : renderQueue)
	{

		
		glm::mat4 mod = currentDraw->getMatrix();
		glm::mat4 cameraMatrix = currentCam->getMatrix();

		int selector;
		selector = glGetUniformLocation(defaultShader->getId(), "model");
		glUniformMatrix4fv(selector, 1, GL_FALSE, glm::value_ptr(mod));

		selector = glGetUniformLocation(defaultShader->getId(), "cam");
		glUniformMatrix4fv(selector, 1, GL_FALSE, glm::value_ptr(cameraMatrix));

		glBufferData(GL_ARRAY_BUFFER, currentDraw->geometry.size()*sizeof(Vertex), &currentDraw->geometry[0], GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, currentDraw->indices.size() * sizeof(unsigned int), &currentDraw->indices[0], GL_STATIC_DRAW);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (const void*)0);

	}

	double MousePositionX, MousePositionY;

	glfwGetCursorPos(window, &MousePositionX, &MousePositionY);

	float sens = 0.1f;

	currentCam->rotate(glm::vec3(sens * (MousePositionX - lastMousePositionX), 0, sens * (MousePositionY - lastMousePositionY)));
	lastMousePositionX = MousePositionX;
	lastMousePositionY = MousePositionY;



	glfwSwapBuffers(window);
	glfwPollEvents();




	

}

GraphicsContext::GraphicsContext(int width, int height, void (*inputHandler)(GLFWwindow*, int, int, int, int), void (*inputHandlerMouse)(GLFWwindow*, int, int, int))
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
		const char* error[512];
		int err = glfwGetError(error);
		std::cout << "\nError Code: " << err << "\nError Desc: " << error << "\n";

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
	glfwSetMouseButtonCallback(window, inputHandlerMouse);

	defaultShader = new Shader(vertexShaderSource, fragShaderSource);
	defaultShader->bind();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)0);
	glEnableVertexAttribArray(0);
	std::cout << "init finished\n";
}

GraphicsContext::~GraphicsContext()
{
}

void GraphicsContext::registerDrawable(Drawable* drawable)
{
	renderQueue.push_back(drawable);
}

void GraphicsContext::focus()
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	std::cout << "FOCUSED\n";

}

void GraphicsContext::unfocus()
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	std::cout << "UNFOCUSED\n";
}
