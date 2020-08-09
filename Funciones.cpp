#include "Funciones.h"

/*
**  @tokenize : metodo de separacion en strings con un delimitador dado
    @param string const &str : seccion de lectura almacenada en una variable auxiliar
    @param const char delim : delimitador predeterminado
    @param vector<string> &out : seccion restante del archivo
**
*/
void tokenize(std::string const &str, const char delim, 
			std::vector<std::string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

/*
**  @cantidad_registros : funcion que retorna la cantidad de filas/"registros" en el archivo .csv leido
    @param file : archivo .csv de lectura enviado por consola
**
*/
double long cantidad_registros(string file)
{
    std::ifstream f(file);
    std::string line;
    double long i=0;
    while(getline(f,line)){
        i++;
    }
    return i;
}

/*
**  @lee_catedras_from_file : funcion de lectura y almacenamiento para las catedras en el archivo .csv 
    @string file : archivo .csv de lectura
**
*/
vector<Catedra> lee_catedras_from_file(string file)
{
    vector<Catedra> lista_semestral;
    string line;
    ifstream file_semestral (file);
    if (file_semestral.is_open())
    {
        Catedra sems = Catedra();
        while(getline(file_semestral,line))
        {
            const char delim = ';';
            std::vector<std::string> out;
            tokenize(line, delim, out); 
            sems.setNivel(stoi(out.at(0)));
            sems.setCodigo_carrera(stoi(out.at(1)));
            sems.setNombre_catedra(out.at(2));
            lista_semestral.push_back(sems); 
        }
        file_semestral.close();
    }
    cout<<"\t** Se ha completado la lectura de asignaturas a sortear **"<<endl;
    return lista_semestral;
}

void procesa_salida(vector<Catedra> lista_semestral)
{
    vector<Catedra> catedra_list_temp = lista_semestral;
    vector<Catedra> mismas_catedras;
    vector<ParallelPrint> paralell_list;
    ParallelPrint parallel_obj = ParallelPrint();
    for(auto Catedra::lista_semestral)
    {
        bool catedras_repetidas = false;
        vector<Sala> salas_temp;
        int cont=1;
        for ( int i=1 ; i<=cont ; i++){

        }
    }

}

