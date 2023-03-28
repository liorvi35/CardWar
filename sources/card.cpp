/**
 * this file contains the implementation for card object functions
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 27.03.2023
*/

#include <iostream>
#include <string>
#include "card.hpp"

using namespace std;

namespace ariel
{
    // defult-ctor
    Card::Card(int value, CardType type)
    {
        this->_value = value;
        this->_type = type;
    }

    // defult-destructor
    Card::~Card() {}
};
