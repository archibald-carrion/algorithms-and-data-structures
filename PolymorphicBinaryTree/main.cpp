#include "Tree.h"
#include "Element.h"
#include "User.h"
#include <iostream>
using namespace std;
int main()
{
   Tree tree;
   Element *element = new User();

   for (int i = 0; i < 10; ++i)
   {
      cout << "Digite un element: ";
      cin >> element;
      tree.add(element);
      cout << endl;
   }
   cout << "ELEMENTS" << endl;
   cout << tree;
   cout << endl;
   do
   {
      cout << "Digite elemento existente: ";
      cin >> element;
      cout << endl;
   } while (tree.exist(element));
   cout << "Ese valor " << element << " no existe " << endl;
   return 0;
}

//    g++ main.cpp User.cpp tree.cpp