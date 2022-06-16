#ifndef COORD_CLASS
#define COORD_CLASS
#include "Elemento.h"
#include<iostream>
using namespace std;

class Coordenadas: public Elemento{
    protected:
        int cantidad;
    public:
        Coordenadas();
        ~Coordenadas();
        //virtual ~Elemento(){};

        Elemento *clonar();
        ostream &imprimir(ostream &);
        istream &leer(istream &);
        int operator==(Elemento *);
        int operator!=(Elemento *);
        int operator<(Elemento *);
        
};
#endif