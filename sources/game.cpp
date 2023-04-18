#include "game.hpp"
#include "player.hpp"
#include "iostream"
#include "stdio.h"
using namespace std;

Game::Game(Player &p1, Player &p2) : player_1(p1), player_2(p2)
{
    if (p1.get_inGame() || p2.get_inGame())
    {
        throw runtime_error("Player in enother game");
    }
    p1.set_inGame(true);
    p2.set_inGame(true);

    Deck deck;
    deck.shuffle();
    while (!deck.is_empty())
    {
        p1.add_card(deck.deal());
        p2.add_card(deck.deal());
    }

    running = true;
    rounds = 0;
    drawCount = 0;
}

void Game::playTurn()
{
    if (!running)
    {
        throw logic_error("Game not running");
    }
    if (rounds > 26)
    {
        throw logic_error("Too many turns");
    }
    if (&player_1 == &player_2)
    {
        throw invalid_argument("Only one player");
    }

    int points = 0;
    int drawForTurn = 0;
    rounds++;
    lastTurn = "";
    while (running) 
    {
        Card card_p1 = player_1.back_card();
        Card card_p2 = player_2.back_card();
        player_1.pop_card();
        player_2.pop_card();
        
        points++;
        lastTurn += player_1.get_name() + " played " + card_p1.cardString() + player_2.get_name() + " played " + card_p2.cardString();
        Winner state = check_win(card_p1, card_p2);
        
        if (state == DRAW)
        {
            lastTurn += "Draw. ";
            drawForTurn++;
            if (deck_over())
            {
                player_1.add_points(1);
                player_2.add_points(1);
                running = false;
                gameDoc += lastTurn;
                break;
            }
            player_1.throw_card();
            player_2.throw_card();
            points++;
            running = !deck_over();
        }
        else if (state == LEFT_P)
        {
            lastTurn += player_1.get_name() + " wins. \n";
            player_1.add_points(2*points);
            break;
        }
        else if (state == RIGHT_P)
        {
            lastTurn += player_2.get_name() + " wins. \n";
            player_2.add_points(2*points);
            break;
        }   
    }
    running = !deck_over();
    gameDoc += lastTurn;
    drawCount += drawForTurn;
}

Winner Game::check_win(const Card& card_p1, const Card& card_p2)
{
    if (card_p1.getValInt() > card_p2.getValInt())
    {
        return LEFT_P;
    }
    else if (card_p1.getValInt() < card_p2.getValInt())
    {
        return RIGHT_P;
    }
    else
    {
        return DRAW;
    }
}

bool Game::deck_over() const
{
    if (player_1.deck_empty() || player_2.deck_empty())
    {
        player_1.set_inGame(false);
        player_2.set_inGame(false);
        return true;
    }
    return false;
}

void Game::playAll()
{
    while (running)
    {
        playTurn();
    }
}

void Game::printWiner()
{
    if (player_1.get_inGame() || player_2.get_inGame())
    {
        return;
    }
    if (player_1.cardesTaken() > player_2.cardesTaken())
    {
        cout << "Winner: " + player_1.get_name()<< endl;
    }
    else if (player_1.cardesTaken() < player_2.cardesTaken())
    {
        cout << "Winner: " + player_2.get_name() << endl;
    }
    else
    {
        cout << "Draw!" << endl;
    }
}

void Game::printLastTurn()
{
    cout << lastTurn << endl;
}

void Game::printLog()
{
    cout << gameDoc << endl;
}

void Game::printStats()
{
    cout << "Player " << player_1.get_name() << " status:" << endl;
    cout << "Cards won: " << player_1.cardesTaken() << endl;
    cout << "Cards left: " << player_1.stacksize() << endl;
    cout << "Win rate: " << (double)(player_1.cardesTaken() / rounds * 100) << "%" << endl << endl;

    cout << "Player " << player_2.get_name() << " status:" << endl;
    cout << "Cards won: " << player_2.cardesTaken() << endl;
    cout << "Cards left: " << player_2.stacksize() << endl;
    cout << "Win rate: " << (double)(player_2.cardesTaken() / rounds * 100) << "%" << endl << endl;
}

