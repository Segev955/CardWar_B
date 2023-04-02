//
// Created by segev95 on 23/03/2023.
//

#ifndef CARDWAR_A_CARD_HPP
#define CARDWAR_A_CARD_HPP
#include <string>
#include <iostream>

class Card {
private:
    int num;
    std::string shape;

public:
    Card(int num, std::string shape);
    int getNum();
    std::string getType();
};
#endif //CARDWAR_A_CARD_HPP

