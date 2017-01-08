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

	//Set/Get player health
	void setHealth(int health);
	int getHealth();

	//Set weapon
	void setWeapon(Item* weapon);

	//Get weapon damage
	int* getWeaponDamage();

	// add item to inventory from lootable room
	void addItemToInventory(Item* item);

	//Get list of items fro inventry
	string getInvetoryList();

	//Get actual weapon
	Item* getWeapon();

	//Change weapon from inventory
	bool changeWeapon();

	//Use health potion from inventory
	bool useHealthPotion();
};

