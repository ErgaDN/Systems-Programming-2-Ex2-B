#include "player.hpp"
#include <string>
using namespace std;

Player::Player(string name)
{
    this->name = name;
}

int Player::stacksize()
{
    return cards.size();
}

int Player::cardesTaken()
{
    return cards_taken;
}

///////
void Player::add_card(Card card)
{
    cards.push_back(card);
}

bool Player::is_empty() const
{
    return cards.empty();
}

int Player::cards_in_deck()
{
    return cards.size;
}

void Player::win()
{
    this->cards_taken++;
}

Card Player::pop_back_card()
{
    Card card = cards.back();
    cards.pop_back();
    return card;
}