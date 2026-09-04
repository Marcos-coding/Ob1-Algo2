#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AVL.h"
#include "tads/AVL.cpp"

using namespace std;


int main()
{
    AVLImp<long long>* catalogoMonedas = new AVLImp<long long>();
    AVLImp<std::string>* titulosPinturas = new AVLImp<std::string>();


    long n;
    cin >> n;
    std::string operacion;
    std::string tipo;
    std::string entrada, entrada2;
    std::string esta;

    for(long i = 0; i < n; i++){
        cin >> operacion;
        cin >> tipo;
        cin >> entrada;

        if(operacion == "RANGO"){
            //lectura de la segunda entrada en la linea
            cin >> entrada2;
        }

        if(tipo == "M"){ 
            if(operacion == "ALTA"){
                long long entradaNum = std::stoll(entrada); 
                catalogoMonedas->insertar(entradaNum);
            }
            else if(operacion == "BUSCAR"){
                long long entradaNum = std::stoll(entrada); 
                esta = (catalogoMonedas->buscar(entradaNum)) ? "si" : "no";
                cout << esta << endl;
            }
            else if(operacion == "RANGO"){
                long long primero = std::stoll(entrada);
                long long segundo = std::stoll(entrada2);
                catalogoMonedas->rango(primero, segundo);
            }
        }
        else if(tipo == "P"){
            if(operacion == "ALTA"){ 
                titulosPinturas->insertar(entrada);
            }
            else if(operacion == "BUSCAR"){
                esta = (titulosPinturas->buscar(entrada)) ? "si" : "no";
                cout << esta << endl;
            }
            else if(operacion == "RANGO"){
                titulosPinturas->rango(entrada, entrada2);
            }
        }
    }


    return 0;
}