#include "Arbol.h"
#include "Element.h"
#include <iostream>

Arbol::Node::Node(Element *element)
{
	this->element = element->clone();
	hijo[IZQ] = 0;
	hijo[DER] = 0;
}

Arbol::Node::~Node()
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

ostream &Arbol::Node::print(ostream &salida)
{
	if (hijo[IZQ])
	{
		hijo[IZQ]->print(salida);
	}
	salida << element << " ";

	if (hijo[DER])
	{
		hijo[DER]->print(salida);
	}
	return salida;
}

void Arbol::Node::add(Element *element)
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
			hijo[lado] = new Node(element);
		}
	}
}

int Arbol::Node::exist(Element *element)
{
	int existElement = 0;
	if (*(this->element) == element)
	{
		existElement = 1;
	}
	else
	{
		int lado = (*element < this->element) ? IZQ : DER;
		if (hijo[lado])
		{
			existElement = hijo[lado]->exist(element);
		}
	}
	return existElement;
}

ostream &Arbol::print(ostream &output)
{
	if (root)
	{
		root->print(output);
	}
	else
	{
		output << "ARBOL VACIO" << endl;
	}
	return output;
}

Arbol::Arbol()
{
	root = 0;
}

Arbol::~Arbol()
{
	if (root)
	{
		delete root;
	}
}

void Arbol::add(Element *element)
{
	if (root)
	{
		root->add(element);
	}
	else
	{
		root = new Node(element);
	}
}

int Arbol::exist(Element *element)
{
	int existElement = 0;
	if (root)
	{
		existElement = root->exist(element);
	}
	return existElement;
}
