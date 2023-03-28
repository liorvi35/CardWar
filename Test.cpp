/**
 * 
*/

#include "doctest.h"
#include <iostream>
#include <string>
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "sources/player.hpp"

using namespace std;
using namespace ariel;

/**
 * 
*/
TEST_CASE("starting the game, initialization check, primary division")
{
    Player first_player("User1");
    Player second_player("User2");

    Game g(first_player, second_player);
    
    CHECK(first_player.stacksize() == 26);
    CHECK(first_player.cardesTaken() == 0);

    CHECK(second_player.stacksize() == 26);
    CHECK(second_player.cardesTaken() == 0);
}

/**
 * 
*/
TEST_CASE("playing the full game, using the playAll() method")
{
    Player first_player("User1");
    Player second_player("User2");

    Game g(first_player, second_player);
    
    g.playAll();
    
    CHECK(first_player.cardesTaken() == 26);
    CHECK(first_player.stacksize() == 0);

    CHECK(second_player.cardesTaken() == 26);
    CHECK(second_player.stacksize() == 0);
}

/**
 * 
*/
TEST_CASE("playing some (5) game steps, using the playTurn() method")
{
    Player first_player("User1");
    Player second_player("User2");

    Game g(first_player, second_player);

    int i = 0;
    for (i = 0; i < 5; i++) 
    {
        g.playTurn();
    }

    CHECK(first_player.cardesTaken() == 0);
    CHECK(first_player.stacksize() == 21);

    CHECK(second_player.cardesTaken() == 0);
    CHECK(second_player.stacksize() == 21);
}

/**
 * 
*/
TEST_CASE("checking the clearence of the game initiallization, reseting the game cards")
{
    Player first_player("User1");
    Player second_player("User2");

    Game first_g(first_player, second_player);
    
    first_g.playAll();

    Game second_g(first_player,second_player);

    CHECK(first_player.cardesTaken() == 0);
    CHECK(first_player.stacksize() == 26);

    CHECK(second_player.cardesTaken() == 0);
    CHECK(second_player.stacksize() == 26);
}

/**
 * 
*/
TEST_CASE("checking player's cards before game initialization (before starting the game)")
{
    Player first_player("User1");
    Player second_player("User2");

    CHECK((first_player.stacksize() == 0));
    CHECK((second_player.stacksize() == 0));
    
    Game first_g(first_player, second_player);
}

/**
 * 
*/
TEST_CASE("bad game object initiallizaition (player cannot play with himself)")
{
    Player first_player("User1");

    CHECK_THROWS(Game(first_player, first_player));
}

/**
 * 
*/
TEST_CASE("bad player initialization - player without name")
{
    Player first_player("");
    Player second_player("User2");

    CHECK_THROWS(Game(first_player, first_player));
}
