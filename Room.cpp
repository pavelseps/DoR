#include "Room.h"

Room::Room()
{
	legend = "\n\t0: Info\n\t2: Pouzij lektvar\n\t3: Zmen zbran\n\n";
}

Room::~Room()
{
}

void Room::setDescription(string description) {
	this->description = description;
}

string Room::getLegend() {
	return legend;
}

void Room::setStatusDoor(string dir, bool status) {
	if (dir == "top") {
		openedDoor[0] = status;
	}
	else if (dir == "right") {
		openedDoor[1] = status;
	}
	else if (dir == "bottom") {
		openedDoor[2] = status;
	}
	else if (dir == "left") {
		openedDoor[3] = status;
	}
}

bool Room::getStatusDoor(string dir) {
	if (dir == "top") {
		return openedDoor[0];
	}
	else if (dir == "right") {
		return openedDoor[1];
	}
	else if (dir == "bottom") {
		return openedDoor[2];
	}
	else if (dir == "left") {
		return openedDoor[3];
	}
	return false;
}

void Room::setLabel(string label) {
	this->label = label;
}

string Room::getLabel() {
	return label;
}

string Room::waitForAction(Player* player) {

	int n = -1;
	while (true) {
		n = readInput->read();
		if (n == 0) {
			return description + "\n";
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

void Room::setInitText(string text) {
	this->initText = text;
}

string Room::getInitText() {
	return initText;
}