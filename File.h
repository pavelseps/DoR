#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Room.h"
#include "RoomFight.h"
#include "RoomLoot.h"
#include "Item.h"
#include "ItemHealth.h"
#include "ItemWeapon.h"
#include "Monster.h"

using namespace std;

#pragma once
class File
{
private:
	string str;
	Item* findItem(int id);
public:
	File();
	~File();
	Room*** getMap();
	int* getStartPos();
};

vector<string> splitString(string str, string delimiter = ";");
vector<string> findAllLines(string str, string sub);