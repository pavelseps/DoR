#include <iostream>
#include <string>
#include <windows.h>
#include "Room.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

#ifndef ROOMFIGHT_H
#define ROOMFIGHT_H

class RoomFight : public Room
{
private:
    Monster* monster;
	string legend = "";
	string errorAtFirstKillMonstrum = "Nejdrive zabij monstrum\n";
	string description = "";
    
public:
    RoomFight();
    ~RoomFight();
	string initText = "";

	string waitForAction(Player* player);
	void addMonster(Monster* monster);
	string getLegend();

	void setInitText(string text);
	string getInitText();

	void setDescription(string description);
	int getActualDmg(int from, int to);

	bool isMonsterDead();
};

#endif // ROOMFIGHT_H
