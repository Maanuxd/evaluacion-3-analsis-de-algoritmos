#ifndef CARRERA_H
#define CARRERA_H
#include "Catedra.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <filesystem>

using namespace std;

class Carrera : public Catedra
{
    private:
        int codigo;
        vector<Catedra> asignaturas;
    public:
        Carrera();
        Carrera(int);
        Carrera(int , vector<Catedra>);
        bool existe(vector<Carrera>);
        void setcod(int);
        int getcod();
        void setvec_asig(vector<Catedra>);
        vector<Catedra> getvec_asig();
        Catedra getvec_superasig(int );
};

#endif //CARRERA_H