#include "ItemWeapon.h"


ItemWeapon::ItemWeapon()
{
}


ItemWeapon::~ItemWeapon()
{
}

void ItemWeapon::setDmg(int from, int to) {
	dmg[0] = from;
	dmg[1] = to;
}

void ItemWeapon::useItem() {

}