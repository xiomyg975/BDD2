#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
//#include "Model.h"
#include <string>


using namespace std;


class Controller
{
    protected:
    string usuario;
    string password;
    int opc;
    public:
    void ingreso();
};

#endif // CONTROLLER_H
