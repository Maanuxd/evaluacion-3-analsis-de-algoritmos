#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/**
 * @param argc cantidad de argumentos
 * @param argv argumentos
 */
struct Seccion {
    string nombre_ramo; //ramo del que se dara la prueba
    string codigo_carrera;
    string nivel;//semestre al que corresponde el ramo
    int periodo; //0 para mañana 1 para tarde
    int bloque; //numero de bloque horario, del 1 al 8
    string sala_designada; //sala designada para la prueba
};


vector<Seccion> secciones;
vector <Seccion> ordenar_secciones();
string sala[6][9];
vector <string> salas = {"M2-201","M2-202","M2-203","M2-204","M2-205"};
//vector<string> titulo = {"Periodo;Lunes;Martes;Miercoles;Jueves;Viernes"};

int main(int argc, char **argv){
    if (argc > 1){
        //ordenar archivo de carreras en un vector

        
        
        
    }   
    else{
        cout<<"No ha ingresado una palabra"<<endl;
    }
    
    return 0;
}

void corrector(){//Busca en el archivo admision-PSU.csv todas las , y las reemplaza por .
    ifstream archivo;
    string aux, espacio, titulo;
    int linea=0;

    archivo.open("ramos.csv",ios::in);
    ofstream auxiliar("auxiliar.csv");

    if(archivo.fail()){
        std::cout<<"ERROR AL BUSCAR EL ARCHIVO"<<endl;
        exit(1);
    }
    else{
        espacio ="";
        while(!archivo.eof()){
            
            getline(archivo,aux);
            int pos = aux.find('"');
            
            while (pos!=-1 ){
                aux.replace(pos,1,espacio);
                pos = aux.find('"',pos + espacio.size()); 
                
            }
            auxiliar<<aux<<endl;
        }
        archivo.close();
        auxiliar.close();
        remove("ramos.csv");
        rename("auxiliar.csv","ramos.csv");
    }
}

vector <Seccion> ordenar_secciones(vector<Seccion> secciones){
/**
 * Lee el archivo ramos.csv e ingresa los datos en un vector
*/
    int i=0,linea=0;
    ifstream archivo;
    string titulo;

    archivo.open("ramos.csv");
    
    if(archivo.fail()){
        std::cout<<"No se pudo leer el archivo"<<endl;
        exit(1);
    }
    else{ 
        std::cout<<"Leyendo archivo ramos...\n"<<endl;
        //leer archivo ramos.csv e ingresa los datos en un vector de struct
        while(!archivo.eof()){
            if (linea=0){
                getline(archivo,titulo,'\n');
                linea ++;
            }
                
            Seccion seccion;
            string nivel, codigo_carrera, asignatura;

            secciones.push_back(Seccion());

            getline(archivo,secciones[i].nivel,';');

            getline(archivo,secciones[i].codigo_carrera,';');

            getline(archivo,secciones[i].nombre_ramo,'\n');
            
                
            if(!archivo.eof()){
                i++;
            }
        }
        secciones.pop_back();       
    }
    
    archivo.close();

    return secciones;
    std::cout<<"\nVECTOR SECCIONES ORDENADO :D"<<"\n"<<endl;
}

void crear_salidas(vector <Seccion> secciones, vector<string>salas){//crear archivos.csv para cada sala
    //recorrer vector carreras, y en cada iteracion cear un archivo.txt de 
    //nombre=codigo.carrera
    std::cout<<"renombrando archivos...\n"<<endl;
    string nombre_archivo;

    for(int i=0; i<5;i++){
        nombre_archivo=salas[i];
        nombre_archivo+=".csv";
        
        ofstream archivo;
        archivo.open(nombre_archivo.c_str(),ios::out);
        
        archivo<<"Periodo;Lunes;Martes;Miercoles;Jueves;Viernes"<<endl;
        
        
        archivo.close();
    }
    std::cout<<"Hecho"<<endl;
}