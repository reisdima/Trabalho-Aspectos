#include <iostream>
#include <string> //string
#include <stack> //pilha

using namespace std;

int main()
{


    string str = "teste oi";
    stack<char> pilha;
    while(true){
        getline(cin, str);
        cout << str << endl;

        if(str[0] == ':'){

            //realiza a divis�o em tags da string do arquivo informado
            if(str[1] == 'f'){
                cout << "teste" << endl;
            }
            //carrega um arquivo com defini��es de tags
            else if(str[1] == 'l'){

            }
            //especifica o caminho do arquivo de sa�da para a divis�o em tags
            else if(str[1] == 'o'){

            }
            //realiza a divis�o em tags da entrada informada
            else if(str[1] == 'p'){

            }
            //Sair do programa
            else if(str[1] == 'q'){
                cout << "Saiu do programa" << endl;
                break;
            }
            //salvar as tags
            else if(str[1] == 's'){

            }

        }
        //Cria��o de Tags
        else{
            int i = 0;
            string tag = "";
            while(str[i] != ':' && str[i] != '\0'){
                tag = tag + str[i];
                i++;
            }
            cout << "TAG: " << tag << endl;
        }

    }
    return 0;
}
