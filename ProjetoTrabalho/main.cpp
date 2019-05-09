#include <iostream>
#include <string> //string
#include <stack> //pilha
#include <list> // lista
#include <fstream> // arquivo
#include "Tag.h"
#include "Automato.h"

using namespace std;



// Cria��o de Tag

void CriaTag(string str, list<Automato> *listaAutomatos){
    int i = 0;
    string tag = "";
    string expressao = "";
    while(str[i] != ':' && str[i] != '\0'){
        tag = tag + str[i];
        i++;
    }
    //Inseriu uma tag
    if(str[i] == ':'){
        i++;
        if(str[i] == ' '){
            i++;
            // Teste: cout << "TAG: " << tag << endl;

            while(str[i] != '\0'){
                expressao += str[i];
                i++;
            }
            // Teste: cout << "Expressao regular:" << expressao << endl;

        }
    }
    Automato* automato = new Automato(tag, expressao);
    if(automato->ValidaExpressao()){
        cout << "[INFO] A expressao " << tag << ": " << expressao << " eh valida." << endl;
        listaAutomatos->push_back(*automato);
    }
    else{
        cout << "[ERRO] A expressao " << tag << ": " << expressao << " nao eh valida." << endl;
        //apagar automato criado
    }
}


int main()
{

    fstream arquivo;
    list<Automato> listaAutomatos;

    string str = "";

// Reconhecimento dos comandos ":"

    while(true){
        int i = 0;
        getline(cin, str);
        //Teste: cout << str << endl << endl;

        if(str[i] == ':'){
            i++;

            //realiza a divis�o em tags da string do arquivo informado

            if(str[i] == 'f'){
                i++;
                if(str[i] == ' '){
                    i++;
                    string path = ""; //nome do arquivo
                    while(str[i] != '\0'){
                        path += str[i];
                        i++;
                    }
                    arquivo.open(path.c_str());
                    if(arquivo.is_open()){
                        //Execu��o se o arquivo abriu
                        //Teste: cout << "Arquivo abriu" << endl;

                    }
                    else{

                        //Erro ao tentar abrir o arquivo
                    }

                }
            }
            //carrega um arquivo com defini��es de tags
            else if(str[i] == 'l'){
                i++;
                if(str[i] == ' '){
                    i++;
                    string aux = ""; //nome do arquivo
                    while(str[i] != '\0'){
                        aux += str[i];
                        i++;
                    }
                    if(aux == ""){
                      cout << "[WAR] Operacao incompleta" << endl;
                    }
                    else{
                        arquivo.open(aux.c_str());
                        if(arquivo.is_open()){
                            //Execu��o se o arquivo abriu
                            //cout << "Arquivo abriu" << endl;
                            while(!arquivo.eof()){

                                getline(arquivo, aux);
                                CriaTag(aux, &listaAutomatos);
                            }
                            arquivo.close();


                        }
                        else{
                            cout << "[ERRO] O arquivo nao foi encontrado." << endl;
                        }
                    }
                }
            }
            //especifica o caminho do arquivo de sa�da para a divis�o em tags
            else if(str[i] == 'o'){
                i++;
                if(str[i] == ' '){
                    i++;
                    string path = ""; //nome do arquivo
                    while(str[i] != '\0'){
                        path += str[i];
                        i++;
                    }
                    arquivo.open(path.c_str(), fstream::out);
                    if(arquivo.is_open()){
                        //Execu��o se o arquivo abriu
                        // teste: cout << "Arquivo abriu" << endl;
                    }
                    else{
                        //Erro ao tentar abrir o arquivo
                    }
                }
            }
            //realiza a divis�o em tags da entrada informada
            else if(str[i] == 'p'){


            }
            //Sair do programa
            else if(str[i] == 'q'){
                i++;
                if(str[i] == '\0'){
                    cout << "[INFO] Saindo do programa" << endl;
                    break;
                }
            }
            //salvar as tags
            else if(str[i] == 's'){
                i++;
                if(str[i] == ' '){
                    i++;
                    string aux = ""; //nome do arquivo
                    while(str[i] != '\0'){
                        aux += str[i];
                        i++;
                    }
                    if(aux == ""){
                        cout << "[WAR] Operacao incompleta" << endl;
                    }
                    else{
                        cout << "[INFO] Arquivo criado: " << aux << endl;
                        arquivo.open(aux.c_str(), fstream::out);
                        if(arquivo.is_open()){
                            //Execu��o se o arquivo abriu
                            // Teste: cout << "Arquivo abriu" << endl;
                            list<Automato>::iterator it;
                            for(it = listaAutomatos.begin(); it != listaAutomatos.end(); it++){
                                string tag = it->GetTag();
                                aux = it->GetExpressao();
                                //Teste: cout << "Aux: " << aux << endl;
                                arquivo << tag << ": " << aux << "\n";
                            }
                            arquivo.close();
                        }
                        else{
                            cout << "[ERRO] Erro ao criar arquivo" << endl;
                        }
                    }
                }
            }
            else{
                cout << "[ERRO] Operacao nao reconhecida." << endl;
            }

        }
        //Cria��o de Tags
        else{
            CriaTag(str, &listaAutomatos);
        }

    }

    return 0;
}
