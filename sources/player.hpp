/**
 * @brief this file contains declarations for player object; Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @since 14/04/2023
 */

#pragma once // insuring that header will be included only once at most

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel
{   
    /**
     * @brief this class representing the player object 
     */
    class Player
    {
        private:
            string _pName; // player's name

            bool _playingGame; // game status

            int _cardsCounter; // how many cards player took

            vector<Card> _playerHand; // player's cards hand

        public:
            Player(string); // constructor

            string getPlayerName(); // getter

            bool getIfPlaying(); // getter

            int stacksize(); // getter

            int cardesTaken(); // getter

            void setIfPlaying(bool); // setter

            void addCard(Card); // adding card for hand

            void removeCard(); // removing card from hand

            Card showLastCard(); // getting card from hand

            void setCardsCounter(int); // setter
    };
}