//
//  rbtree.h
//

#ifndef rbtree_h
#define rbtree_h

#include <iostream>

enum colors {RED, BLACK};


// Nodos del arbol:
template <typename T>
class rbtnode
{
public:
    // Esta clase es usada por la clase rbtree. Por eficiencia se hacen los atributos publicos.
    T key;
    rbtnode<T> *p, *left, *right;
    enum colors color;
    
    // Constructor por omision.
    rbtnode() {
        // Constructor of the node class
        p = nullptr;
        left = nullptr;
        right = nullptr;
        color = RED;
    };
    
    //Inicializacion de datos miembro.
    rbtnode (const T& k, rbtnode<T> *w = nullptr, rbtnode<T> *y = nullptr,
        rbtnode<T> *z = nullptr, enum colors c = RED):
        key(k), p(w), left(y), right(z), color(c) {};
    
    ~rbtnode() {
    };
};

// Arbol rojinegro:
template <typename T>
class rbtree {

private:

    void leftRotate(rbtnode<T> *x) {
        // set y
        rbtnode<T> *y = x->right;
        // turn y's left subtree into x's right subtree
        x->right = y->left;
        if (y->left != nil) {
            y->left->p = x;
        }
        // set x parent to y parent
        y->p = x->p;
        // case were x is the root
        if (x->p == nil) {
            this->root = y;
        }
        else if (x == x->p->left) {
            x->p->left = y;
        }
        else {
            x->p->right = y;
        }
        // set x as y's left child
        y->left = x;
        x->p = y;
    }

    void rightRotate(rbtnode<T> *x){
        // set y
        rbtnode<T> *y = x->left;
        // turn y's right subtree into x's left subtree
        x->left = y->right;
        if (y->right != nil) {
            y->right->p = x;
        }
        // link x's parent to y
        y->p = x->p;
        // case were x is the root
        if (x->p == nil) {
            this->root = y;
        }
        else if (x == x->p->right) {
            x->p->right = y;
        }
        else {
            x->p->left = y;
        }
        // put x on y's right
        y->right = x;
        x->p = y;
    }


    void insertFix(rbtnode<T>* z) {
        // while the father of z is red
        while (z->p->color == RED) {
            // father is left child of grandfather
            if (z->p == z->p->p->left) {
                // set y as z's uncle
                rbtnode<T> *y = z->p->p->right;
                // if y is red
                // case 1, "tio rojo"
                if (y->color == RED) {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                }
                else if (z == z->p->right) {
                    // set z as z's parent
                    z = z->p;
                    // rotation
                    this->leftRotate(z);
                }
                // else
                else {
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    this->rightRotate(z->p->p);
                }
            }
            // father is right child of grandfather
            else {
                // set y as z's uncle
                rbtnode<T> *y = z->p->p->left;
                // case were y is red
                if (y->color == RED) {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                }
                // else if z is the left child of z's parent
                else if (z == z->p->left) {
                    // set z as z's parent
                    z = z->p;
                    // rotation
                    this->rightRotate(z);
                }
                // z is the right child of z's parent
                else {
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    this->leftRotate(z->p->p);
                }
            }
        } 
        // tree is fixed
        // set root as black
        root->color = BLACK;
    };

    void deleteRecursive(rbtnode<T>* root) {
        if (root == nil){
            return;
        }

        deleteRecursive(root->left);
        deleteRecursive(root->right);

        delete root;    
    };

public:
    rbtnode<T> *root;    // raiz del arbol
    rbtnode<T> *nil;     // nodo nil (hoja) del arbol
    
    rbtree() {
        // Constructor (crea un arbol vacio)
        nil = new rbtnode<T>();
        nil->color = BLACK;
        root = nil;
        root->color = BLACK;
    };

    
    ~rbtree() {
        deleteRecursive(root);
        delete nil;
    };
    
    void Insert(rbtnode<T>* z) {
        // set z color to red
        z->color = RED;
        z->left = nil;
        z->right = nil;
        // insert z to the correct place in the tree, the same way as in BST
        rbtnode<T> *buffer = nil;
        rbtnode<T> *x = root;
        while (x != nil) {
            buffer = x;
            if (z->key < x->key) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        z->p = buffer;
        // first insertion
        if (buffer == nil) {
            root = z;
            root->p = nil;
        }
        else if (z->key < buffer->key) {
            buffer->left = z;
        }
        else {
            buffer->right = z;
        }
        // fix the tree
        this->insertFix(z);

        // Inserta el nodo z en la posicion que le corresponde en el arbol.
    };
    
    void InorderWalk(rbtnode<T> *x) {
        // inorder walk trough the tree
        // starting from the given node x
        if (x == nil) {
            return;
        }
        this->InorderWalk(x->left);
        std::cout << x->key << std::endl;
        this->InorderWalk(x->right);
        // Recorre en orden el subarbol con raiz x, imprimiendo la llave de cada nodo en en una nueva linea de la salida estandar despues de recorrido el subarbol izquierdo y antes de recorrer el subarbol derecho.
    };
    
    rbtnode<T>* Search(rbtnode<T> *x, const T& k) {
        // search in the tree using the recursive method
        if (x == nil || k == x->key) {
            return x;
        }
        if (k < x->key) {
            return this->Search(x->left, k);
        }
        else {
            return this->Search(x->right, k);
        }        
        // Busca la llave k iterativamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
    };
    
    rbtnode<T>* IterativeSearch(rbtnode<T> *x, const T& k) {
        if (x == nil || k == x->key) {
            return x;
        }
        while (true)
        {
            if (k < x->key) {
                x = x->left;
            }
            else {
                x = x->right;
            }
            if (x == nil || k == x->key) {
                return x;
            }
        }
        // Busca la llave k iterativamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
    };
    
    rbtnode<T>* Minimum(rbtnode<T> *x) {
        // search minimum value in the tree
        while (x->left != nil) {
            x = x->left;
        }
        return x;
        // Devuelve el nodo que tiene la llave menor. Si el arbol esta vacio, devuelve el nodo nil.
    };
    
    rbtnode<T>* Maximum(rbtnode<T> *x) {
        // search miximum value in the tree
        while (x->right != nil) {
            x = x->right;
        }
        return x;
        // Devuelve el nodo que tiene la llave mayor. Si el arbol esta vacio devuelve el nodo nil.
    };
    
    rbtnode<T>* Successor(rbtnode<T> *x) {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve el nodo nil.
    };
};

#endif /* rbtree_h */
