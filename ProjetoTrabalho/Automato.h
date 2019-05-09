#ifndef AUTOMATO_H
#define AUTOMATO_H
#include <iostream>
#include <list>
#include "Transicao.h"

using namespace std;

class Automato
{
public:
    Automato(string tag, string expressao);
    ~Automato();
    void ReconheceAlfabeto();
    bool ValidaExpressao();

    void ExibirAlfabeto();
    string GetExpressao();
    string GetTag();

private:
    string tag;
    string expressao;
    list<char> alfabeto;
    list<string> conjuntoEstados;
    string estadoInicial;
    string nomeTag;
    list<Transicao> conjuntoTransicao;


};

#endif // AUTOMATO_H
