#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include <string>
using namespace std;

class Persona
{
    public:
        void set_nombre(string a);
        void set_apellido(string a);
        void set_edad(int);
        string get_nombre();
        string get_apellido();
        int get_edad();
    protected:
        string nombre;
        string apellido;
        int edad;
};

#endif // PERSONA_H
