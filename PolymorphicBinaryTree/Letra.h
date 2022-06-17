#ifndef LETRA
#define LETRA
#include "Elemento.h"
#include<iostream>
using namespace std;

class Letra: public Elemento {
   private:
      char letra;
   public:
      Letra();
	  Letra(char);
      Elemento * clonar();
      ostream& imprimir(ostream&);
      istream& leer(istream&);
      int operator==(Elemento *);
      int operator!=(Elemento *);
      int operator<(Elemento *);
};


#endif