#ifndef _USER_
#define _USER_
#include "Elemento.h"
#include<iostream>
using namespace std;

class User: public Elemento {
   private:
      char* nombre;
   public:
      User();
	   User(char*);
      Elemento * clonar();
      ostream& imprimir(ostream&);
      istream& leer(istream&);
      int operator==(Elemento *);
      int operator!=(Elemento *);
      int operator<(Elemento *);
};


#endif