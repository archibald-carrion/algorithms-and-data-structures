#ifndef _USER_
#define _USER_
#include "Elemento.h"
#include<iostream>
using namespace std;

class User: public Elemento {
   private:
      unsigned long int id;               //de 0 a 4 294 967 295
   public:
      User();
	   User(unsigned long int);
      Elemento * clonar();
      ostream& imprimir(ostream&);
      istream& leer(istream&);
      int operator==(Elemento *);
      int operator!=(Elemento *);
      int operator<(Elemento *);
};


#endif