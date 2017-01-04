#include "Monster.h"

Monster::Monster(int health)
{
	this->health = health;
}

Monster::~Monster()
{
	delete weapon;
}

void Monster::setMonsterName(string name) {
	monsterName = name;
}

string Monster::getMonsterName() {
	return monsterName;
}

void Monster::setWeapon(Item* weapon) {
	this->weapon = weapon;
}

int Monster::getMonsterHealth() {
	return health;
}

int* Monster::getDmg(){
	return weapon->getDmg();
}