#include <fstream>
#include <string>
#include "Lista.h"

int main(int args, char **argv){ 
    string inputFile = argv[1];
    string outputFile = argv[2];
    
    Lista *lista = new Lista();
    int data;
    ifstream documentoInput(inputFile);
    if(!(documentoInput.is_open())){
        cout<<"problema con la apertura del archivo de texto"<<endl;
    } 
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
    
    ofstream documentoOuput(outputFile);
    if(documentoOuput.is_open()){
        documentoOuput<<"Frecuencia\tCantidad de Números \n";
    } else {
        cout<<"problema con la apertura del archivo de texto"<<endl;
    }

    int sizeFrecuencia = (*listaFrecuencia).getSize();
    counter = 0;
    while(counter<sizeFrecuencia){
        documentoOuput << (*listaFrecuencia).get(counter) << "\t\t" << (*listaFrecuencia).getFrecuencia(counter)<<"\n";
    }

    documentoOuput.close();
    delete listaFrecuencia;
    delete lista;
    return 0;
}