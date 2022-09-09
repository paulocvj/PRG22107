#include <iostream>
#include "dice.h"

using namespace std;

Dice::Dice()
{
    srand(time(NULL));
    roll();
    cout << this << " with a value of " << faceValue << endl; // this mostra o endereço 
}

void Dice::roll()
{
    faceValue = (rand() % 6) + 1;
}

int Dice::FaceValue()
{
    return faceValue;
}

void Dice::FaceValue(int value)
{
    if (value > 0 && value < 7) faceValue = value;
}

int DiceGame::play()
{
    die1.roll();
    die2.roll();

    cout << "Die 1 has rolled -> " << die1.FaceValue() << endl << "Die 2 has rolled -> " << die2.FaceValue() << endl;

    return die1.FaceValue() + die2.FaceValue();
}