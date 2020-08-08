#include "Semestre.h"
using namespace std;

Semestre::Semestre()
{
    nivel = 7;
    codigo_carrera = 21041;
    nombre_asignatura = 'Analisis de Algoritmos';
}

void Semestre::setNivel(int lvl)
{
    nivel = lvl ;
}

int Semestre::getNivel()
{
    return nivel;
}

void Semestre::setCodigo_carrera(int cod)
{
    codigo_carrera = cod ;
}

int  Semestre::getCodigo_carrera()
{
    return codigo_carrera;
}

void Semestre::setNombre_catedra(string name_cat)
{
    nombre_asignatura = name_cat;
}

string Semestre::getNombre_catedra()
{
    return nombre_asignatura;
}