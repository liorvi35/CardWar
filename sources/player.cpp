/**
 * this file contains the implementation for player object functions
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 27.03.2023
*/

#include <iostream>
#include <string>
#include "player.hpp"

using namespace std;

namespace ariel
{
    // standard-ctor
    Player::Player(string name)
    {
        this->_pName = name;
        this->_isWon = false;
        this->_cardsCounter = 0;
        this->_stackLenght = 0;
    }

    // defult destructor
    Player::~Player() {}
};
