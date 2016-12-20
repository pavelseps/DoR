#include <conio.h>
#include "Map.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	Map *map;
    
public:
    Game();
    ~Game();
    
	void startGame();
};

#endif // GAME_H
