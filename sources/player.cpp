//
// Created by segev95 on 23/03/2023.
//
#include "player.hpp"


using namespace std;
using namespace ariel;

Player::Player() {}

Player::Player(string pName) {
    this->name = pName;
    this->cards = 0;
    this->wins = 0;
    this->losses = 0;
    this->draws = 0;
}

int Player::stacksize() {
    return this->stack.size();
}

int Player::cardesTaken() {
    return this->cards;
}

void Player::setStack(vector <Card> stack) {
    this->stack = stack;
}

vector <Card> Player::getStack() {
    return this->stack;
}

void Player::removeCard() {
    this->stack.pop_back();
}

void Player::addCards(int n) {
    this->cards += n;
}

string Player::getName() {
    return this->name;
}

int Player::getWins() {
    return this->wins;
}
void Player::setWins(){
    this->wins++;
}

int Player::getLosses() {
    return this->losses;
}
void Player::setLosses() {
    this->losses ++;
}

int Player::getDraws() {
    return this->draws;
}
void Player::setDraws() {
    this->draws++;
}


