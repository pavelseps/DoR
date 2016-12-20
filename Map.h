#include <iostream>
#include <string>
#include "Item.h"
#include "Monster.h"
#include "Room.h"
#include "RoomLoot.h"
#include "RoomFight.h"
using namespace std;

#ifndef MAP_H
#define MAP_H

class Map
{
private:
    static const int sizeX = 3;
    static const int sizeY = 3;
    int plaActualPos[2] = {0,0};

    Room* map [sizeX][sizeY];
    
	void changeActualPlaPos(int x, int y);
    
    
public:
    Map();
    ~Map();
    
	void initMap();

	void printMap();
    
	void moveWithPla(string dir);
};

#endif // MAP_H
