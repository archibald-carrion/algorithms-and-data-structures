#ifndef BIGFOOT_CLASS
#define BIGFOOT_CLASS
#include "Elemento.h"
#include<iostream>
using namespace std;

class Bigfoot: public Elemento{
    protected:
        int cantidad;
    public:
        Bigfoot();
        ~Bigfoot();
        //virtual ~Elemento(){};
        Bigfoot *clonar();
        ostream &imprimir(ostream &);
        istream &leer(istream &);
        int operator==(Elemento *);
        int operator!=(Elemento *);
        int operator<(Elemento *);
        
};
#endif