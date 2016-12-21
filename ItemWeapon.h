#include "Item.h"
using namespace std;

#pragma once
class ItemWeapon : public Item
{
private:
	int dmg[2] = { 0, 0 };
public:
	ItemWeapon();
	~ItemWeapon();

	void setDmg(int from, int to);
	void useItem();
};

