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
Lista::Lista(Lista& otra) {
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
Lista::Lista(int cantidadElementos, int arregloElementos[]) {
    int contador = 0;
    while(contador < cantidadElementos){
        this->insertar(arregloElementos[contador]);
        ++contador;
    }
}

//metodo destructor de la Lista
//hace delete a cada elemento de manera recursiva
Lista::~Lista() {
    if(!(*this==*siguienteLista)) { //caso base de la recursividad para que no se encicla el programa
        delete siguienteLista;
    }
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
Lista& Lista::operator = (Lista& otra) {
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
int Lista::operator == (const Lista& otra){
    //la versión original tenia un problema de recurisividad, por lo tanto tuve que hacerle cambios mayores
}

//metodo que devuelve el_valor de la lista en la posicion dada en los parametros
int Lista::get(int pos) {
    Lista temporal(*this);
    int contador = 0;
    int esValido = 2;
    while(contador<pos) {
        if(temporal == *temporal.siguienteLista) {
            --esValido;
        }
        temporal = *temporal.siguienteLista;
        ++contador;
    }
    if(esValido<= 0) {
        cerr<<"se intento acceder a un valor fuera del rango de la Lista";
        return 0;
    } else {
        return temporal.el_valor;
    }
}

//metodo getFrecuencia que devuelve la frecuencia del elemento de la posicion dada
int Lista::getFrecuencia(int pos) {
    Lista temporal(*this);
    int contador = 0;
    int posValida = 2;
    while(contador <pos) {
        if(temporal==*temporal.siguienteLista) {
            --posValida;
        }
        temporal = *temporal.siguienteLista;
        ++contador;
    }

    if(posValida>0){
        int frecuencia = temporal.su_frecuencia;
        //delete temporal;
        return frecuencia ;
    } else {
        //delete temporal;
        return 0;
    }
}

//metodo imprimir que permite imprimir la lista
ostream& Lista::imprimir(ostream& salida){
    salida<<"Valor : "<<el_valor<<" Frecuencia : "<<su_frecuencia<<"/n";
    if(!(*this==*siguienteLista)) {
        siguienteLista -> imprimir(salida);
    }
    return salida;
}

//metodo insertar, no tuve tiempo de terminarla durante el examen entonces hare varias modificaciones ahora
int Lista::insertar(int elemento){
    Lista temporal(*this);
    int elmentoExiste=0;
    int posicionado = 0;

    //el primer caso es cuando el elemento es menor al primer elemento, lo cual implica que aun no esta en la lista
    if(elemento<temporal.el_valor) {
        Lista *nuevaLista = new Lista();
        (*nuevaLista).su_frecuencia = 1;
        (*nuevaLista).el_valor = elemento;
        *(*nuevaLista).siguienteLista = *this;
        *this = *nuevaLista;
        posicionado = 1;
        //delete nuevaLista;
    } else {
        //en ese while se busca si ya existe una lista con ese elemento
        //en cual caso solo occupo incrementar de 1 la frecuencia
        while(!(temporal==*temporal.siguienteLista)) {
            if(elemento==temporal.el_valor) {
                ++(temporal.su_frecuencia);
                posicionado = 1;
            }
            temporal = *temporal.siguienteLista;
        }

        //en esa situación aun no esta posicionado, ya que es mayor al primer elemento y aun no existe un elemento 
        //igual en la lista, por lo tanto hay que agregar una nueva lista en la buena posición
        if(posicionado==0) {


        }



    }
    return posicionado;
}