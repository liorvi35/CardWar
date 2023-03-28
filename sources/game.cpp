/**
 * this file contains the implementation for game object functions
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 27.03.2023
*/

#include <iostream>
#include <string>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    // defult-ctor
    Game::Game(Player &o1, Player &o2) : _plr1(o1), _plr2(o2), _move(FIRST_PLAYER)
    {
        this->_plr1 = o1;
        this->_plr1 = o2;
        this->_move = FIRST_PLAYER;
    }

    // defult-destructor
    // Game::~Game()
    // { 
    //     delete &_plr1;
    //     delete &_plr2;
    // }

    void Game::playTurn() {}

    void Game::printLastTurn() {}

    void Game::playAll() {}

    void Game::printWiner() {}

    void Game::printLog() {}

    void Game::printStats() {}
};
