#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::startGame() {
	map = new Map();
	player->setHealth(20);
	string response = "";
	bool finish = false;
	bool hasResponse = false;

	while (!finish) {
		system("cls");

		//Print player health
		cout << "\tZivoty: " << player->getHealth() << endl;
		//Print player damage
		int* playerDmg = player->getDamage();
		cout << "\tUtok: " << playerDmg[0] << "-" << playerDmg[1] << endl;
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