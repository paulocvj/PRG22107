#include <iostream>
#include "cards.h"

void Cards::printCards()
{
    std::string cast;
        for (int i = PAUS; i <= OURO; i++)
        {
            if (i == PAUS) cast = "paus";
            else if (i == COPAS) cast = "copas";
            else if (i == ESPADAS) cast = "espadas";
            else if (i == OURO) cast = "ouro";
            for (int j = DOIS; j <= AS; j++)
            {
                std::cout << j << " de " << cast << std::endl; 
            }
        }
}

