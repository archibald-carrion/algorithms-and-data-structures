#include "Lista.h"
#include<iostream> 
using namespace std;

//metodo constructor por omisión, no recibe parametros
Lista::Lista(){
    el_valor = 0;
    su_frecuencia = 0;
    siguienteLista = 0; //no hay que desreferenciar el puntero cuando le doy el valor nulo (0)
    //iterador.pointerLista = this;
}

//metodo constructor por copia
Lista::Lista(Lista& otra) {
    el_valor = otra.el_valor;
    su_frecuencia = otra.su_frecuencia;
    if(!(otra==*(otra.siguienteLista))) {
        Lista *nuevaLista = new Lista(*(otra.siguienteLista));
        siguienteLista = nuevaLista;
    } else {
        siguienteLista = this;
    }
}

//metodo constructor por parametros, recibe una array de numeros y un int que indica la cantidad de elementos en el array
Lista::Lista(int cantidadElementos, int arregloElementos[]) {
    int contador = 0;
    su_frecuencia=0;
    while(contador < cantidadElementos){
        insertar(arregloElementos[contador]);
        ++contador;
    }
}

//metodo destructor de la Lista, se llama recursivamente hasta llegar al ultimo elemento
Lista::~Lista() {
    if(!(*this==*siguienteLista)) { //caso base de la recursividad para que no se encicla el programa
        delete siguienteLista;
    }
}

//metodo isEmpty que permite saber si la lista es vacia o no
int Lista::isEmpty() {
    int empty = 0;
    if(siguienteLista==0) {
        empty = 1; //la lista es vacia, solo en el caso de que el atributo siguienteLista punta a 0
    }
    return empty;
}

//metodo de sobrecarga del operator =, permite asignar a una lista el contenido de otra lista
Lista& Lista::operator = (Lista& otra) {
    if(otra.isEmpty()){
        su_frecuencia=0;
        el_valor=0;
        siguienteLista=0;
    } else{
        Lista *nuevaLista = new Lista(*(otra.siguienteLista));
        siguienteLista = nuevaLista;
        el_valor = otra.el_valor;
        su_frecuencia = otra.su_frecuencia;
    }
    return *this;
}

//metodo de sobrecarga del operator ==, permite verificar si una lista es igual a otra lista
int Lista::operator == (const Lista& otra){
    int sonIguales = 1;
    
    if(!(otra.el_valor==el_valor && otra.su_frecuencia==su_frecuencia)){
        sonIguales = 0;
    }

    if((*otra.siguienteLista).el_valor==otra.el_valor || (*siguienteLista).el_valor==el_valor){
        if((*otra.siguienteLista).el_valor==otra.el_valor && (*siguienteLista).el_valor==el_valor){
            sonIguales = 1;
            return sonIguales;
        } else {
            sonIguales = 0;
            return sonIguales;
        }
    }

    if(sonIguales==0){
        return 0;
    } else {
        return((*siguienteLista)==(*otra.siguienteLista));      //se llama el mismo metodo pero con las listas "siguientes"
    }
}

//metodo que devuelve el_valor de la lista en la posicion dada en los parametros
int Lista::get(int pos) {
    Iterador iterador(this);
    int encontrado = 0;
    int valorFinal = 0;
    while(encontrado==0){
        if(pos>0 && *(iterador.pointerLista)==*((*(iterador.pointerLista)).siguienteLista)){
            cerr<<"se intento acceder a un valor fuera del rango de la Lista";
            valorFinal= 0;
            encontrado= 1;
        } else {
            if(pos==0) {
                valorFinal = (*(iterador.pointerLista)).el_valor;
                encontrado=1;
            } else {
                ++iterador;
                --pos;
            }
        }
    }
    return valorFinal;
}

//metodo getFrecuencia que devuelve la frecuencia del elemento de la posicion dada
int Lista::getFrecuencia(int pos) {
    Iterador iterador(this);
    int encontrado = 0;
    int valorFinal = 0;
    while(encontrado==0){
        if(pos>0 && *(iterador.pointerLista)==*((*(iterador.pointerLista)).siguienteLista)){
            valorFinal= 0;
            encontrado= 1;
        } else {
            if(pos==0) {
                valorFinal = (*(iterador.pointerLista)).su_frecuencia;
                encontrado=1;
            } else {
                ++iterador;
                --pos;
            }
        }
    }
    return valorFinal;
}

//metodo imprimir que permite imprimir la lista
ostream& Lista::imprimir(ostream& salida){
    if(this->isEmpty()){ 
        salida<<"Valor : "<<el_valor<<" Frecuencia : "<<su_frecuencia<<"\n";
    } else {
        salida<<"Valor : "<<el_valor<<" Frecuencia : "<<su_frecuencia<<"\n";
        if(!(*this==*siguienteLista)) {
            siguienteLista -> imprimir(salida);
        }
    }
    return salida;
}

