#include <iostream>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
    string itemName = "";
public:
    Item();
    ~Item();

    void setName(string name){
        itemName = name;
    }
    
    string getName(){
        return itemName;
    }
};

#endif // ITEM_H
