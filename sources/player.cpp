#include "player.hpp"

using namespace std;

namespace ariel
{
    Player::Player()
    {
        this->_pName = "PLayer";
        this->_isWon = false;
        this->_cardsCounter = 0;
        this->_stackLenght = 0;
    }

    Player::Player(string name)
    {
        this->_pName = name;
        this->_isWon = false;
        this->_cardsCounter = 0;
        this->_stackLenght = 0;
    }

    Player::Player(Player &other)
    {
        this->_pName = other._pName;
        this->_isWon = other._isWon;
        this->_cardsCounter = other._cardsCounter;
        this->_stackLenght = other._stackLenght;
    }

    Player::~Player() {}
};