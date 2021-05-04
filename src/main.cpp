#include <iostream>
#include "../include/arbol.h"


int main(void) {

ArbolB<int> arbol;
int eleccion;

do {

    std::cout << "\nSeleccione la opcion deseada:\n\t[0] Salir\n\t[1] Insertar Clave\n\t[2] Buscar Clave\n";
    std::cin >> eleccion;

    switch (eleccion)
    {
    case 0:
        std::cout << "\nSaliendo . . .";
        break;
    
    case 1: 
        int clave;
        std::cout << "\nIntroduzca la Clave a insertar: ";
        std::cin >> clave;
        arbol.insertar(clave);
        std::cout << "Nivel 0: [.]";
        arbol.imprime(arbol.getRaiz(), 0);
        break;

    case 2: 

        int numero;
        std::cout << "\nIntroduzca la Clave a buscar: "; 
        std::cin >> numero;
        arbol.buscar(numero);
        break;

    default:

        std::cout << "\nOpción errónea";
        break;
    }


} while (eleccion != 0);

}