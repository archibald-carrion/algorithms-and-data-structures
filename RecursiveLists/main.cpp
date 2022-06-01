#include "Lista.h"

int main(){ 

    Lista *lista1 = new Lista();; //lista por omisión

    int numeros[5]={1,4,3,2,1};
    Lista lista2(5,numeros); //occure un error en el constuctor que hace que se cae el programa

    *lista1 = lista2;

    cout<<"lista1 :"<<endl;
    cout<<*lista1<<"\n"<<endl;
    cout<<"lista2 :"<<endl;
    cout<<lista2<<"\n"<<endl;
    cout<<"lista1.isEmpty = "<<(*lista1).isEmpty()<<endl;
    cout<<"lista2.isEmpty = " << lista2.isEmpty()<<endl;
    
    return 0;
}