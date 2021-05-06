#include <iostream>
#include <string>
#include "../include/nodo.h"

template<class Clave>
class ArbolB {

private: //

    nodoB<Clave> *raiz_;
public:

    ArbolB(void);
    ~ArbolB(void);

    void podar(nodoB<Clave>* nodo);

    nodoB<Clave>* buscar(Clave &x);
    nodoB<Clave>* buscar(const Clave &x, nodoB<Clave> *nodo);
    
    void insertar(const Clave& x);
    void insertar(const Clave& x, nodoB<Clave>* nodo);

    bool estaVacio(nodoB<Clave> *nodo);
    bool esHoja(nodoB<Clave> *nodo);

    const int size();
    const int sizeRama(nodoB<Clave> *nodo);

    const int altura();
    const int alturaN(nodoB<Clave> *nodo);

    void imprime(nodoB<Clave> *nodo, int nivel);
    void imprimeNivel(nodoB<Clave> *nodo, int nivel);

    nodoB<Clave>* getRaiz() {return raiz_;};
};

template<class Clave>
ArbolB<Clave>::ArbolB(void) : 
    raiz_(nullptr) {}

template<class Clave>
ArbolB<Clave>::~ArbolB(void) {
    podar(raiz_);
}

template<class Clave>
void ArbolB<Clave>::podar(nodoB<Clave>* nodo) {

    if (nodo == nullptr) return;
    podar(nodo->getIzquierda());
    podar(nodo->getDerecha());
    delete nodo;
    nodo = nullptr;
}


template<class Clave>
nodoB<Clave>* ArbolB<Clave>::buscar(Clave &x) {
    return buscar(x, raiz_);
}

template<class Clave>
nodoB<Clave>* ArbolB<Clave>::buscar(const Clave &x, nodoB<Clave> *nodo) {
    
    if (nodo == nullptr) {
        //std::cout << "nullptr";
        return nullptr;
    }
    if (x == nodo->getDato())  {
        //std::cout << "dato"<< x << " " << nodo->getDato();
        return nodo;
    }
    if (x < nodo->getDato()) {
        //std::cout << "izq" << x << " " << nodo->getDato();
        return buscar(x, nodo->getIzquierda());
    } 
    //std::cout << "drc" << x << " " << nodo->getDato();
    return buscar(x, nodo->getDerecha());

}

template<class Clave>
void ArbolB<Clave>::insertar(const Clave& x) {
    
    if(raiz_ == nullptr) 
        raiz_ = new nodoB<Clave>(nullptr, nullptr, x);
    
    else 
        insertar(x, raiz_);
}


template<class Clave>
void ArbolB<Clave>::insertar(const Clave& x, nodoB<Clave>* nodo) {

    if(sizeRama(nodo->getIzquierda()) <= sizeRama(nodo->getDerecha())) {
        if(nodo->getIzquierda() != nullptr) {
            insertar(x, nodo->getIzquierda());
        } else {
           nodo->setIzquierda(new nodoB<Clave>(x));
        }
    } else {
        if (nodo->getDerecha() != nullptr) {
            insertar(x, nodo->getDerecha());
        } else {
            nodo->setDerecha(new nodoB<Clave>(x));
        }
    }
}

template<class Clave>
bool ArbolB<Clave>::estaVacio(nodoB<Clave> *nodo) {
    return nodo == nullptr;
}

template<class Clave>
bool ArbolB<Clave>::esHoja(nodoB<Clave> *nodo) {
    return !nodo->getDerecha() && !nodo->getIzquierda();
}

template<class Clave>
const int ArbolB<Clave>::size() {
    return sizeRama(raiz_);
}
    
template<class Clave> 
const int ArbolB<Clave>::sizeRama(nodoB<Clave> *nodo) {
    if (nodo == nullptr)
        return 0;
    else 
        return (1 + sizeRama(nodo->getIzquierda()) + sizeRama(nodo->getDerecha()));
}

template<class Clave>
const int ArbolB<Clave>::altura() {
    return alturaN(raiz_);
}

template<class Clave>
const int ArbolB<Clave>::alturaN(nodoB<Clave> *nodo) {
    if (nodo == nullptr)
        return 0;

    int altura_izqd = alturaN(nodo->getIzquierda());
    int altura_dcha = alturaN(nodo->getDerecha());

    if (altura_dcha > altura_izqd)
        return ++altura_dcha;
    else 
        return ++altura_izqd;
}

template<class Clave>
void ArbolB<Clave>::imprime(nodoB<Clave> *nodo, int nivel) {

    if (nivel == 0) {
        if (nodo == nullptr) {
            std::cout << "[.]";
        } else {
            nodo->imprimeNodo();
        }
    }
    
    else if((nodo != nullptr) && nivel > 0) {
        
        imprime(nodo->getIzquierda(), nivel - 1);
        imprime(nodo->getDerecha(), nivel - 1);
    }
    
    
}

template<class Clave>
void ArbolB<Clave>::imprimeNivel(nodoB<Clave> *nodo, int nivel) {
    const int size = alturaN(nodo);

    if(raiz_ == nullptr) {
        std::cout << "Nivel 0: [.]";
    }
    
    for (int i = 0; i <= size; i++) {
        std::cout << "\nNivel " << i << ": ";
        imprime(nodo, i);
        std::cout << "\n";
    }
    
}