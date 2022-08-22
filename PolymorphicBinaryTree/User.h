#ifndef _USER_
#define _USER_
#include "Element.h"
#include <iostream>
using namespace std;

class User : public Element
{
private:
   unsigned long int id; // de 0 a 4 294 967 295
public:
   User();
   User(unsigned long int);
   Element *clonar();
   ostream &imprimir(ostream &);
   istream &leer(istream &);
   int operator==(Element *);
   int operator!=(Element *);
   int operator<(Element *);
};

#endif