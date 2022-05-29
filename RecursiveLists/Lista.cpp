#include "Lista.h"
#include<iostream> 
using namespace std;

//metodo constructor por omisión, no recibe parametros
Lista::Lista(){
    el_valor = 0;
    su_frecuencia = 0;
    siguienteLista = 0; //no hay que desreferenciar el puntero cuando le doy el valor nulo (0)
}

//metodo constructor por copia
//como la lista es recursiva, entonces el mismo constructor es recursivo
Lista::Lista(const Lista& otra) {
    el_valor = otra.el_valor;
    su_frecuencia = otra.su_frecuencia;
    if(!(otra==*otra.siguienteLista)) {
        Lista *siguienteLista = new Lista(*otra.siguienteLista);
    } else {
        siguienteLista = this;
    }
}

//metodo constructor por parametros, recibe una array de numeros 
//y un int que indica la cantidad de elementos en el array
Lista::Lista(int a, int b[]) {

}

//metodo isEmpty que permite saber si la lista es vacia o no
int Lista::isEmpty() {
    int empty = 0;
    if(siguienteLista==0) {
        empty = 1; //la lista es vacia, o nula, solo en el caso de que el atributo siguienteLista punta a 0
    }
    return empty;
}

//metodo de sobrecarga del operator =
//permite asignar a una lista el contenido de otra lista
Lista& Lista::operator = (const Lista& otra) {
    el_valor = otra.el_valor;
    su_frecuencia = otra.su_frecuencia;
    if(!(otra==*otra.siguienteLista)) { //solo se ejecuta en el caso que no sea el 
        *siguienteLista = *otra.siguienteLista; 
    } else {
        *siguienteLista = *this;
    }
    return *this;
}

//metodo de sobrecarga del operator ==
//permite verificar si una lista es igual a otra lista
int Lista::operator == (const Lista& otra) {
    
}

