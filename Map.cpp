#include "Map.h"

Map::Map()
{
	File* file = new File();
	map = file->getMap();
	int* actualPosFile = file->getStartPos();
	setActualPlaPos(actualPosFile[0], actualPosFile[1]);
	sizeX = file->getMapSizeX();
	sizeY = file->getMapSizeY();

	/*for (int x = 0; x<sizeX; x++) {
		for (int y = 0; y<sizeY; y++) {
			map[x][y] = NULL;
		}
	}

	Item* i1 = new ItemHealth();
	Item* i2 = new ItemWeapon();
	i1->setName("Lecivy lektvar");
	i1->setHealthChange(4);
	i2->setName("Mec");
	i2->setDmg(4, 6);

	Monster* m1 = new Monster(8);
	Monster* m2 = new Monster(8);
	m1->setMonsterName("Krecopazout");
	m2->setMonsterName("Alfons");
	ItemWeapon* i3 = new ItemWeapon();
	i3->setName("Palice");
	i3->setDmg(6, 12);
	m1->setWeapon(i3);
	ItemWeapon* i4 = new ItemWeapon();
	i4->setName("Nuz");
	i4->setDmg(3, 5);
	m2->setWeapon(i4);


	map[0][0] = new Room();
	map[0][1] = new RoomLoot();

	map[1][1] = new RoomFight();
	map[1][2] = new RoomLoot();

	map[2][1] = new RoomFight();
	map[2][2] = new Room();

	setActualPlaPos(0, 0);

	map[0][0]->setLabel("STA");
	map[0][0]->setDescription("Jsi na startu");
	map[0][0]->setStatusDoor("right", true);
	map[0][0]->setInitText("0 0");

	map[0][1]->setStatusDoor("left", true);
	map[0][1]->setStatusDoor("bottom", true);
	map[0][1]->setDescription("Kuchyne");
	map[0][1]->addItem(i1);
	map[0][1]->addItem(i2);
	map[0][1]->setInitText("0 1");

	map[1][1]->setStatusDoor("top", true);
	map[1][1]->setStatusDoor("bottom", true);
	map[1][1]->setStatusDoor("right", true);
	map[1][1]->setDescription("chodba");
	map[1][1]->addMonster(m1);
	map[1][1]->setInitText("1 1");

	map[1][2]->setStatusDoor("left", true);
	map[1][2]->setInitText("1 2");

	map[2][1]->setStatusDoor("top", true);
	map[2][1]->setStatusDoor("right", true);
	map[2][1]->addMonster(m2);
	map[2][1]->setInitText("2 1");

	map[2][2]->setDescription("Konec hry");
	map[2][2]->setStatusDoor("left", true);
	map[2][2]->setInitText("2 2");
	map[2][2]->setLabel("END");*/
}

Map::~Map()
{
	for (int x = 0; x<sizeX; x++) {
		for (int y = 0; y<sizeY; y++) {
			delete map[x][y];
			map[x][y] = nullptr;
		}
	}
	delete map;
}

void Map::setActualPlaPos(int x, int y) {
	plaActualPos[0] = x;
	plaActualPos[1] = y;
}

Room* Map::moveActualPlaPos(string dir) {
	if (dir == "top") {
		setActualPlaPos(plaActualPos[0] - 1, plaActualPos[1]);
	}
	else if (dir == "right") {
		setActualPlaPos(plaActualPos[0], plaActualPos[1] + 1);
	}
	else if (dir == "bottom") {
		setActualPlaPos(plaActualPos[0] + 1, plaActualPos[1]);
	}
	else if (dir == "left") {
		setActualPlaPos(plaActualPos[0], plaActualPos[1] - 1);
	}
	return getActualRoom();
}

Room* Map::getActualRoom() {
	return getRoom(plaActualPos[0], plaActualPos[1]);
}

Room* Map::getRoom(int x, int y) {
	return map[x][y];
}

void Map::printMap() {
	string s1 = "";
	string s2 = "";
	string s3 = "";
	string s4 = "";
	string s5 = "";

	string top = "___";
	string right1 = "  ";
	string right2 = "|  ";
	string bottom1 = "___";
	string bottom2 = "   ";
	string left1 = " ";
	string left2 = " |";
	string label = "   ";

	for (int x = 0; x<sizeX; x++) {
		for (int y = 0; y<sizeY; y++) {

			if (map[x][y] != nullptr) {
				if (x != 0 && map[x][y]->getStatusDoor("top")) {
					top = "| |";
				}

				if (y != 0 && map[x][y]->getStatusDoor("left")) {
					left1 = "_";
					left2 = "_ ";
				}

				if (x + 1 != sizeX && map[x][y]->getStatusDoor("bottom")) {
					bottom1 = "   ";
					bottom2 = "| |";
				}

				if (y + 1 != sizeY && map[x][y]->getStatusDoor("right")) {
					right1 = "__";
					right2 = " __";
				}

				if (map[x][y]->getLabel() != "") {
					label = map[x][y]->getLabel();
				}

				if (x == plaActualPos[0] && y == plaActualPos[1]) {
					label = "PLA";
				}

				s1.append("  __").append(top).append("__   ");
				s2.append(left1).append("|       |").append(right1);
				s3.append(left2).append("  ").append(label).append("  ").append(right2);
				s4.append(" |__").append(bottom1).append("__|  ");
				s5.append("    ").append(bottom2).append("     ");
			}
			else {
				s1.append("            ");
				s2.append("            ");
				s3.append("            ");
				s4.append("            ");
				s5.append("            ");
			}

			top = "___";
			right1 = "  ";
			right2 = "|  ";
			bottom1 = "___";
			bottom2 = "   ";
			left1 = " ";
			left2 = " |";
			label = "   ";
		}

		s1.append("\n");
		s2.append("\n");
		s3.append("\n");
		s4.append("\n");
		s5.append("\n");
		cout << s1 << s2 << s3 << s4 << s5;
		s1 = "";
		s2 = "";
		s3 = "";
		s4 = "";
		s5 = "";
	}
}