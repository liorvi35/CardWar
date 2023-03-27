#include "game.hpp"

using namespace std;

namespace ariel
{
    Game::Game() {}

    Game::Game(Player &o1, Player &o2)
    {
        this->_plr1 = o1;
        this->_plr2 = o2;
    }

    Game::Game(Game &other) {}

    Game::~Game() {}
};