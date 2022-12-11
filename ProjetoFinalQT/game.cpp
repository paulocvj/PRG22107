#include <QtWidgets>
#include <tuple>
#include <iostream>
#include <QObject>
#include "game.h"

Game::Game(QWidget *parent)
    : QWidget(parent) {

    QWidget * window = new QWidget();
    window->resize(800,600);

    grid = new QGridLayout;

    btnYes = new QPushButton;
    btnNo = new QPushButton;
    confirm = new QPushButton;
    start = new QPushButton;

    text = new QLabel;
    turn = new QLabel;
    card1 = new QLabel;
    card2 = new QLabel;
    points = new QLabel;

    /* Label defs */
    points->setText("Points: ");
    text->setText("Is your card in between?");
    card1->setText("");
    card2->setText("");

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
    start->setGeometry(470, 430, 200, 90);

    /* Grid defs */
    grid->addWidget(text, 0, 2);
    grid->addWidget(points, 0, 3);
    grid->addWidget(turn, 0, 0);
    grid->addWidget(card1, 1, 1);
    grid->addWidget(start, 1, 2);
    grid->addWidget(card2, 1, 3);
    grid->addWidget(btnYes, 2, 0);
    grid->addWidget(btnNo, 2, 4);
    grid->addWidget(confirm, 2, 2);
    grid->setSpacing(30);
    grid->setSizeConstraint(QLayout::SetMaximumSize);

/* Creates all the objects for the game */
    player = new Player();
    deck = new Deck();
    dealer = new Dealer();
    cards = new Cards();

    deck->build();
    deck->shuffle();
    deck->printDeck();

    text->setVisible(false);
    turn->setVisible(false);
    card1->setVisible(false);
    card2->setVisible(false);
    btnYes->setVisible(false);
    btnNo->setVisible(false);
    confirm->setVisible(false);
    points->setVisible(false);

    connect(start, &QPushButton::released, [=]{
        text->setVisible(true);
        turn->setVisible(true);
        card1->setVisible(true);
        card2->setVisible(true);
        btnYes->setVisible(true);
        btnNo->setVisible(true);
        confirm->setVisible(true);
        start->setVisible(false);
        points->setVisible(true);
        window->resize(800,600);
//        auto [aCard, bCard] = dealerTurn(*dealer, *deck);
        dealer->takeCard(*deck);
        deck->popArr();
        card1->setText(QString::number(dealer->dealFirstCard()));
        deck->popArr();
        card2->setText(QString::number(dealer->dealSecondCard()));
        deck->popArr();
        turn->setText("Rodada " + QString::number(round));
    });

    connect(btnYes, &QPushButton::released, [=] {
        player->setAnswer(true);
    });

    connect(btnNo, &QPushButton::released, [=] {
        player->setAnswer(false);
    });

    connect(confirm, &QPushButton::released, [=]{
        if (playersTurn(*player, *dealer, *deck))
            player->addPoints();
        dealer->takeCard(*deck);
        deck->popArr();
        points->setText("Points: " + QString::number(player->getPoints()));
        card1->setText(QString::number(dealer->dealFirstCard()));
        deck->popArr();
        card2->setText(QString::number(dealer->dealSecondCard()));
        deck->popArr();
        nextTurn();
        turn->setText("Rodada " + QString::number(round));

        btnYes->setChecked(false);
        btnNo->setChecked(false);

        if (getRound() > 10)
        {
            btnYes->hide();
            btnNo->hide();
            confirm->hide();
            window->setLayout(grid);
        }
    });




    window->setLayout(grid);
    window->show();
}


std::tuple<int, int> Game::dealerTurn(Dealer dealer, Deck deck)
{
    int cardReceived;
    bool result;
    char box;

    dealer.takeCard(deck);
    return {dealer.turnBoardCards(), dealer.turnBoardCards()};
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
    std::cout << "getcard -> " << player.getCard() << std::endl;
    std::cout << "getanswer -> " << player.getAnswer() << std::endl;
    std::cout << dealer.checkBetween(player.getCard(), player.getAnswer()) << std::endl;
    return dealer.checkBetween(player.getCard(), player.getAnswer());
}
