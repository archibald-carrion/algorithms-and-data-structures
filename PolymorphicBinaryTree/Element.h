#ifndef ELEMENT_
#define ELEMENT_
#include <iostream>
using namespace std;

class Element
{
   friend ostream &operator<<(ostream &salida, Element *p)
   {
      return p->print(salida);
   }

   friend istream &operator>>(istream &entrada, Element *p)
   {
      return p->read(entrada);
   }

public:
   virtual ~Element(){};
   virtual Element *clonar() = 0;
   virtual ostream &print(ostream &) = 0;
   virtual istream &read(istream &) = 0;
   virtual int operator==(Element *) = 0;
   virtual int operator!=(Element *) = 0;
   virtual int operator<(Element *) = 0;
};

#endif