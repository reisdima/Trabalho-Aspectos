#ifndef AUTOMATO_H
#define AUTOMATO_H
#include <iostream>

using namespace std;

class Automato
{
    public:
        Automato();
        ~Automato();



    private:
        string alfabeto[];
        string conjuntoEstados[];
        string estadoInicial[];

};

#endif // AUTOMATO_H
