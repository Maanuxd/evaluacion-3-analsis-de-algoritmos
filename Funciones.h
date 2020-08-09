#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Sala.h"
#include "Catedra.h"
#include <chrono>
#include <dirent.h>
#include <sys/stat.h>
#include <omp.h>

//superestructura temporal para crear los archivos en paralelo
class ParallelPrint{
    private: 
        vector <Sala> lista_salas;
        int numero_periodo;
    public:
        void setSalidaList(vector <Sala> salida){
            lista_salas = salida;
        }
        vector<Sala> getlista_salas(){
            return lista_salas;
        }
        void setNumero_periodo(int c){
            numero_periodo = c;
        }
        int getNumero_periodo(){
            return numero_periodo;
        }
};

void tokenize(std::string const &,const char);
double long cantidad_registros(string );
/*
**  @lee_catedras_from_file : funcion que lee el archivo .csv linea a linea como un string
    @param string : archivo .csv de lectura con info de pruebas de catedra a rendir
**
*/
vector<Catedra> lee_catedras_from_file(string );

/*
**  @procesa_salida : metodo que pretende determinar horario para 1 bloque
    @param
    @param
**    
*/
void procesa_salida(vector<Catedra>  , vector<Sala> , string );


#endif  //FUNCIONES_H