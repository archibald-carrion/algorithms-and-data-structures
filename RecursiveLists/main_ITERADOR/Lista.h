#ifndef MI_LISTA_
#define MI_LISTA_
#include<iostream>
using namespace std;

class Lista {
    friend ostream& operator<<(ostream& salida, Lista& lista) {
        return lista.imprimir(salida);
    }

    class Iterador {
        friend class Lista;
        private:
            Lista *pointerLista;
        public:
            Iterador();
            Iterador(Lista*);
            Iterador& operator++();     //devuelve la posicion "siguiente", ++iterador
            int operator==(Iterador&);
            Iterador& getUltimo();      //devuelve un iterador que apunta al ultimo elemento de la Lista
    };

    friend class Iterador;

    private:
        int el_valor;
        int su_frecuencia;
        //Iterador iterador;
        Lista* siguienteLista;
        ostream& imprimir(ostream&);
    public:
        Lista();
        Lista(Lista&);                      //no hay que pasar el parametro como const, sino no se puede acceder a siguienteLista
        Lista(int,int[]);
        ~Lista();
        Lista& insertar(int);
        int isEmpty();
        Lista& operator = (Lista&);         //no hay que pasar el parametro como const, sino no se puede acceder a siguienteLista
        int operator ==(const Lista&);
        int getFrecuencia(int);
        int get(int);    
        int getSize();      //metodo que devuelve el tamano de la lista


        

};
#endif