#include "Item.h"

Item::Item()
{
	itemName = "";
}

Item::~Item()
{
}

string Item::getName() {
	return itemName;
}

void Item::setName(string name) {
	itemName = name;
}

void Item::useItem() {}
void Item::setDmg(int from, int to) {}
void Item::setHealthChange(int change) {}