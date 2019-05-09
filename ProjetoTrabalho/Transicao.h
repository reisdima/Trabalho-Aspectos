#ifndef TRANSICAO_H
#define TRANSICAO_H
#include <iostream>
#include <string>

using namespace std;

class Transicao
{
public:
    Transicao();
    ~Transicao();

private:
    char simbolo;
    string estadoInicial;
    string estadoFinal;
};

#endif // TRANSICAO_H
