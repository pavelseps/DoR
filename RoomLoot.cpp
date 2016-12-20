#include "RoomLoot.h"

RoomLoot::RoomLoot()
{
}

RoomLoot::~RoomLoot()
{
}

string RoomLoot::waitForAction(bool info) {
	if (info)
		cout << endl << "0: Prohledej mistnost" << endl;

	int n = -1;
	while (true) {
		n = g->readInput();
		int vectorSize = items.size();
		if (n == 0) {
			if (vectorSize != 0) {
				itemsNameS.append(items[0]->getName());
				for (int i = 1; i<vectorSize; i++) {
					itemsNameS.append(", ").append(items[i]->getName());
				}
				itemsNameS.append(".\n");
				items.clear();
				return itemsNameS;
				return "Neco tu je";
			}
			else {
				return "Nic jsi nenasel..\n";
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

void RoomLoot::addItem(Item* item) {
	items.push_back(item);
}