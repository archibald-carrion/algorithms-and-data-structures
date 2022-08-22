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
	friend ostream &operator<<(ostream &salida, Arbol &arbol)
	{
		return arbol.imprimir(salida);
	}

private:
	class Nodo
	{
	public:
		Element *element;
		Nodo *hijo[HIJOS];
		Nodo(Element *);
		~Nodo();
		ostream &imprimir(ostream &);
		void add(Element *);
		int existe(Element *);
	};

	Nodo *raiz;
	ostream &imprimir(ostream &);

public:
	Arbol();
	~Arbol();
	void add(Element *);
	int existe(Element *);
};
#endif