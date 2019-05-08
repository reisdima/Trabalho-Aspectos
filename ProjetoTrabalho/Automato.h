#ifndef AUTOMATO_H
#define AUTOMATO_H
#include <iostream>
#include <list>

using namespace std;

class Automato
{
    public:
        Automato();
        ~Automato();
        void setAlfabeto(string expressao);



    private:
        list<char> alfabeto;
        string conjuntoEstados[];
        string estadoInicial[];
        string tag;

};

#endif // AUTOMATO_H
