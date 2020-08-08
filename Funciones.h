#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Semestre.h"
#include <chrono>
#include <dirent.h>
#include <sys/stat.h>
#include <omp.h>


void tokenize(std::string const &,const char);
double long cantidad_registros(string );
/*
**  @lee_catedras_from_file : funcion que lee el archivo .csv linea a linea como un string
    @param string : archivo .csv de lectura con info de pruebas de catedra a rendir
**
*/
vector<Semestre> lee_catedras_from_file(string );



#endif  //FUNCIONES_H