//
// Created by segev95 on 23/03/2023.
//

#ifndef CARDWAR_A_GAME_HPP
#define CARDWAR_A_GAME_HPP

#include "player.hpp"
#include "card.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

class Game {
private:
    Player& player1;
    Player& player2;
    vector<Card> gameDeck;
    vector<string> gameLog;
    int tableCards;
    string lastTurn;
    string winner;
    int round;
    int turns;

public:
    Game(Player& player1, Player& player2);

    void playTurn();

    void printLastTurn();

    void playAll();

    void printWiner();

    void printLog();

    void printStats();

    void createDeck();

    void dealCards();

    void setGameLog(string str);

    int getRound();
};

#endif //CARDWAR_A_GAME_HPP


