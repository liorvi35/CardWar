/**
 * this file contains the header (interface) for card implementation in CardWar game
 * Assignment 2(a), Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 27.03.2023
*/

#include <iostream>
#include <string>

namespace ariel 
{   
    /**
     * this constants representing the suit of each card
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
             * defult-ctor for creating empty object
            */
            Card();

            /**
             * creating-ctor for creating new object with new parameters
             * @param int card's value
             * @param CardType card's suit
            */
            Card(int, CardType);

            /**
             * copying-ctor for creating new object from existing object
             * @param Card the object that should be copied
            */
            Card(Card&);

            /**
             * defult-destructor for destroying (deleting) the object
            */
            ~Card();

            /**
             * standard getter for getting the value of the card
            */
            int getValue() const {return this->_value;}

            /**
             * standard getter for getting the suit of the card
            */
            int getType() const {return this->_type;}
    };
};
