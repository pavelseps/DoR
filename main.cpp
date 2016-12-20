#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Map.h"
#include "Game.h"

using namespace std;

/**
 * @brief Dungeon of Rudix
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char **argv)
{

    /*cout << "*==================* *====================================**===========================*" << endl;
    cout << "*                  * *                                    **                           *" << endl;
    cout << "*    0: aaaa       * *  Nasel jsi pokad                   **  Zivoty: 20               *" << endl;
    cout << "*    1: bbb        * *  Co snim chces udelat?             **  Utok: 10-12              *" << endl;
    cout << "*    2: ccccc      * *                                    **  Zbran: Velky mec         *" << endl;
    cout << "*                  * *                                    **                           *" << endl;
    cout << "*==================* *====================================**===========================*" << endl;
    cout << "*=========================================================**===========================*" << endl;
    cout << "*                                                         **                           *" << endl;
    cout << "*   ________     ________                                 ** Inventar                  *" << endl;
    cout << "*  |        |___|        |                                **                           *" << endl;
    cout << "*  |   PL    ___         |                                **   Lektvar na zivoty       *" << endl;
    cout << "*  |________|   |__    __|                                **   Klic                    *" << endl;
    cout << "*                  |  |                                   **   Svice                   *" << endl;
    cout << "*                __|  |__                                 **   Kamen                   *" << endl;
    cout << "*               |        |                                **                           *" << endl;
    cout << "*               |        |                                **                           *" << endl;
    cout << "*               |________|                                **                           *" << endl;
    cout << "*                                                         **                           *" << endl;
    cout << "*=========================================================**===========================*" << endl;*/
   
    Game* g = new Game();
    
    g->startGame();
    
	return 0;
}
