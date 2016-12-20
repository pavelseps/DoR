#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

int Game::readInput() {
	int n = -1;
	n = _getch();
	n -= 48;
	return n;
}