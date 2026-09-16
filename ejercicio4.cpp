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

};

int main()
{
    int V;
    int A;
    cin >> V >> A; //no me acuerdo si esta bien esto, revisar
    grafo* dependencias = new grafo(V);
    for(int i = 0; i < V; i ++){
        //No se todavia bien q hacer con las prioridades
    }
    for(int i = 0; i < A; i ++){
        int origen;
        int destino;
        cin >> origen >> destino;
        dependencias->agregarArista(origen, destino);
    }
    //Detectar ciclos, si ciclo => termina
    //heap->insterar(vertices de grado de incidencia 0)
    //while(!heap->esVacio){
        //modulo = heap->desencolar
        //cout modulo
        //for each arista in grafo->ady[modulo]{
            //grafo->grados[arista->destino] --
            //if(grafo->grados[arista->destino] == 0){
                //heap->insertar(arista->destino)
            

    return 0;
}