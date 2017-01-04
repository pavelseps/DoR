#include <windows.h>
#include "Map.h"
#include "Player.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	Map *map;
	Player* player = new Player();
    
public:
    Game();
    ~Game();
    
	void startGame();
};


void ClearScreen();

#endif // GAME_H
