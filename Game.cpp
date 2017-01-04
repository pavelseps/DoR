#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

//Rychlejsi vykreslovani do konzole
static void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void Game::startGame() {
	map = new Map();
	player->setHealth(20);
	string response = "";
	bool finish = false;
	bool hasResponse = false;

	while (!finish) {
		ClearScreen();

		//Print player health
		cout << "\tZivoty: " << player->getHealth() << endl;
		//Print player damage
		int* playerDmg = player->getWeaponDamage();
		cout << "\tUtok: " << player->getWeapon()->getName() << " (" << playerDmg[0] << "-" << playerDmg[1] << ")" << endl;
		//Print player inventory
		cout << "\tInventar: " << player->getInvetoryList() << endl << endl;

		//Print legend
		cout << map->getActualRoom()->getLegend() << endl;
		//Print response
		if (hasResponse) {
			cout << response;
		}
		else {
			cout << endl;
		}
		//Print map
		map->printMap();

		response = "";
		//Wait for input
		response = map->getActualRoom()->waitForAction(player);

		//If has text/info response
		hasResponse = response != "top" && response != "right" && response != "bottom" && response != "left";

		if (map->getActualRoom()->getStatusDoor(response)) {
			response = map->moveActualPlaPos(response)->getInitText();
			response.append("\n");
			hasResponse = true;
		}
	}
}