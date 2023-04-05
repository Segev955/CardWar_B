//
// Created by segev95 on 23/03/2023.
// helped: https://cplusplus.com/reference/cstdlib/rand/
#include "game.hpp"


using namespace std;
using namespace ariel;

Game::Game(Player& p1, Player& p2) : player1(p1), player2(p2) {
//    this->player1 = p1;
//    this->player2 = p2;
//    if (&p1 == &p2) {
//        throw invalid_argument("Cannot start the game with the same player");
//    }
    createDeck();
    dealCards();
    this->tableCards = 0;
    this->round = 0;
    this->winner = "None";
    this->lastTurn = "Round 0";

}

void Game::playTurn() {
    if (&player1 == &player2) {
        throw invalid_argument("Cannot start the game with the same player");
    }
    if (this->player1.stacksize()  <= 0) {
        throw invalid_argument("Game finish.");
    }
    Card p1Card = this->player1.getStack().back();
    this->player1.removeCard(); //pop the card from stack
    Card p2Card = this->player2.getStack().back();
    this->player2.removeCard(); //pop the card from stack
    this->tableCards += 2;
    if (p1Card.getNum() > p2Card.getNum()) {
        if (p2Card.getNum() == 2 && p1Card.getNum() == 14) {// 2 > Ace
            this->player2.addCards(this->tableCards);
            winner = this->player2.getName();
            this->player2.setWins();
            this->player1.setLosses();
        }
        else {
            this->player1.addCards(this->tableCards);
            winner = this->player1.getName();
            this->player1.setWins();
            this->player2.setLosses();
        }
    }
    else if (p1Card.getNum() < p2Card.getNum()) {
        if (p1Card.getNum() == 2 && p2Card.getNum() == 14) { // 2 > Ace
            this->player1.addCards(this->tableCards);
            winner = this->player1.getName();
            this->player1.setWins();
            this->player2.setLosses();
        }
        else {
            this->player2.addCards(this->tableCards);
            winner = this->player2.getName();
            this->player2.setWins();
            this->player1.setLosses();
        }
    }
    else { //Draw:
        string s = this->player1.getName() + " played " + p1Card.getType() +  ", " +
                   this->player2.getName() + " played " + p2Card.getType() + ". Draw.";
        this->setGameLog("         " + s);
        this->player1.setDraws();
        this->player2.setDraws();
        if (this->player1.stacksize() > 0) {
            this->player1.removeCard(); //add face down card
            this->player2.removeCard(); //add face down card
            this->tableCards += 2;
        }
        if (this->player1.stacksize()  > 0) {
            this->playTurn();
        } else { //no more cards (at draw play)
            int tc = this->tableCards/2;
            this->player1.addCards(tc);
            this->player2.addCards(tc);
            this->winner = "no-one";
        }
    }
    this->lastTurn = this->player1.getName() + " played " + p1Card.getType() +  ", " +
    this->player2.getName() + " played " + p2Card.getType() + ". " + this->winner + " won.";
    this->round ++;
    this->setGameLog("Round " + std::to_string(this->round) + ": " + this->lastTurn);
    this->tableCards = 0;

}

void Game::printLastTurn() {
    cout << this->lastTurn << endl;
}

void Game::playAll() {
    while (this->player1.stacksize() > 0) {
        this->playTurn();
    }
    cout << "Game finish." << endl;

}

void Game::printWiner() {
    if (this->player1.cardesTaken() > this->player2.cardesTaken()) {
        cout << this->player1.getName() << endl;
    }
    else if  (this->player1.cardesTaken() < this->player2.cardesTaken()) {
        cout << this->player2.getName() << endl;
    } else
        throw invalid_argument("Draw!");
}
void Game::setGameLog(string str) {
    this->gameLog.push_back(str);
}

int Game::getRound() {
    return this->round;
}

void Game::printLog() {
    for (int i = 0; i < this->gameLog.size(); ++i) {
        cout << this->gameLog[static_cast<vector<string>::size_type>(i)] << endl;
    }
}

void Game::printStats() {
    double ratio = 1;
    //Player 1:
    if (this->player1.getLosses() > 0)
        ratio = static_cast<double>(this->player1.getWins()) / this->player1.getLosses();
    cout << this->player1.getName() + ":" << endl;
    cout << "Wins: " + std::to_string(this->player1.getWins()) << endl;
    cout << "Losses: " + std::to_string(this->player1.getLosses()) << endl;
    cout << "Ratio: " << std::setprecision(2) << ratio << endl;
    cout << "Draws: " + std::to_string(this->player1.getDraws()) << endl;
    cout << "Cards taken: " + std::to_string(this->player1.cardesTaken()) << endl;
    cout << "---------------------------------" << endl;
    //Player 2:
    ratio = 1;
    if (this->player2.getLosses() > 0)
        ratio = static_cast<double>(this->player2.getWins()) / this->player2.getLosses();
    cout << this->player2.getName() + ":" << endl;
    cout << "Wins: " + std::to_string(this->player2.getWins()) << endl;
    cout << "Losses: " + std::to_string(this->player2.getLosses()) << endl;
    cout << "Ratio: " << std::setprecision(2) << ratio << endl;
    cout << "Draws: " + std::to_string(this->player2.getDraws()) << endl;
    cout << "Cards taken: " + std::to_string(this->player2.cardesTaken()) << endl;
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

