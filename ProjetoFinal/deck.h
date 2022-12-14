#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <array>
#include <queue>
#include <vector>

#include "cards.h"

struct arrCards {
    int num;
    std::string suit;
};

class Deck
{
    public:
        void build();
        void printDeck();
        void shuffle();
        void getArrPos(int pos);
        void popArr();
        int giveCard();
    private:
        std::array<arrCards, 52> array;
        //std::vector<arrCards> array;
};

#endif