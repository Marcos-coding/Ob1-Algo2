#include "AVL.h"

template <class T>
void AVL<T>::insertar(T valor){
    raiz = insertarNodo(raiz, valor);
}

template <class T>
bool AVL<T>::buscar(T valor){
    return buscarNodo(raiz, valor);
}

template <class T>
void AVL<T>::rango(T valorMin, T valorMax){
    imprimirRango(raiz, valorMin, valorMax);
}