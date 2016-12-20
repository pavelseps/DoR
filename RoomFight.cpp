#include "RoomFight.h"

RoomFight::RoomFight()
{
}

RoomFight::~RoomFight()
{
}

string RoomFight::waitForAction(bool info) {
	if (info)
		cout << endl << "0: Zautoc" << endl;

	int n = -1;
	while (true) {
		n = g->readInput();

		if (n == 0) {
			if (monster != NULL) {
				string monsterName = monster->getMonsterName();
				monster = NULL;
				return "Pozazil jsi monstrum " + monsterName + ". Gratuluji!\n";
			}
			else {
				return "Uz jsi monstrum porazil.\n";
			}
		}
		else if (n == 8) {
			return "top";
		}
		else if (n == 4) {
			return "left";
		}
		else if (n == 6) {
			return "right";
		}
		else if (n == 5) {
			return "bottom";
		}
	}
}

void RoomFight::addMonster(Monster* monster) {
	this->monster = monster;
}