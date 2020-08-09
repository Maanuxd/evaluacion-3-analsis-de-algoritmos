#include "Catedra.h"
using namespace std;

Catedra::Catedra()
{
    nivel = 7;
    codigo_carrera = 21041;
    nombre_asignatura = 'Analisis de Algoritmos';
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