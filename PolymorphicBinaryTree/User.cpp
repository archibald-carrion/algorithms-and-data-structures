#include "User.h"

User::User()
{
    nombreUser =(char*) "default";
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
    return output;
}

istream &User::leer(istream & input)
{
    input >> nombreUser;
    return input;
}

int User::operator==(Elemento *)
{
    return 0;
}

int User::operator!=(Elemento *)
{
    return 0;
}

int User::operator<(Elemento *)
{
    return 0;
}