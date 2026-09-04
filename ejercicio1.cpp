#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "AVL.h"

using namespace std;


int main()
{
    AVL<int> catalogoMonedas();
    AVL<std::string> titulosPinturas();


    int n;
    cin >> n;
    std::string op;

    for(int i = 0; i < n; i++){
        cin >> op;

        int primerInd = op.find(' ');
        int segundoInd = op.find(' ', primerInd);
        std::string nombre = op.substr(0, primerInd);
        std::string tipo = op.substr(primerInd + 1, 1);
        std::string entrada = op.substr(segundoInd + 1);

        if(nombre == "ALTA"){
            
        }
        else if(nombre == "BUSCAR"){

        }
        else if(nombre == "RANGO"){

        }
    }


    return 0;
}