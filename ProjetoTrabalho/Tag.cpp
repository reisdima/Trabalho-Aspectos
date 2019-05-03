#include "Tag.h"
#include <stack>

Tag::Tag(string tag)
{
    primeiro  = NULL;
    stack<string> pilha;
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == '+'){
            if(!pilha.empty()){
                string a = pilha.top();
                pilha.pop();
                string b = pilha.top();
                InserirElemento(a, b);
                i++;
            }
        }
        else if(str[i] == '*'){

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
    ElementoTag *a = new ElementoTag(a);
    ElementoTag *b = new ElementoTag(b);

    a->SetProx(b);
    if(primeiro == NULL){
        primeiro = a;
    }
    else{
        ElementoTag *aux = primeiro;
        while(aux->GetProx() != NULL)
            aux = aux->GetProx();
        aux->SetProx(a);
    }
}
