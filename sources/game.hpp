/**
 * this file contains the header (interface) for game implementation in CardWar game
 * Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 29.03.2023
*/

#pragma once

#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    /**
     * this class representing game object
     */
    class Game
    {
        private:
            /**
             * those fields are players that playing the game
             */
            Player &_player1, &_player2;

            /**
             * this field are how many game moves were done
            */
           int _gameMove;

        public:
            /**
             * standart-ctor for creating a new object
             * @param Player first player of game
             * @param Player second player of game
             */
            Game(Player &, Player &);

            /**
             * this function is a single in-game move of one of the players
             */
            void playTurn();

            /**
             * this function is a method to print the last move
             */
            void printLastTurn();

            /**
             * this function is a method to play the full game
             */
            void playAll();

            /**
             * this function is a method to print the winner of the game
             */
            void printWiner();

            /**
             * this function is a method to print the game log (all moves by order)
             */
            void printLog();

            /**
             * this function is a method to print the game statistics
             */
            void printStats();
    };
}
