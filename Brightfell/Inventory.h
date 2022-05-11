#pragma once
#include <vector>
#include "Item.h"
class Item;

//represents a collection of items on a characters person
//or on a vehicle

//most characters will have an inventory, but not all

class Inventory
{
protected:
	std::vector<Item*> contents;
	float weightLimit;

};

