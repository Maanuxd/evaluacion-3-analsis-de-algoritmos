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
vector<string> tokenize(std::string ,char);
double long cantidad_registros(string );
/*
**  @genera_catedras_from_file : funcion que lee el archivo .csv linea a linea como un string
    @param string : archivo .csv de lectura con info de pruebas de catedra a rendir
**
*/
vector<Carrera> genera_catedras_from_file(string);

/*
**  @procesa_salida : metodo que pretende determinar horario para 1 bloque
    @param
    @param
**    
*/
void procesa_salida(vector<Catedra>  , vector<Sala> , string );

std::map<std::string,int> Conteo_x_catedra(std::vector<Catedra> );

vector<Sala> SalasDisponibles(vector<Sala>, int, int);
string bigger_amount_seccion(std::map<std::string, int>);
void estudiantes();
void metodo_Asignador();
void armarCsv(Sala);
vector<int> mismoPeriodoLibre(vector<Sala>, int );
vector<int> indexs_catedra(vector<Catedra> , string );
vector<Catedra> CatedraSinAsignar(vector<Carrera> );
vector<Catedra> Comprobador(vector<Catedra>);
vector<Carrera> Generador_Carreras(string );
bool aprobador(string);



#endif  //FUNCIONES_H