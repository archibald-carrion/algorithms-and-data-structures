#include <fstream>
#include <string>
#include "Lista.h"

int main(int args, char **argv){ 
    string inputFile = argv[1];
    string outputFile = argv[2];
    
    Lista lista;
    int data;
    ifstream documentoInput;
    documentoInput.open(inputFile, ios::in);
    if(documentoInput.fail()){
        cout<<"problema con la apertura del archivo de texto"<<endl;
    } 
    documentoInput>>data;
    lista.insertar(data);   
    //ese while permite guardar en la lsita todos los ints que se encontran en el archivo de texto
	while(!documentoInput.eof()) {
        documentoInput>>data;
        //cout<<data<<endl;
        lista.insertar(data);
	}
    documentoInput.close();

    cout<<lista<<"\n"<<endl;
    int sizeLista = lista.getSize();
    int counter = 0;
    Lista listaFrecuencia;
    //en ese while se guarda las frecuencias en una lista de frecuencias
    //de esa manera es mucho mas facil extraer las frecuencias de frecuencias
    while(counter<sizeLista){
        listaFrecuencia.insertar(lista.getFrecuencia(counter));
        ++counter;
    }
    cout<<listaFrecuencia<<endl;
    
    ofstream documentoOuput;
	documentoOuput.open(outputFile,ios::out);
    if(!(documentoOuput.fail())){
        documentoOuput<<"Frecuencia\tCantidad de Números \n";
    } else {
        cout<<"problema con la apertura del archivo de texto \n"<<endl;
    }

    int sizeFrecuencia = listaFrecuencia.getSize();
    counter = 0;
    cout<<"Frecuencia\tCantidad de Numeros \n";
    //en ese while se guarda cada valor en el archivo de texto
    while(counter<sizeFrecuencia){
        documentoOuput << listaFrecuencia.get(counter) << "\t\t" << listaFrecuencia.getFrecuencia(counter)<<"\n";
        cout << listaFrecuencia.get(counter) << "\t\t" << listaFrecuencia.getFrecuencia(counter)<<"\n";
        ++counter;
    }

    documentoOuput.close();
    return 0;
}
