// Brightfell.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "GraphicsContext.h"


bool shouldRun = true;

class GraphicsContext* context;

void handleInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        shouldRun = false;
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void renderLoop()
{
    while (shouldRun)
    {
        context->processFrame();
    }
    glfwTerminate();
}

void gameLoop()
{
    while (shouldRun)
    {

    }
    
}

int main()
{
    context = new GraphicsContext(800,600,handleInput);

    std::thread gameThread(gameLoop);
    renderLoop();
    gameThread.join();

    delete context;
}

