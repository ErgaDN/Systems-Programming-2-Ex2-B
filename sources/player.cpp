#include "player.hpp"
#include <string>
using namespace std;

Player::Player(string name)
{
    this->name = name;
    this->cards_taken = 0;
    this->playing = false;
}

int Player::stacksize()
{
    return cardsInDeck.size();
}

int Player::cardesTaken()
{
    return cards_taken;
}

///////
void Player::add_card(Card card)
{
    cardsInDeck.push_back(card);
}

bool Player::is_empty() const
{
    return cardsInDeck.empty();
}

int Player::cards_in_deck()
{
    return cardsInDeck.size;
}

void Player::add_points(int points)
{
    for (int i = 0; i < points; i++)
    {
        this->cards_taken++;
    }
}

Card Player::pop_back_card()
{
    Card card = cardsInDeck.back();
    this->cardsTaken_vec.push_back(card);
    cardsInDeck.pop_back();
    return card;
}

void Player::pop_hidden_card()
{
    this->cardsInDeck.pop_back();
}

bool Player::get_playing() const
{
    return this->playing;
}

void Player::set_playing(bool flag)
{
    this->playing = flag;
}

string Player::get_name()
{
    return this->name;
}

vector<Card> &Player::get_cardsTaken_vec()
{
    return this->cardsTaken_vec;
}