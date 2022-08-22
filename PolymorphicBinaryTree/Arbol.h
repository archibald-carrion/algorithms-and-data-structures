#ifndef ARBOLBIN
#define ARBOLBIN
#define IZQ 0
#define DER 1
#define HIJOS 2
#include <iostream>
#include "Element.h"
using namespace std;
class Arbol
{
	friend ostream &operator<<(ostream &output, Arbol &arbol)
	{
		return arbol.print(output);
	}

private:
	class Node
	{
	public:
		Element *element;
		Node *hijo[HIJOS];
		Node(Element *);
		~Node();
		ostream &print(ostream &);
		void add(Element *);
		int exist(Element *);
	};

	Node *root;
	ostream &print(ostream &);

public:
	Arbol();
	~Arbol();
	void add(Element *);
	int exist(Element *);
};
#endif