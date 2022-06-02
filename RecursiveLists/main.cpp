#include "Lista.h"

int main(){ 
    //como descrito en el enunciado, se recibe un archivo de texto con la estructura deseada
    //lo cual es recibir cada dato en una linea differente, ya que voy a utilizar la función 
    
    //primero hay que abrir el archivo de texto
    //se crea una lista por omision
    //en un ciclo se agrega cada elemento en la lista, linea por linea
    //despues se llama cada frecuencia y se saca la frecuencia de la frecuencia
    Lista *lista = new Lista();
    char* archivoTexto = (char*)"datos.txt";
    FILE *miDocumento;
	miDocumento = fopen(archivoTexto,"r+t");
	//int contador = 0;
    char* input;
    int finArchivo = 0;
	//el while permite reiterar la cantidad de veces necesarias para sacar la linea necesitada
	while(finArchivo != 1) {
		//hileraLinea[0]='\0';
		fgets(input, 50, miDocumento);
        
        //hay que poner un if para saber si es el fin del archivos
	}
	fclose(miDocumento);
    return 0;
}