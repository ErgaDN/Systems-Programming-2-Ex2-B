#pragma once
#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
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
enum Value
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

class Card
{
private:
    Suit suit;
    Value value;

public:
    Card(Value v, Suit s) : value(v), suit(s) {}
    int getSuit()
    {
        return this->suit;
    }
    int getValue ()
    {
        return this->value;
    }
};

class Deck
{
private:
    vector<Card> cards;

public:
    Deck()
    {
        for (int suit = HEARTS; suit <= DIAMONDS; suit++)
        {
            for (int value = ACE; value <= KING; value++)
            {
                cards.push_back(Card(static_cast<Value>(value), static_cast<Suit>(suit)));
            }
        }
    }
    void shuffle()
    {
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(cards.begin(), cards.end());
    }

    Card deal()
    {
        Card top_card = cards.back();
        cards.pop_back();
        return top_card;
    }
    
    bool is_empty() const
    {
        return cards.empty();
    }
};
