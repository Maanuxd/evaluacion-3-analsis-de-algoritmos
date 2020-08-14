#include "Funciones.h"
#include "Carrera.h"
#include "Catedra.h"
#include "Sala.h"
using namespace std;
#define dirCatedra "data/ramos.csv"
#define dirAulas "data/salas.txt"
#define dirBloques "data/bloques.txt"
#define dias "Período, Lunes , Martes, Miércoles, Jueves, Viernes"
#define cantidad_dias 5




int main(int argc, char **argv)
{
       
    estudiantes();
    cout<<endl;
     auto start = chrono::system_clock::now();
    if(aprobador(dirCatedra)&&aprobador(dirAulas)&&aprobador(dirBloques))
    {
        std::vector<Sala> Aulas = generaAulas(dirAulas);
        std::vector<Carrera> Campus = Generador_Carreras(dirCatedra);
        std::vector<Catedra> carr_aux = CatedrasNoAsignadas(Campus);
        int m=0;
        while(carr_aux.size()!=0)
        {
            std::map<std::string,int> cont_catedra = Conteo_x_catedra(carr_aux);
            std::string lamayor = bigger_amount_seccion(cont_catedra);
            std::vector<int> celda_mayor = indexs_catedra(carr_aux,lamayor);
            std::vector<int> celda_check = mismoPeriodoLibre(Aulas,lamayor.size());
            long unsigned int cont=0;
            while(cont<celda_mayor.size())
            {
                for(unsigned int i=0; i<Aulas.size();i++)
                {
                    if(Aulas[i].getDisponibilidad(celda_check[0],celda_check[1]))
                    {
                        if(cont<celda_mayor.size())
                        {
                            Aulas[i].useHorario(carr_aux.at(cont),celda_check.at(0),celda_check.at(1));
                            cont++;
                            m++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        continue;
                    }
                    
                }
            }
            carr_aux = Comprobador(carr_aux);
        }
            
// DEBUGGING

    cout << "Conteo global de inserciones: " << m << endl;
    cout << "===== M2-201 =====" << endl;
    Aulas.at(0).printBloques();
    cout << endl;
    cout << "===== M2-202 =====" << endl;
    Aulas.at(1).printBloques();
    cout << endl;
    cout << "===== M2-203 =====" << endl;
    Aulas.at(2).printBloques();
    cout << endl;
    cout << "===== M2-204 =====" << endl;
    Aulas.at(3).printBloques();
    cout << endl;
    cout << "===== M2-205 =====" << endl;
    Aulas.at(4).printBloques();

    // Escribir csv

    // Escribir csv
        for(unsigned int i=0 ; i<Aulas.size();i++)
        {
            armarCsv(Aulas[i]);
        }
    }
    else 
    {
        cout<<"ERROR EN LA LECTURA DE ARCHIVO"<<endl;
    }

        auto end = chrono::system_clock::now();
        chrono::duration<float, milli> duration = end - start;
        cout << duration.count() << "'milisegundos" << endl; 
   return 0;

}