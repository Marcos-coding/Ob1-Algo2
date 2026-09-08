#ifndef HEAP_H
#define HEAP_H

class HeapMin {
private:
    long hijoIzq(long pos);

    long hijoDer(long pos);

    long padre(long pos);

    bool existe(long pos);

    //PRE: 1 <= pos <= capacidad
    //POST: hunde el valor en la posición pos hasta que sus dos hijos sean mayores que él
    void hundir(long pos);

    //PRE: 1 <= pos <= capacidad 
    //POST: flota el valor en la posición pos hasta que su padre sea menor que él
    void flotar(long pos);

public:

    long cantElementos();

    //PRE: -
    //POST: inserta un valor en el heap si hay lugar. Sino no hace nada
    void insertar(long valor);

    //PRE: !esVacio(heap)
    //POST: elimina el menor valor del heap
    long long eliminar();
};

#endif