#include "Player.h"


Player::Player()
{
	Item* startWeapon = new ItemWeapon();
	startWeapon->setName("Klacek");
	startWeapon->setDmg(1, 2);
	weapon = startWeapon;
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

void Player::setWeapon(Item* weapon) {
	this->weapon = weapon;
}
int* Player::getWeaponDamage() {
	return weapon->getDmg();
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

Item* Player::getWeapon() {
	return weapon;
}

bool Player::changeWeapon() {
	for (int i = 0; i<inventory.size(); i++) {
		if (inventory[i]->getDmg() != NULL) {
			inventory.push_back(weapon);
			weapon = inventory[i];
			inventory.erase(inventory.begin() + i);
			return true;
		}
	}
	return false;
}

bool Player::useHealthPotion() {
	for (int i = 0; i<inventory.size(); i++) {
		if (inventory[i]->getHealthChange() != NULL) {
			health = health + inventory[i]->getHealthChange();
			delete inventory[i];
			inventory.erase(inventory.begin() + i);
			return true;
		}
	}
	return false;
}