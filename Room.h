#include <iostream>
#include "Monster.h"
#include "Game.h"
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
    
public:
    Room();
    ~Room();
    
    Game* g = new Game();
    
    virtual void addMonster(Monster* monster){};
    virtual void addItem(Item* item){};
    
	void setDescription(string description);
    
	string getDescription();
    
	void setStatusDoor(string dir, bool status = false);
    
	bool getStatusDoor(string dir);
    
	void setLabel(string label);
    
	string getLabel();
    
	virtual string waitForAction(bool info = true);
};

#endif // ROOM_H
