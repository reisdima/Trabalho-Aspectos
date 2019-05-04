#include "Tag.h"
#include <stack>


Tag::Tag(string tag)
{
    primeiro  = NULL;
    stack<string> pilha;
    int i = 0;
    while(tag[i] != '\0'){
        if(tag[i] == '+'){
            if(!pilha.empty()){
                string a = pilha.top();
                pilha.pop();
                string b = pilha.top();
                InserirElemento(a, b);
                i++;
            }
        }
        else if(tag[i] == '*'){

        }
        else{

        }
    }
}

Tag::~Tag()
{
    //dtor
}

void Tag::InserirElemento(string a, string b){
    ElementoTag *first = new ElementoTag(a);
    ElementoTag *second = new ElementoTag(b);

    first->SetProx(second);
    if(primeiro == NULL){
        primeiro = first;
    }
    else{
        ElementoTag *aux = primeiro;
        while(aux->GetProx() != NULL)
            aux = aux->GetProx();
        aux->SetProx(first);
    }
}
