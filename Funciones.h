#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Sala.h"
#include "Catedra.h"
#include "Carrera.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <chrono>

void tokenize(std::string const& ,const char , std::vector<std::string>& );
double long cantidad_registros(string );
/*
**  @genera_catedras_from_file : funcion que lee el archivo .csv linea a linea como un string
    @param string : archivo .csv de lectura con info de pruebas de catedra a rendir
**
*/
std::vector<Catedra> genera_catedras_from_file(string);

/*
**  @procesa_salida : metodo que pretende determinar horario para 1 bloque
    @param
    @param
**    
*/
void procesa_salida(std::vector<Catedra>  , std::vector<Sala> , std::string );
std::vector<Sala> generaAulas(std::string );
std::map<std::string,int> Conteo_x_catedra(std::vector<Catedra> );
std::vector<Catedra> CatedrasNoAsignadas(std::vector<Carrera> );
std::vector<Sala> SalasDisponibles(std::vector<Sala>, int, int);
std::string bigger_amount_seccion(std::map<std::string, int> );
void estudiantes();
void metodo_Asignador();
void armarCsv(Sala );
std::vector<int> mismoPeriodoLibre(std::vector<Sala> , int);
std::vector<int> indexs_catedra(std::vector<Catedra> , string );
std::vector<Catedra> CatedraSinAsignar(std::vector<Carrera> );
//
std::vector<Catedra> Comprobador(std::vector<Catedra> );
std::vector<Carrera> Generador_Carreras(std::string );
bool aprobador(std::string );
void Macro();


#endif  //FUNCIONES_H