#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <QLabel>
#include <QGridLayout>
#include <QThread>
#include <tuple>
#include <QPushButton>

#include "deck.h"
#include "dealer.h"
#include "player.h"

class Game : public QWidget {
    Q_OBJECT

    public:
        Game(QWidget *parent = nullptr);
        Cards * cards;
        Deck * deck;
        Dealer * dealer;
        Player * player;


        QGridLayout * grid;

        QPushButton * btnYes;
        QPushButton * btnNo;
        QPushButton * confirm;
        QPushButton * start;

        QLabel * text;
        QLabel * turn;
        QLabel * card1;
        QLabel * card2;
        QLabel * points;


        void init();
        std::tuple<int, int> dealerTurn(Dealer dealer, Deck deck);
        bool playersTurn(Player player, Dealer dealer, Deck deck);
        void nextTurn();
        int getRound();

        void startGame();
        void enableStart();

    private:
        int cardReceived;
        int round = 1;
};

#endif
