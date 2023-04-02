//
// Created by segev95 on 23/03/2023.
//

#include "card.hpp"
using namespace std;

Card::Card(int num, std::string shape) {
    this->num = num;
    this->shape = shape;
}
int Card::getNum() {
    return this->num;
}
//get the card number and shape
std::string Card::getType() {
    string s = std::to_string(this->num);
    if (this->num == 14)
        s = "Ace";
    else if (this->num == 11)
        s = "Jack";
    else if (this->num == 12)
        s = "Queen";
    else if (this->num == 13)
        s = "King";
    return s + " of " + this->shape;
}




