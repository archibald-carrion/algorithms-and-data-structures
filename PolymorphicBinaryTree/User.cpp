#include "User.h"

User::User()
{
    nombreUser = "default";
}

User::User(char* nombre)
{
    nombreUser = nombre;
}


User::~User()
{
}

Elemento *User::clonar()
{
    User clon(nombreUser);
    return &clon;
}

ostream &User::imprimir(ostream & output)
{
    output<<"\nnombreUser: "<< nombreUser <<endl;
}

istream &User::leer(istream & input)
{
}

int User::operator==(Elemento *)
{
}

int User::operator!=(Elemento *)
{
}

int User::operator<(Elemento *)
{
}