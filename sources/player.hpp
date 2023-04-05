//
// Created by segev95 on 23/03/2023.
//

#ifndef CARDWAR_A_PLAYER_HPP
#define CARDWAR_A_PLAYER_HPP

#include "card.hpp"
#include <stdio.h>
#include <string>
#include <vector>

namespace ariel{}
using namespace std;

class Player {
private:
    string name;
    vector<Card> stack;
    int cards;
    //stats:
    int wins;
    int losses;
    int draws;

public:
    Player();
    Player(string pName);

    int stacksize();

    int cardesTaken();

    void setStack(vector<Card>);

    vector<Card> getStack();

    void removeCard();

    void addCards(int n);

    string getName();

    int getWins();
    void setWins();

    int getLosses();
    void setLosses();

    int getDraws();
    void setDraws();



};
#endif //CARDWAR_A_PLAYER_HPP


