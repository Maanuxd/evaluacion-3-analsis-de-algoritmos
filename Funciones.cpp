#include "Funciones.h"

/*
**  @tokenize : funcion de separacion en strings con un delimitador dado
    @param string str : seccion de lectura almacenada en una variable auxiliar
    @param const char delim : delimitador predeterminado   
**
*/
vector <string> tokenize(std::string str, char delim)
{
	vector<string> result;
    stringstream ss(str);
    while (ss.good()) {
        string substr;
        getline(ss, substr, delim);
        result.push_back(substr);
    }

    return result;
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
vector<Carrera> genera_catedras_from_file(string file)
{
    ifstream entrada(file);
    vector<Carrera> carr = Generador_Carreras(file);
    vector<Catedra> catedras;
    for(string linea; getline(entrada, linea);)
    {
        vector<string> arreglin = tokenize(linea,';');
        int lvl =stoi(arreglin[0].substr(1,arreglin[0].size()-1));
        int cod =stoi(arreglin[1].substr(1,arreglin[1].size()-1));
        Catedra asignatura = Catedra(lvl, arreglin[2], cod);
        for(unsigned int i=0; i<carr.size();i++)
        {
            if(cod == carr[i].getcod())
            {
                carr.at(i).setNombre_catedra(asignatura.getNombre_catedra());
            }
        }
    }
    return carr;
}

vector<Sala> generaAulas(string datos){
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
vector<Catedra> CatedrasNoAsignadas(vector<Carrera> campus)
{
    vector<Catedra> CatedrasNoAsignadas;
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
std::map<std::string,int> Conteo_x_catedra(vector<Catedra> arreglin)
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

vector<Sala> SalasDisponibles(vector<Sala> algo , int n_dia , int n_periodo)
{
    vector<Sala> aux;
    for(long unsigned int i=0; i<algo.size() ; i++)
    {
        if(algo[i].getDisponibilidad(n_dia,n_periodo))
        {
            aux.push_back(algo[i]);
        }
        
    }
    return aux;
}

vector<int> mismoPeriodoLibre(vector<Sala> salas, int cantidad)
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

string bigger_amount_seccion(std::map<std::string, int> amount_asignatura)
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

vector<int> indexs_catedra(vector<Catedra> ramos, string nombre_ramo)
{
    vector<int> indexs;
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
    string titulo= "Período;Lunes;Martes;Miércoles;Jueves;Viernes";
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

vector<Catedra> CatedraSinAsignar(vector<Carrera> algo)
{
    vector<Catedra> catedra_no_asignada;
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

vector<Catedra> Comprobador(vector<Catedra> algo)
{
    vector<Catedra> aux_sin_sala;
    for(long unsigned int i=0 ; i<algo.size() ;i++)
    {
        if(!algo[i].getAsignacion())
        {
            aux_sin_sala.push_back(algo[i]);
        }
    }
    return aux_sin_sala;
}

vector<Carrera> Generador_Carreras(string algo)
{
    vector<Carrera> aux_car;
    ifstream entrada(algo);
    for( string linea; getline(entrada, linea);)
    {
        vector<string> arreglin = tokenize(linea,';');
        string car = arreglin[1].substr(1, arreglin[1].size()-1);
        int cod = stoi(car);
        Carrera esta = Carrera(cod);
        if(!esta.existe(aux_car))
        {
            aux_car.push_back(esta);
        }
    }
    cout<<"... Se analizaron carreras en archivo"<<endl;
    return aux_car;
}

bool aprobador(string ruta)
{
    ifstream f(ruta.c_str());
    return f.good();
}

void Macro(){
    auto start = chrono::system_clock::now();
    if(aprobador(dirCatedra)&&aprobador(dirAulas)&&aprobador(dirBloques))
    {
        vector<Sala> Aulas = generaAulas(dirAulas);
        vector<Carrera> Campus = Generador_Carreras(dirCatedra);
        vector<Catedra> carr_aux = CatedrasNoAsignadas(Campus);
        int m=0;
        while(carr_aux.size()!=0)
        {
            std::map<string,int> cont_catedra = Conteo_x_catedra(carr_aux);
            string lamayor = bigger_amount_seccion(cont_catedra);
            vector<int> celda_mayor = indexs_catedra(carr_aux,lamayor);
            vector<int> celda_check = mismoPeriodoLibre(Aulas,lamayor.size());
            long unsigned int cont=0;
            while(cont<celda_mayor.size())
            {
                for(unsigned int i=0; i<Aulas.size();i++)
                {
                    if(Aulas[i].getDisponibilidad(celda_check[0],celda_check[1]))
                    {
                        if(cont<celda_mayor.size())
                        {
                            Aulas[i].useHorario(carr_aux[celda_mayor[cont]],celda_check[0],celda_check[1]);
                            cont++;
                            m++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            carr_aux = Comprobador(carr_aux);
        }
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
        cout << duration.count() << "'ms" << endl; 

}