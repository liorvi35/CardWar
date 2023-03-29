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
     * this class representing player object
    */
    class Player
    {
        private:

            /**
             * this field is player's name
            */
            string _pName;

            /**
             * this field is for holding the amount of cards that left
            */
            int _stackLenght;

            /**
             * this field is for holding if this player won the game
            */
            bool _playingGame;

            /**
             * this field is for holding the amount of cards that player has won
            */
            int _cardsCounter;

        public:
            
            /**
             * creating-ctor for creating new object with new parameters
             * @param string player's name
            */
            Player(string);

            /**
             * standard getter for getting player's name
            */
            string getPlayerName();

            /**
             * 
            */
            bool getIfPlaying();

            /**
             * standard getter for getting stack size
            */
            int stacksize();

            /**
             * standard getter for getting taken cards counter
            */
            int cardesTaken();

            /**
             * setter for field that indicating if player in game
            */
           void setIfPlaying(bool);
    };
}
