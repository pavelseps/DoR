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

	//Wait for player action on keyboard
	string waitForAction(Player* player);

	//Add item to room for loot
	void addItem(Item* item);

	//Get legend
	string getLegend();

	//Set/Get Init text
	void setInitText(string text);
	string getInitText();

	//Set description
	void setDescription(string description);
};

#endif // ROOMLOOT_H
