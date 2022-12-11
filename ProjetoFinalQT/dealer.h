#ifndef DEALER_H_
#define DEALER_H_

#include <iostream>

#include "deck.h"

class Dealer
{
    public:
        void takeCard(Deck deck);
        int turnBoardCards();
        int dealCardPlayer();
        int dealFirstCard();
        int dealSecondCard();
        bool checkBetween(int cardToCheck, bool answer);
    private:
        std::array<int, 3> gameCards = {0, 0, 0};
};

#endif
