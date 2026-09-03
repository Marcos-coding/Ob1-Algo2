#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

template <typename T> class AVL {
    public: 
        class Nodo {
            public:
                Nodo(T unValor) : valor(unValor), izq(NULL), der(NULL), altura(1) {};
        }

        AVL(): raiz(NULL){};

        int calcularBalance(Nodo* raiz){
            int alturaIzquierda = (raiz->izq) : raiz->izq->altura ? 0;
            int alturaDerecha = (raiz->der) : raiz->der->altura ? 0;
            return alturaDerecha - alturaIzquierda;
        }

        void actualizarAltura(Nodo* raiz){
            if(raiz != NULL){
                int alturaIzquierda = (raiz->izq) : raiz->izq->altura ? 0;
                int alturaDerecha = (raiz->der) : raiz->der->altura ? 0;
                raiz->altura = max(alturaIzquierda, alturaDerecha) + 1;
            }
        }

        Nodo* rotarIzquierda(Nodo* A, Nodo* B){
            //A es el padre, B es el hijo derecho
            A->der = B->izq;
            B->izq = A;
            actualizarAltura(B);

            return B;
        }

        Nodo* rotarDerecha(Nodo* A, Nodo* B){
            //A es el padre, B es el hijo izquierdo
            A->izq = B->der;
            B->der = A;
            actualizarAltura(B);

            return B;
        }

        void insertar(AVL arb, T valor){
            insertarNodo(arb->raiz, valor);
        }

        void insertarNodo(Nodo* raiz, T valor){
            if(raiz == NULL){
                raiz = Nodo(valor);
            }
            else if(raiz->valor > valor){
                insertarNodo(raiz->izq, valor);
            }
            else if(raiz->valor < valor){
                insertarNodo(raiz->der, valor)
            }
            else if(raiz->valor == valor){
                return;
            }

            int balance = calcularBalance(raiz);


            if(balance < 1){
                //izq-izq
                if(valor < raiz->valor){
                    raiz = rotarDerecha(raiz, raiz->izq);
                }
                //izq-der
                else if(valor > raiz->valor){
                    raiz->izq = rotarIzquierda(raiz->izq, raiz->izq->der);
                    raiz = rotarDerecha(raiz, raiz->izq);
                }
            }
            else if(balance > 1){
                //der-izq
                if(valor < raiz->valor){
                    raiz->der = rotarDerecha(raiz->der, raiz->der->izq);
                    raiz = rotarIzquierda(raiz, raiz->der);
                }
                //der-der
                else if(valor > raiz->valor){
                    raiz = rotarIzquierda(raiz, raiz->der);
                }
            }
        }

        bool buscar(AVL arb, T valor){
            return buscarNodo(arb->raiz, valor);
        }

        bool buscarNodo(Nodo* raiz, T valor){
            if(raiz == NULL){
                return false;
            }
            else if(valor < raiz->valor){
                return buscarNodo(raiz->izq, valor);
            }
            else if(valor > raiz->valor){
                return buscarNodo(raiz->der, valor);
            }
            return valor == raiz->valor;
        }

        void rango(AVL arb, T valorMin, T valorMax){
            imprimirRango(arb->raiz, valorMin, valorMax);
        }

        void imprimirRango(Nodo* raiz, T min, T max){
            if(raiz != NULL){
                if(min < raiz->valor){
                    imprimirRango(raiz->izq, min, max);
                }
                
                cout << raiz->valor << endl;

                if(max > raiz->valor){
                    imprimirRango(raiz->der, min, max);                    
                }
            }
        }
};


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