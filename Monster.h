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
    
	void setMonsterName(string name);
	string getMonsterName();
	void setWeapon(Item* weapon);
	int getMonsterHealth();
	int* getDmg();
};

#endif // MONSTER_H
