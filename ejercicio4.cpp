#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/NodoModulo.cpp"
#include "tads/HeapTemp.cpp"

using namespace std;

class arista {
    public:
        int dest;
        arista* sig;

        int getDest(){
            return this->dest;
        }
        arista* getSig(){
            return this->sig;
        }
        arista(int unDest, arista* unSig){
            this->dest = unDest;
            this->sig = unSig;
        }
};

class grafo {
    private:
        int cantV;
        arista** ady;
        int* grados; //Grados de incidencia de los vertices
    public:
        grafo(int cantV){
            this->cantV = cantV;
            this->ady = new arista*[cantV + 1];
            this->grados = new int[cantV + 1];
            for (int i = 0; i <= cantV; i++){
                this->ady[i] = NULL;
                grados[i] = 0;
            }
            
        }

        void agregarArista(int origen, int destino){
            arista* a = new arista(destino, NULL);
            a->sig = this->ady[origen];
            this->ady[origen] = a;
            this->grados[destino]++;
        }
        int gradosIncidencia(int vertice){
            return grados[vertice];
        }
        
        void reducirIncidencia(int vertice){
            if(grados[vertice] > 0){
                grados[vertice]--;
            }
        }

        arista* vecinos(int vertice){
            return this->ady[vertice];
        }
};

int main()
{
    int V;
    int A;
    cin >> V >> A;

    int pos = 0;
    int* modulosOrd = new int[V];
    
    grafo* dependencias = new grafo(V);
    HeapMin<NodoModulo> proximos = HeapMin<NodoModulo>(V);

    //cargamos las prioridades en un array
    int* prioridades = new int[V + 1];
    for(int i = 1; i <= V; i++){
        cin >> prioridades[i];
    }

    int origen;
    int destino;
    for(int i = 0; i < A; i ++){
        cin >> origen >> destino;
        dependencias->agregarArista(origen, destino);
    }

    for(int vert = 1; vert <= V; vert ++){
        if(dependencias->gradosIncidencia(vert) == 0){
            NodoModulo n = NodoModulo(vert, prioridades[vert]);
            proximos.insertar(n);
        }
    }

    

    NodoModulo elim;
    NodoModulo nuevo;
    int moduloDep;
    arista* aristaDep;

    while(proximos.cantElementos() > 0){
        elim = proximos.eliminar();
        modulosOrd[pos] = elim.modulo;
        pos++;

        arista* vecinos = dependencias->vecinos(elim.modulo);

        aristaDep = vecinos;

        while(aristaDep != NULL){
            moduloDep = aristaDep->getDest();
            dependencias->reducirIncidencia(moduloDep);

            if(dependencias->gradosIncidencia(moduloDep) == 0){
                nuevo = NodoModulo(moduloDep, prioridades[moduloDep]);
                proximos.insertar(nuevo);
            }
            aristaDep = aristaDep->getSig();
        }
    }

    bool hayCiclo = pos < V;

    if(hayCiclo){
        cout << "imposible" << endl;
    }
    else {
        for (int i = 0; i < V; i++){
            cout << modulosOrd[i] << endl;
        }
    }           

    return 0;
}