#include "GraphicsContext.h"


void GraphicsContext::processFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLint p;
	glValidateProgram(defaultShader->getId());
	glGetProgramiv(defaultShader->getId(), GL_VALIDATE_STATUS, &p);

	if (p == GL_TRUE) {
		std::cout << "Validated Shader Successfully" << "\n";
	}
	else
	{
		std::cout << "Shader Validation Failed" << "\n";
	}


	//Render all the drawables in the queue
	for (Drawable* currentDraw : renderQueue)
	{



		//buffer the vertex data
		glBufferData(GL_ARRAY_BUFFER, currentDraw->geometry.size() * sizeof(Vertex), &currentDraw->geometry[0], GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, currentDraw->indices.size() * sizeof(unsigned int), &currentDraw->indices[0], GL_STATIC_DRAW);

		//setup the attrib ptr
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		//glEnableVertexAttribArray(1);

		//setup the uniforms
		glm::mat4 model = currentDraw->getMatrix();
		glm::mat4 cameraMatrix = currentCam->getMatrix();

		//send the uniforms
		//int selector;
		//selector = glGetUniformLocation(defaultShader->getId(), "model");
		//glUniformMatrix4fv(selector, 1, GL_FALSE, glm::value_ptr(model));

		//selector = glGetUniformLocation(defaultShader->getId(), "cameraMatrix");
		//glUniformMatrix4fv(selector, 1, GL_FALSE, glm::value_ptr(cameraMatrix));


		//draw
		glDrawElements(GL_TRIANGLES, currentDraw->indices.size(), GL_UNSIGNED_INT, (const void*)0);

	}

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

	//Shader compilation	

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	defaultShader = new Shader(vertexShaderSource, fragmentShaderSource);
	defaultShader->bind();
}

GraphicsContext::~GraphicsContext()
{
}

void GraphicsContext::registerDrawable(Drawable* drawable)
{
	renderQueue.push_back(drawable);
}
