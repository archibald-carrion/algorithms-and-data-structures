#include <fstream>
#include <iostream>
#include "Lista.h"
/*
123
3
6
565
3
1
1
12
22
12
1
6
6


*/
int main(){ 
    //como descrito en el enunciado, se recibe un archivo de texto con la estructura deseada
    //lo cual es recibir cada dato en una linea differente para que sea mas lisible
    
    Lista *lista = new Lista();
    int data;
    ifstream documento;
    documento.open((char*)"datos.txt",ios::in);
    documento>>data;
    (*lista).insertar(data);    //para "recibir" el primer data
	while(!documento.eof()) {
        documento>>data;
        cout<<data<<endl;
        (*lista).insertar(data);
	}
    //(*lista).insertar(data);    //para insertar el ultimo data
    documento.close();
    cout<<(*lista)<<endl;

    //aqui se pone el codigo para sacar las frecuencias y las frecuiencias de frecuencias








    delete lista;
    return 0;
}