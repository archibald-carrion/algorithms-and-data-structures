#include "Elemento.h"
#include "User.h"
#include<iostream>
using namespace std;

User::User(){
	nombre = 0;
}
User::User(char* nombreUser){
	this->nombre = nombreUser;
}

Elemento * User::clonar(){
	return new User(nombre);
}

ostream& User::imprimir(ostream& salida){
	salida << nombre << " ";
	return salida;
}

istream& User::leer(istream& entrada){
	entrada >> nombre;
	return entrada;
}

int User::operator==(Elemento * otro){
	User * otroUser = dynamic_cast<User *>(otro);
	return otroUser && nombre==otroUser->nombre;
}

int User::operator!=(Elemento * otro){
    return !((*this)==otro);
}

int User::operator<(Elemento * otro){
	User * otroUser = dynamic_cast<User *>(otro);
	return otroUser && this->nombre < otroUser->nombre;		  		  
}
