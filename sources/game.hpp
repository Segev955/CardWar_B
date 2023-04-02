//
// Created by segev95 on 23/03/2023.
//

#ifndef CARDWAR_A_GAME_HPP
#define CARDWAR_A_GAME_HPP

#include "player.hpp"
#include <string>
#include <iostream>

class Game {
public:
    Game(Player player1, Player player2);

    void playTurn();

    string printLastTurn();

    void playAll();

    string printWiner();

    string printLog();

    string printStats();
};

#endif //CARDWAR_A_GAME_HPP
