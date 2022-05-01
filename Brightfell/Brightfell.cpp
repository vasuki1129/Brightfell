// Brightfell.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "GraphicsContext.h"
#include "GameModule.h"
#include "TestGame.h"

bool shouldRun = true;

class GraphicsContext* context;
class GameModule* game;

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



    game->gameStart();
    double lastTime = 0.0f;

    double thisTime;
    while (shouldRun)
    {
        thisTime = glfwGetTime();
        game->tick(thisTime - lastTime);
        lastTime = glfwGetTime();
    }
    game->gameEnd();
}

int main()
{
    
    context = new GraphicsContext(800,600,handleInput);

    game = new TestGame();

    std::thread gameThread(gameLoop);
    renderLoop();
    gameThread.join();

    delete context;
}

