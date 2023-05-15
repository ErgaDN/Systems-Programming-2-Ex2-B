#pragma once
#include <string>
#include <vector>
#include "card.hpp"

namespace ariel
{
    class Player
    {
    private:
        std::string name;
        vector<Card> cardsInDeck;
        int points;
        bool inGame;

    public:
        Player(string name);
        int stacksize() const;
        int cardesTaken() const;

        std::string get_name() const;
        bool get_inGame() const;
        void set_inGame(bool flag);
        void add_card(Card card);
        int cardsInDeck_size() const;
        bool deck_empty() const;
        void pop_card();
        void add_points(int points);
        void throw_card();
        const Card &back_card() const;
    };
}
