#ifndef BINARY_TREE_
#define BINARY_TREE_
#define IZQ 0
#define DER 1
#define HIJOS 2
#include <iostream>
#include "Element.h"
using namespace std;
class Tree
{
	friend ostream &operator<<(ostream &output, Tree &tree)
	{
		return tree.print(output);
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
	Tree();
	~Tree();
	void add(Element *);
	int exist(Element *);
};
#endif