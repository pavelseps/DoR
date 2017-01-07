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
   
	//Print map from array
	void printMap();

	//Get actual room where is player now
	Room* getActualRoom();

	//Get room on x,y position
	Room* getRoom(int x, int y);

	//Move with player to next room
	Room* moveActualPlaPos(string dir);
};

#endif // MAP_H
