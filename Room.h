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
    
    virtual void addMonster(Monster* monster){};
    virtual void addItem(Item* item){};

	virtual bool isMonsterDead() { return true; };
    
	virtual void setDescription(string description);

	virtual string getLegend();
    
	void setStatusDoor(string dir, bool status = false);
	bool getStatusDoor(string dir);
    
	void setLabel(string label);
	string getLabel();

	virtual void setInitText(string text);
	virtual string getInitText();
    
	virtual string waitForAction(Player* player);
};

#endif // ROOM_H
