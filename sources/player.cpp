/**
 * @brief this file contains implementation for game functions; Assignment 2, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @since 14/04/2023
 */

#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "card.hpp"
#include <stdexcept>

using namespace std;

namespace ariel
{
    /**
     * @brief standard constructor, creates an player object with name
     * @param name player's name
     * @throws invalid_argument in case that name is empty
     */
    Player::Player(string name)
    {
        if(name == "") // checking case
        {
            throw invalid_argument("Name is empty!!!");
        }
        else // setting all data members
        {
            this->_pName = name;
            this->_playingGame = false;
            this->_cardsCounter = 0;
        }
    }
    
    /**
     * @brief standard getter method for player's name data member
     */
    string Player::getPlayerName()
    {
        return this->_pName;
    }

    /**
     * @brief standard getter method for player's numbers of cards he holds
     */
    int Player::cardesTaken()
    {
        return this->_cardsCounter;
    }

    /**
     * @brief standard setter method for player's numbers of cards he holds
     * @param num number of cards to add
     */
    void Player::setCardsCounter(int num)
    {
        this->_cardsCounter += num;
    }

    /**
     * @brief standard getter method for player's game status
     */
    bool Player::getIfPlaying()
    {
        return this->_playingGame;
    }

    /**
     * @brief standard getter method for player's hand size
     */
    int Player::stacksize()
    {
        return this->_playerHand.size();
    }

    /**
     * @brief standard setter method for player's game status
     * @param status game status - true(playing) / false(not playing)
     */
    void Player::setIfPlaying(bool change)
    {
        this->_playingGame = change;
    }

    /**
     * @brief this function adds card to hand
     * @param card card to add
     */
    void Player::addCard(Card card)
    {
        this->_playerHand.push_back(card);
    }

    /**
     * @brief this function removes the last card of player
     */
    void Player::removeCard()
    {
        this->_playerHand.pop_back();
    }

    /**
     * @brief this function gets the last card of player
     * @return last card
     */
    Card Player::showLastCard()
    {
        return this->_playerHand.back();
    }
}