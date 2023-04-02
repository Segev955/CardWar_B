//
// Created by segev95 on 23/03/2023.
//

#ifndef CARDWAR_A_PLAYER_HPP
#define CARDWAR_A_PLAYER_HPP

#include <stdio.h>
#include <string>
namespace ariel{}
using namespace std;

class Player {
private:
    string name;

public:
    Player(string pName);

    int stacksize();

    int cardesTaken();



};
#endif //CARDWAR_A_PLAYER_HPP

