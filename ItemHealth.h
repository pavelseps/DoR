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

	//Set/Get health change
	void setHealthChange(int change);
	int getHealthChange();
};

