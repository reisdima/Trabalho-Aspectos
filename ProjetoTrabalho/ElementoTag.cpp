#include "ElementoTag.h"

ElementoTag::ElementoTag(string valor)
{
    this->valor = valor;
    prox = NULL;
}

ElementoTag::~ElementoTag()
{
    //dtor
}

void ElementoTag::SetProx(ElementoTag *p){
    prox = p;
}

ElementoTag* ElementoTag::GetProx(){
    return prox;
}


string ElementoTag::GetValor(){
    return valor;
}
