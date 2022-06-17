#ifndef USER_CLASS
#define USER_CLASS
#include "Elemento.h"
#include<iostream>
using namespace std;

class User: public Elemento{
    protected:
        char* nombreUser;
    public:
        User();
        User(char*);
        ~User();
        Elemento *clonar();
        ostream &imprimir(ostream &);
        istream &leer(istream &);
        int operator==(Elemento *);
        int operator!=(Elemento *);
        int operator<(Elemento *);
        
};
#endif