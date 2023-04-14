/**
 * @brief this file contains declarations for game object; Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @since 14/04/2023
 */

#pragma once // insuring that header will be included only once at most

#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{   
    /**
     * @brief this class representing the game object 
     */
    class Game
    {
        private:
            Player &_player1, &_player2; // players in game

            int _gameMove, _winRateP1, _winRateP2, _drawRate; // all game statistics

            string _gameLog, _currentLog; // game logs

            vector<Card> _cards; // game cards

        public:
            Game(Player &, Player &); // constructor

            void playTurn(); // play one turn in game 

            void printLastTurn(); // print the last turn stats

            void playAll(); // playes the game untill the end

            void printWiner(); // prints the name of the winning player

            void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())

            void printStats(); // for each player prints basic statistics
    };
}