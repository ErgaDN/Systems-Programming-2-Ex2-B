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
    vector<Card> cardsInDeck;
    vector<Card> cardsTaken_vec;
    int cards_taken;
    int winCount;
    bool playing;

public:
    Player(string name);
    int stacksize();
    int cardesTaken();

    ////
    void add_card(Card card);
    bool is_empty() const; // returns 1 (true) if cardsInDeck is empty
    int cards_in_deck();
    void add_points(int points);
    Card pop_back_card();
    void pop_hidden_card();
    bool get_playing() const;
    void set_playing(bool flag);
    string get_name() const;
    vector<Card>& get_cardsTaken_vec();
    int get_winCount() const;

};