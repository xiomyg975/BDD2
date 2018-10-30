#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Paciente.h"
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <conio.h>

#include<iostream>
using namespace std;
class Hospital
{
    public:
        Hospital();
        int get_tamanio();
        void cambiar(int, int ,string,string);
        void imprimir();
        void borrar(int);
        void vacear();
        int comodin(string,string);

        void ord_edad();
        void ord_alf();
        void ord_numpac();

        bool buscar(string,string);
        void bus_rela(string);
        void bus_numpac(int);


        void agregar(string,string,int);
        ~Hospital();
    protected:
        char p_l(string);
        int lenght(string);
        int conv_char(char);
        void mod_arch(string,string,string,int,int);
        string convertiratexto(float );
        int convertiranumero(string);
        string obt_linea(string,int);
        int contador=1799;
    private:
        Paciente *a;
        int tamanio=0;
};

#endif // HOSPITAL_H
