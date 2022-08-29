#include "Tree.h"
#include "Element.h"
#include <iostream>

Tree::Node::Node(Element *element)
{
	this->element = element->clone();
	children[LEFT] = 0;
	children[RIGHT] = 0;
}

Tree::Node::~Node()
{
	if (children[LEFT])
	{
		delete children[LEFT];
	}
	if (element)
	{
		delete element;
	}
	if (children[RIGHT])
	{
		delete children[RIGHT];
	}
}

ostream &Tree::Node::print(ostream &salida)
{
	if (children[LEFT])
	{
		children[LEFT]->print(salida);
	}
	salida << element << " ";

	if (children[RIGHT])
	{
		children[RIGHT]->print(salida);
	}
	return salida;
}

void Tree::Node::add(Element *element)
{
	if (*(this->element) != element)
	{
		int lado = (*element < this->element) ? LEFT : RIGHT;
		if (children[lado])
		{
			children[lado]->add(element);
		}
		else
		{
			children[lado] = new Node(element);
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
		int lado = (*element < this->element) ? LEFT : RIGHT;
		if (children[lado])
		{
			existElement = children[lado]->exist(element);
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
		output << "Empty tree" << endl;
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