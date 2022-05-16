#include "TestRenderer.h"

TestRenderer::TestRenderer(void(*inputHandler)(GLFWwindow*, int, int, int, int))
{
	initialize(inputHandler);
}

void TestRenderer::initialize(void(*inputHandler)(GLFWwindow*, int, int, int, int))
{


	int width = 800;
	int height = 600;


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

	s = new Shader(vertexShSrc, fragShSrc);
	s->bind();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (const void*)0);
	glEnableVertexAttribArray(0);
	std::cout << "init finished\n";
	
}

void TestRenderer::render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	glm::mat4 rotate = glm::rotate(glm::mat4(1.0f),(float)sin(glfwGetTime())*2.0f,glm::vec3(0.5, 1.0, 0.0));
	glm::mat4 trans = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 mod = rotate * trans;

	int selector;
	selector = glGetUniformLocation(s->getId(), "model");
	glUniformMatrix4fv(selector,1, GL_FALSE, glm::value_ptr(mod));

	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), verts, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (const void*)0);

	glfwSwapBuffers(window);
	glfwPollEvents();
}
