#include <iostream>
using namespace std;
#include "Controller.h"
#include <windows.h>


int lenght(char* a){
    int cont=0;
    for(int i=0;a[i]!='\0';i++){
        cont++;
    }
    return cont;
}

int conv_char(char a){
    return a-'0';
}

int  comodin(char *a,char* b){//b es el mayor
    int conta=0;
    if(lenght(b)<lenght(a)){
        return 0;
    }
    for(int i=0;b[i]!='\0';i++){
        if(b[i]==a[0]){
            for(int j=0;j<lenght(a);j++){
                if(a[j]==b[i+j]){
                    conta++;
                }
            }
            if(conta==lenght(a)){
                return 1;
            }
        }
    }
    return 0;
}

void ord_alf(char *a[],int tamanio){
    for(int i=0;i<tamanio-1;i++){
        if(conv_char(*(a[i])) >= conv_char(*(a[i+1]))){
            char * temp =a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
}


int main()
{
    /*
    char* a="pepe";
    char* b="pepean";
    char* c="asdpepeasd";
    char* d="asdasdpepe";
    cout<<comodin(a,b)<<endl;
    cout<<comodin(a,c)<<endl;
    cout<<comodin(a,d)<<endl;

    char* e[]={"Abeja","Carro","Burro","Elefante","Dentista"};
    ord_alf(e,5);
     for(int i=0;i<5;i++){//3
        cout<<e[i]<<endl;
        cout<<"\n";
    }
    */
    Controller c;
    while (true){
        int elec=0;
        cout<<"1) ORDENAR PACIENTES "<<endl;
        cout<<"2) INGRESAR NUEVO PACIENTE "<<endl;
        cout<<"3) MODIFICAR PACIENTE"<<endl;
        cout<<"4) ELIMINAR PACIENTE "<<endl;
        cout<<"5) BUSCAR PACIENTE"<<endl;
        cout<<"6) IMPRIMIR REGISTRO"<<endl;cin>>elec;
        c.eleccion(elec);
        system("pause");
        system("CLS");
    }





    return 0;

}

