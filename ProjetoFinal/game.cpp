#include <iostream>
#include "game.h"

void Game::init()
{
    Deck deck;
    Dealer dealer;
    Player player[8];
 
    char box;
    bool result;
    int numPlayers;

    int maxScore = 0;
    int maxScoreId = 0;
    
    deck.build();
    deck.shuffle();

    std::cout << "How many players are playing the game? " << std::endl;
    std::cin >> numPlayers;

    for (int i = 0; i < 10; i++) {
        dealerTurn(dealer, deck, i, numPlayers);
        for (int j = 0; j < numPlayers; j++) {
            player[j].setId(j+1);
            playersTurn(dealer, deck, player[j], i, j+1);
        }
    }

    std::cout << "--------------------GAME IS OVER--------------------" << std::endl;
    for (int i = 0; i < numPlayers; i++) {
        std::cout << "Player " << player[i].getId() << " score is " << player[i].getPoints() << std::endl;
        if (maxScore < player[i].getPoints()) {
            maxScore = player[i].getPoints();
            maxScoreId = player[i].getId();
        }
    }
    std::cout << "Player " << maxScoreId << " wins the game!" << std::endl;
}


void Game::dealerTurn(Dealer &dealer, Deck &deck, int round, int numPlayers)
{
    int cardReceived;
    bool result;
    char box;

    dealer.takeCard(deck, numPlayers);
    dealer.turnBoardCards();
}

void Game::playersTurn(Dealer &dealer, Deck &deck, Player &player, int round, int playerId)
{
    int cardReceived;
    bool result;
    char box;

    cardReceived = dealer.dealCard();

    std::cout << "--------------------PLAYER " << playerId << "--------------------" << std::endl;

    std::cout << "Is your card in between? [y/n]" << std::endl;
    std::cin >> box;

    result = dealer.checkBetween(cardReceived);
    
    if ((result && box == 'y') || (!result && box == 'n')) {
        std::cout << "You got it!" << std::endl;
        player.addPoints();
        }
    else std::cout << "Wrong!" << std::endl;

    std::cout << "Your card was -> " << cardReceived << std::endl;
    std::cout << "Score for player " << playerId << " after round " << round + 1 << " is " << player.getPoints() << std::endl;
    
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