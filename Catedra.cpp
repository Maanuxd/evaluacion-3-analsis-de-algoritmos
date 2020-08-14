#include "Catedra.h"
using namespace std;

Catedra::Catedra()
{
    nivel;
    codigo_carrera;
    nombre_asignatura;
}

Catedra::Catedra(const Catedra& copycat )
{
    nivel = copycat.nivel;
    codigo_carrera = copycat.codigo_carrera;
    nombre_asignatura = copycat.nombre_asignatura;    
}

Catedra::Catedra(int a, string b,int c)
{
    nivel=a;
    nombre_asignatura=b;
    codigo_carrera=c;

}

void Catedra::setNivel(int lvl)
{
    nivel = lvl ;
}

int Catedra::getNivel()
{
    return nivel;
}

void Catedra::setCodigo_carrera(int cod)
{
    codigo_carrera = cod ;
}

int  Catedra::getCodigo_carrera()
{
    return codigo_carrera;
}

void Catedra::setNombre_catedra(string name_cat)
{
    nombre_asignatura = name_cat;
}

string Catedra::getNombre_catedra()
{
    return nombre_asignatura;
}

void Catedra::setAsignacion(bool valor)
{
    asignado = valor;
}

bool Catedra::getAsignacion()
{
    return asignado;
}

