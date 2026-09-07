#include "HeapMin.h"

class HeapMin {
private:
    long* datos;
    long capacidad;
    long cantidad;

public:
    HeapMin(long esperados){
        datos = new long[esperados];
        capacidad = esperados;
        cantidad = 0;
    }

    bool esVacio(){
        return cantidad == 0;
    }

    void hundir(long pos){

    }

    void flotar(long pos){

    }

    void insertar(long valor){
        cantidad++;
        datos[cantidad] = valor;
        flotar(cantidad);
    }

    long eliminar(){
        long top = datos[1];
        datos[1] = datos[cantidad];
        cantidad--;
        hundir(1);
    }
};