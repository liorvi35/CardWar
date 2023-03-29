/**
 * this file contains the implementation for player object functions
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 29.03.2023
*/

#include <iostream>
#include <string>
#include "player.hpp"

using namespace std;

namespace ariel
{
    // defult-ctor
    Player::Player(string name)
    {
        this->_pName = name;
        this->_playingGame = false;
        this->_cardsCounter = 0;
        this->_stackLenght = 26;
    }

    // getter for player name 
    string Player::getPlayerName()
    {
        return this->_pName;
    }

    // getter for cards counter
    int Player::cardesTaken()
    {
        return this->_cardsCounter;
    }

    // getter for field that indicating if player inside game
    bool Player::getIfPlaying()
    {
        return this->_playingGame;
    }

    // getter for stack size
    int Player::stacksize()
    {
        return this->_stackLenght;
    }

    // setter for changing game mode
    void Player::setIfPlaying(bool change)
    {
        this->_playingGame = change;
    }
}
