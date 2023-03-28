/**
 * this file contains the implementation for player object functions
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 28.03.2023
*/

#include <iostream>
#include <string>
#include "player.hpp"

using namespace std;

namespace ariel
{
    // defult-ctor
    Player::Player()
    {
        this->_pName = "User";
        this->_isWon = false;
        this->_cardsCounter = 0;
        this->_stackLenght = 0;
    }

    // standard-ctor
    Player::Player(string name)
    {
        this->_pName = name;
        this->_isWon = false;
        this->_cardsCounter = 0;
        this->_stackLenght = 0;
    }

    // copying-ctor
    Player::Player(const Player &other)
    {
        this->_pName = other._pName;
        this->_isWon = other._isWon;
        this->_cardsCounter = other._cardsCounter;
        this->_stackLenght = other._stackLenght;
    }

    // move-ctor
    Player::Player(Player &&other) noexcept:
        _pName(std::move(other._pName)),
        _isWon(std::move(other._isWon)),
        _cardsCounter(std::move(other._cardsCounter)),
        _stackLenght(std::move(other._stackLenght)) {}

    // copying operator
    Player& Player::operator=(const Player& other)
    {
        if (this != &other) 
        {
            this->_pName = other._pName;
            this->_isWon = other._isWon;
            this->_cardsCounter = other._cardsCounter;
            this->_stackLenght = other._stackLenght;
        }
        return *this;
    }

    // moving operator
    Player& Player::operator=(Player&& other) noexcept
    {
        if (this != &other)
        {
            this->_pName = std::move(other._pName);
            this->_isWon = std::move(other._isWon);
            this->_cardsCounter = std::move(other._cardsCounter);
            this->_stackLenght = std::move(other._stackLenght);
        }
        return *this;
    }
};
