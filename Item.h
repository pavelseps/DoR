#include <iostream>
using namespace std;
#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
    string itemName;
public:
    Item();
    ~Item();

	void setName(string name);
    
	string getName();
};

#endif // ITEM_H
