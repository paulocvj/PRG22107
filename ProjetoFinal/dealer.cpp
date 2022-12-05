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
    int cardToReturn;
    for (int i = 2; i < gameCards.size() - 2; i++)
        if (gameCards[i] != 0) {
             cardToReturn = gameCards[i];
             gameCards[i] = 0;
             return cardToReturn;
        }
    return -1;
}

bool Dealer::checkBetween(int cardToCheck)
{
    if ((cardToCheck > gameCards[0] && cardToCheck < gameCards[1]) || (cardToCheck > gameCards[1] && cardToCheck < gameCards[0])){
        return true;
    }
    return false;
}