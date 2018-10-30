#include "Paciente.h"

Paciente::Paciente(){
    nombre="NULL";
    edad=0;

}
Paciente::Paciente(string i,int j)
{
    nombre=i;
    edad=j;
}
Paciente::Paciente(const Paciente &pa){

    this->nombre=pa.nombre;
    this->apellido=pa.apellido;
    this->edad=pa.edad;
    this->p.Num_paciente=pa.p.Num_paciente;
}
bool Paciente::operator >(const Paciente& a){
    if(this->edad >= a.edad){
        return true;
    }
    return false;
}
bool Paciente::operator >=(const Paciente& a){
    if(this->p.Num_paciente >= p.Num_paciente){
        return true;
    }
    return false;
}
int Paciente::get_numpac(){
    return p.Num_paciente;
}
void Paciente::set_numpac(int a){
    p.Num_paciente=a;
}
