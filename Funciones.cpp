#include "Funciones.h"

/*
**  @tokenize : funcion de separacion en strings con un delimitador dado
    @param string str : seccion de lectura almacenada en una variable auxiliar
    @param const char delim : delimitador predeterminado   
**
*/
void tokenize(std::string const &str,const char delim, std::vector<std::string> &out)
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
std::vector<Catedra> genera_catedras_from_file(string file)
{
    vector<Catedra> aux_catedra;
    string line;
    ifstream entrada(file);
    if(entrada.is_open())
    {
        while(getline(entrada,line))
        {
            const char delim = ';';
            std::vector<std::string> out;
            tokenize(line,delim,out);
            Catedra semestre = Catedra();
            semestre.setNivel(stoi(out.at(0)));
            semestre.setCodigo_carrera(out.at(1));
            semestre.setNombre_catedra(out.at(2));
            aux_catedra.push_back(semestre);
        }
        entrada.close();
    }
    return aux_catedra;
}

std::vector<Sala> generaAulas(string datos){
    vector<Sala> ss;
    ifstream salas(datos);
    for(string linea; getline(salas,linea);)
    {
        vector<vector<string>>per(6,vector<string>(8));
        for(int i=0;i<=5;i++)
        {
            for (int j=0;j<=7;j++)
            {
                if(i==0)
                {
                    per[i][j]='"'+std::to_string(j+1)+'"';
                }
                else
                {
                    per[i][j]='"';
                }
                
            }
        }
        Sala maestra = Sala(linea,per);
        ss.push_back(maestra);
    }
    return ss;
}

/*void procesa_salida(vector<Catedra> lista_semestral)
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

}*/
std::vector<Catedra> CatedrasNoAsignadas(std::vector<Carrera> campus)
{
    std::vector<Catedra> CatedrasNoAsignadas;
    for(long unsigned int i=0 ; i<campus.size() ; i++)
    {
        for(long unsigned int j=0; j<campus[i].getNombre_catedra().size();j++)
        {
                      
            if(!campus[i].getvec_superasig(j).getAsignacion())
            {
                CatedrasNoAsignadas.push_back(campus[i].getvec_superasig(j));
            }
        }
    }
    return CatedrasNoAsignadas;
}
std::map<std::string,int> Conteo_x_catedra(std::vector<Catedra> arreglin)
{
    std::vector<string>aux_catedra;
    for(long unsigned int i=0;i<arreglin.size();i++)
    {
        aux_catedra.push_back(arreglin.at(i).getNombre_catedra());
    }
    std::sort(aux_catedra.begin(),aux_catedra.end());
    auto it = std::unique(aux_catedra.begin(), aux_catedra.end());
    aux_catedra.erase(it, aux_catedra.end());
    std::map<std::string, int> amount;
    for(long unsigned int i=0 ; i<aux_catedra.size() ; i++)
    {
        int catedra_amount = 0;
        for(long unsigned int j=0 ; j<arreglin.size();j++)
        {
            if(aux_catedra[i]==arreglin[j].getNombre_catedra())
            {
                catedra_amount++;
            }
        }
        amount.insert(pair<std::string,int>(aux_catedra[i],catedra_amount));
    }
    return amount;
}

std::vector<Sala> SalasDisponibles(std::vector<Sala> algo , int n_dia , int n_periodo)
{
    std::vector<Sala> aux;
    for(long unsigned int i=0; i<algo.size() ; i++)
    {
        if(algo[i].getDisponibilidad(n_dia,n_periodo))
        {
            aux.push_back(algo[i]);
        }
        
    }
    return aux;
}

std::vector<int> mismoPeriodoLibre(std::vector<Sala> salas, int cantidad)
{
    vector<int> indexs; 
    for(long unsigned int i=1;i<6;i++)
    {
        for (long unsigned int j=0; j<8 ; j++)
        {
            int encontra2=0;
            for(long unsigned int k=0 ; k<salas.size() ; k++)
            {
                if(salas[k].getDisponibilidad(i,j))
                {
                    encontra2++;
                }
            }
            if(encontra2 >= cantidad)
            {
                indexs.push_back(i);
                indexs.push_back(j);
                return indexs;
            }       
        }
    }
    return indexs;
}

std::string bigger_amount_seccion(std::map<std::string, int> amount_asignatura)
{
    string aux_mayor;
    int mayor=0;
    for (const auto& a : amount_asignatura)
    {
        if(a.second>mayor)
        {
            aux_mayor=a.first;
        }
    }
    return aux_mayor;
}

std::vector<int> indexs_catedra(std::vector<Catedra> ramos, std::string nombre_ramo)
{
    std::vector<int> indexs;
    for(long unsigned int i=0; i<ramos.size();i++)
    {
        if(ramos[i].getNombre_catedra() == nombre_ramo)
        {
            indexs.push_back(i);
        }
    }
return indexs;
}

void armarCsv(Sala aula)
{
    std::string titulo= "Período;Lunes;Martes;Miércoles;Jueves;Viernes";
    ofstream myFile;
    myFile.open("salas/"+aula.getnombre_sala()+".csv");
    for (int i=0 ; i<8 ; i++)
    {
        for(int j=0;j<6 ;j++)
        {
            if(i==0 && j==0)
            {
                myFile << titulo << endl;
            }
        }
        myFile<<endl;
    }
}

void estudiantes()
{
    cout << endl
    << "[/////////////////////////]=== TAREA 03 ===[/////////////////////////]" << endl;
  cout << "[/////////////////////////]=== Kevin Labra Soto ===[/////////////////////////]"  << endl;
  cout << "[/////////////////////////]=== Manuel Toledo Levican ===[/////////////////////////]"  << endl;
}

std::vector<Catedra> CatedraSinAsignar(vector<Carrera> algo)
{
    std::vector<Catedra> catedra_no_asignada;
    for(long unsigned int i=0 ; i<algo.size();i++)
    {
        for(long unsigned int j=0 ; j<algo[i].getvec_asig().size();j++)
        {
            if(!algo[i].getAsignacion())
            {
                catedra_no_asignada.push_back(algo[i]);
            }
        }
    }
    return catedra_no_asignada;
}

std::vector<Catedra> Comprobador(std::vector<Catedra> algo)
{
    std::vector<Catedra> aux_sin_sala;
    for(long unsigned int i=0 ; i<algo.size() ;i++)
    {
        if(!algo[i].getAsignacion())
        {
            aux_sin_sala.push_back(algo[i]);
        }
    }
    return aux_sin_sala;
}

std::vector<Carrera> Generador_Carreras(string algo)
{
   std::vector<Carrera> lista_carreras;
   string line;
   ifstream entrada(algo);
   if(entrada.is_open())
   {
       while(getline(entrada,line))
       {
           const char delim = ';';
           std::vector<std::string> out;
           tokenize(line,delim,out);
           Carrera carr = Carrera();
           carr.setCodigo_carrera(stoi(out.at(0)));
           if(!carr.existe(lista_carreras))
           {
               lista_carreras.push_back(carr);
           }
           else
           {
               continue;
           }
       }
   }
    cout<<"... comprobador de que se crearon bien las carreras .... "<<endl;
    return lista_carreras;
}

bool aprobador(string ruta)
{
    ifstream f(ruta.c_str());
    return f.good();
}

void Macro(){
   

}