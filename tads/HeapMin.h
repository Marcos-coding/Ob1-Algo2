#ifndef HEAP_H
#define HEAP_H

class HeapMin {
    //PRE: -
    //POST: devuelve true si y solo si el heap es vacío
    bool esVacio();

    //PRE: 1 <= pos <= capacidad
    //POST: hunde el valor en la posición pos hasta que sus dos hijos sean mayores que él
    void hundir(long pos);

    //PRE: 1 <= pos <= capacidad 
    //POST: flota el valor en la posición pos hasta que su padre sea menor que él
    void flotar(long pos);

    //PRE: -
    //POST: inserta un valor en el heap
    void insertar(long valor);

    //PRE: !esVacio(heap)
    //POST: elimina el menor valor del heap
    long eliminar();
};

#endif