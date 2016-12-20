#include <iostream>
#include "Room.h"
#include "Monster.h"
using namespace std;

#ifndef ROOMFIGHT_H
#define ROOMFIGHT_H

class RoomFight : public Room
{
private:
    Monster* monster;
	string legend = "";
    
public:
    RoomFight();
    ~RoomFight();

	string waitForAction();
	void addMonster(Monster* monster);
	string getLegend();
};

#endif // ROOMFIGHT_H
