#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include "cards.h"
#include "deck.h"
#include "dealer.h"
#include "player.h"

class Game
{
    public:
        void start();
        void playRound(Deck &deck, Player &player, int round);
    private:
        int cardReceived;
};

#endif