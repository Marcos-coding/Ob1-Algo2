#ifndef NODO_MODULO
#define NODO_MODULO

class NodoModulo {
public:
    long modulo;
    long prioridad;

    NodoModulo(){};
    NodoModulo(long modulo, long pri) : modulo(modulo), prioridad(pri) {};

    bool operator<(const NodoModulo &otro) const{
        if(this->prioridad != otro.prioridad){
            return this->prioridad < otro.prioridad;
        }
        else {
            return this->modulo < otro.modulo;
        }
    }    

    bool operator>(const NodoModulo &otro) const{
        return otro < *this;
    }

    bool operator<=(const NodoModulo &otro) const{
        return !(*this > otro);
    }
};

#endif