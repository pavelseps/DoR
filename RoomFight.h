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

	//Wait for player action on keyboard
	string waitForAction(Player* player);

	//Add monster to room
	void addMonster(Monster* monster);

	//Get legend
	string getLegend();

	//Set/Get Init text
	void setInitText(string text);
	string getInitText();

	//Set description
	void setDescription(string description);

	//Get dmg of monster
	int getActualDmg(int from, int to);

	//If is monster dead
	bool isMonsterDead();
};

#endif // ROOMFIGHT_H
