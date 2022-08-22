#include "Arbol.h"
#include "Elemento.h"
//#include "Letra.h"
#include "User.h"
#include <iostream>
using namespace std;
int main()
{
   Arbol arbol;
   // Elemento * elemento = new Entero();
   // Elemento * elemento = new Letra();
   Elemento *elemento = new User();

   for (int i = 0; i < 10; ++i)
   {
      cout << "Digite un elemento: ";
      cin >> elemento;
      arbol.add(elemento);
      cout << endl;
   }
   cout << "ELEMENTOS" << endl;
   cout << arbol;
   cout << endl;
   do
   {
      cout << "Digite elemento existente: ";
      cin >> elemento;
      cout << endl;
   } while (arbol.existe(elemento));
   cout << "Ese valor " << elemento << " no existe " << endl;
   return 0;
}

//    g++ main.cpp User.cpp Arbol.cpp