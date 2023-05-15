#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

int main()
{
    // Create two players with their names
    Player p1("Tom");
    Player p2("Jerry");
    
    Game game(p1, p2);
    cout << "Game: " << p1.get_name() << " VS " << p2.get_name() << endl << endl; 

    for (int i = 0; i < 3; i++)
    {
        game.playTurn();
        game.printLastTurn();
    }                                
                                      
    cout << p1.get_name() << "_stacksize = " << p1.stacksize() << endl;   
    cout << p2.get_name() << "_stacksize = " << p2.stacksize() << endl;

    cout << endl << "Game documentation:" << endl;
    game.playAll();                                   
    game.printLog();   
                   
    game.printStats();
    game.printWiner();              
}