/**
 * this file contains the header (interface) for card implementation in CardWar game
 * Assignment 2(a), Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 28.03.2023
*/

#pragma once // telling that this librarie will be included only once

#include <iostream>
#include <string>

using namespace std;

namespace ariel 
{   
    /**
     * this class representing a single player in CardWar game
    */
    class Player 
    {
        private:
            /**
             * this field is for holding player's name
            */
            string _pName;

            /**
             * this field is for holding the amount of cards that left
            */
            int _stackLenght;

            /**
             * this field is for holding the amount of cards that player has won
            */
            int _cardsCounter;

            /**
             * this field is for holding if this player won the game
            */
            bool _isWon;

        public:

            /**
             * defult-ctor for creating defult object
            */
            Player();

            /**
             * creating-ctor for creating new object with new parameters
             * @param string player's name
            */
            Player(string);

            /**
             * copy-ctor for creating new object from existing object
             * @param Player existing object to copy
            */
            Player(const Player&);

            /**
             * move-ctor for creating new object from existing object by moving it's params
             * @param Player existing object to move
            */
            Player(Player&&) noexcept;

            /**
             * defult-destructor for destroying (deleting) the objects
            */
            ~Player() = default;

            /**
             * standard getter for getting player's name
            */
            string getPlayerName() {return this->_pName;}

            /**
             * standard getter for getting the game state (won/continue) of the player
            */
            bool getIsWon() const {return this->_isWon;}

            /**
             * standard getter for getting stack size
            */
            int stacksize() const {return this->_stackLenght;}

            /**
             * standard getter for getting taken cards counter
            */
            int cardesTaken() const {return this->_cardsCounter;}

            /**
             * operator to perform asignmention
            */
            Player& operator=(const Player&);

            /**
             * operator to perform move
            */
            Player& operator=(Player&&) noexcept;      
    };
};
