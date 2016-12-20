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
    
public:
    RoomFight();
    ~RoomFight();

	string waitForAction(bool info = true);
    
	void addMonster(Monster* monster);
};

#endif // ROOMFIGHT_H
