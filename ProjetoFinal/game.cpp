#include <iostream>
#include "game.h"

void Game::start()
{
    char box;
    bool result;

    Deck deck;
    Dealer dealer;
    Player player;
    deck.build();
    deck.shuffle();

    for (int i = 0; i < 10; i++) {
        playRound(deck, player, i);
    }

    std::cout << "Your final score was: " << player.getPoints() << std::endl;
}

void Game::playRound(Deck &deck, Player &player, int round){
    Dealer dealer;
    int cardReceived;
    bool result;
    char box;
    
    dealer.takeCard(deck, 1);
    dealer.turnBoardCards();

    cardReceived = dealer.dealCard();

    std::cout << "Is your card in between? [y/n]" << std::endl;
    std::cin >> box;

    result = dealer.checkBetween(cardReceived);
    
    if ((result && box == 'y') || (!result && box == 'n')) {
        std::cout << "You got it!" << std::endl;
        player.addPoints();
        }
    else std::cout << "Wrong!" << std::endl;

    std::cout << "Your card was -> " << cardReceived << std::endl;
    std::cout << "Your score after round " << round + 1 << " is " << player.getPoints() << std::endl;
}