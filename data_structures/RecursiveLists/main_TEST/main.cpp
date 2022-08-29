#include "Lista.h"

int main(){ 
    Lista *lista1 = new Lista();;   //lista por omisión
    int numeros[6]={1,4,3,2,1,-2};     
    Lista lista2(6,numeros);        //lista por parametros
    Lista lista3(lista2);           //lista por copia
    Lista *lista4 = new Lista();    //lista nula

    *lista1 = lista2;
    //lista3 = (*lista4);
    lista2.insertar(10);
    lista2.insertar(1);
    lista2.insertar(-10); //SIGO TENIENDO EL PROBLEMA DE INSERTAR UNA ELEMENTO MAS PEQUEÑO

    cout<<"lista1 :"<<endl;
    cout<<*lista1<<"\n"<<endl;
    cout<<"lista2 :"<<endl;
    cout<<lista2<<"\n"<<endl;
    cout<<"lista3 :"<<endl;
    cout<<lista3<<"\n"<<endl;
    cout<<"lista4 :"<<endl;
    cout<<*lista4<<"\n"<<endl;

    cout<<"lista1.isEmpty = "<<(*lista1).isEmpty()<<endl;
    cout<<"lista2.isEmpty = " << lista2.isEmpty()<<endl;
    cout<<"lista3.isEmpty = " << lista3.isEmpty()<<endl;
    cout<<"lista4.isEmpty = " <<(*lista4).isEmpty()<<"\n"<<endl;
    
    int numero = lista2==(*lista1);
    cout<<"lista2==(*lista1);  is iqual to: " << numero<<"\n"<<endl;

    int posicion = 0;
    cout<<"posicion: "<<posicion<<endl;
    cout<<"el_valor: " << lista2.get(posicion)<<endl;
    cout<<"su_frecuencia: " << lista2.getFrecuencia(posicion)<<endl;
    
    delete lista1;
    delete lista4;
    return 0;
}