/**
 * this file contains the implementation for card object functions
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 28.03.2023
*/

#include <iostream>
#include <string>
#include "card.hpp"

using namespace std;

namespace ariel
{   
    // defult-ctor
    Card::Card()
    {
        this->_value = 1;
        this->_type = DIAMOND;
    }

    // standard-ctor
    Card::Card(int value, CardType type)
    {
        this->_value = value;
        this->_type = type;
    }

    // copy-ctor
    Card::Card(const Card &other)
    {
        this->_type = other._type;
        this->_value = other._value;
    }

    // move-ctor
    Card::Card(Card &&other) noexcept:
        _type(std::move(other._type)),
        _value(std::move(other._value)) {}

    // copying operator
    Card& Card::operator=(const Card& other)
    {
        if (this != &other) 
        {
            this->_value = other._value;
            this->_type = other._type;
        }
        return *this;
    }

    // moving operator
    Card& Card::operator=(Card&& other) noexcept
    {
        if (this != &other)
        {
            this->_value = std::move(other._value);
            this->_type = std::move(other._type);
        }
        return *this;
    }
};
