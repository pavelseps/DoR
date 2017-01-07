#include <iostream>
using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
    string itemName;
	int healthChange = 0;
	int dmg[2] = { 0, 0 };
	
public:
    Item();
    ~Item();

	//Set/Get item name
	void setName(string name);
	string getName();

	//Set/Get damage to weapon
	virtual void setDmg(int from, int to);
	virtual int* getDmg();

	//Set/Get health change
	virtual void setHealthChange(int change);
	virtual int getHealthChange();
};

#endif // ITEM_H
