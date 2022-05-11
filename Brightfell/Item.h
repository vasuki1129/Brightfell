#pragma once
#include "Character.h"
class Character;
class Item
{
protected:
	float condition;
	float quality;
	bool bIsUnidentified;
	Character* maker;
	int yearCreated;
	float weight;
	bool bIsCommodity;
	float quantity;

};

