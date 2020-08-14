#ifndef CATEDRA_H
#define CATEDRA_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <filesystem>

using namespace std;

class Catedra
{
    private:
        int nivel;
        int codigo_carrera;
        string nombre_asignatura;
        bool asignado = false; 
    public:
        Catedra();
        Catedra(const Catedra& );
        Catedra(int, string ,int);
        void setNivel(int );
        int  getNivel();
        void setCodigo_carrera(int );
        int  getCodigo_carrera();
        void setNombre_catedra(string );
        string getNombre_catedra();
        void setAsignacion(bool );
        bool getAsignacion();
};

#endif  //CATEDRA_H