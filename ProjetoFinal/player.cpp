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