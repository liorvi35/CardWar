#include <iostream>
#include <string>
#include "doctest.h"
#include "sources/game.hpp"

using namespace std;
using namespace ariel;

/**
 * this test for checking game starting, at start each player gets 52/2 = 26 cards (stack) and holds 0 cards (taken)
*/
TEST_CASE("game initialization - checking primary card division")
{
    // creating 2 players to the game
    Player first_player("User1");
    Player second_player("User2");

    // creating the game
    Game g(first_player, second_player);

    // checking if players taken 0 cards (cannot be more)
    CHECK(first_player.cardesTaken() == 0);
    CHECK(second_player.cardesTaken() == 0);

    // checking if players has 52/2(=26) cards
    CHECK(first_player.stacksize() == 26);
    CHECK(second_player.stacksize() == 26);
}

/**
 * 
*/
TEST_CASE("playing playing 7 moves")
{
    // creating 2 players to the game
    Player first_player("User1");
    Player second_player("User2");

    // creating the game
    Game g(first_player, second_player);

    // playing 7 player's moves in the game
    int i = 0;
    for(i = 0; i < 7; i++)
    {
        g.playTurn();
    }

    // checking if players taken 0 cards (cannot be more)
    CHECK(first_player.cardesTaken() == 7);
    CHECK(second_player.cardesTaken() == 7);

    // checking if players has 52/2(=26) cards
    CHECK(first_player.stacksize() == 19);
    CHECK(second_player.stacksize() == 19);
}

/**
 * 
*/
TEST_CASE("playing playing full game (26 moves) - manually")
{
    // creating 2 players to the game
    Player first_player("User1");
    Player second_player("User2");

    // creating the game
    Game g(first_player, second_player);

    // playing 7 player's moves in the game
    int i = 0;
    for(i = 0; i < 26; i++)
    {
        g.playTurn();
    }

    // checking if players taken 0 cards (cannot be more)
    CHECK(first_player.cardesTaken() == 26);
    CHECK(second_player.cardesTaken() == 26);

    // checking if players has 52/2(=26) cards
    CHECK(first_player.stacksize() == 0);
    CHECK(second_player.stacksize() == 0);
}

/**
 * 
*/
TEST_CASE("playing playing full game (26 moves) - automatically")
{
    // creating 2 players to the game
    Player first_player("User1");
    Player second_player("User2");

    // creating the game
    Game g(first_player, second_player);

    // playing 7 player's moves in the game
    g.playAll();

    // checking if players taken 0 cards (cannot be more)
    CHECK(first_player.cardesTaken() == 26);
    CHECK(second_player.cardesTaken() == 26);

    // checking if players has 52/2(=26) cards
    CHECK(first_player.stacksize() == 0);
    CHECK(second_player.stacksize() == 0);
}

/**
 * 
*/
TEST_CASE("player withoun name")