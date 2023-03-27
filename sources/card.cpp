#include "card.hpp"

using namespace std;

namespace ariel
{
    Card::Card()
    {
        this->_value = 2;
        this->_type = CLUB;
    }

    Card::Card(int value, CardType type)
    {
        this->_value = value;
        this->_type = type;
    }

    Card::Card(Card &other)
    {
        this->_value = other._value;
        this->_type = other._type;
    }

    Card::~Card() {}
};