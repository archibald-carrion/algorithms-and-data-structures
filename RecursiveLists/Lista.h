#ifndef MI_LISTA_
#define MI_LISTA_
#include<iostream>
using namespace std;

class Lista {
    friend ostream& operator<<(ostream& salida, Lista& lista) {
        return lista.imprimir(salida);
    }
    private:
        int el_valor;
        int su_frecuencia;
        Lista* siguienteLista;
        ostream& imprimir(ostream&);
    public:
        Lista();
        Lista(Lista&);                      //no hay que pasar el parametro como const, sino no se puede acceder a siguienteLista
        Lista(int,int[]);
        ~Lista();
        int insertar(int);
        int isEmpty();
        Lista& operator = (Lista&);         //no hay que pasar el parametro como const, sino no se puede acceder a siguienteLista
        int operator ==(const Lista&);
        int getFrecuencia(int);
        int get(int);    
};
#endif