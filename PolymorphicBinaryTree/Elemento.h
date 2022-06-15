#ifndef ELEMENTO
#define ELEMENTO
#include <iostream>
using namespace std;

class Elemento
{
    friend ostream &operator<<(ostream &salida, Elemento *p)
    {
        return p->imprimir(salida);
    }

    friend istream &operator>>(istream &entrada, Elemento *p)
    {
        return p->leer(entrada);
    }

public:
    virtual ~Elemento(){};
    virtual Elemento *clonar() = 0;
    virtual ostream &imprimir(ostream &) = 0;
    virtual istream &leer(istream &) = 0;
    virtual int operator==(Elemento *) = 0;
    virtual int operator!=(Elemento *) = 0;
    virtual int operator<(Elemento *) = 0;
};

#endif