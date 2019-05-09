#include "Automato.h"
#include <list>
#include <stack>

Automato::Automato(string tag, string expressao)
{
    this->tag = tag;
    this->expressao = expressao;
    ReconheceAlfabeto();


}

Automato::~Automato()
{
    //dtor
}

void Automato::ReconheceAlfabeto(){
    list<char>::iterator it;
    for(int i = 0; i < expressao.length(); i++){
        if(expressao[i] != '+' && expressao[i] != '.' && expressao[i] != '*' && expressao[i] != '\\'){
            alfabeto.push_back(expressao[i]);
        }
    }
    alfabeto.sort();
    alfabeto.unique();

}
// função para verificar se a expressão é válida

bool Automato::ValidaExpressao(){
    stack<string> pilha;
    int i = 0;
    bool valida = true;

    while(expressao[i] != '\0'){
        string aux = "";
        aux += expressao[i];
        if(aux == "\\"){

        }
        else if(aux != "+" && aux != "." && aux != "*"){
            pilha.push(aux);
        }
        else if(aux == "+"){
            string a;
            string b;
            if(!pilha.empty()){
                a = pilha.top();
                pilha.pop();
            }
            else{
                valida = false;
                break;
            }

            if(!pilha.empty()){
                b = pilha.top();
                pilha.pop();
            }
            else{
                valida = false;
                break;
            }
            pilha.push(b+"+"+a);
        }
        else if(aux == "."){
            string a;
            string b;
            if(!pilha.empty()){
                a = pilha.top();
                pilha.pop();
            }
            else{
                valida = false;
                break;
            }

            if(!pilha.empty()){
                b = pilha.top();
                pilha.pop();
            }
            else{
                valida = false;
                break;
            }
            pilha.push(b+"."+a);
        }
        else if(aux == "*"){
            string a;
            if(!pilha.empty()){
                a = pilha.top();
                pilha.pop();
            }
            else{
                valida = false;
                break;
            }
            pilha.push("("+a+")*");
        }
        i++;
    }
    string expressao2;
    if(!pilha.empty()){
            // Teste: cout << expressao2 << endl;
        expressao2 = pilha.top();
        pilha.pop();
    }
    if(pilha.empty() && valida){
            //Teste: cout << "Expressao: " << expressao2 << endl;
        return true;
    }
    else{
        return false;
    }
}

void Automato::ExibirAlfabeto(){
    list<char>::iterator it;
    for(it = alfabeto.begin(); it != alfabeto.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

string Automato::GetExpressao(){
    return expressao;
}

string Automato::GetTag(){
    return tag;
}
