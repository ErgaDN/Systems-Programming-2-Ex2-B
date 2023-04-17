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
    // TWO,
    // THREE,
    // FOUR,
    // FIVE,
    // SIX,
    // SEVEN,
    // EIGHT,
    // NINE,
    // TEN,
    JACK = 11,
    QUEEN = 12,
    KING = 13
};

class Card
{
private:
    Suit suit;
    string value;
    int num;

public:
    Card(Suit suit, int num) {
        string valStr[] = {"Ace","2","3","4","5","6","7","8","9" ,"10","Jack","Queen","King"};
        if (num < 1 || num > 13)
        {
            throw logic_error("Invalid entry");
        }
        this->suit = suit;
        this->num = num;
        this->value = valStr[num-1];
    }
    Suit getSuit() const
    {
        return this->suit;
    }
    Value getValue () const
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
