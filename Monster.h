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
    
    void setMonsterName(string name){
        monsterName = name;
    }
    
    string getMonsterName(){
        return monsterName;
    }

};

#endif // MONSTER_H
