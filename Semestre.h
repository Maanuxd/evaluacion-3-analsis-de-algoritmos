#ifndef SEMESTRE_H
#define SEMESTRE_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <filesystem>

using namespace std;

class Semestre{
    private:
        int nivel;
        int codigo_carrera;
        string nombre_asignatura;
    public:
        /*
        **constructor por defecto
        */
        Semestre();
        void setNivel(int );
        int  getNivel();
        void setCodigo_carrera(int );
        int  getCodigo_carrera();
        void setNombre_catedra(string );
        string getNombre_catedra();
};

#endif  //SEMESTRE_H