#ifndef HEAP_TEMP
#define HEAP_TEMP

template<class T>
class HeapMin{
private:
    long capacidad;
    long cantidad;
    T* datos;

public:
    HeapMin(long cantEsperados) {
        capacidad = cantEsperados;
        cantidad = 0;
        datos = new T[cantEsperados + 1];
    }

    long cantElementos(){
        return cantidad;
    }

    long hijoIzq(long pos){
        return pos * 2;
    }

    long hijoDer(long pos){
        return pos * 2 + 1;
    }

    long padre(long pos){
        return pos / 2;
    }

    bool existe(long pos){
        return pos > 0 && pos <= cantidad;
    }

    void hundir(long pos){
        T valor = datos[pos];
        long hijo;

        while(existe(hijoIzq(pos))){
            hijo = hijoIzq(pos);


            if(existe(hijoDer(pos))){
                if(valor <= datos[hijoIzq(pos)] && valor <= datos[hijoDer(pos)]){
                    break;
                }

                hijo = (datos[hijoIzq(pos)] <= datos[hijoDer(pos)]) ? hijoIzq(pos) : hijoDer(pos);
            }
            else if(valor <= datos[hijoIzq(pos)]){
                break;
            }
            
            datos[pos] = datos[hijo];
            pos = hijo;
        }
        datos[pos] = valor;
    }

    void flotar(long pos){
        T valor = datos[pos];
        long padrePos = padre(pos);

        while(existe(padrePos) && datos[padrePos] > valor){
            datos[pos] = datos[padrePos];
            pos = padrePos;
            padrePos = padre(pos);
        }
        datos[pos] = valor;
    }

    void insertar(T valor){
        if(cantidad < capacidad){
            cantidad++;
            datos[cantidad] = valor;
            flotar(cantidad);
        }
    }

    T eliminar(){
        T top = datos[1];
        datos[1] = datos[cantidad];
        cantidad--;
        
        if(cantidad > 0){
            hundir(1);
        }

        return top;
    }
};

#endif