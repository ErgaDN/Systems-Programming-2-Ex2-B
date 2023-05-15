#include "card.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;
using namespace ariel;

Card::Card(Suit suit, int valInt)
{
    string valStr[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    if (valInt < 1 || valInt > 13)
    {
        throw logic_error("Invalid entry");
    }
    this->suit = suit;
    this->valInt = valInt;
    this->valStr = valStr[valInt - 1];
}

string Card::getSuit() const
{
    switch (this->suit)
    {
    case HEARTS:
        return "Hearts";
    case SPADES:
        return "Spades";
    case CLUBS:
        return "Clubs";
    case DIAMONDS:
        return "Diamonds";
    }
}

string Card::getValStr() const
{
    return this->valStr;
}

int Card::getValInt() const
{
    return this->valInt;
}

string Card::cardString() const
{
    return getValStr() + " of " + getSuit() + ". ";
}

Deck::Deck()
{
    for (int i = 1; i < 14; i++)
    {
        deck.push_back(Card(HEARTS, i));
        deck.push_back(Card(CLUBS, i));
        deck.push_back(Card(SPADES, i));
        deck.push_back(Card(DIAMONDS, i));
    }
}
