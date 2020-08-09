#ifndef SALA_H
#define SALA_H
#include "Catedra.h"

using namespace std;

class Sala{
    private:
        int bloque; //from 1 to 8
        string dia; // lunes a viernes
        int num_dia; //from 1 to 5
        Catedra ramo; 
        string nombre_sala;  //from m2-201 to m2-205

    public:
        Sala();
        void setBloque(int);
        int  getBloque();
        void setDia(string );
        string getDia();
        void setnum_dia(int );
        int  getnum_dia();
        void setRamo(Catedra );
        Catedra getRamo();
        void setnombre_sala(string );
        string getnombre_sala();

};






#endif  //SALA_H