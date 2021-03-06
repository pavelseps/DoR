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
			if (!isMonsterDead()) {
				int monsterHealth = monster->getMonsterHealth();
				int* monsterDmg = monster->getDmg();
				int playerHealth = player->getHealth();
				int* playerDmg = player->getWeaponDamage();
				bool plaAttack = true;
				int actualDmg = 0;

				system("CLS");
				cout << endl
					<< "\t ==================================== " << endl
					<< "\t*                                    *" << endl
					<< "\t*               BITVA                *" << endl
					<< "\t*====================================*" << endl
					<< endl;


				while (monsterHealth > 0 && playerHealth > 0) {

					if (plaAttack) {
						plaAttack = false;
						actualDmg = getActualDmg(playerDmg[0], playerDmg[1]);
						monsterHealth -= actualDmg;

						cout << "\t*   Utocis za: " << actualDmg << endl
							<< "\t*   Monstrum ma: " << monsterHealth << " zivotu" << endl << endl;
					}
					else {
						plaAttack = true;
						actualDmg = getActualDmg(monsterDmg[0], monsterDmg[1]);
						playerHealth -= actualDmg;

						cout << "\t*   Monstrum utoci za: " << actualDmg << endl
							<< "\t*   Mas: " << playerHealth << " zivotu" << endl << endl;
					}

					Sleep(1900);
				}


				player->setHealth(playerHealth);

				if (playerHealth < 1) {
					cout << "\t ==================================== " << endl
						<< "\t*   Monstrum te porazilo, zbylo mu " + to_string(monsterHealth) + " zivotu\n\n";

					Sleep(3000);
					return "Monstrum te porazilo, zbylo mu " + to_string(monsterHealth) + " zivotu\n";
				}
				else {
					string monsterName = monster->getMonsterName();
					delete monster;
					monster = nullptr;
					cout << "\t ==================================== " << endl
						<< "\t*   Pozazil jsi monstrum " + monsterName + ". Gratuluji!\n\n";

					Sleep(3000);
					return "Pozazil jsi monstrum " + monsterName + ". Gratuluji!\n";
				}
			}
			else {
				return "Uz jsi monstrum porazil.\n";
			}
		}
		else if (n == 2) {
			if (player->useHealthPotion()) {
				return "Pouzil jsi lektvar\n";
			}
			else {
				return "Zadny lektvar nemas\n";
			}
		}
		else if (n == 3) {
			if (player->changeWeapon()) {
				return "Zmenil jsi zbran\n";
			}
			else {
				return "Nemas vice zbrani\n";
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

int RoomFight::getActualDmg(int from, int to) {
	return rand() % (to - from + 1) + from;
}

bool RoomFight::isMonsterDead() {
	return monster == nullptr;
}