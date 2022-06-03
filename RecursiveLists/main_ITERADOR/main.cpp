#include <fstream>
#include <string>
#include "Lista.h"

/*
Esta versión del codigo usa objectos de tipo Iterador
Hay iteradores implementados en los metodos get, getFrecuencia, getSize de la clase Lista, 3 metodos muy
importantes para este main
Al usar el iterador no se usa un metodo recursivo, y por lo tanto es mucho menos pesado para la memoria
Por lo tanto, al usar menos memoria se considera esta solución como más eficiente
*/

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
    lista.insertar(data);    //para "recibir" el primer data
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

    Lista::Iterador iterador1(&listaFrecuencia);
    while(counter<sizeLista){
        //(*iterador.getPointer()).getFrecuencia()
        listaFrecuencia.insertar(lista.getFrecuencia(counter));
        ++counter;
    }
    cout<<listaFrecuencia<<endl;
    
    ofstream documentoOuput;
    //cout<<outputFile<<endl;
	documentoOuput.open(outputFile,ios::out);
    if(!(documentoOuput.fail())){
        documentoOuput<<"Frecuencia\tCantidad de Numeros \n";
    } else {
        cout<<"occurio un problema al abrir archivo de texto \n"<<endl;
    }

    int sizeFrecuencia = listaFrecuencia.getSize();
    counter = 0;
    Lista::Iterador iterador2 = (&listaFrecuencia);
    cout<<"Frecuencia\tCantidad de Numeros \n";
    while(counter<sizeFrecuencia){
        documentoOuput << (*iterador2.getPointer()).getValor() << "\t\t" << (*iterador2.getPointer()).getFrecuencia()<<"\n";
        cout << (*iterador2.getPointer()).getValor() << "\t\t" << (*iterador2.getPointer()).getFrecuencia()<<"\n";
        ++iterador2;
        ++counter;
    }

    documentoOuput.close();
    return 0;
}
