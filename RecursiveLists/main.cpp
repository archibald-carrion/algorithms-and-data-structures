#include "Lista.h"

int main(){ 
    //voy a fabricar una lista para probar
    Lista lista1(); //lista por omisión
    int numeros[5]={5,4,3,2,1};
    Lista lista2(5,numeros); //occure un error en el constuctor que hace que se cae el programa
    cout<<"lista1 :"<<endl;
    cout<<lista1<<endl;
    cout<<"lista2 :"<<endl;
    cout<<lista2<<endl;

    return 0;
}