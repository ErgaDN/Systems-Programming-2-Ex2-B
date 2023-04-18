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
    Deck()
    {
        for (int i = 1; i < 14; i++)
        {
            deck.push_back(Card(HEARTS, i));
            deck.push_back(Card(CLUBS, i));
            deck.push_back(Card(SPADES, i));
            deck.push_back(Card(DIAMONDS, i));
        }
    }

    void shuffle()
    {
        random_device rd;
        mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
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

    // void printDeck()
    // {
    //     for (int i = 0 ; i < deck.size() ; i++)
    //     {
    //         // Card card = deck[i];
    //         Card card = this->deck[static_cast<vector<Card>::size_type>(i)];
    //         card.cardString();
    //         cout << endl;

    //     }
    // }
};
