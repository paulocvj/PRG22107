#include <iostream>
#include <chrono>

//#define SHOW_RESULTS // Mostra os resultados a cada jogo (não usar junto com DEBUG)
#define DEBUG  // DEBUG faz o teste de 10 milhões de iterações

using namespace std;

class Dice
{
    private: 
        int faceValue;
    public:
        Dice() {
            srand(time(NULL));
            roll();
            cout << this << " with a value of " << faceValue << endl; // this mostra o endereço 
        }
        void roll() {
            faceValue = (rand() % 6) + 1;
        }
        int FaceValue(){ 
            return faceValue; // getter method
        }
        void FaceValue(int value){
            if ((value > 0) && (value < 7)) faceValue = value; // setter method 
        }
};

class DiceGame
{
    private:
        Dice dice1;
        Dice dice2;
    public:
        int play()
        {
            dice1.roll();
            dice2.roll();
            int die1 = dice1.FaceValue();
            int die2 = dice2.FaceValue();
#ifdef SHOW_RESULTS
            cout << "Rolls: " << endl << "Dice 1 -> " << die1 << endl << "Dice 2 -> " << die2 << endl;
#endif
            return die1 + die2;
        }
};

int main()
{
    DiceGame game;
    int result = game.play();
    
    cout << "Dice game" << endl;

    cout << (result == 7 ? "Won " : "Lost ") << "with a roll of " << result << endl;

#ifdef DEBUG
    auto start = chrono::steady_clock::now();

    const int i = 10000000;
    int wins = 0;

    cout << "Benchmark: " << i << " games" << endl;

    for (int x = 0; x < i; x++)
    {
        result = game.play();
        if (result == 7) wins += 1;
    }
    auto end = chrono::steady_clock::now();

    cout << i << " Games with " << wins << " wins. " << endl;
    cout << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" << endl;
#endif

    return 0;
}