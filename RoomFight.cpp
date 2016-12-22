#include "RoomFight.h"

RoomFight::RoomFight()
{
	legend = "\n\t0: Info\n\t1: Zautoc\n\t2: Pouzij lektvar\n\t3: Zmen zbran\n";
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
			if (monster != nullptr) {
				string monsterName = monster->getMonsterName();
				delete monster;
				monster = nullptr;
				return "Pozazil jsi monstrum " + monsterName + ". Gratuluji!\n";
			}
			else {
				return "Uz jsi monstrum porazil.\n";
			}
		}
		else if (n == 2) {
			player->useHealthPotion();
			return "Pouzil jsi lektvar\n";
		}
		else if (n == 3) {
			player->changeWeapon();
			return "Zmenil jsi zbran\n";
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