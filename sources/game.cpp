/**
 * @brief this file contains implementation for game functions; Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @since 14/04/2023
 */

#include <iostream>
#include <string>
#include "game.hpp"
#include "player.hpp"
#include <stdexcept>
#include <random>

using namespace std;

namespace ariel
{
    /**
     * @brief standard constructor, creates an game object with two players
     * @param player1 first player in game
     * @param player2 second player in game
     * @throws invalid_argument in case that one of players already playing game
     */
    Game::Game(Player &player1, Player &player2) : _player1(player1), _player2(player2)
    {
        if(this->_player1.getIfPlaying() || this->_player2.getIfPlaying()) // checking case 
        {
            throw invalid_argument("One of the players already in game!!!");
        }
        else
        {
            this->_player1 = player1; // updating data members and reseting else
            this->_player1.setIfPlaying(true);

            this->_player2 = player2;
            this->_player2.setIfPlaying(true);

            this->_currentLog = "";
            this->_gameLog = "";

            this->_drawRate = 0;

            this->_winRateP1 = 0;
            this->_winRateP2 = 0;

            int i = 0; // updting game cards, adding one of each type
            for(i = 1; i < 14; i++)
            {
                this->_cards.push_back(Card(i, DIAMOND));
                this->_cards.push_back(Card(i, SPADE));
                this->_cards.push_back(Card(i, HEARTH));
                this->_cards.push_back(Card(i, CLUB));
            }

            random_device rd; // randomly shuffeling all cards
            default_random_engine rng(rd());
            shuffle(this->_cards.begin(), this->_cards.end(), rng);

            for(i = 0; i < 26; i++) // giving cards for players
            {
                this->_player1.addCard(this->_cards.back());
                this->_cards.pop_back();

                this->_player2.addCard(this->_cards.back());
                this->_cards.pop_back();
            }
        }
    }

    /**
     * @brief this function is playing one turn in game
     * @throws invalid_argument in case that both players are same player
     */   
    void Game::playTurn()
    {
        if (&_player1 == &_player2) // checking case
        {
            throw invalid_argument("Same player!!!");
        }
        else if (this->_player1.stacksize() == 0 || this->_player2.stacksize() == 0) // both checking if game ended
        {
            exit(0);
        }
        else if (!this->_player1.getIfPlaying() || !this->_player2.getIfPlaying())
        {
            exit(0);
        }
        else
        {
            this->_currentLog = "";

            int take = 2; // numbers of cards that player should take after winning turn
    
            Card p1 = this->_player1.showLastCard(), p2 = this->_player2.showLastCard(); // holding card for each player
            this->_player1.removeCard();
            this->_player2.removeCard();

            // updating current turn's log
            this->_currentLog = this->_player1.getPlayerName() + " played " + p1.to_string() + " " + this->_player2.getPlayerName() + " played " + p2.to_string() + ".";

            while(p1.getValue() == p2.getValue()) // draw case
            {
                this->_gameMove++; // updating moves and current log
                this->_drawRate++;
                this->_currentLog += " Draw. ";

                if (this->_player1.stacksize() <= 1 || this->_player2.stacksize() <= 1) // if one of players stayed with last card
                {
                    this->_player1.setCardsCounter(take / 2);
                    this->_player2.setCardsCounter(take / 2);
                    break;
                }

                this->_player1.removeCard();
                this->_player2.removeCard();

                p1 = this->_player1.showLastCard();
                p2 = this->_player2.showLastCard();

                this->_player1.removeCard();
                this->_player2.removeCard();

                take += 4; // in each war winner gets 4 cards because each sets two, back + top

                // updating log after each draw round
                this->_currentLog += this->_player1.getPlayerName() + " played " + p1.to_string() + " " + this->_player2.getPlayerName() + " played " + p2.to_string() + ".";
            }

            if(p1.getValue() == 1) // case that first player has ace card
            {
                this->_gameMove++;
                if (p2.getValue() == 2) // case that '2' card takes an ace
                {
                    this->_currentLog += " " + this->_player2.getPlayerName() + " wins.";
                    this->_player2.setCardsCounter(take);
                    this->_winRateP2++;
                }
                else
                {
                    this->_currentLog += " " + this->_player1.getPlayerName() + " wins.";
                    this->_player1.setCardsCounter(take);
                    this->_winRateP1++;
                }
            }
            else if (p2.getValue() == 1) // same checks as previous, but for second player
            {
                this->_gameMove++;
                if (p1.getValue() == 2)
                {
                    this->_currentLog += " " + this->_player1.getPlayerName() + " wins.";
                    this->_player1.setCardsCounter(take);
                    this->_winRateP1++;
                }
                else
                {
                    this->_currentLog += " " + this->_player2.getPlayerName() + " wins.";
                    this->_player2.setCardsCounter(take);
                    this->_winRateP2++;
                }
            }
            else // other cases where there are no aces
            {
                this->_gameMove++;
                if (p1.getValue() > p2.getValue())
                {
                    this->_currentLog += " " + this->_player1.getPlayerName() + " wins.";
                    this->_player1.setCardsCounter(take);
                    this->_winRateP1++;
                }
                else if (p1.getValue() < p2.getValue())
                {
                    this->_currentLog += " " + this->_player2.getPlayerName() + " wins.";
                    this->_player2.setCardsCounter(take);
                    this->_winRateP2++;
                }
            }

            if (this->_player1.stacksize() == 0 || this->_player2.stacksize() == 0) // if cards are empty at both players
            {
                this->_player1.setIfPlaying(false);
                this->_player2.setIfPlaying(false);
            }
            
            // updating full game log
            this->_gameLog += this->_currentLog + "\n"; 
        }
    }

