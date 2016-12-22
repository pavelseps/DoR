#include "Item.h"
#include "ItemWeapon.h"
#include <vector>
using namespace std;

#pragma once
class Player
{
private:
	int health = 0;
	Item* weapon;
	vector<Item*> inventory;
public:
	Player();
	~Player();

	void setHealth(int health);
	int getHealth();
	void setWeapon(Item* weapon);
	int* getWeaponDamage();
	void addItemToInventory(Item* item);
	string getInvetoryList();
	Item* getWeapon();
	void changeWeapon();
	void useHealthPotion();
};

