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

    // Deck deck;
    // vector<Winner> winTurn;
    // vector<string> gameStr;    

public:
    // Game() {}
    Game(Player &player_1, Player &player_2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    //
    // void initionalDeck(vector<Card>& deck);
    // void shuffle(vector<Card>& deck);
    Winner check_win(const Card& card_p1, const Card& card_p2);
    bool deck_over() const;
    



    //
    // Winner winner_single_turn(const Card& left, const Card& right);
    // // void add_winner(Winner winner);
    
    // int num_of_draw();
    // void print_one_turn(int index);
};

