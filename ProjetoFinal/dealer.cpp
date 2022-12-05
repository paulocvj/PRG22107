#include <iostream>

#include "dealer.h"

void Dealer::takeCard(Deck &deck, int playerNum)
{
    for (int i = 0; i < 2 + playerNum; i++){
        gameCards[i] = deck.giveCard();
        deck.popArr();
    }
}

void Dealer::turnBoardCards()
{
    std::cout << gameCards[0] << " - " << gameCards[1] << std::endl;
}

int Dealer::dealCard()
{
    return gameCards[2];
}

bool Dealer::checkBetween(int cardToCheck)
{
    if ((cardToCheck > gameCards[0] && cardToCheck < gameCards[1]) || (cardToCheck > gameCards[1] && cardToCheck < gameCards[0])){
        return true;
    }
    return false;
}