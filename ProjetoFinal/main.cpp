#include <iostream>

#include "cards.h"
#include "deck.h"
#include "dealer.h"
#include "game.h"

int main()
{
    Game game;
    
    while (!game.init());

    return 0;
}