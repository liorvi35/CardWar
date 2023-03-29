/**
 * this file contains the implementation for game object functions
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 29.03.2023
*/

#include <iostream>
#include <string>
#include "game.hpp"
#include "player.hpp"
#include <stdexcept>

using namespace std;

namespace ariel
{
    // ctor
    Game::Game(Player &player1, Player &player2) : _player1(player1), _player2(player2)
    {
        if(player1.getIfPlaying() || player2.getIfPlaying())
        {
            throw invalid_argument("One of players already playing the game!!!");
        }
        else if(player1.getPlayerName() == "" || player2.getPlayerName() == "")
        {
            throw invalid_argument("One of players has no name!!!");
        }
        else if(&player1 == &player2)
        {
            throw invalid_argument("Both players are the same player!!!");
        }
        else
        {
            this->_player1 = player1;
            this->_player1.setIfPlaying(true);

            this->_player2 = player2;       
            this->_player2.setIfPlaying(true);
        }
    }

    // play one move in game
    void Game::playTurn() {}

    // print last turn of game
    void Game::printLastTurn() {}

    // play all game
    void Game::playAll() {}

    // print's the winner
    void Game::printWiner() {}

    // print's log of full game
    void Game::printLog() {}

    // print's game statistics
    void Game::printStats() {}
}
