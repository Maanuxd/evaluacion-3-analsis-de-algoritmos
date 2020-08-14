#ifndef SALA_H
#define SALA_H
#include "Catedra.h"

using namespace std;

class Sala : public Catedra
{
    private:
        std::vector<std::vector<std::string>> horarios; //horarios [dia][bloque]
        std::string dia; // lunes a viernes
        int num_dia; //from 1 to 5
        std::vector<Catedra> ramo; //vector de catedras con indice 8 
        std::string nombre_sala;  //from m2-201 to m2-205

    public:
        
        Sala();
        Sala(std::string , std::vector<std::vector<std::string>>);
        void setHorarios(std::vector<std::vector<std::string>>);
        void setHor_espf(int, int,std::string );
        std::string getHor_espf(int, int);
        std::vector<std::vector<std::string>>  getHorarios();        
        void setDia(std::string );
        std::string getDia();
        void setnum_dia(int );
        int  getnum_dia();
        void setRamo(std::vector<Catedra> );
        std::vector<Catedra> getRamo();
        void setnombre_sala(std::string );
        std::string getnombre_sala();
        bool getDisponibilidad(int ,int);
        void useHorario(Catedra &,int ,int);
        void printBloques();

};






#endif  //SALA_H