#include <iostream>
#include <array>

#include "cards.h"

struct arrCards {
    int num;
    std::string suit;
};

class Deck
{
    public:
        Deck();
        void build();
        void printDeck();
        void shuffle();
    private:
        std::array<arrCards, 52> array;
};