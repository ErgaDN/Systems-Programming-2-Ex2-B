#pragma once
#include <iostream>
#include <string>
#include "stdio.h"
#include <vector>
#include "card.hpp"

namespace ariel
{
}
using namespace ariel;
using namespace std;

class Player
{
    string name;
    vector<Card> cards;
    int cards_taken;

public:
    Player() {}
    Player(string name)
    {
        this->name = name;
        this->cards_taken = 0;
    }
    
    int stacksize();
    int cardesTaken();

    ////
    void add_card(Card card);
    bool is_empty() const;
    int cards_in_deck();
    void win();
    Card Player::pop_back_card();
};