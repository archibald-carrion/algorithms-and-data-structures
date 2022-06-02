#include <fstream>
#include <iostream>
#include <string>
#include "Lista.h"

int main(int args, char **argv){ 
    string inputFile = argv[1];
    string outputFile = argv[2];
    //como descrito en el enunciado, se recibe un archivo de texto con la estructura deseada
    //lo cual es recibir cada dato en una linea differente para que sea mas lisible
  //  char* inputFile = (char*)"datosInput.txt";
    //char* outputFile = (char*)"datosOutput.txt";
    Lista *lista = new Lista();
    int data;
    ifstream documentoInput;
    documentoInput.open((char*)"i.txt",ios::in);
    documentoInput>>data;
    (*lista).insertar(data);    //para "recibir" el primer data
	while(!documentoInput.eof()) {
        documentoInput>>data;
        //cout<<data<<endl;
        (*lista).insertar(data);
	}
    documentoInput.close();

    cout<<(*lista)<<"\n"<<endl;
    int sizeLista = (*lista).getSize();
    int counter = 0;
    Lista *listaFrecuencia = new Lista();
    while(counter<sizeLista){
        (*listaFrecuencia).insertar(lista->getFrecuencia(counter));
        ++counter;
    }
    cout<<(*listaFrecuencia)<<endl;
    //aqui se pone el codigo para sacar las frecuencias y las frecuiencias de frecuencias
    
    //cout<<(*lista).getSize()<<endl;
    //while((*lista))
    ofstream documentoOuput;
    //cout<<"a"<<endl;
    documentoOuput.open(outputFile, ios::out);
    if(documentoOuput.is_open()){
        documentoOuput<<"Frecuencia     Cantidad de Números \n";
    } else {
        cout<<"problema con la apertura del archivo de texto"<<endl;
    }
    //int sizeFrecuencia = (*listaFrecuencia).getSize();
    //counter = 0;
    //while(counter<sizeFrecuencia){
      //  documentoOuput
   /// }
    //hay que reiterativamente agregar cada frecuencia y frecuencia de frecuencia
    documentoOuput.close();






    delete listaFrecuencia;
    delete lista;
    return 0;
}