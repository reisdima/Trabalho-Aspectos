#ifndef ELEMENTOTAG_H
#define ELEMENTOTAG_H
#include <iostream>
#include <string> //string
#include <stack> //pilha
using namespace std;

class ElementoTag
{

public:
    ElementoTag(string valor);
    ~ElementoTag();

    void SetProx(ElementoTag *p);
    ElementoTag* GetProx();

private:
    string valor;
    ElementoTag *prox;

};

#endif // ELEMENTOTAG_H
