#pragma once
#include "iostream"
#include <string>
#include "stdio.h"
#include "player.hpp"

namespace ariel
{
}
using namespace ariel;
using namespace std;

enum Winner
{
    LEFT_P, // Player_1
    RIGHT_P, // Player_2
    DRAW
};

class Game
{
private:
    Player& player_1;
    Player& player_2;

    string lastTurn;
    string gameDoc;
    bool running;
    int rounds;
    int drawCount;

public:
    Game(Player &player_1, Player &player_2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
   
    Winner check_win(const Card& card_p1, const Card& card_p2);
    bool deck_over() const;
};

