#include <iostream>


template<class Clave>
class nodoB {

private: 

    nodoB *derecha_;
    nodoB *izquierda_;
    Clave dato_;
public:

nodoB(nodoB *derecha = NULL, nodoB *izquierda = NULL, Clave dato = NULL);
~nodoB();

Clave getDato();
friend std::ostream &operator<<(std::ostream &os, Clave&x) {
        if (x.dato_ == NULL) 
            os << "[.]";
        else 
            os << "[" << std::to_string(x.dato_) << "]";
            
        return os;
    }

};


template<class Clave>
nodoB<Clave>::nodoB(nodoB *derecha, nodoB *izquierda, Clave dato) :
    derecha_(derecha),
    izquierda_(izquierda), 
    dato_(dato) {}

template<class Clave>
nodoB<Clave>::~nodoB(){}

template<class Clave>
Clave nodoB<Clave>::getDato() {
    return dato_;
}
