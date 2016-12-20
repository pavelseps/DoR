#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::startGame() {
	map = new Map();
	string response = "";
	bool finish = false;
	bool hasResponse = false;

	while (!finish) {
		system("cls");

		cout << map->getActualRoom()->getLegend() << endl;
		if (hasResponse) {
			cout << response;
			response = "";
		}
		else {
			cout << endl;
		}
		map->printMap();

		response = map->getActualRoom()->waitForAction();
		hasResponse = response != "top" && response != "right" && response != "bottom" && response != "left";

		if (map->getActualRoom()->getStatusDoor(response)) {
			map->moveActualPlaPos(response);
		}

		if (!hasResponse)
			response = "";
	}
}