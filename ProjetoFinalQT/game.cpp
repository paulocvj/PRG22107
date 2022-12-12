#include <iostream>
#include <string>
#include <QtWidgets>
#include <QThread>

#include "game.h"

//#define DEBUG

Game::Game(QWidget *parent)
    : QWidget(parent) {

    QWidget * window = new QWidget();
    window->setStyleSheet("background.jpg");
    window->setMinimumHeight(600);
    window->setMinimumWidth(800);

    configWidgets();

/* Creates all the objects for the game */
    player = new Player();
    deck = new Deck();
    dealer = new Dealer();
    cards = new Cards();

    deck->build();
    deck->shuffle();
#ifdef DEBUG
    deck->printDeck();
#endif
    hideWidgets();

    connect(start, &QPushButton::released, [=]{
        showWidgets();

        /* Takes 3 cards, pops them all from the deck array */
        dealer->takeCard(*deck);
        deck->popArr();
        card1->setText(displayCard(dealer->dealFirstCard()));
        deck->popArr();
        card2->setText(displayCard(dealer->dealSecondCard()));
        deck->popArr();
        /* ------------------------------------------------ */

        turn->setText("Round " + QString::number(round));
    });

    connect(btnYes, &QPushButton::released, [=] {
        if (btnNo->isChecked()) btnNo->setChecked(false);
        player->setAnswer(true);
    });

    connect(btnNo, &QPushButton::released, [=] {
        if (btnYes->isChecked()) btnYes->setChecked(false);
        player->setAnswer(false);
    });

    connect(confirm, &QPushButton::released, [=]{
        yourCard->setText("Last card -> " + displayCard(dealer->dealCardPlayer()));
        /* boolean function, checks if player made the right call */
        if (playersTurn(*player, *dealer, *deck))
            player->addPoints();
        /* ------------------------------------------------------ */
        /* Takes another 3 cards and so on until round 10 */
        dealer->takeCard(*deck);
        deck->popArr();
        points->setText("Points: " + QString::number(player->getPoints()));
        card1->setText(displayCard(dealer->dealFirstCard()));
        deck->popArr();
        card2->setText(displayCard(dealer->dealSecondCard()));
        deck->popArr();
        nextTurn();
        turn->setText("Round " + QString::number(round));
        /* ------------------------------------------------------ */

        btnYes->setChecked(false);
        btnNo->setChecked(false);

        if (getRound() > 10)
        {
            endGame();
        }
    });




    window->setLayout(grid);
    window->show();
}

void Game::nextTurn()
{
    round++;
}

int Game::getRound()
{
    return round;
}

bool Game::playersTurn(Player player, Dealer dealer, Deck deck)
{
    player.setCard(dealer.dealCardPlayer());
#ifdef DEBUG
    std::cout << "getcard -> " << player.getCard() << std::endl;
    std::cout << "getanswer -> " << player.getAnswer() << std::endl;
    std::cout << dealer.checkBetween(player.getCard(), player.getAnswer()) << std::endl;
#endif
    return dealer.checkBetween(player.getCard(), player.getAnswer());
}

QString Game::displayCard(int card)
{
    QString strCard;
    if (card <= 10) strCard = QString::number(card);
    else if (card == 11) strCard = 'J';
    else if (card == 12) strCard = 'Q';
    else if (card == 13) strCard = 'K';
    else if (card == 14) strCard = 'A';

    return strCard;
}

void Game::hideWidgets()
{
    btnYes->setVisible(false);
    text->setVisible(false);
    turn->setVisible(false);
    card1->setVisible(false);
    card2->setVisible(false);
    btnNo->setVisible(false);
    confirm->setVisible(false);
    points->setVisible(false);
    yourCard->setVisible(false);
}

void Game::endGame()
{
    hideWidgets();
    points->setVisible(true);
    text->setVisible(true);
    yourCard->setVisible(true);
    turn->setVisible(true);
    turn->setText("");
    text->setText("Game is over!");
}

void Game::showWidgets()
{
    btnYes->setVisible(true);
    text->setVisible(true);
    turn->setVisible(true);
    card1->setVisible(true);
    card2->setVisible(true);
    btnNo->setVisible(true);
    confirm->setVisible(true);
    points->setVisible(true);
    yourCard->setVisible(true);
    start->setVisible(false);
}

void Game::configWidgets()
{
    /* Label defs */
    points->setText("Points: ");
    text->setText("Is your card in between?");
    card1->setText("");
    card2->setText("");
    yourCard->setText("Your card");
    points->setAlignment(Qt::AlignCenter);
    text->setAlignment(Qt::AlignCenter);
    card1->setAlignment(Qt::AlignCenter);
    card2->setAlignment(Qt::AlignCenter);
    yourCard->setAlignment(Qt::AlignCenter);

    /* Button 1 for yes creation */
    btnYes->setText("Yes");
    btnYes->setMinimumHeight(90);
    btnYes->setGeometry(90, 430, 200, 90);
    btnYes->setCheckable(true);
    /* ------------------------- */

    /* Button 2 for no creation */
    btnNo->setText("No");
    btnNo->setMinimumHeight(90);
    btnNo->setGeometry(470, 430, 200, 90);
    btnNo->setCheckable(true);
     /* ----------------------- */

    confirm->setText("Turn card");
    confirm->setMinimumHeight(90);
    confirm->setGeometry(470, 430, 200, 90);

    start->setText("START");
    start->setMinimumHeight(90);
    start->setMaximumWidth(100);

    /* Grid defs */
    grid->addWidget(text, 1, 2);
    grid->addWidget(points, 0, 4);
    grid->addWidget(turn, 0, 0);
    grid->addWidget(card1, 2, 1);
    grid->addWidget(start, 1, 2);
    grid->addWidget(card2, 2, 3);
    grid->addWidget(yourCard, 3, 2);
    grid->addWidget(btnYes, 4, 0);
    grid->addWidget(btnNo, 4, 4);
    grid->addWidget(confirm, 4, 2);
    grid->setSpacing(30);
    grid->setSizeConstraint(QLayout::SetMaximumSize);
}

