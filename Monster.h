#include <iostream>
#include "Item.h"
using namespace std;

#ifndef MONSTER_H
#define MONSTER_H

class Monster
{
private:
    string monsterName = "";
	int health = 0;
	Item* weapon;
public:
    Monster(int health = 0);
    ~Monster();
    
	//Set/Get monster name
	void setMonsterName(string name);
	string getMonsterName();

	//Set weapon
	void setWeapon(Item* weapon);

	//Get monster health
	int getMonsterHealth();

	//Get monster damage
	int* getDmg();
};

#endif // MONSTER_H
