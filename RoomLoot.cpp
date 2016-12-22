#include "RoomLoot.h"

RoomLoot::RoomLoot()
{
	legend = "\n\t0: Info\n\t1: Prohledej mistnost\n\t2: Pouzij lektvar\n\t3: Zmen zbran\n";
}

RoomLoot::~RoomLoot()
{
}

string RoomLoot::waitForAction(Player* player) {
	int n = -1;
	while (true) {
		n = readInput->read();
		int vectorSize = items.size();

		if (n == 0) {
			return description + "\n";
		}
		else if (n == 1) {
			if (vectorSize != 0) {
				itemsNameS.append(items[0]->getName());
				player->addItemToInventory(items[0]);

				for (int i = 1; i<vectorSize; i++) {
					itemsNameS.append(", ").append(items[i]->getName());
					player->addItemToInventory(items[i]);
				}

				itemsNameS.append(".\n");
				items.clear();
				return itemsNameS;
			}
			else {
				return "Nic jsi nenasel..\n";
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

void RoomLoot::addItem(Item* item) {
	items.push_back(item);
}

string RoomLoot::getLegend() {
	return legend;
}

void RoomLoot::setInitText(string text) {
	this->initText = text;
}

string RoomLoot::getInitText() {
	return initText;
}

void RoomLoot::setDescription(string description) {
	this->description = description;
}