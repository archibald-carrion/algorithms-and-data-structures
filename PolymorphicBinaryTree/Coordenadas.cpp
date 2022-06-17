#include "Coordenadas.h"

Coordenadas::Coordenadas()
{
    abscisa = 0; 
    ordenada = 0;
}

Coordenadas::Coordenadas(int X, int Y)
{
    abscisa = X;
    ordenada = Y;
}


Coordenadas::~Coordenadas()
{
}

Elemento *Coordenadas::clonar()
{
}

ostream &Coordenadas::imprimir(ostream &)
{
}
istream &Coordenadas::leer(istream &)
{
}

int Coordenadas::operator==(Elemento *)
{
}

int Coordenadas::operator!=(Elemento *)
{
}

int Coordenadas::operator<(Elemento *)
{
}