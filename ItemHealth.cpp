#include "ItemHealth.h"


ItemHealth::ItemHealth()
{
}


ItemHealth::~ItemHealth()
{
}

void ItemHealth::setHealthChange(int change) {
	healthChange = change;
}

int ItemHealth::getHealthChange() {
	return healthChange;
}