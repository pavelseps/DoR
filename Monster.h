#include <iostream>
using namespace std;

#ifndef MONSTER_H
#define MONSTER_H

class Monster
{
private:
    string monsterName = "";
public:
    Monster();
    ~Monster();
    
	void setMonsterName(string name);
    
	string getMonsterName();

};

#endif // MONSTER_H
