#include <conio.h>

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    
public:
    Game();
    ~Game();
    
    int readInput(){
        int n = -1;
        n = _getch();
        n -= 48;
        return n;
    }
};

#endif // GAME_H
