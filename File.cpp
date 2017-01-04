#include "File.h"


File::File()
{
}

File::~File()
{
}

Room*** File::getMap() {
	//Read settings file
	ifstream t("C:\\Users\\Pavel\\prace\\skola\\cpp\\cpp\\DoR\\settings\\map.txt");
	str.assign((istreambuf_iterator<char>(t)),
		istreambuf_iterator<char>());
	
	//Generate map size
	vector<string> mapsize = splitString(str.substr(str.find("MAPSIZE"), str.find('\n')));
	Room*** map = new Room**[stoi(mapsize.at(1))];
	for (int i = 0; i < stoi(mapsize.at(1)); i++) {
		map[i] = new Room*[stoi(mapsize.at(2))];

		for (int y = 0; y < stoi(mapsize.at(2)); y++) {
			map[i][y] = nullptr;
		}
	}


	//Generate room
	vector <string> roomsString = findAllLines(str, "ROOM");
	vector <string> roomString;
	int roomX = 0;
	int roomY = 0;

	for (int i = 0; i < roomsString.size(); i++) {
		roomString = splitString(roomsString.at(i));
		roomX = stoi(roomString.at(1));
		roomY = stoi(roomString.at(2));

		Room* room;
		if (roomString.at(0) == "ROOMFIGHT") {
			room = new RoomFight();
			Monster* monster = new Monster(stoi(roomString.at(11)));
			monster->setMonsterName(roomString.at(10));
			monster->setWeapon(findItem(stoi(roomString.at(12))));
			room->addMonster(monster);
		}
		else if (roomString.at(0) == "ROOMLOOT") {
			room = new RoomLoot();
			vector<string> items;
			items = splitString(roomString.at(10), ",");
			for (int y = 0; y < items.size(); y++) {
				room->addItem(findItem(stoi(items.at(y))));
			}
		}
		else {
			room = new Room();
		}

		room->setDescription(roomString.at(5));
		room->setInitText(roomString.at(4));
		room->setLabel(roomString.at(3));
		room->setStatusDoor("top", stoi(roomString.at(6)));
		room->setStatusDoor("right", stoi(roomString.at(7)));
		room->setStatusDoor("bottom", stoi(roomString.at(8)));
		room->setStatusDoor("left", stoi(roomString.at(9)));

		map[roomX][roomY] = room;
	}
	
	return map;
}

int* File::getStartPos() {
	int returnVal[2];
	vector<string> startpos = splitString(str.substr(str.find("STARTPOS"), str.find('\n')));
	returnVal[0] = stoi(startpos.at(1));
	returnVal[1] = stoi(startpos.at(2));
	return returnVal;
}

vector<string> findAllLines(string str, string sub) {
	vector<size_t> positions;
	vector<string> returnVec;
	size_t pos = str.find(sub, 0);

	while (pos != string::npos)
	{
		positions.push_back(pos);
		pos = str.find(sub, pos + 1);
	}
	for (int i = 0; i < positions.size(); i++) {
		returnVec.push_back(str.substr(positions.at(i), str.substr(positions.at(i)).find("\n")));
	}

	return returnVec;
}

vector<string> splitString(string str, string delimiter) {
	size_t pos = 0;
	string token;
	vector<string> returnVec;

	while ((pos = str.find(delimiter)) != string::npos) {
		token = str.substr(0, pos);
		returnVec.push_back(token);
		str.erase(0, pos + delimiter.length());
	}

	return returnVec;
}


Item* File::findItem(int id) {
	vector <string> itemsString = findAllLines(str, "ITEM;");
	vector <string> itemString;
	Item* items;

	for (int i = 0; i < itemsString.size(); i++) {
		itemString = splitString(itemsString.at(i));
		if (stoi(itemString.at(1)) == id) {
			Item* item;
			if (itemString.at(2) == "ITEMWEAPON") {
				item = new ItemWeapon();
				item->setName(itemString.at(5));
				item->setDmg(stoi(itemString.at(3)), stoi(itemString.at(4)));
			}
			else {
				item = new ItemHealth();
				item->setName(itemString.at(4));
				item->setHealthChange(stoi(itemString.at(3)));
			}
			return item;
		}
	}
}