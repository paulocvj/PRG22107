#include <iostream>
#include <random>
#include <algorithm>
#include <array>

#include "cards.h"
#include "deck.h"

Deck::Deck()
{
    Cards cards;
    build();
}

void Deck::build()
{
    Cards cards;
    Cards::suits suits;
    Cards::values values;
    
    int index;
    std::string cast;

    std::cout << "Building deck" << std::endl;
    
    for (int i = Cards::PAUS; i <= Cards::OURO; i++){
        if (i == Cards::PAUS) cast = "paus";
        else if (i == Cards::COPAS) cast = "copas";
        else if (i == Cards::ESPADAS) cast = "espadas";
        else if (i == Cards::OURO) cast = "ouro";
        for (int j = Cards::DOIS; j <= Cards::AS; j++){
            index = (13*i) + j - 2;
            array[index].num = j;
            array[index].suit = cast;
        }
    }
}

void Deck::printDeck()
{
    for (int i = 0; i < 52; i++){
        std::cout << "Pos -> " << i+1 << " -> " << array[i].num << " de " << array[i].suit << std::endl; 
    }
}

void Deck::shuffle()
{
    std::random_device device;
    std::mt19937 g(device());

    std::shuffle(array.begin(), array.end(), g);
}