class GrafoDir {
//implementación con listas de adyacencia
public:
    class Nodo {
    public:
        long dato;
        bool visitado;
        Nodo* sig;


        Nodo(long num) : dato(num), visitado(false), sig(nullptr) {};
    };

    Nodo** aristas;
    long vertices;
    long* aristasEntrada;

    GrafoDir(long numVertices) : vertices(numVertices) {
        aristas = new Nodo* [vertices];
        aristasEntrada = new long[vertices];
        for (long i = 0; i < vertices; i++){
            aristasEntrada[i] = 0;
        } 
    }

    void agregarArista(long inicio, long fin){
        Nodo* n = aristas[inicio];
        Nodo* nuevo = new Nodo(fin);

        if(n == nullptr){
            aristas[inicio] = nuevo;
        }
        else {
            nuevo->sig = n;
            n = nuevo;
        }

        aristasEntrada[fin]++;
    }

    Nodo* vecinos(long vertice){
        return aristas[vertice];
    }

    Nodo* verticesSinPrev(){
        //retorna los vértices que no tienen aristas de entrada. Si no hay ninguno, se acabó el grafo o hay un ciclo.
    }
};