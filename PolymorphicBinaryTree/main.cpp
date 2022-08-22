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
      cout << "Digit a new element: ";
      cin >> element;
      tree.add(element);
      cout << endl;
   }
   cout << "ELEMENTS" << endl;
   cout << tree;
   cout << endl;
   do
   {
      cout << "Digit an existing element: ";
      cin >> element;
      cout << endl;
   } while (tree.exist(element));
   cout << "This value: " << element << " does not exist" << endl;
   return 0;
}

//    g++ main.cpp User.cpp Tree.cpp