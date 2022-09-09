#ifndef DICE_H_
#define DICE_H_

#include <iostream>

using namespace std;

class Dice
{
    private:
        int faceValue;
    public:
        Dice();
        void roll();
        int FaceValue();
        void FaceValue(int value);
};

class DiceGame
{
    private:
        Dice die1;
        Dice die2;
    public:
        int play();
};

#endif