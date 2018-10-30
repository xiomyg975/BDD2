#include "Persona.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <direct.h>
#include <string>
Persona::Persona():Controller(){
}
int Persona :: registro()
{

    int op;
    do {
        system("cls");
        cout<<"\t\t\tBIENVENIDO E"<<endl;
        cout<<"\t\t\t------------------------------"<<endl;
        cout<<"[1]. ALTAS "<<endl;
        //cout<<"[2]. BUSCAR"<<endl;
        cout<<"[0]. SALIR "<<endl;
        cout<<"INGRESE OPCION  :  ";
        cin>>op;
        system("cls");
        switch (op){
        case 1:
        {

            altas();
            break;
        }
        case 2:
        {
            //buscar();
            break;
        }
    }
        }while (op != 0);

}
void Persona ::altas()
{
string nameArchivo;
    string extension;
        cout<<"INGRESE EL NOMBRE DEL NUEVO PACIENTE :";
            cin.ignore();
            getline(cin,nameArchivo);
            system("cls");
            cout<<"\t\t\tALTA NUEVA"<<endl;
            cout<<"\t\t\t----------"<<endl;
            cout<<"NOMBRE     :";
            cin.getline(nombre,30);
            cout<<"APELLIDOS  : ";
            cin.getline(apellidos,30);
            cout<<"EDAD    :";
            cin>>edad;
            nameArchivo += ".txt";
            ofstream fs(nameArchivo.c_str());
            fs <<"NOMBRE   : "<<nombre<<endl;
            fs <<"APELLIDO :"<<apellidos<<endl;
            fs <<"EDAD  :"<<edad<<endl;
            //fs <<"DIRECCION :"<<domicilio<<endl;

            fs.close();
            cout<<" REGISTRO GUARDADO...... "<<endl;
            system("pause");


}
