#include <cassert>
#include <string>
#include <iostream>
#include <limits>


using namespace std;

struct Modulo{
    long num;
    long prio;

    bool MenorQue(Modulo* otro){
        if(this->prio == otro->prio){
            return this->num < otro->num;
        }else{
            return this->prio < otro->prio;
        }
    }
    Modulo(long numero, long prioridad){
        num = numero;
        prio = prioridad;
    }
};

class HeapMin {
private:
    Modulo** datos;
    long capacidad;
    long cantidad;

public:
    HeapMin(long esperados){
        datos = new Modulo*[esperados + 1];
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
        Modulo* valor = datos[pos];

        long hijo;

        while(existe(hijoIzq(pos))){
            hijo = hijoIzq(pos);


            if(existe(hijoDer(pos))){
                if(valor->MenorQue(datos[hijoIzq(pos)])  && valor->MenorQue(datos[hijoDer(pos)])){
                    break;
                }

                hijo = (datos[hijoIzq(pos)]->MenorQue(datos[hijoDer(pos)])) ? hijoIzq(pos) : hijoDer(pos); //Revisar esto
            }
            else if(valor->MenorQue(datos[hijoIzq(pos)])){
                break;
            }
            
            datos[pos] = datos[hijo];
            pos = hijo;
        }
        datos[pos] = valor;
    }

    void flotar(long pos){
        Modulo* valor = datos[pos];
        long padrePos = padre(pos);

        while(existe(padrePos) && valor->MenorQue(datos[padrePos])){
            datos[pos] = datos[padrePos];
            pos = padrePos;
            padrePos = padre(pos);
        }
        datos[pos] = valor;
    }

    void insertar(Modulo* valor){
        if(cantidad < capacidad){
            cantidad++;
            datos[cantidad] = valor;
            flotar(cantidad);
        }
    }

    Modulo* eliminar(){
        Modulo* top = datos[1];
        datos[1] = datos[cantidad];
        cantidad--;
        hundir(1);

        return top;
    }
};

class arista {
    private:
        long dest;
        arista* sig;
    public:
        long getDest(){
            return this->dest;
        }
        arista* getSig(){
            return this->sig;
        }
        arista(long unDest, arista* unSig){
            this->dest = unDest;
            this->sig = unSig;
        }
        ~arista(){
            delete this->sig; //Esta bien esta llamada recursiva??
            delete this;
        }
};

class grafo {
    private:
        long cantV;
        arista** ady;
        long* grados; //Grados de incidencia de los vertices
    public:
        grafo(long cantV){
            this->cantV = cantV;
            this->ady = new arista*[cantV + 1]; //Si desperdicia la pos 0, se puede ver de desplazar los indices
            for(int i = 0; i <= cantV; i++){
                this->ady[i] = NULL;
            }
            this->grados = new long[cantV + 1];
        }
        ~grafo(){
            for(int i = 0; i <= cantV; i++){
                delete ady[i];
            }
            delete [] ady;
        }
        void agregarArista(long origen, long destino){
            arista* a = new arista(destino, this->ady[origen]);
            this->ady[origen] = a;
            this->grados[destino] ++;
        }
        arista* vecinos(long origen){
            return this->ady[origen];
        }
        void bajarGrado(long vertice){
            this->grados[vertice]--;
        }
        long gradoIncidencia(long vertice){
            return this->grados[vertice];
        }
        void setGrados(long* unArray){
            delete [] this->grados;
            this->grados = unArray;
        }

};

int main()
{
    int V;
    int A;
    cin >> V >> A;
    grafo* dependencias = new grafo(V);
    int* prioridades = new int[V + 1];
    HeapMin* heap = new HeapMin(V);
    for(int i = 1; i <= V; i ++){
        cin >> prioridades[i];
    }
    for(int i = 0; i < A; i ++){
        int origen;
        int destino;
        cin >> origen >> destino;
        dependencias->agregarArista(origen, destino);
    }
    long* prioCopia = new long[V + 1];
    //Detectar ciclos, si ciclo => termina
    //No se si es la mejor forma, pero voy a hacer el proceso dos veces, la primera sin imprimir y si no llega a pasar por todos los nodos hay un ciclo, la segunda cuando se que no hay ciclo imprimo respuestas
    for(int i = 0; i <= V; i++){
        prioCopia[i] = dependencias->gradoIncidencia(i);
    }
    bool hayCiclo = false;
    for(int i = 1; i <= V; i++){
        if(dependencias->gradoIncidencia(i) == 0){
            Modulo* n = new Modulo(i, prioridades[i]);
            heap->insertar(n); 
        }
    }
    while(heap->cantElementos() != 0){
        Modulo* modulo = heap->eliminar();
        
        arista* vecinos = dependencias->vecinos(modulo->num);
        while(vecinos) { 
            int dest = vecinos->getDest();
            dependencias->bajarGrado(dest);
            if(dependencias->gradoIncidencia(dest) == 0){
                heap->insertar(new Modulo(dest, prioridades[dest]));
            }
            vecinos = vecinos->getSig();
        }            
    }
    for(int i = 0; i <= V; i++){
        if(dependencias->gradoIncidencia(i) > 0 && !hayCiclo){
            hayCiclo = true;
            cout << "imposible" << endl;
        }
    }
    if(!hayCiclo){
        dependencias->setGrados(prioCopia);
        for(int i = 1; i <= V; i++){
            if(dependencias->gradoIncidencia(i) == 0){
                Modulo* n = new Modulo(i, prioridades[i]);
                heap->insertar(n); 
            }
        }
        while(heap->cantElementos() != 0){
            Modulo* modulo = heap->eliminar();
            cout << modulo->num << "\n";
            arista* vecinos = dependencias->vecinos(modulo->num);
            while(vecinos) { 
                int dest = vecinos->getDest();
                dependencias->bajarGrado(dest);
                if(dependencias->gradoIncidencia(dest) == 0){
                    heap->insertar(new Modulo(dest, prioridades[dest]));
                }
                vecinos = vecinos->getSig();
            }            
        }
    }

    delete [] prioridades;
    //resto de deletes si se quiere
    return 0;
}