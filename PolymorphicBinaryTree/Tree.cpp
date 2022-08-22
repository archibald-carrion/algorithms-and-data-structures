#include "Tree.h"
#include "Element.h"
#include <iostream>

Tree::Node::Node(Element *element)
{
	this->element = element->clone();
	hijo[IZQ] = 0;
	hijo[DER] = 0;
}

Tree::Node::~Node()
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

ostream &Tree::Node::print(ostream &salida)
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

void Tree::Node::add(Element *element)
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

int Tree::Node::exist(Element *element)
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

ostream &Tree::print(ostream &output)
{
	if (root)
	{
		root->print(output);
	}
	else
	{
		output << "Tree VACIO" << endl;
	}
	return output;
}

Tree::Tree()
{
	root = 0;
}

Tree::~Tree()
{
	if (root)
	{
		delete root;
	}
}

void Tree::add(Element *element)
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

int Tree::exist(Element *element)
{
	int existElement = 0;
	if (root)
	{
		existElement = root->exist(element);
	}
	return existElement;
}
