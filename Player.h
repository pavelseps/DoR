#include "Item.h"
#include <vector>
using namespace std;

#pragma once
class Player
{
private:
	int health = 0;
	int dmg[2] = { 1, 3 };
	vector<Item*> inventory;
public:
	Player();
	~Player();

	void setHealth(int health);
	int getHealth();
	void setDamage(int from, int to);
	int* getDamage();
	void addItemToInventory(Item* item);
	string getInvetoryList();
};

