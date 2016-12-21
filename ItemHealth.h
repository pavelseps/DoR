#include "Item.h"
using namespace std;

#pragma once
class ItemHealth: public Item
{
private:
	int healthChange = 0;
public:
	ItemHealth();
	~ItemHealth();

	void setHealthChange(int change);
	void useItem();
};

