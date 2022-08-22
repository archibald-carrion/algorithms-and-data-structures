#include "Elemento.h"
#include "User.h"
#include <iostream>
using namespace std;

User::User()
{
	id = 0;
}
User::User(unsigned long int idUser)
{
	this->id = idUser;
}

Elemento *User::clonar()
{
	return new User(id);
}

ostream &User::imprimir(ostream &salida)
{
	salida << id << " ";
	return salida;
}

istream &User::leer(istream &entrada)
{
	entrada >> id;
	return entrada;
}

int User::operator==(Elemento *otro)
{
	User *otroUser = dynamic_cast<User *>(otro);
	return otroUser && id == otroUser->id;
}

int User::operator!=(Elemento *otro)
{
	return !((*this) == otro);
}

int User::operator<(Elemento *otro)
{
	User *otroUser = dynamic_cast<User *>(otro);
	return otroUser && this->id < otroUser->id;
}
