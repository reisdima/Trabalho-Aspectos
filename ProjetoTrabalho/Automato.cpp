#include "Automato.h"
#include <list>

Automato::Automato()
{
    //ctor
}

Automato::~Automato()
{
    //dtor
}

void Automato::setAlfabeto(string expressao){
    list<char>::iterator it;
    for(int i = 0; i < expressao.length(); i++){
        if(expressao[i] != '+' && expressao[i] != '.' && expressao[i] != '*'){
            alfabeto.push_back(expressao[i]);
        }
    }
    alfabeto.sort();
    alfabeto.unique();

}


