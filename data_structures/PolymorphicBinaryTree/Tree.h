#ifndef BINARY_TREE_
#define BINARY_TREE_
#define LEFT 0
#define RIGHT 1
#define CHILDRE 2
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
		Node *children[];
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