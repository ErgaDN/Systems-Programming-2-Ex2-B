#include "game.hpp"
#include "player.hpp"
#include "iostream"
#include "stdio.h"

using namespace std;

// Game::Game(Player p1, Player p2)
// {
//     this->p1 = p1;
//     this->p2 = p2;
//     Deck cards;
//     cards.shuffle();

//     std::vector<Card> player1(deck.cards.begin(), deck.cards.begin() + deck.cards.size() / 2);
//     std::vector<Card> player2(deck.cards.begin() + deck.cards.size() / 2, deck.cards.end());
// }

Game::Game(Player p1, Player p2) : p1(p1), p2(p2)
{
    deck = Deck();
    deck.shuffle();
    while (!deck.is_empty())
    {
        p1.add_card(deck.deal());
        p2.add_card(deck.deal());
    }
}

void Game::playTurn()
{
    Card p1_card = p1.pop_back_card();
    Card p2_card = p2.pop_back_card();
}

Winner Game::winner(Card left, Card right)
{
    // A draw between the players
    if (left.getValue() == right.getValue())
    {
        return DRAW;
    }
    // Ace card for the left player
    if (left.getValue() == ACE)
    {
        if (right.getValue() == TWO)
        {
            return RIGHT;
        }
        else
        {
            return LEFT;
        }
    }
    // Ace card for the right player
    if (right.getValue() == ACE)
    {
        if (left.getValue() == TWO)
        {
            return LEFT;
        }
        else
        {
            return RIGHT;
        }
    }
    // Two different cards, not an ace
    if (left.getValue() > right.getValue())
    {
        return LEFT;
    }
    else
    {
        return RIGHT;
    }
}

void Game::printLastTurn()
{
}

void Game::playAll()
{
}

void Game::printWiner()
{
}

void Game::printLog()
{
}

void Game::printStats()
{
}