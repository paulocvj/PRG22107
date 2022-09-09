#include <iostream>
#include "dice.h"

using namespace std;

int main()
{
    DiceGame game;

    int result = game.play();

    cout << "Dice game!" << endl;
    cout << (result == 7 ? "Won" : "Lost") << " with a roll of " << result << endl;

    return 0;    
}