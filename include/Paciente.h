#ifndef PACIENTE_H
#define PACIENTE_H
#include "Persona.h"
#include "Pacien.h"
class Paciente:public Persona
{
        Pacien p;

    public:
        Paciente();
        Paciente(string,int);
        Paciente(const Paciente &p);
        bool operator > (const Paciente& a);
        bool operator >= (const Paciente& a);
        int get_numpac();
        void set_numpac(int);

};

#endif // PACIENTE_H
