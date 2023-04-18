#pragma once
#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

namespace ariel
{
}
using namespace ariel;

enum Suit
{
    HEARTS,
    CLUBS,
    SPADES,
    DIAMONDS
};

class Card
{
private:
    Suit suit;
    string valStr;
    int valInt;

public:
    Card(Suit suit, int valInt);
    string getSuit() const;
    string getValStr() const;
    int getValInt() const;
    string cardString() const;
    vector<Card> initionalDeck();
    void shuffle(const vector<Card> &deck);
};




class Deck
{
private:
    vector<Card> deck;

public:
    Deck();

    void shuffle()
    {
        random_device rdd;
        mt19937 ggg(rdd());
        std::shuffle(deck.begin(), deck.end(), ggg);
    }

    Card deal()
    {
        Card top_card = deck.back();
        deck.pop_back();
        return top_card;
    }

    bool is_empty() const
    {
        return deck.empty();
    }

};
