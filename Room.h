#include <iostream>
#include "Monster.h"
#include "ReadInput.h"
#include "Item.h"
#include "Player.h"
using namespace std;

#ifndef ROOM_H
#define ROOM_H

class Room
{
private:
    string description = "";
    string label = "";
    bool openedDoor[4] = {
        false,
        false,
        false,
        false
    };
	string legend = "";
    
public:
    Room();
    ~Room();

	string initText = "";
    ReadInput* readInput = new ReadInput();

	//Set/Get opened/closed door
	void setStatusDoor(string dir, bool status = false);
	bool getStatusDoor(string dir);

	//Set/Get room label
	void setLabel(string label);
	string getLabel();
    
	//Add monster to room
    virtual void addMonster(Monster* monster){};

	//Add item to room for loot
    virtual void addItem(Item* item){};

	//If is monster dead
	virtual bool isMonsterDead() { return true; };
    
	//Set description
	virtual void setDescription(string description);

	//Get legend
	virtual string getLegend();

	//Set/Get Init text
	virtual void setInitText(string text);
	virtual string getInitText();
    
	//Wait for player action on keyboard
	virtual string waitForAction(Player* player);
};

#endif // ROOM_H
