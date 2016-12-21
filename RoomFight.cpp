#include "RoomFight.h"

RoomFight::RoomFight()
{
	legend = "\n\t0: Info\n\t1: Zautoc\n";
}

RoomFight::~RoomFight()
{
}

string RoomFight::waitForAction(Player* player) {
	int n = -1;
	while (true) {
		n = readInput->read();

		if (n == 0) {
			return description + "\n";
		}
		else if (n == 1) {
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
			if (monster == NULL) {
				return "top";
			}
			else {
				return errorAtFirstKillMonstrum;
			}
		}
		else if (n == 4) {
			if (monster == NULL) {
				return "left";
			}
			else {
				return errorAtFirstKillMonstrum;
			}
		}
		else if (n == 6) {
			if (monster == NULL) {
				return "right";
			}
			else {
				return errorAtFirstKillMonstrum;
			}
		}
		else if (n == 5) {
			if (monster == NULL) {
				return "bottom";
			}
			else {
				return errorAtFirstKillMonstrum;
			}
		}
	}
}

void RoomFight::addMonster(Monster* monster) {
	this->monster = monster;
}

string RoomFight::getLegend() {
	return legend;
}

void RoomFight::setInitText(string text) {
	this->initText = text;
}

string RoomFight::getInitText() {
	return initText;
}

void RoomFight::setDescription(string description) {
	this->description = description;
}