/**
 * this file contains the header (interface) for card implementation in CardWar game
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 29.03.2023
*/

#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace ariel
{   
    /**
     * these constants representing the suit of each card
    */
    enum CardType { HEARTH = 'h', DIAMOND = 'd', CLUB = 'c', SPADE = 's' };

    /**
     * this class representing a single card in CardWar game
    */
    class Card
    {
        private:

            /**
             * this field holds the value of the card (i.e. the number that on card)
            */
            int _value;
            
            /**
             * this field holds the type of the card (i.e. the symbol that on card)
            */
            CardType _type;
        
        public:

            /**
             * creating-ctor for creating new object with new parameters
             * @param int card's value
             * @param CardType card's suit
            */
            Card(int, CardType);
            
            /**
             * standard getter for getting the value of the card
            */
            int getValue();
            
            /**
             * standard getter for getting the suit of the card
            */
            char getType();
    };
}
