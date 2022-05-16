// Brightfell.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <thread>
#include "GraphicsContext.h"
#include "GameModule.h"
#include "TestGame.h"
#include "TestQuad.h"
#include "TestRenderer.h"
bool shouldRun = true;
class TestQuad;


class GraphicsContext* context;
class GameModule* game;
class TestRenderer* test;

void handleInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{


    if (key == GLFW_KEY_GRAVE_ACCENT && action == GLFW_PRESS)
    {
        context->unfocus();
    }

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        shouldRun = false;
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    if (key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        context->currentCam->HStartMoveForward();
    }
    if (key == GLFW_KEY_W && action == GLFW_RELEASE)
    {
        context->currentCam->HStopMoveForward();
    }

    if (key == GLFW_KEY_S && action == GLFW_PRESS)
    {
        context->currentCam->HStartMoveBack();
    }
    if (key == GLFW_KEY_S && action == GLFW_RELEASE)
    {
        context->currentCam->HStopMoveBack();
    }

    if (key == GLFW_KEY_A && action == GLFW_PRESS)
    {
        context->currentCam->HStartMoveLeft();
    }
    if (key == GLFW_KEY_A && action == GLFW_RELEASE)
    {
        context->currentCam->HStopMoveLeft();
    }

    if (key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        context->currentCam->HStartMoveRight();
    }
    if (key == GLFW_KEY_D && action == GLFW_RELEASE)
    {
        context->currentCam->HStopMoveRight();
    }

    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
    {
        context->currentCam->HStartMoveUp();
    }
    if (key == GLFW_KEY_Q && action == GLFW_RELEASE)
    {
        context->currentCam->HStopMoveUp();
    }

    if (key == GLFW_KEY_Z && action == GLFW_PRESS)
    {
        context->currentCam->HStartMoveDown();
    }
    if (key == GLFW_KEY_Z && action == GLFW_RELEASE)
    {
        context->currentCam->HStopMoveDown();
    }
    
}

void handleMouseInput(GLFWwindow* window, int button, int action, int mods)
{

    if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
    {
        context->focus();
    }

}

void renderLoop()
{
    
    TestQuad* quad = new TestQuad();
    quad->position = glm::vec3(0.0f, 0.0f, 0.0f);
    quad->rotation = glm::quat(glm::vec3(0.0f, 0.0f, 0.0f));
    quad->scale = glm::vec3(1.0f, 1.0f, 1.0f);
    context->registerDrawable(quad);
    context->currentCam = new Camera();
    context->currentCam->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    context->currentCam->setFov(70);

    
    game->registerObject(context->currentCam);
    while (shouldRun)
    {
        //test->render();
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

void printSquare(std::vector<std::vector<int>> inSqr)
{
    for (int i = 0; i < inSqr.size(); i++)
    {
        for (int p = 0; p < inSqr.at(0).size(); p++)
        {
            std::cout << inSqr.at(i).at(p);
        }
        std::cout << "\n";
    }

}






int main()
{
    
    if (false)
    {
        int desiredIterations = 3;

        std::vector<std::vector<int>> square;

        //initialize the square with as many total cells as we'll need
        int pix = 1;
        for (int i = 0; i < desiredIterations; i++)
        {
            pix = pix * 4;
        }
        std::cout << pix << "\n";

        for (int py = 0;py<pix;py++)
        {
            square.push_back(std::vector<int>());
            for (int px = 0; px < pix; px++)
            {
                square.at(py).push_back(1);
            }
        }
        printSquare(square);


        int currentSubdiv = pix / 2;

        for (int i = 1; i <= desiredIterations; i++)
        {
            for (int cx = 0;cx < pix; cx += currentSubdiv)
            {
                for (int cy = 0; cy < pix; cy += currentSubdiv)
                {
                    //determine eligibility




                }
            }


        }

        return 0;
    }




    context = new GraphicsContext(800,600,handleInput, handleMouseInput);

    game = new TestGame();
    //test = new TestRenderer(handleInput);
    std::thread gameThread(gameLoop);
    renderLoop();
    gameThread.join();

    delete context;
}

