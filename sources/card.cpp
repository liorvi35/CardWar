/**
 * this file contains the implementation for card object functions
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 29.03.2023
*/

#include <iostream>
#include <string>
#include "card.hpp"

using namespace std;

namespace ariel
{
    // ctor
    Card::Card(int value, CardType type)
    {
        this->_value = value;
        this->_type = type;
    }

    // getter for card's value
    int Card::getValue()
    {
        return this->_value;
    }

    // getter for card's symbol
    char Card::getType()
    {
        return this->_type;
    }
}
