#include "Tag.h"
#include <stack>


Tag::Tag(string tag)
{
    primeiro  = NULL;

}

Tag::~Tag()
{
    //dtor
}

void Tag::InserirElemento(string a, string b){
    ElementoTag *elemento1 = new ElementoTag(a);
    ElementoTag *elemento2 = new ElementoTag(b);

    elemento1->SetProx(elemento2);
    if(primeiro == NULL){
        primeiro = elemento1;
    }
    else{
        ElementoTag *aux = primeiro;
        while(aux->GetProx() != NULL)
            aux = aux->GetProx();
        aux->SetProx(elemento1);
    }
}

void Tag::PrintTag(){
    ElementoTag *aux = primeiro;
    while(aux != NULL){
        cout << aux->GetValor() << "  ";
        aux = aux->GetProx();
    }
    cout << endl;
}

void Tag::CriarTag(string tag){
    stack<string> pilha;
    int i = 0;
    while(tag[i] != '\0'){
        if(tag[i] == '+'){
            if(!pilha.empty()){

                string a = pilha.top();
                pilha.pop();
                string b = pilha.top();
                pilha.pop();
                InserirElemento(a, b);

            }
        }
        else if(tag[i] == '*'){

        }
        else{
            string aux = "";
            aux += tag[i];
            pilha.push(aux);
        }
        i++;
    }
}
