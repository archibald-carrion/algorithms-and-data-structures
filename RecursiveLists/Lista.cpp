#include "Lista.h"
#include<iostream> 
using namespace std;

//metodo constructor por omisión, no recibe parametros
Lista::Lista(){
    el_valor = 0;
    su_frecuencia = 1;
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
        insertar(arregloElementos[contador]);
        cout<<"se ejecuto el while"<<endl;
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
        return((*siguienteLista)==(*otra.siguienteLista));
        //se llama el mismo metodo pero con las listas "siguientes"
    }
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
    salida<<"Valor : "<<el_valor<<" Frecuencia : "<<su_frecuencia<<"\n";
    if(!(*this==*siguienteLista)) {
        siguienteLista -> imprimir(salida);
    }
    return salida;
}

//metodo insertar, no tuve tiempo de terminarla durante el examen entonces hare varias modificaciones ahora
int Lista::insertar(int elemento){
    int posicionado = 0;
    cout<<"hola jajajajja"<<endl;

    //ese caso signfica que aun no hay elementos en la lista y por lo tanto se esta guardando el primero elemento
    if(su_frecuencia==0){
        el_valor = elemento;
        su_frecuencia = 1;
        return 1;
    } else {
        //en ese caso se encontro el "campo" donde se tiene que insertar una nueva lista
        if(elemento>el_valor && elemento<(*siguienteLista).el_valor){
            //hay que agregar otro subcaso en el cual se agrega el elemento si es el ultimo !!

            //hay que insertar una nueva lista aqui
        } else {
            //en ese caso ya existe el elemento en la lista y solo se occupa incrementar el la frecuencia
            if(elemento==el_valor) {
               //solo hay que incrementar la frecuencia, ya que ya existe el elemento en la lista
            } else {
                //en ese caso el valor es menor al priemr valor entonces hay que crear una neuva lista y ponerla al inicio
                if(elemento<el_valor) {
                    Lista *nuevaLista = new Lista();
                    (*nuevaLista).su_frecuencia = 1;
                    (*nuevaLista).el_valor = elemento;
                    *(*nuevaLista).siguienteLista = *this;
                    *this = *nuevaLista;
                    return 1;
                    //posicionado = 1;
                    //delete nuevaLista;
                } else {
                    //hay que llamar de nuevo el metodo pero con la lsitaSiguiente
                }
            }
        }
    }
    return 0;
}