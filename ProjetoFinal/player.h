#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

class Player
{
    public:
        void addPoints();
        int getPoints();
    private:
        int points = 0;
};

#endif