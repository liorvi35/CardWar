/**
 * @brief this file contains declarations for card object; Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @since 14/04/2023
 */

#pragma once // insuring that header will be included only once at most

#include <iostream>
#include <string>

using namespace std;

namespace ariel
{
    /**
     * @brief this enum representing constants that should be card's type
     */
    enum CardType
    {
        HEARTH = 'h',
        DIAMOND = 'd',
        CLUB = 'c',
        SPADE = 's'
    };

    /**
     * @brief this class representing the game object 
     */
    class Card
    {
        private:
            int _value; // number on card

            CardType _type; // symbol on card

        public:
            Card(int, CardType); // constructor

            int getValue(); // getter

            char getType(); // getter

            string to_string(); // to string method
    };
}