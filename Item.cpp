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