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
public:
    RoomLoot();
    ~RoomLoot();

	string waitForAction(bool info = true);
    
	void addItem(Item* item);
};

#endif // ROOMLOOT_H
