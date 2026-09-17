#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HeapMin.cpp"

using namespace std;

class arista {
    private:
        int dest;
        arista* sig;
    public:
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
            this->ady = new arista*[cantV];
            for(int i = 0; i < cantV; i++){
                this->ady[i] = NULL;
            }
            this->grados = new int[cantV];
        }
        void agregarArista(int origen, int destino){
            arista* a = new arista(destino, this->ady[origen]);
            this->ady[origen] = a;
            this->grados[destino] ++;
        }
        arista* vecinos(int origen){
            return this->ady[origen];
        }
        void bajarGrado(int vertice){
            this->grados[vertice]--;
        }
        int gradoIncidencia(int vertice){
            return this->grados[vertice];
        }

};

int main()
{
    int V;
    int A;
    cin >> V >> A; //no me acuerdo si esta bien esto, revisar
    grafo* dependencias = new grafo(V);
    int* prioridades = new int[V];
    HeapMin* heap = new HeapMin(V);
    for(int i = 0; i < V; i ++){
        cin >> prioridades[i];
    }
    for(int i = 0; i < A; i ++){
        int origen;
        int destino;
        cin >> origen >> destino;
        dependencias->agregarArista(origen, destino);
    }
    //Detectar ciclos, si ciclo => termina
    for(int i = 0; i < V; i++){
        if(dependencias->gradoIncidencia(i) == 0){
            heap->insertar(i); //cambiar heap para insertar la prioridad tambien
        }
    }
    while(heap->cantElementos() != 0){
        int modulo = heap->eliminar();
        cout << modulo << "\n";
        arista* vecinos = dependencias->vecinos(modulo);
        while(vecinos->getSig()) { 
            int dest = vecinos->getDest();
            dependencias->bajarGrado(dest);
            if(dependencias->gradoIncidencia(dest) == 0){
                heap->insertar(dest);
            }
            vecinos = vecinos->getSig();
        }            
    }
    delete [] prioridades;
    //resto de deletes si se quiere
    return 0;
}