#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

template <typename T> class AVL {
    public: 
        class Nodo {
            public:
                Nodo *izq, *der;
                T valor;
                
                Nodo(T unValor){
                  valor = unValor;
                  izq = NULL; 
                  der = NULL;
                };
        }


};


int main()
{
    return 0;
}