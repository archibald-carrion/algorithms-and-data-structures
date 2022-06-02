#include "Lista.h"

int main(){ 

    Lista *lista1 = new Lista();;   //lista por omisión
    int numeros[5]={1,4,3,2,1};     
    Lista lista2(5,numeros);        //lista por parametros
    Lista lista3(lista2);           //lista por copia

    *lista1 = lista2;

    cout<<"lista1 :"<<endl;
    cout<<*lista1<<"\n"<<endl;
    cout<<"lista2 :"<<endl;
    cout<<lista2<<"\n"<<endl;
    cout<<"lista3 :"<<endl;
    cout<<lista3<<"\n"<<endl;
    cout<<"lista1.isEmpty = "<<(*lista1).isEmpty()<<endl;
    cout<<"lista2.isEmpty = " << lista2.isEmpty()<<"\n"<<endl;
    cout<<"lista3.isEmpty = " << lista3.isEmpty()<<"\n"<<endl;
    
    int numero = lista2==(*lista1);
    cout<<"lista2==(*lista1);  is iqual to: " << numero<<"\n"<<endl;

    int posicion = 0;
    cout<<"posicion: "<<posicion<<endl;
    cout<<"el_valor: " << lista2.get(posicion)<<endl;
    cout<<"su_frecuencia: " << lista2.getFrecuencia(posicion)<<endl;
    
    return 0;
}