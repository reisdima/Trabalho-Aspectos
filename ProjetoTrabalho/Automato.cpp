#include "Automato.h"
#include <list>
#include <stack>

Automato::Automato(string expressao)
{
    this->expressao = expressao;
    SetAlfabeto();
    //bool a = ValidaExpressao();
    ExibirAlfabeto();


}

Automato::~Automato()
{
    //dtor
}

void Automato::SetAlfabeto(){
    list<char>::iterator it;
    for(int i = 0; i < expressao.length(); i++){
        if(expressao[i] != '+' && expressao[i] != '.' && expressao[i] != '*'){
            alfabeto.push_back(expressao[i]);
        }
    }
    alfabeto.sort();
    alfabeto.unique();

}

bool Automato::ValidaExpressao(){
    stack<string> pilha;
    int i = 0;
    bool valida = true;

    while(expressao[i] != '\0'){
        cout << expressao[i] << " ";
        string aux = "";
        aux += expressao[i];
        if(aux != "+" && aux != "." && aux != "*"){
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
            pilha.push(a+"+"+b);
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
            pilha.push(a+"."+b);
        }
        else if(aux == "*"){
                cout << "teste" << endl;
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
    cout << endl;
    string expressao2;
    if(!pilha.empty()){
        expressao2 = pilha.top();
        pilha.pop();
    }
    if(pilha.empty() && valida){
            cout << "Expressao: " << expressao2 << endl;
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
