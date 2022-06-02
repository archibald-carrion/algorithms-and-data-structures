#include <fstream>
#include <iostream>
#include "Lista.h"

int main(){ 
    //como descrito en el enunciado, se recibe un archivo de texto con la estructura deseada
    //lo cual es recibir cada dato en una linea differente para que sea mas lisible
    
    Lista *lista = new Lista();
    int data;
    ifstream documento;
    documento.open((char*)"datos.txt",ios::in);
    documento>>data;
    //cout<<data<<endl; 
    //char* archivoTexto = (char*)"datos.txt";
    //FILE *miDocumento;
	//miDocumento = fopen(archivoTexto,"r+t");
    //const int sizeInput = 10;
    // char input[sizeInput];

    //int finArchivo = 0;
	while(!documento.eof()) {
        cout<<data<<endl;
        //codigo que guarda el int en la lista
        documento>>data;
        //cout<<input<<endl;
		//fgets(input, sizeInput, miDocumento);

       // if(input.eof()){
         //   finArchivo=1;
        //}
        //cout<<input<<endl;
        /*
        int contador=0;
        while(contador<sizeInput){
            if(input[contador]=='\0'){
                finArchivo=1;
            }
            ++contador;
        }*/

        //cout<<input<<endl; 
	}
    documento.close();
	//fclose(miDocumento);


    //aqui se pone el codigo para sacar las frecuencias y las frecuiencias de frecuencias









    return 0;
}