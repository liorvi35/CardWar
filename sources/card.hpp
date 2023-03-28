/**
 * this file contains the header (interface) for card implementation in CardWar game
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 28.03.2023
*/

#pragma once // telling that this librarie will be included only once

#include <iostream>
#include <string>

namespace ariel 
{   
    /**
     * these constants representing the suit of each card
    */
    enum CardType
    {
        HEARTH = 'h',
        DIAMOND = 'd',
        CLUB = 'c',
        SPADE = 's'
    };

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
             * defult-ctor for creating defult object
            */
            Card();

            /**
             * creating-ctor for creating new object with new parameters
             * @param int card's value
             * @param CardType card's suit
            */
            Card(int, CardType);

            /**
             * copy-ctor for creating new object from existing object
             * @param Player existing object to copy
            */
            Card(const Card&);

            /**
             * move-ctor for creating new object from existing object by moving it's params
             * @param Player existing object to move
            */
            Card(Card&&) noexcept;

            /**
             * defult-destructor for destroying (deleting) the object
            */
            ~Card() = default;

            /**
             * standard getter for getting the value of the card
            */
            int getValue() const {return this->_value;}

            /**
             * standard getter for getting the suit of the card
            */
            char getType() const {return this->_type;}


            /**
             * operator to perform asignmention
            */
            Card& operator=(const Card&);

            /**
             * operator to perform move
            */
            Card& operator=(Card&&) noexcept;
    };
};

