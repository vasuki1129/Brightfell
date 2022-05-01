#pragma once
#include "GameModule.h"
#include <iostream>

class TestGame : public GameModule
{
public:
	void gameStart() override;
	void tick(double deltaTime) override;
	void gameEnd() override;

};

