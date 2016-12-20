#include "Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::setMonsterName(string name) {
	monsterName = name;
}

string Monster::getMonsterName() {
	return monsterName;
}