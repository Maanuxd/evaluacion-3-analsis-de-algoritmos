#ifndef SALA_H
#define SALA_H
#include "Catedra.h"

using namespace std;

class Sala : public Catedra
{
    private:
        vector<vector<string>> horarios; //horarios [dia][bloque]
        string dia; // lunes a viernes
        int num_dia; //from 1 to 5
        vector<Catedra> ramo; //vector de catedras con indice 8 
        string nombre_sala;  //from m2-201 to m2-205

    public:
        
        Sala();
        Sala(string , vector<vector<string>>);
        void setHorarios(vector<vector<string>>);
        void setHor_espf(int, int,string );
        string getHor_espf(int, int);
        vector<vector<string>>  getHorarios();        
        void setDia(string );
        string getDia();
        void setnum_dia(int );
        int  getnum_dia();
        void setRamo(vector<Catedra> );
        vector<Catedra> getRamo();
        void setnombre_sala(string );
        string getnombre_sala();
        bool getDisponibilidad(int ,int);
        void useHorario(Catedra &,int ,int);
        void printBloques();

};






#endif  //SALA_H