#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <Controller.h>

using namespace std;
class Persona : public Controller
{

    private:
        char nombre[30];
        char apellidos[30];
        string domicilio;
        int edad;
    public:
        Persona();
        int registro();
        void altas();
//        char sexo();
        //int numHistorial();
};

#endif // PERSONA_H
