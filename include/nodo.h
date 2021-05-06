#include <iostream>


template<class Clave>
class nodoB {

private: 

    nodoB *derecha_;
    nodoB *izquierda_;
    Clave dato_;
public:

nodoB(nodoB *derecha, nodoB *izquierda, Clave dato);
nodoB(Clave dato);
~nodoB();

Clave getDato();

nodoB<Clave>* getIzquierda() { return izquierda_; };
nodoB<Clave>* getDerecha() { return derecha_; };

void setIzquierda(nodoB<Clave> *nodo);
void setDerecha(nodoB<Clave> *nodo);

void imprimeNodo();

};


template<class Clave>
nodoB<Clave>::nodoB(nodoB *derecha, nodoB *izquierda, Clave dato) :
    derecha_(derecha),
    izquierda_(izquierda), 
    dato_(dato) {}

template<class Clave>
nodoB<Clave>::nodoB(Clave dato) :
    derecha_(nullptr),
    izquierda_(nullptr), 
    dato_(dato) {}

template<class Clave>
nodoB<Clave>::~nodoB(){}

template<class Clave>
Clave nodoB<Clave>::getDato() {
    return dato_;
}

template<class Clave>
void nodoB<Clave>::imprimeNodo() {
    
    std::cout << "[" << getDato() << "]";
}

template<class Clave>
void nodoB<Clave>::setIzquierda(nodoB<Clave> *nodo) {
    izquierda_ = nodo;
}

template<class Clave>
void nodoB<Clave>::setDerecha(nodoB<Clave> *nodo) {
    derecha_ = nodo;
}