#include <iostream>
#include "game.h"

void Game::start()
{
    char box;
    bool result;

    Deck deck;
    Dealer dealer;
    deck.build();
    deck.shuffle();

    dealer.takeCard(deck, 1);
    dealer.turnBoardCards();

    cardReceived = dealer.dealCard();

    std::cout << "Is your card in between? [y/n]" << std::endl;
    std::cin >> box;

    result = dealer.checkBetween(cardReceived);
    
    if ((result && box == 'y') || (!result && box == 'n')) std::cout << "You got it!" << std::endl;
    else std::cout << "Wrong!" << std::endl;

    std::cout << "Your card was -> " << cardReceived << std::endl;
}