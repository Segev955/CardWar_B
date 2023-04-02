//
// Created by segev95 on 23/03/2023.
// helped: https://cplusplus.com/reference/cstdlib/rand/
#include "game.hpp"


using namespace std;
using namespace ariel;

Game::Game(Player& p1, Player& p2) : player1(p1), player2(p2) {
//    this->player1 = p1;
//    this->player2 = p2;
    createDeck();
    dealCards();
    this->tableCards = 0;

}

void Game::playTurn() {
    Card p1Card = this->player1.getStack().back();
    this->player1.removeCard(); //pop the card from stack
    Card p2Card = this->player2.getStack().back();
    this->player2.removeCard(); //pop the card from stack
    this->tableCards += 2;
    if (p1Card.getNum() > p2Card.getNum()) {
        if (p2Card.getNum() == 2 && p1Card.getNum() == 14) {// 2 > Ace
            this->player2.addCards(this->tableCards);
            winner = this->player2.getName();
        }
        else {
            this->player1.addCards(this->tableCards);
            winner = this->player1.getName();
        }
    }
    else if (p1Card.getNum() < p2Card.getNum()) {
        if (p1Card.getNum() == 2 && p2Card.getNum() == 14) { // 2 > Ace
            this->player1.addCards(this->tableCards);
            winner = this->player1.getName();
        }
        else {
            this->player2.addCards(this->tableCards);
            winner = this->player2.getName();
        }
    }
    else {
        this->player1.removeCard(); //add face down card
        this->player2.removeCard(); //add face down card
        this->tableCards += 2;
        this->playTurn();
    }
    this->lastTurn = this->player1.getName() + " played " + p1Card.getType() +  ", " +
    this->player2.getName() + " played " + p2Card.getType() + ". " + this->winner + " won.";
    this->tableCards = 0;

}

void Game::printLastTurn() {
    cout << this->lastTurn << endl;
}

void Game::playAll() {}

void Game::printWiner() {
    cout << this->winner << endl;
}

void Game::printLog() {
}

void Game::printStats() {
}

void Game::createDeck() {
    vector <Card> gameDeck;
    int cardNum[]{14,2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    string cardShape[]{"Diamond", "Heart", "Club", "Spade"};

    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            Card card(cardNum[i], cardShape[j]); //create the card
            gameDeck.push_back(card); //add the card to the list(deck)
        }
    }
    // Shuffle:
    srand(time(NULL)); //initialize random seed
    for (Card &card: gameDeck) {
        int temp = rand() % 52;
        swap(card, gameDeck[static_cast<vector<Card>::size_type>(temp)]); //swap randomly
    }
//    for (Card card : gameDeck) {
//        cout << card.getNum() << card.getShape() << endl;
//    }
    this->gameDeck = gameDeck;
}

void Game::dealCards() {
    vector <Card> sPlayer1;
    vector <Card> sPlayer2;

    for (int i = 0; i < 52; ++i) {
        if (i % 2 == 0) {
            sPlayer1.push_back(this->gameDeck[static_cast<vector<Card>::size_type>(i)]);
        } else {
            sPlayer2.push_back(this->gameDeck[static_cast<vector<Card>::size_type>(i)]);
        }
    }
    this->player1.setStack(sPlayer1);
    this->player2.setStack(sPlayer2);
}

