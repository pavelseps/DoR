#include <iostream>
#include "Room.h"
#include "Monster.h"
using namespace std;

#ifndef ROOMFIGHT_H
#define ROOMFIGHT_H

class RoomFight : public Room
{
private:
    Monster* monster;
    
public:
    RoomFight();
    ~RoomFight();

    string waitForAction(bool info = true){
        if(info)
        cout << endl << "0: Zautoc" << endl;
        
        int n = -1;
        while(true){
            n = g->readInput();
            
            if(n == 0){
                if(monster != NULL){
                    string monsterName = monster->getMonsterName();
                    monster = NULL;
                    return "Pozazil jsi monstrum "+monsterName+". Gratuluji!\n";   
                }else{
                    return "Uz jsi monstrum porazil.";
                }
            }else if (n == 8){
                return "top";
            }else if (n == 4){
                return "left";
            }else if (n == 6){
                return "right";
            }else if (n == 5){
                return "bottom";
            }
        }
    }
    
    void addMonster(Monster* monster){
        this->monster = monster;
    }
};

#endif // ROOMFIGHT_H
