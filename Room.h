#include <iostream>
#include "Monster.h"
#include "ReadInput.h"
#include "Item.h"
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
    
    ReadInput* readInput = new ReadInput();
    
    virtual void addMonster(Monster* monster){};
    virtual void addItem(Item* item){};
    
	void setDescription(string description);

	virtual string getLegend();
    
	string getDescription();
    
	void setStatusDoor(string dir, bool status = false);
    
	bool getStatusDoor(string dir);
    
	void setLabel(string label);
    
	string getLabel();
    
	virtual string waitForAction();
};

#endif // ROOM_H
