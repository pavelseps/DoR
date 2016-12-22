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

	void setName(string name);
    
	string getName();
	virtual void setDmg(int from, int to);
	virtual int* getDmg();
	virtual void setHealthChange(int change);
	virtual int getHealthChange();
};

#endif // ITEM_H
