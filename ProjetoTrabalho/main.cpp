#include <iostream>
#include <string> //string
#include <stack> //pilha
#include <list>
#include <fstream>
#include "Tag.h"
#include "Automato.h"

using namespace std;

int main()
{


/*
    string str;
    getline(cin, str);
    Tag *tag = new Tag(str);
    tag->PrintTag();*/


    fstream arquivo;


    string str = "teste oi";

    while(true){
        int i = 0;
        getline(cin, str);
        cout << str << endl << endl;

        if(str[i] == ':'){
            i++;

            //realiza a divisão em tags da string do arquivo informado
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
                        //Execução se o arquivo abriu
                        cout << "Arquivo abriu" << endl;

                    }
                    else{
                        //Erro ao tentar abrir o arquivo
                    }

                }
            }
            //carrega um arquivo com definições de tags
            else if(str[i] == 'l'){
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
                        //Execução se o arquivo abriu
                        cout << "Arquivo abriu" << endl;
                    }
                    else{
                        //Erro ao tentar abrir o arquivo
                    }
                }
            }
            //especifica o caminho do arquivo de saída para a divisão em tags
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
                        //Execução se o arquivo abriu
                        cout << "Arquivo abriu" << endl;
                    }
                    else{
                        //Erro ao tentar abrir o arquivo
                    }
                }
            }
            //realiza a divisão em tags da entrada informada
            else if(str[i] == 'p'){

#include <iostream>

using namespace std;
            }
            //Sair do programa
            else if(str[i] == 'q'){
                i++;
                if(str[i] == '\0'){
                    cout << "Saiu do programa" << endl;
                    break;
                }
            }
            //salvar as tags
            else if(str[i] == 's'){
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
                        //Execução se o arquivo abriu
                        cout << "Arquivo abriu" << endl;
                    }
                    else{
                        //Erro ao tentar abrir o arquivo
                    }
                }
            }

        }
        //Criação de Tags
        else{
            int i = 0;
            string tag = "";
            while(str[i] != ':' && str[i] != '\0'){
                tag = tag + str[i];
                i++;
            }
            //Inseriu uma tag
            if(str[i] == ':'){
                i++;
                if(str[i] == ' '){
                    cout << "TAG: " << tag << endl;
                    string expressao = "";
                    while(str[i] != '\0'){
                        expressao += str[i];
                        i++;
                    }
                    cout << "Expressao regular:  " << expressao << endl;
                    Automato* teste = new Automato();
                    teste->setAlfabeto(expressao);
                }
            }

        }

    }

    return 0;
}
