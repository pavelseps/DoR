#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Map.h"
#include "Game.h"
#include "File.h"

using namespace std;

/**
 * @brief Dungeon of Rudix
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char **argv)
{
   
    Game* g = new Game();
    g->startGame();


	system("PAUSE");
	return 0;
}
