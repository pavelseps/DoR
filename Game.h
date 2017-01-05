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
	Player* player;
	ReadInput* readInput = new ReadInput();
    
public:
    Game();
    ~Game();
    
	bool startGame();
	void startMenu();
	bool endGame(bool victory);
};


void ClearScreen();

#endif // GAME_H
