#ifndef ARBOLBIN
#define ARBOLBIN
#define IZQ 0
#define DER 1
#define HIJOS 2
#include <iostream>
#include "Elemento.h"
using namespace std;

class Arbol
{
    friend ostream &operator<<(ostream &salida, Arbol &arbol)
    {
        return arbol.imprimir(salida);
    }

private:
    class Nodo
    {
    public:
        Elemento *elemento;
        Nodo *hijo[HIJOS];
        Nodo(Elemento *);
        ~Nodo();
        ostream &imprimir(ostream &);
        void add(Elemento *);
        int existe(Elemento *);
    };

    Nodo *raiz;
    ostream &imprimir(ostream &);

public:
    Arbol();
    ~Arbol();
    void add(Elemento *);
    int existe(Elemento *);
};
#endif