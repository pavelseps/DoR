#include <iostream>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

#ifndef ROOMLOOT_H
#define ROOMLOOT_H

class RoomLoot : public Room
{
private:
    vector<Item*> items;
    string itemsNameS = "";
	string legend = "";

public:
    RoomLoot();
    ~RoomLoot();

	string waitForAction();
	void addItem(Item* item);
	string getLegend();
};

#endif // ROOMLOOT_H
