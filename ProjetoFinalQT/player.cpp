#include "player.h"

int Player::getPoints()
{
    return points;
}

void Player::addPoints()
{
    points += 10;
}

int Player::getId()
{
    return id;
}

void Player::setId(int i)
{
    id = i;
}

void Player::setCard(int i)
{
    card = i;
}

int Player::getCard()
{
    return card;
}

void Player::setAnswer(bool res)
{
    result = res;
}

bool Player::getAnswer()
{
    return result;
}