    /**
     * @brief standard printer, prints the last turn was made
     */
    void Game::printLastTurn()
    {
        std::cout << this->_currentLog << endl;
    }

    /**
     * @brief this function is playing all game
     */
    void Game::playAll()
    {
        while (this->_player1.stacksize() != 0 && this->_player2.stacksize() != 0) // playing one turn until one of players runs out of cards
        {
            playTurn();
        }
    }

    /**
     * @brief standard printer, prints the winner of the game
     */
    void Game::printWiner()
    {
        if (this->_player1.stacksize() != 0 && this->_player2.stacksize() != 0) // if game sill not ended
        {
            return;
        }

        if (this->_player1.cardesTaken() == this->_player2.cardesTaken()) // if points are equal
        {
            std::cout << "Draw." << endl;
        }
        else if (this->_player1.cardesTaken() > this->_player2.cardesTaken()) // if first player won
        {
            std::cout << this->_player1.getPlayerName() << " wins." << endl;
        }
        else // second player won
        {
            std::cout << this->_player2.getPlayerName() << " wins." << endl;
        }
    }

    /**
     * @brief standard printer, prints the full log of game
     */
    void Game::printLog()
    {
        std::cout << this->_gameLog << endl;
    }

    /**
     * @brief standard printer, prints the statistics of game
     */
    void Game::printStats()
    {
        double winRateP1 = 0, winRateP2 = 0, drawRate = 0;

        winRateP1 = ((this->_winRateP1 * 100) / this->_gameMove); // calculating all precentage (win/draw rates)
        winRateP2 = ((this->_winRateP2 * 100) / this->_gameMove);
        drawRate = ((this->_drawRate * 100) / this->_gameMove);

        // print for first player
        std::cout << "Statistics of - " << this->_player1.getPlayerName() << ":" << endl
                  << "1) Win rate: " << std::to_string(winRateP1) << "%" << endl
                  << "2) Cards won: " << std::to_string(this->_player1.cardesTaken()) << endl;

        // print for second player
        std::cout << "Statistics of - " << this->_player2.getPlayerName() << ":" << endl
                  << "1) Win rate: " << std::to_string(winRateP2) << "%" << endl
                  << "2) Cards won: " << std::to_string(this->_player2.cardesTaken()) << endl;

        // print for draw stats
        std::cout << "Game statistics:" << endl
                  << "1) Draw rate: " << std::to_string(drawRate) << "%" << endl
                  << "2) Draw amounts: " << std::to_string(this->_drawRate) << endl;
    }
}