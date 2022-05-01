#pragma once
//main loop is just a forward to this loop function
//which is overridden to make a game
#include <vector>
class GameModule
{
protected:
	short fpsSmooth = 50;
	std::vector<long> fpsHistory;

public:
	virtual void gameStart();
	virtual void tick(double deltaTime);
	virtual void gameEnd();


};

