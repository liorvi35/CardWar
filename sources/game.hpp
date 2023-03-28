/**
 * this file contains the header (interface) for game implementation in CardWar game
 * Assignment 2(a), Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @date 27.03.2023
*/

#pragma once // telling that this librarie will be included only once

#include "player.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel 
{
    /**
     * this constants representing who's players is the current move
    */
    enum PlayerMove
    {
        FIRST_PLAYER = 0,
        SECOND_PLAYER = 1
    };

    /**
     * this class implement the CardWar game
    */
    class Game
    {
        private:
            /**
             * those fields representing the players that playing the game
            */
            Player &_plr1, &_plr2;

            /**
             * this field represents the current move of the game
            */
            PlayerMove _move;

        public:
            /**
             * creating-ctor for creating new object with new parameters
             * @param Player first player in the game
             * @param Player second player in the game
            */
            Game(Player&, Player&);

            /**
             * defult-destructor for destroying (deleting) the objects
            */
            //~Game();

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
};

