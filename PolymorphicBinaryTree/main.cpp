#include "Arbol.h"
#include "Element.h"
//#include "Letra.h"
#include "User.h"
#include <iostream>
using namespace std;
int main()
{
   Arbol arbol;
   // Elemento * elemento = new Entero();
   // Elemento * elemento = new Letra();
   Element *element = new User();

   for (int i = 0; i < 10; ++i)
   {
      cout << "Digite un element: ";
      cin >> element;
      arbol.add(element);
      cout << endl;
   }
   cout << "ELEMENTS" << endl;
   cout << arbol;
   cout << endl;
   do
   {
      cout << "Digite elemento existente: ";
      cin >> element;
      cout << endl;
   } while (arbol.exist(element));
   cout << "Ese valor " << element << " no existe " << endl;
   return 0;
}

//    g++ main.cpp User.cpp Arbol.cpp