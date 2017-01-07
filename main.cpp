#include "Game.h"
#include <windows.h>

using namespace std;

/**
 * @brief Dungeon of Rudix
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char **argv)
{
	system("mode 650");

	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE );

    Game* g = new Game();

	start:
    g->startMenu();
	if (g->endGame(g->startGame()))
		goto start;

	return 0;
}
