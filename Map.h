#include <iostream>
#include <string>
#include "Player.h"
#include "File.h"
using namespace std;

#ifndef MAP_H
#define MAP_H

class Map
{
private:
    int sizeX = 0;
    int sizeY = 0;
    int plaActualPos[2] = {0,0};

    Room*** map;
    
	void setActualPlaPos(int x, int y);
    
    
public:
    Map();
    ~Map();
   
	void printMap();
	Room* getActualRoom();
	Room* getRoom(int x, int y);
	Room* moveActualPlaPos(string dir);
};

#endif // MAP_H
