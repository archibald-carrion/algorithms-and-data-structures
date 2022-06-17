#include "Elemento.h"
#include "Letra.h"
#include<iostream>
using namespace std;

Letra::Letra(){
	letra = '_';
}
Letra::Letra(char letra){
	this->letra = letra;
}

Elemento * Letra::clonar(){
	return new Letra(letra);
}

ostream& Letra::imprimir(ostream& salida){
	salida << letra << " ";
	return salida;
}

istream& Letra::leer(istream& entrada){
	entrada >> letra;
	return entrada;
}

int Letra::operator==(Elemento * p){
	Letra * pLetra = dynamic_cast<Letra *>(p);
	return pLetra && letra==pLetra->letra;
}

int Letra::operator!=(Elemento * p){
    return !((*this)==p);
}

int Letra::operator<(Elemento * p){
	Letra * pLetra = dynamic_cast<Letra *>(p);
	return pLetra && this->letra < pLetra->letra;		  		  
}
