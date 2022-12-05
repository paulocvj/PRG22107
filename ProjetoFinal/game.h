#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include "cards.h"
#include "deck.h"
#include "dealer.h"

class Game
{
    public:
        void start();
    private:
        int cardReceived;
};

#endif