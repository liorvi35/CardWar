/**
 * @brief this file contains implementation for card functions; Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @since 14/04/2023
 */

#include <iostream>
#include <string>
#include "card.hpp"

using namespace std;

namespace ariel
{
    /**
     * @brief standard constructor, creates an card object with number and type
     * @param value number of card
     * @param type suit of card
     */
    Card::Card(int value, CardType type)
    {
        this->_value = value;
        this->_type = type;
    }

    /**
     * @brief this function is standard getter method for value data member
     * @return current card's value
     */
    int Card::getValue()
    {
        return this->_value;
    }

    /**
     * @brief this function is standard getter method for type data member
     * @return current card's suit
     */
    char Card::getType()
    {
        return this->_type;
    }

    /**
     *  @brief this function is a standard to-string method for object
     *  @return a string that representing card object
     */
    string Card::to_string()
    {
        string suit = "", str = "";

        switch (this->_type) // checking card suit
        {
            case HEARTH:
                suit = "Hearths";
                break;
            case DIAMOND:
                suit = "Diamonds";
                break;
            case CLUB:
                suit = "Clubs";
                break;
            case SPADE:
                suit = "Spades";
                break;
        }

        switch (this->_value) // checking card name
        {
            case 1:
                str = "Ace of " + suit;
                break;
            case 11:
                str = "Prince of " + suit;
                break;
            case 12:
                str = "Queen of " + suit;
                break;
            case 13:
                str = "King of " + suit;
                break;
            default:
                str = std::to_string(this->_value) + " of " + suit;
                break;
        }

        return str;
    }
}