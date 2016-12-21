#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::setHealth(int health) {
	this->health = health;
}

int Player::getHealth() {
	return health;
}

void Player::setDamage(int from, int to) {
	dmg[0] = from;
	dmg[1] = to;
}
int* Player::getDamage() {
	return dmg;
}
void Player::addItemToInventory(Item* item) {
	inventory.push_back(item);
}

string Player::getInvetoryList() {
	string itemsNameS = "";
	if (inventory.size() != 0) {
		itemsNameS.append(inventory[0]->getName());
		for (int i = 1; i<inventory.size(); i++) {
			itemsNameS.append(", ").append(inventory[i]->getName());
		}
		itemsNameS.append(".");
		return itemsNameS;
	}
	else {
		return "Prazdny inventar";
	}
}