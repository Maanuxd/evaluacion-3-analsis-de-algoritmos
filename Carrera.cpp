#include "Carrera.h"

Carrera::Carrera()
{
    codigo;
    asignaturas;
}
Carrera::Carrera(int cod)
{
    codigo=cod;
}
Carrera::Carrera(int cod, vector<Catedra> algo)
{
    codigo=cod;
    asignaturas=algo;
}
void Carrera::setcod(int c)
{
    codigo=c;
}

int Carrera::getcod()
{
    return codigo;
}
void Carrera::setvec_asig(vector<Catedra> algo)
{
    asignaturas=algo;
}

vector<Catedra> Carrera::getvec_asig()
{
    return asignaturas;
}

Catedra Carrera::getvec_superasig(int indice)
{
    return asignaturas[indice];
}

bool Carrera::existe(vector<Carrera> algo)
{
    if(!algo.empty())
    {
        for(long unsigned int i=0; i<algo.size();i++)
        {
            if(codigo == algo[i].getCodigo_carrera())
            {
                return true;
            }
        }
    }      
    return false;
}