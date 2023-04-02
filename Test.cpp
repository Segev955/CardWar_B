//
// Created by segev95 on 23/03/2023.
//
#include <iostream>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("First game") {
    Player p1("Segev");
    Player p2("Tzabar");
    Game game(p1, p2);

    CHECK_THROWS(game.printWiner()); //no winner before the game starts
    CHECK(p1.stacksize() == p2.stacksize()); // at the beginning it should be equal
    CHECK(p1.stacksize() == 26); //at the beginning should be 26
    CHECK(p2.stacksize() == 26);//same


    for (int i = 0; i < 5; i++) {
        CHECK_NOTHROW(game.playTurn());
    }
    CHECK(p1.stacksize() <= 21); // should be 21 but can be less if a draw was played
    CHECK(p2.stacksize() <= 21); // should be 21 but can be less if a draw was played
    CHECK(p1.cardesTaken() <= 0); // Should be 0 or more (if this player won)
    CHECK(p2.cardesTaken() <= 0); // Should be 0 or more (if this player won)
    CHECK_NOTHROW(game.printLastTurn()); //Varies
    CHECK_NOTHROW(game.playAll()); //void
    CHECK_NOTHROW(game.printWiner()); //player1 or player2
    CHECK_NOTHROW(game.printLog()); //Varies
    CHECK_NOTHROW(game.printStats()); //Varies
}

TEST_CASE("Second game") {
    Player p1("se");
    Player p2("tz");
    Game game(p1, p2);

    CHECK(p1.stacksize() == p2.stacksize()); // at the beginning it should be equal
    CHECK(p1.stacksize() == 26); //at the beginning should be 26
    CHECK(p2.stacksize() == 26);//same

    for (int i = 0; i < 2; i++) {
        CHECK_NOTHROW(game.playTurn());
    }
    CHECK(p1.stacksize() <= 24); // should be 24 but can be less if a draw was played
    CHECK(p2.stacksize() <= 24); // should be 24 but can be less if a draw was played
    CHECK(p1.cardesTaken() <= 0); // Should be 0 or more (if this player won)
    CHECK(p2.cardesTaken() <= 0); // Should be 0 or more (if this player won)
    CHECK_NOTHROW(game.printLastTurn()); //Varies
    CHECK_NOTHROW(game.playAll()); //void
    CHECK_NOTHROW(game.printWiner()); //player1 or player2
    CHECK_NOTHROW(game.printLog()); //Varies
    CHECK_NOTHROW(game.printStats()); //Varies
}
