#ifndef CARDS_H_
#define CARDS_H_

#include <iostream>

class Cards {
    public:
        enum suits
        {
            PAUS = 0,
            COPAS,
            ESPADAS,
            OURO
        };

        enum values
        {
            DOIS = 2,
            TRES,
            QUATRO,
            CINCO,
            SEIS,
            SETE,
            OITO,
            NOVE,
            DEZ,
            VALETE,
            DAMA,
            REI,
            AS
        };

        void printCards();
};

#endif
