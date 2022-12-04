#include <iostream>
#include "cards.h"
#include "deck.h"

int main()
{
    Deck deck;
    deck.build();
    deck.shuffle();
    deck.printDeck();
    return 0;
}