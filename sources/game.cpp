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

Game::Game(Player &p1, Player &p2) : p1(p1), p2(p2)
{
    try
    {
        if (p1.get_playing() || p2.get_playing())
        {
            throw runtime_error("Player in enother game");
        }
        p1.set_playing(true);
        p2.set_playing(true);
    }
    catch (runtime_error &e)
    {
    }

    Deck deck;
    deck.shuffle();
    while (!deck.is_empty())
    {
        p1.add_card(deck.deal());
        p2.add_card(deck.deal());
    }
    this->gameRunning = true;
    rounds = 0;
    drawCount = 0;
}

void Game::playTurn()
{
    this->gameRunning = enough_cards(p1, p2);
    int points = 0;
    while (gameRunning)
    {
        Winner state = winner_single_turn(p1.pop_back_card(), p2.pop_back_card());
        this->winTurn.push_back(state);
        points++;
        /*
        I need to check if the players have enough cards in the deck
        */
        if (state == LEFT_P)
        {
            p1.add_points(2 * points);
            break;
        }
        else if (state == RIGHT_P)
        {
            p2.add_points(2 * points);
            break;
        }
        else if (state == DRAW)
        {
            this->p1.pop_hidden_card();
            this->p2.pop_hidden_card();
            drawCount++;
            points++;
        }
        this->gameRunning = enough_cards(p1, p2);
    }
    rounds++;
}

bool Game::enough_cards(const Player &p1, const Player &p2)
{
    if (p1.is_empty() || p2.is_empty())
    {
        return false;
    }
    return true;
}

Winner Game::winner_single_turn(Card left, Card right)
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
            return RIGHT_P;
        }
        else
        {
            return LEFT_P;
        }
    }
    // Ace card for the right player
    if (right.getValue() == ACE)
    {
        if (left.getValue() == TWO)
        {
            return LEFT_P;
        }
        else
        {
            return RIGHT_P;
        }
    }
    // Two different cards, not an ace
    if (left.getValue() > right.getValue())
    {
        return LEFT_P;
    }
    else
    {
        return RIGHT_P;
    }
}

// void Game::add_winner(Winner winner)
// {
//     this->winTurn.push_back(winner);
// }

void Game::printLastTurn()
{
    int numOfDraws = num_of_draw();
    int index = winTurn.size() - 1 - numOfDraws;
    while (numOfDraws > 0)
    {
        print_one_turn(index);
        index++;
        numOfDraws--;
        cout << "DRAW. "
    }
    print_one_turn(winTurn.size() - 1);
    if (this->winTurn.back() == LEFT_P)
    {
        cout << this->p1.get_name() << " wins. " << endl;
    }
    else if (this->winTurn.back() == RIGHT_P)
    {
        cout << this->p2.get_name() << " wins. " << endl;
    }
}

void Game::print_one_turn(int index)
{
    cout << this->p1.get_name() << ": "
         << this->p1.get_cardsTaken_vec()[index].getValue() << "of"
         << this->p1.get_cardsTaken_vec()[index].getValue()
         << ". "
         << this->p1.get_name() << ": "
         << this->p1.get_cardsTaken_vec()[index].getValue() << "of"
         << this->p1.get_cardsTaken_vec()[index].getValue()
         << ". ";
}

int Game::num_of_draw()
{
    int ans = 0;
    int size = winTurn.size();
    Winner tempWin = winTurn[size];
    if (size <= 1)
    {
        return 0;
    }
    else
    {
        size--;
        while (size >= 0 && winTurn[size] == DRAW)
        {
            ans++;
            size--;
        }
        return ans;
    }
}

void Game::playAll()
{
    while (gameRunning)
    {
        playTurn();
    }
}

void Game::printWiner()
{
    if (winTurn.size() != 0 && this->p1.cards_in_deck() == 0 && this->p2.cards_in_deck() == 0)
    {
        if (this->p1.cardesTaken() > this->p2.cardesTaken())
        {
            cout << p1.get_name() << endl;
        }
        else if (this->p2.cardesTaken() > this->p1.cardesTaken())
        {
            cout << p2.get_name() << endl;
        }
        else {
            cout << "Draw." << endl;
        }
    }
}

void Game::printLog()
{
    if (winTurn.size() == 0)
    {
        return;
    }
    int index = 0;
    while (index < winTurn.size())
    {
        print_one_turn(index);
        if (this->winTurn[index] == LEFT_P)
        {
            cout << this->p1.get_name() << " wins. " << endl;
        }
        else if (this->winTurn[index] == RIGHT_P)
        {
            cout << this->p2.get_name() << " wins. " << endl;
        }
        else if (this->winTurn[index] == DRAW)
        {
            cout << "DRAW. ";
        }
    }
}

void Game::printStats()
{
}