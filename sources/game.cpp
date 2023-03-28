/**
 * this file contains the implementation for game object functions
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 28.03.2023
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
    Game::Game()
    {
        this->_plr1 = Player("User1");
        this->_plr2 = Player("User2");
        this->_move = FIRST_PLAYER;
    }

    // standard-ctor
    Game::Game(Player other1, Player other2)
    {
        this->_plr1 = other1;
        this->_plr1 = other2;
        this->_move = FIRST_PLAYER;
    }

    //
    Game::Game(const Game &other)
    {
        this->_plr1 = other._plr1;
        this->_plr1 = other._plr1;
        this->_move = other._move;
    }
    

    //
    Game::Game(Game &&other) noexcept:
        _plr1(std::move(other._plr1)),
        _plr2(std::move(other._plr2)),
        _move(std::move(other._move)) {}

    void Game::playTurn() {}

    void Game::printLastTurn() {}

    void Game::playAll() {}

    void Game::printWiner() {}

    void Game::printLog() {}

    void Game::printStats() {}

    // copying operator
    Game& Game::operator=(const Game& other)
    {
        if (this != &other) 
        {
            this->_plr1 = other._plr1;
            this->_plr2 = other._plr2;
            this->_move = other._move;
        }
        return *this;
    }

    // moving operator
    Game& Game::operator=(Game&& other) noexcept
    {
        if (this != &other)
        {
            this->_plr1 = std::move(other._plr1);
            this->_plr2 = std::move(other._plr2);
            this->_move = std::move(other._move);
        }
        return *this;
    }
};
