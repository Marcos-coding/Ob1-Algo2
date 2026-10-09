#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;


class Arista {
    private:
        long origen;
        long destino;
        long peso;
    public:
        long getDestino(){
            return this->destino;
        }
        long getOrigen(){
            return this->origen;
        }
        long getPeso(){
            return this->peso;
        }
        Arista(long unDest, long unPeso, long unOrigen){
            this->destino = unDest;
            this->peso = unPeso;
            this->origen = unOrigen;
        }
    

};

class HeapMin {
private:
    Arista** datos;
    long capacidad;
    long cantidad;

public:
    HeapMin(long esperados){ 
        datos = new Arista*[esperados + 1];
        capacidad = esperados;
        cantidad = 0;
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
        Arista* valor = datos[pos];

        long hijo;

        while(existe(hijoIzq(pos))){
            hijo = hijoIzq(pos);


            if(existe(hijoDer(pos))){
                if(valor->getPeso() <= datos[hijoIzq(pos)]->getPeso()  && valor->getPeso() <= datos[hijoDer(pos)]->getPeso()){
                    break;
                }

                hijo = (datos[hijoIzq(pos)]->getPeso() <= datos[hijoDer(pos)]->getPeso()) ? hijoIzq(pos) : hijoDer(pos); //Revisar esto
            }
            else if(valor->getPeso() <= datos[hijoIzq(pos)]->getPeso()){
                break;
            }
            
            datos[pos] = datos[hijo];
            pos = hijo;
        }
        datos[pos] = valor;
    }

    void flotar(long pos){
        Arista* valor = datos[pos];
        long padrePos = padre(pos);

        while(existe(padrePos) && valor->getPeso() <= datos[padrePos]->getPeso()){
            datos[pos] = datos[padrePos];
            pos = padrePos;
            padrePos = padre(pos);
        }
        datos[pos] = valor;
    }

    void insertar(Arista* valor){
        if(cantidad < capacidad){
            cantidad++;
            datos[cantidad] = valor;
            flotar(cantidad);
        }
    }

    Arista* eliminar(){
        Arista* top = datos[1];
        datos[1] = datos[cantidad];
        cantidad--;
        hundir(1);

        return top;
    }
};

class MFset {
    private:
        long cantE;
        long* padre;
        long* cantidad;
    public:
        MFset(int cant){
            this->cantE = cant;
            this->padre = new long[cant+1];
            this->cantidad = new long[cant+1];
            for(int i = 0; i <= cantE; i ++){
                this->padre[i] = i;
                this->cantidad[i] = 1;
            }
        }
        long grupo(long x){
            if(padre[x] == x){
                return x;
            }
            padre[x] = grupo(padre[x]);
            return padre[x];
        }
        void unir(long x, long y){
            long grupoX = this->grupo(x);
            long grupoY = this->grupo(y);
            if(grupoX != grupoY){
                if(cantidad[grupoX] < cantidad[grupoY]){
                    this->padre[grupoX] = grupoY;
                }else if(cantidad[grupoX] > cantidad[grupoY]){
                    this->padre[grupoY] = grupoX;
                }else{
                    this->padre[grupoX] = grupoY;
                    cantidad[grupoY]++;
                }
            }

        }
};


int main()
{
    long V;
    long E;
    cin >> V >> E;
    if(V == 1){
        cout << 0 << endl;
        return 0;
    }
    HeapMin* heap = new HeapMin(E);
    MFset* mfs = new MFset(V);
    for(int i = 0; i < E; i++){
        long o;
        long p;
        long d;
        cin >> o >> d >> p;
        heap->insertar(new Arista(d, p, o));
    }
    long cantA = 0;
    long sum = 0;
    for(int i = 0; i < E && cantA < V-1; i ++){
        Arista* a = heap->eliminar();
        if(mfs->grupo(a->getDestino()) != mfs->grupo(a->getOrigen())){
            cantA++;
            sum += a->getPeso();
            mfs->unir(a->getDestino(), a->getOrigen());
        }
    }
    if(cantA == V-1){
        cout << sum << endl;
    }else{
        cout << "imposible" << endl;
    }
    return 0;
}