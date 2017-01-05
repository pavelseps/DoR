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

	start:
    g->startMenu();

	if (g->endGame(g->startGame())) {
		goto start;
	}



	return 0;
}
