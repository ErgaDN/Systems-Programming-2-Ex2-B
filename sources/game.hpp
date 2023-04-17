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
    Player p1;
    Player p2;
    Deck deck;
    vector<Winner> winTurn;
    bool gameRunning;
    int rounds;
    int drawCount;

public:
    // Game() {}
    Game(Player &p1, Player &p2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    //
    Winner winner_single_turn(const Card& left, const Card& right);
    // void add_winner(Winner winner);
    bool enough_cards(const Player& p1, const Player& p2);
    int num_of_draw();
    void print_one_turn(int index);
};