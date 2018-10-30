#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include <string>


#include <fstream>
#include<stdio.h>
#include<stdlib.h>
#include <cstdlib>
#include <conio.h>


#include "Model.h"
using namespace std;

class Controller
{
    public:
        void opcion(int a);
    private:
        Model modelo;
};


#endif // CONTROLLER_H
