#pragma once
//main loop is just a forward to this loop function
//which is overridden to make a game
#include <vector>
#include "Tickable.h"
class GameModule
{
protected:
	short fpsSmooth = 50;
	std::vector<long> fpsHistory;
	std::vector<Tickable*> objects;


public:
	virtual void gameStart();
	virtual void tick(double deltaTime);
	virtual void gameEnd();

	virtual void registerObject(Tickable* obj);


};

