#ifndef AUTOMATO_H
#define AUTOMATO_H
#include <iostream>
#include <list>
#include "Transicao.h"

using namespace std;

class Automato
{
public:
    Automato(string expressao);
    ~Automato();
    void SetAlfabeto();
    bool ValidaExpressao();

    void ExibirAlfabeto();
    string GetExpressao();

private:
    string expressao;
    list<char> alfabeto;
    list<string> conjuntoEstados;
    string estadoInicial;
    string nomeTag;
    list<Transicao> conjuntoTransicao;


};

#endif // AUTOMATO_H
