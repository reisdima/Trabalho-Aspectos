#ifndef CONJUNTOTRANSICOES_H
#define CONJUNTOTRANSICOES_H
#include <iostream>

using namespace std;


class ConjuntoTransicoes
{
    public:
        ConjuntoTransicoes();
        ~ConjuntoTransicoes();



    private:
        string simbolos[];
        string estadoOrigem[];
        string estadoDestino[];
};

#endif // CONJUNTOTRANSICOES_H
