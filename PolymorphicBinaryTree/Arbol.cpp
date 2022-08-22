#include "Arbol.h"
#include "Elemento.h"
#include <iostream>

Arbol::Nodo::Nodo(Elemento *elemento)
{
	this->elemento = elemento->clonar();
	hijo[IZQ] = 0;
	hijo[DER] = 0;
}

Arbol::Nodo::~Nodo()
{
	if (hijo[IZQ])
	{
		delete hijo[IZQ];
	}
	if (elemento)
	{
		delete elemento;
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
	salida << elemento << " ";

	if (hijo[DER])
	{
		hijo[DER]->imprimir(salida);
	}
	return salida;
}

void Arbol::Nodo::add(Elemento *elemento)
{
	if (*(this->elemento) != elemento)
	{
		int lado = (*elemento < this->elemento) ? IZQ : DER;
		if (hijo[lado])
		{
			hijo[lado]->add(elemento);
		}
		else
		{
			hijo[lado] = new Nodo(elemento);
		}
	}
}

int Arbol::Nodo::existe(Elemento *elemento)
{
	int existeElemento = 0;
	if (*(this->elemento) == elemento)
	{
		existeElemento = 1;
	}
	else
	{
		int lado = (*elemento < this->elemento) ? IZQ : DER;
		if (hijo[lado])
		{
			existeElemento = hijo[lado]->existe(elemento);
		}
	}
	return existeElemento;
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

void Arbol::add(Elemento *elemento)
{
	if (raiz)
	{
		raiz->add(elemento);
	}
	else
	{
		raiz = new Nodo(elemento);
	}
}

int Arbol::existe(Elemento *elemento)
{
	int existeElemento = 0;
	if (raiz)
	{
		existeElemento = raiz->existe(elemento);
	}
	return existeElemento;
}
