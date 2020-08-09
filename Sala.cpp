#include "Sala.h"
using namespace std;

Sala::Sala()
{
    bloque = 0;
    dia = 'sabado';
    num_dia = 6;
    ramo = Catedra();
}

void Sala::setBloque(int n)
{
    bloque=n;
}

int  Sala::getBloque()
{
    return bloque;
}
void Sala::setDia(string p)
{
    dia = p;
}

string Sala::getDia()
{
    return dia;
}

void Sala::setnum_dia(int m)
{
    num_dia = m;
}

int  Sala::getnum_dia()
{
    return num_dia;
}

void Sala::setRamo(Catedra a)
{
    ramo = a;
}

Catedra Sala::getRamo()
{
    return ramo;
}