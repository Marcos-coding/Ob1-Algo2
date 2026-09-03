#ifndef AVL
#define AVL


template <class T>
class AVL {
    public:
        struct Nodo {
            public:
                Nodo(T unValor) : valor(unValor), izq(NULL), der(NULL), altura(1) {};
        };
        
        //PRE: recibe un valor
        //POS: 
        virtual void insertar(T valor);

}

#endif