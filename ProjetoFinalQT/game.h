#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <QLabel>
#include <QGridLayout>
#include <QThread>
#include <tuple>
#include <QPushButton>
#include <string>

#include "cards.h"
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

        QGridLayout * grid = new QGridLayout;

        QPushButton * btnYes = new QPushButton;
        QPushButton * btnNo = new QPushButton;
        QPushButton * confirm = new QPushButton;
        QPushButton * start = new QPushButton;

        QLabel * text = new QLabel;
        QLabel * turn = new QLabel;
        QLabel * card1 = new QLabel;
        QLabel * card2 = new QLabel;
        QLabel * points = new QLabel;
        QLabel * yourCard = new QLabel;

/* ----- Game functions ----- */
        void nextTurn();
        int getRound();
        bool playersTurn(Player player, Dealer dealer, Deck deck);
/* -------------------------- */
/* ----- Config functions ----- */
        QString displayCard(int card);
        void hideWidgets();
        void showWidgets();
        void configWidgets();
        void endGame();
/* ---------------------------- */

    private:
        int cardReceived;
        int round = 1;
};

#endif
