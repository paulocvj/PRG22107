#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

class Player
{
    public:
        void addPoints();
        int getPoints();
        int getId();
        void setId(int i);
    private:
        int points = 0;
        int id;
};

#endif