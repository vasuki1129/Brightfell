#pragma once
#include <string>
//an entity that has stats and can be controlled by either
//a player or the ai

//unlike many other games, EVERYTHING that is ai controllable
//is ultimately a character, even rats or flies

class Character
{
protected:
	//to disambiguate incase there are identical characters
	long characterID;

	std::string displayName;
	
	//stats
	int level;
	long xp;

	long hp;
	long mana;
	long stamina;


};

