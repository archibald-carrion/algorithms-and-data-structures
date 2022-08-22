#include "Arbol.h"
#include "Element.h"
#include <iostream>

Arbol::Nodo::Nodo(Element *element)
{
	this->element = element->clonar();
	hijo[IZQ] = 0;
	hijo[DER] = 0;
}

Arbol::Nodo::~Nodo()
{
	if (hijo[IZQ])
	{
		delete hijo[IZQ];
	}
	if (element)
	{
		delete element;
	}
	if (hijo[DER])
	{
		delete hijo[DER];
	}
}

ostream &Arbol::Nodo::imprimir(ostream &salida)
{
	if (hijo[IZQ])
	{
		hijo[IZQ]->imprimir(salida);
	}
	salida << element << " ";

	if (hijo[DER])
	{
		hijo[DER]->imprimir(salida);
	}
	return salida;
}

void Arbol::Nodo::add(Element *element)
{
	if (*(this->element) != element)
	{
		int lado = (*element < this->element) ? IZQ : DER;
		if (hijo[lado])
		{
			hijo[lado]->add(element);
		}
		else
		{
			hijo[lado] = new Nodo(element);
		}
	}
}

int Arbol::Nodo::existe(Element *element)
{
	int existeElement = 0;
	if (*(this->element) == element)
	{
		existeElement = 1;
	}
	else
	{
		int lado = (*element < this->element) ? IZQ : DER;
		if (hijo[lado])
		{
			existeElement = hijo[lado]->existe(element);
		}
	}
	return existeElement;
}

ostream &Arbol::imprimir(ostream &salida)
{
	if (raiz)
	{
		raiz->imprimir(salida);
	}
	else
	{
		salida << "ARBOL VACIO" << endl;
	}
	return salida;
}

Arbol::Arbol()
{
	raiz = 0;
}

Arbol::~Arbol()
{
	if (raiz)
	{
		delete raiz;
	}
}

void Arbol::add(Element *element)
{
	if (raiz)
	{
		raiz->add(element);
	}
	else
	{
		raiz = new Nodo(element);
	}
}

int Arbol::existe(Element *element)
{
	int existeElemento = 0;
	if (raiz)
	{
		existeElement = raiz->existe(element);
	}
	return existeElement;
}
