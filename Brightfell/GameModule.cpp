#include "GameModule.h"
#include <iostream>
void GameModule::gameStart()
{

}

void GameModule::tick(double deltaTime)
{
	if (fpsHistory.size() >= fpsSmooth)
	{
		fpsHistory.insert(fpsHistory.begin(), 1 / deltaTime);
		fpsHistory.pop_back();
	}
	else
	{
		fpsHistory.push_back(1 / deltaTime);
	}

	int fps=0;
	if (fpsHistory.size() >= fpsSmooth)
	{
		for (int i = 0; i < fpsHistory.size(); i++)
		{
			fps += fpsHistory[i];
		}
		fps = fps / fpsSmooth;
	}

	for (Tickable* t : objects)
	{
		t->logicTick(deltaTime);
	}

	//std::cout << "Game FPS: " << fps << "\n";
	//std::cout << "Game Delta: " << deltaTime << "\n";

	

}

void GameModule::gameEnd()
{

}

void GameModule::registerObject(Tickable* obj)
{
	objects.push_back(obj);
}
