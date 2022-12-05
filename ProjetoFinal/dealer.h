#ifndef DEALER_H_
#define DEALER_H_

#include <iostream>

#include "deck.h"

class Dealer
{
    public:
        void takeCard(Deck &deck, int playerNum);
        void turnBoardCards();
        int dealCard();
        bool checkBetween(int cardToCheck);
    private:
        std::array<int, 3> gameCards = {0, 0, 0};
};

#endif