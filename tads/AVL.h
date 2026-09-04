#ifndef AVL_H
#define AVL_H


template <class T>
class AVL {
public:
    //PRE: recibe un valor
    //POST: si no está presente, lo inserta en el árbol y lo balancea. Si ya está presente,
    //no hace nada
    void insertar(T valor);

    //PRE: recibe un valor
    //POST: devuelve true si está presente en el árbol, false en otro caso
    bool buscar(T valor);

    //PRE: valorMin <= valorMax
    //POST: imprime uno por línea, los valores presentes en el árbol
    //que están entre valorMin y valorMax inclusive
    void rango(T valorMin, T valorMax);
};

#endif
