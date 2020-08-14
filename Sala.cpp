#include "Sala.h"
using namespace std;

Sala::Sala()
{
    Catedra();
    horarios;
    dia;
    num_dia;
    ramo;
}
Sala::Sala(string a, vector<vector<string>> b)
{
    nombre_sala = a;
    horarios = b;
}


void Sala::setHorarios(vector<vector<string>> n)
{
    horarios = n;
}

vector<vector<string>>  Sala::getHorarios()
{
    return horarios;
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

void Sala::setRamo(vector<Catedra> a)
{
    ramo = a;
}

vector<Catedra> Sala::getRamo()
{
    return ramo;
}

bool Sala::getDisponibilidad(int n_dia,int n_bloque)
{
    vector<vector<string>> horarios_aux = getHorarios();
    if((horarios_aux).empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Sala::setHor_espf(int n_dia, int n_bloque,string algo)
{
    horarios[n_dia][n_bloque] = algo;

}
string Sala::getHor_espf(int n_dia, int n_bloque)
{
    string aux=horarios[n_dia][n_bloque];
    return aux;

}

void Sala::useHorario(Catedra &ramo,int n_dia,int n_bloque)
{
    std::string nombre = ramo.getNombre_catedra().substr(1, ramo.getNombre_catedra().size()-1);
    std::string casilla = '"'+(ramo.getNombre_catedra())+" - "+nombre;
    setHor_espf(n_dia,n_bloque,casilla);
    ramo.setAsignacion(true);      
}          
   
void Sala::printBloques()
{
    for(int i=0;i<=7;i++)
    {
        for(int j=0;j<=5;j++)
        {
            cout<<getHor_espf(i,j);
        }
    }
}