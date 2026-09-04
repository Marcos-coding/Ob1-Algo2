#ifndef AVL_H
#define AVL_H


template <class T>
class AVL {
private:
    class Nodo {
    public:
        T valor;
        int altura;
        Nodo *izq, *der;
        Nodo(T unValor) : valor(unValor), izq(NULL), der(NULL), altura(1) {};
    };

    Nodo* raiz;

    int calcularBalance(Nodo* t){
        int alturaIzquierda = (t->izq) ? t->izq->altura : 0;
        int alturaDerecha = (t->der) ? t->der->altura : 0;
        return alturaDerecha - alturaIzquierda;
    }

    void actualizarAltura(Nodo* t){
        if(t != NULL){
            int alturaIzquierda = (t->izq) ? t->izq->altura : 0;
            int alturaDerecha = (t->der) ? t->der->altura : 0;
            t->altura = std::max(alturaIzquierda, alturaDerecha) + 1;
        }
    }

    Nodo* rotarIzquierda(Nodo* A, Nodo* B){
        //A es el padre, B es el hijo derecho
        A->der = B->izq;
        B->izq = A;
        actualizarAltura(A);
        actualizarAltura(B);

        return B;
    }

    Nodo* rotarDerecha(Nodo* A, Nodo* B){
        //A es el padre, B es el hijo izquierdo
        A->izq = B->der;
        B->der = A;
        actualizarAltura(A);
        actualizarAltura(B);

        return B;
    }

    //PRE: recibe un valor
    //POS: si no está presente en el árbol, inserta el nodo con el valor y balancea
    //el árbol si es necesario. Si está presente, no hace nada
    Nodo* insertarNodo(Nodo* t, T valor){
        if(t == NULL){
            return new Nodo(valor);
        }
        else if(t->valor > valor){
            t->izq = insertarNodo(t->izq, valor);
        }
        else if(t->valor < valor){
            t->der = insertarNodo(t->der, valor);
        }
        else if(t->valor == valor){
            return t;
        }

        actualizarAltura(t);
        int balance = calcularBalance(t);


        if(balance < -1){
            //izq-izq
            if(valor < t->valor){
                return rotarDerecha(t, t->izq);
            }
            //izq-der
            else if(valor > t->valor){
                t->izq = rotarIzquierda(t->izq, t->izq->der);
                return rotarDerecha(t, t->izq);
            }
        }
        else if(balance > 1){
            //der-izq
            if(valor < t->valor){
                t->der = rotarDerecha(t->der, t->der->izq);
                return rotarIzquierda(t, t->der);
            }
            //der-der
            else if(valor > t->valor){
                return rotarIzquierda(t, t->der);
            }
        }

        return t;
    }   

    bool buscarNodo(Nodo* t, T valor){
        if(t == NULL){
            return false;
        }
        else if(valor < t->valor){
            return buscarNodo(t->izq, valor);
        }
        else if(valor > t->valor){
            return buscarNodo(t->der, valor);
        }
        return valor == t->valor;
    }

    void imprimirRango(Nodo* t, T min, T max){
        if(t != NULL){
            if(min < t->valor){
                imprimirRango(t->izq, min, max);
            }
            
            std::cout << t->valor << std::endl;

            if(max > t->valor){
                imprimirRango(t->der, min, max);                    
            }
        }
    }

public:
    AVL() : raiz(NULL) {};

    void insertar(T valor);
    bool buscar(T valor);
    void rango(T valorMin, T valorMax);

};

#include "AVL.tpp"

#endif