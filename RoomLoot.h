#include <iostream>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "Player.h"

using namespace std;

#ifndef ROOMLOOT_H
#define ROOMLOOT_H

class RoomLoot : public Room
{
private:
    vector<Item*> items;
    string itemsNameS = "";
	string legend = "";
	string description = "";

public:
    RoomLoot();
    ~RoomLoot();
	string initText = "";

	string waitForAction(Player* player);
	void addItem(Item* item);
	string getLegend();

	void setInitText(string text);
	string getInitText();

	void setDescription(string description);
};

#endif // ROOMLOOT_H
