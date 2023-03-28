/**
 * this file contains test checks for CardWar game implementation
 * @author Lior Vinman
 * @date 28.03.2023
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
 * this test checks the primary division of cards to both player after game starting,
 * each player should have 52/2 = 26 cards at their stack and 0 cards should be taken since there wasn't moves
*/
TEST_CASE("starting the game, initialization check, primary division")
{
    // creating players
    Player first_player("User1");
    Player second_player("User2");

    // creating game
    Game g(first_player, second_player);

    // checking first player
    CHECK(first_player.stacksize() == 26);
    CHECK(first_player.cardesTaken() == 0);

    // checking second player
    CHECK(second_player.stacksize() == 26);
    CHECK(second_player.cardesTaken() == 0);
}

/**
 * this test check the card usage when the game ends
 * each player should have taken 26 cards and their stacks should be empty
*/
TEST_CASE("playing the full game, using the playAll() method")
{   
    // creating players
    Player first_player("User1");
    Player second_player("User2");

    // creating game
    Game g(first_player, second_player);
    
    // playing full game
    g.playAll();
    
    // checking first player
    CHECK(first_player.cardesTaken() == 26);
    CHECK(first_player.stacksize() == 0);

    // checking second player
    CHECK(second_player.cardesTaken() == 26);
    CHECK(second_player.stacksize() == 0);
}

/**
 * this test check the card usage after 5 game turns
 * this test allready used at Demo.cpp file(!)
*/
TEST_CASE("playing some (5) game steps, using the playTurn() method")
{   
    // creating both players
    Player first_player("User1");
    Player second_player("User2");

    // creating game
    Game g(first_player, second_player);

    // making 5 game moves
    int i = 0;
    for (i = 0; i < 5; i++) 
    {
        g.playTurn();
    }

    // checking first player
    CHECK(first_player.cardesTaken() == 0);
    CHECK(first_player.stacksize() == 21);

    // checking second player
    CHECK(second_player.cardesTaken() == 0);
    CHECK(second_player.stacksize() == 21);
}

/**
 * this test checking the cards after the game starts then ends then another game starting
 * cards should be (taken, stack) = (26,0) then change somehow in the game then should be reset again to (26,0)
*/
TEST_CASE("checking the clearence of the game initiallization, reseting the game cards")
{
    // creating players
    Player first_player("User1");
    Player second_player("User2");

    // creating first game
    Game first_g(first_player, second_player);
    
    // playing the first game
    first_g.playAll();

    // creating second game
    Game second_g(first_player,second_player);

    // checking first player
    CHECK(first_player.cardesTaken() == 0);
    CHECK(first_player.stacksize() == 26);

    // checking second player
    CHECK(second_player.cardesTaken() == 0);
    CHECK(second_player.stacksize() == 26);
}

/**
 * this test both of the players has zero crads in stack before game starting
*/
TEST_CASE("checking player's cards before game initialization (before starting the game)")
{
    // creating players
    Player first_player("User1");
    Player second_player("User2");

    // checking both players
    CHECK((first_player.stacksize() == 0));
    CHECK((second_player.stacksize() == 0));
    
    // creating game
    Game first_g(first_player, second_player);
}

/**
 * this test checks if game started with same player twice,
 * of course for playing game for two you need real two players...
*/
TEST_CASE("bad game object initiallizaition (player cannot play with himself)")
{
    // creating first player only
    Player first_player("User1");

    // checking initallization with one player
    CHECK_THROWS(Game(first_player, first_player));
}

/**
 * this test checks the initiallization of player object
 * every player should have a name by definition
*/
TEST_CASE("bad player initialization - player without name")
{
    // creating players
    Player first_player("");
    Player second_player("User2");

    // checking
    CHECK_THROWS(Game(first_player, second_player));
}
