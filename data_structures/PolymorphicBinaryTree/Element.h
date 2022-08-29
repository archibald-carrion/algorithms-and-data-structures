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

   friend istream &operator>>(istream &input, Element *p)
   {
      return p->read(input);
   }

public:
   virtual ~Element(){};
   virtual Element *clone() = 0;
   virtual ostream &print(ostream &) = 0;
   virtual istream &read(istream &) = 0;
   virtual int operator==(Element *) = 0;
   virtual int operator!=(Element *) = 0;
   virtual int operator<(Element *) = 0;
};

#endif