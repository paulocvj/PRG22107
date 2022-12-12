#include <iostream>
#include <QLabel>
#include <QGridLayout>
#include <QThread>

#include "dealer.h"

void Dealer::takeCard(Deck deck)
{
    for (int i = 0; i < 3; i++){
        gameCards[i] = deck.giveCard();
        deck.popArr();
    }
}

int Dealer::turnBoardCards()
{
    int temp;
    for (int i = 0; i < 2; i++) {
        if (gameCards[i] != 0) {
            temp = gameCards[i];
            gameCards[i] = 0;
            return temp;
        }
    }
    return -1;
}

int Dealer::dealCardPlayer()
{
#ifdef DEBUG
    std::cout << "Player card: " << gameCards[2] << std::endl;
#endif
    return gameCards[2];
}

int Dealer::dealFirstCard()
{
    return gameCards[0];
}

int Dealer::dealSecondCard()
{
    return gameCards[1];
}

bool Dealer::checkBetween(int cardToCheck, bool answer)
{
    bool between;
#ifdef DEBUG
    std::cout << gameCards[0] << " - " << gameCards[1] << std::endl;
#endif
    if ((cardToCheck > gameCards[0] && cardToCheck < gameCards[1]) || (cardToCheck > gameCards[1] && cardToCheck < gameCards[0])){
        between = true;
    }
    else between = false;

    if ((between == true && answer == true) || (between == false && answer == false)) return true;
    else return false;
}
