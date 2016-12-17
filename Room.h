#include <iostream>
#include "Monster.h"
#include "Game.h"
#include "Item.h"
using namespace std;

#ifndef ROOM_H
#define ROOM_H

class Room
{
private:
    string description = "";
    string label = "";
    bool openedDoor[4] = {
        false,
        false,
        false,
        false
    };
    
public:
    Room();
    ~Room();
    
    Game* g = new Game();
    
    virtual void addMonster(Monster* monster){};
    virtual void addItem(Item* item){};
    
    void setDescription(string description){
        this->description = description;
    }
    
    string getDescription(){
        return this->description;
    }
    
    void setStatusDoor(string dir, bool status = false){
        if(dir == "top"){
            openedDoor[0] = status;
        }else if(dir == "right"){
            openedDoor[1] = status;
        }else if(dir == "bottom"){
            openedDoor[2] = status;
        }else if(dir == "left"){
            openedDoor[3] = status;
        }
    }
    
    bool getStatusDoor(string dir){
        if(dir == "top"){
            return openedDoor[0];
        }else if(dir == "right"){
            return openedDoor[1];
        }else if(dir == "bottom"){
            return openedDoor[2];
        }else if(dir == "left"){
            return openedDoor[3];
        }
    }
    
    void setLabel(string label){
        this->label = label;
    }
    
    string getLabel(){
        return label;
    }
    
    virtual string waitForAction(bool info = true){
        if(info)
            cout << endl << "0: Prectes info" << endl;
        
        int n = -1;
        while(true){
            n = g->readInput();
            
            if(n == 0){
                return description + "\n";
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
};

#endif // ROOM_H