//metodo insertar, no tuve tiempo de terminarla durante el examen entonces hare varias modificaciones ahora
Lista& Lista::insertar(int elemento){
    //cout<<"Elemento que hay que insertar: "<< elemento<<endl;
    if(su_frecuencia==0){                                                   //la lista esta vacia por el momento
        //cout<<"caso 0"<<endl;
        el_valor = elemento;
        su_frecuencia = 1;
        siguienteLista = this;
        return *this;
    } else {
        if(elemento>el_valor && (*siguienteLista).el_valor==el_valor){      //hay que agregar una lista al final de la lista
            //cout<<"caso 1"<<endl;
            Lista *nuevaLista = new Lista();
            (*nuevaLista).su_frecuencia = 1;
            (*nuevaLista).el_valor = elemento;
            (*nuevaLista).siguienteLista = nuevaLista;
            siguienteLista = nuevaLista;
            return *this;
        } else {
            if(elemento>el_valor && elemento<(*siguienteLista).el_valor){   //hay que insertar una nueva lista entre 2 listas
                //cout<<"caso 2"<<endl;
                Lista *nuevaLista = new Lista();
                (*nuevaLista).su_frecuencia = 1;
                (*nuevaLista).el_valor = elemento;
                (*nuevaLista).siguienteLista = siguienteLista;
                siguienteLista = nuevaLista;
                return *this;
            } else {
                if(elemento==el_valor) {                                    //ya existe, solo se occupa incrementar la frecuencia
                    //cout<<"caso 3"<<endl;
                    ++su_frecuencia;
                    return *this;               
                } else {                    //en ese caso el valor es menor al priemr valor entonces hay que crear una neuva lista y ponerla al inicio
                    if(elemento<el_valor) {
                        //cout<<"caso 4"<<endl;
                        Lista *nuevaLista = new Lista();
                        (*nuevaLista).su_frecuencia = su_frecuencia;
                        (*nuevaLista).el_valor = el_valor;
                        if(!(*this==*siguienteLista)){
                            (*nuevaLista).siguienteLista = siguienteLista;
                        } else {    //en ese caso el elemento se vuelve el ultimo elemento
                             (*nuevaLista).siguienteLista = nuevaLista;
                        }
                        el_valor = elemento;
                        su_frecuencia = 1;
                        siguienteLista = nuevaLista;
                        return *this;
                        //return (*nuevaLista);
                    } else {
                        //cout<<"caso 5"<<endl;
                        (*siguienteLista).insertar(elemento);
                    }
                }
            }
        }
    }
    return *this;
}

//metodo que devuelve el tamano de la lista
int Lista::getSize(){
    Iterador iterador(this);
    int encontrado = 0;
    int size = 0;
    while(encontrado==0){
        if(*(iterador.pointerLista)==*((*(iterador.pointerLista)).siguienteLista)){
            ++size;
            encontrado= 1;
        } else {
            ++size;
            ++iterador;
        }
    }
    return size;
}

//metodo que devuelve el valor de la lista
int Lista::getValor(){
    return el_valor;
}

//metodo que devuelve la frecuencia de la lista
int Lista::getFrecuencia(){
    return su_frecuencia;
}

//metodo construcotr por omisión de iterador
Lista::Iterador::Iterador(){
    pointerLista = 0;
}

//metodo constructor con parametro de iterador
Lista::Iterador::Iterador(Lista* unaLista){
    pointerLista = unaLista;
}

//devuelve la posicion "siguiente", ++iterador
Lista::Iterador& Lista::Iterador::operator++(){
    pointerLista = (*pointerLista).siguienteLista;
    return *this;
}     

//metodo que verifica si 2 listas son iguales, devuelve 1 si son las mismas
int Lista::Iterador::operator==(Iterador& otro){
    if(*(otro.pointerLista) == *pointerLista){
        return 1;
    } else {
        return 0;
    }
}

//metodo que asigna une nuevo valor al iterador
Lista:: Iterador& Lista::Iterador::operator=(Iterador& otro){
    pointerLista = otro.pointerLista;
    return *this;
}

//metodo que devuelve el ultimo elemento de la lista
Lista::Iterador& Lista::Iterador::getUltimo(){
    while(!(*pointerLista==*((*pointerLista).siguienteLista))){
        pointerLista = (*pointerLista).siguienteLista;
    }
    return *this;
}

//metodo que devuelve el pointerLista del iterador
Lista* Lista::Iterador::getPointer(){
    return pointerLista;
}