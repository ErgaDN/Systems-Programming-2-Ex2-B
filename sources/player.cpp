#include "player.hpp"
#include <string>
using namespace std;
using namespace ariel;

Player::Player(string name)
{
    this->name = name;
    this->points = 0;
    this->inGame = false;
}

int Player::stacksize() const
{
    return (int)cardsInDeck.size();
}

int Player::cardesTaken() const
{
    return points;
}

string Player::get_name() const
{
    return this->name;
}

bool Player::get_inGame() const
{
    return this->inGame;
}

void Player::set_inGame(bool flag)
{
    this->inGame = flag;
}

void Player::add_card(Card card)
{
    cardsInDeck.push_back(card);
}

int Player::cardsInDeck_size() const
{
    return (int)cardsInDeck.size();
}

bool Player::deck_empty() const
{
    return cardsInDeck.empty();
}

const Card &Player::back_card() const
{
    return this->cardsInDeck.back();
}

void Player::pop_card()
{
    cardsInDeck.pop_back();
}

void Player::add_points(int num)
{
    this->points += num;
}

void Player::throw_card()
{
    this->cardsInDeck.pop_back();
}
