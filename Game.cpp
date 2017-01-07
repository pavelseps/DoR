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

bool Game::startGame() {
	map = new Map();
	player = new Player();
	player->setHealth(20);

	string response = "";
	bool hasResponse = false;
	bool startgame = true;

	while (true) {
		ClearScreen();

		//if player died
		if (player->getHealth() < 1) {
			delete map;
			return false;
		}

		//If player won
		if (map->getActualRoom()->getLabel() == "END" && map->getActualRoom()->isMonsterDead()) {
			delete map;
			return true;
		}

		//Print player health
		cout << endl
			<< "\t==== Hrac" << endl
		<< "\t*  Zivoty: " << player->getHealth() << endl;
		//Print player damage
		int* playerDmg = player->getWeaponDamage();
		cout << "\t*  Utok: " << player->getWeapon()->getName() << " (" << playerDmg[0] << "-" << playerDmg[1] << ")" << endl;
		//Print player inventory
		cout << "\t*  Inventar: " << player->getInvetoryList() << endl 
			<< "\t====" << endl << endl;

		//Print legend
		cout << "\t==== Legenda"
			<< map->getActualRoom()->getLegend()
			<< "\t====" << endl << endl;
		//Print response
		if (startgame) {
			response = map->getActualRoom()->getInitText();
			response.append("\n");
		}
		if (hasResponse || startgame) {
			cout << "\t==== Informace" << endl
				<< "\t*   " << endl
				<< "\t*  " << response
				<< "\t*   " << endl
				<< "\t====" << endl;
			startgame = false;
		}
		else {
			cout << "\t==== Informace" << endl
				<< "\t*   " << endl
				<< "\t*   " << endl
				<< "\t*   " << endl
				<< "\t====" << endl;
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

void Game::startMenu() {

	int n = -1;
	while (true) {
		ClearScreen();
		cout << endl
			<< "\t ======================================================================= " << endl
			<< "\t*                                                                       *" << endl
			<< "\t*    ____                                 ___    _____       _ _        *" << endl
			<< "\t*   |    \\ _ _ ___ ___ ___ ___ ___    ___|  _|  | __  |_ _ _| |_|_ _    *" << endl
			<< "\t*   |  |  | | |   | . | -_| . |   |  | . |  _|  |    -| | | . | |_'_|   *" << endl
			<< "\t*   |____/|___|_|_|_  |___|___|_|_|  |___|_|    |__|__|___|___|_|_,_|   *" << endl
			<< "\t*                 |___|                                                 *" << endl
			<< "\t*                                                                       *" << endl
			<< "\t*_______________________________________________________________________*" << endl
			<< "\t*                                                                       *" << endl
			<< "\t*                                                                       *" << endl
			<< "\t*   0: Zacit hru                                                        *" << endl
			<< "\t*   1: Jak se hra hraje                                                 *" << endl
			<< "\t*   2: O autorovi                                                       *" << endl
			<< "\t*                                                                       *" << endl
			<< "\t*                                                                       *" << endl
			<< "\t*=======================================================================*" << endl;

		n = readInput->read();

		if (n == 0) {
			break;
		}
		else if (n == 1) {
			while (n != 3) {
				ClearScreen();
				cout << endl
					<< "\t ======================================================================= " << endl
					<< "\t*                                                                       *" << endl
					<< "\t*    ____                                 ___    _____       _ _        *" << endl
					<< "\t*   |    \\ _ _ ___ ___ ___ ___ ___    ___|  _|  | __  |_ _ _| |_|_ _    *" << endl
					<< "\t*   |  |  | | |   | . | -_| . |   |  | . |  _|  |    -| | | . | |_'_|   *" << endl
					<< "\t*   |____/|___|_|_|_  |___|___|_|_|  |___|_|    |__|__|___|___|_|_,_|   *" << endl
					<< "\t*                 |___|                                                 *" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*_______________________________________________________________________*" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*   Cela hra se ovlada pomoci cisel.                                    *" << endl
					<< "\t*   Cislicemi 8, 6, 5, 4 se ovlada smer pohybu                          *" << endl
					<< "\t*   Cislice 0, 1, 2, 3 jsou ovladani akci, ktere jsou                   *" << endl
					<< "\t*   vysvetlene v legende                                                *" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*   Ukolem hry je se dostat do mistnosti s napisem END                  *" << endl
					<< "\t*   Po ceste ziskavas predmety a zabijis monstra                        *" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*   3: zpet                                                             *" << endl
					<< "\t*=======================================================================*" << endl;
				n = readInput->read();
			}

		}
		else if (n == 2) {
			while (n != 3) {
				ClearScreen();
				cout << endl
					<< "\t ======================================================================= " << endl
					<< "\t*                                                                       *" << endl
					<< "\t*    ____                                 ___    _____       _ _        *" << endl
					<< "\t*   |    \\ _ _ ___ ___ ___ ___ ___    ___|  _|  | __  |_ _ _| |_|_ _    *" << endl
					<< "\t*   |  |  | | |   | . | -_| . |   |  | . |  _|  |    -| | | . | |_'_|   *" << endl
					<< "\t*   |____/|___|_|_|_  |___|___|_|_|  |___|_|    |__|__|___|___|_|_,_|   *" << endl
					<< "\t*                 |___|                                                 *" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*_______________________________________________________________________*" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*   Autorem teto hry je Pavel Seps, kdy tuto hru vytvoril jako          *" << endl
					<< "\t*   semestralni praci.                                                  *" << endl
					<< "\t*   Cely projekt je k nahlednuti na githabu:                            *" << endl
					<< "\t*   https://github.com/pavelseps/DoR                                    *" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*                                                                       *" << endl
					<< "\t*   3: zpet                                                             *" << endl
					<< "\t*=======================================================================*" << endl;
				n = readInput->read();
			}
		}
	}
}

bool Game::endGame(bool victory) {
	string response = "";
	if (victory) {
		response = "Gratuluji! Vyhral jsi a porazil jsi Rudixe";
	}
	else {
		response = "Dungeon te porazil                        ";
	}

	int n = -1;
	while (true) {
		ClearScreen();
		cout << endl
			<< "\t ======================================================================= " << endl
			<< "\t*                                                                       *" << endl
			<< "\t*    ____                                 ___    _____       _ _        *" << endl
			<< "\t*   |    \\ _ _ ___ ___ ___ ___ ___    ___|  _|  | __  |_ _ _| |_|_ _    *" << endl
			<< "\t*   |  |  | | |   | . | -_| . |   |  | . |  _|  |    -| | | . | |_'_|   *" << endl
			<< "\t*   |____/|___|_|_|_  |___|___|_|_|  |___|_|    |__|__|___|___|_|_,_|   *" << endl
			<< "\t*                 |___|                                                 *" << endl
			<< "\t*                                                                       *" << endl
			<< "\t*_______________________________________________________________________*" << endl
			<< "\t*                                                                       *" << endl
			<< "\t*   " << response << "                          *" << endl
			<< "\t*   Prejes si zacit znovu?                                              *" << endl
			<< "\t*                                                                       *" << endl
			<< "\t*   0: Ano                                                              *" << endl
			<< "\t*   1: Ne, hra se vypne                                                 *" << endl
			<< "\t*                                                                       *" << endl
			<< "\t*=======================================================================*" << endl;

		n = readInput->read();

		if (n == 0) {
			return 1;
		}
		else if (n == 1) {
			return 0;
		}
	}
}