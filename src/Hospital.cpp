#include "Hospital.h"

Hospital::Hospital(){
    bool b=true;
    int cont=1;
    while(b==true){
        string nameArchivo=convertiratexto(cont);
        nameArchivo += ".txt";
        ifstream fs(nameArchivo.c_str(),ios :: in);
        if(fs.fail()){
            b=false;
            tamanio--;
        }
        tamanio++;
        fs.close();
        cont++;
        contador++;
    }

    a=new Paciente[tamanio];

    for(int i=1;i<=tamanio;i++){
        string nameArchivo=convertiratexto(i);
        nameArchivo += ".txt";
        ifstream fs(nameArchivo.c_str(),ios :: in);
        a[i-1].set_nombre(obt_linea(nameArchivo,0));
        ////////////////////
        a[i-1].set_apellido(obt_linea(nameArchivo,1));
        ///////////////////
        string temp1=obt_linea(nameArchivo,2);
        a[i-1].set_edad(convertiranumero(temp1));
        ///////////////////
        string temp2=obt_linea(nameArchivo,3);
        a[i-1].set_numpac(convertiranumero(temp2));
        //////////////////
        fs.close();
    }
}

int Hospital::lenght(string a){
    int cont=0;
    for(int i=0;a[i]!='\0';i++){
        cont++;
    }
    return cont;
}

int Hospital::conv_char(char a){
    return a-'0';
}

string Hospital::obt_linea(string a,int b){
    ifstream archivo_entrada(a);
    string linea;
    int contador = 0;
    while(getline(archivo_entrada, linea)) {
        if(b==contador) {
            return linea;
        }
        contador++;
    }
}

string Hospital::convertiratexto(float f){
    stringstream ss;
	ss << f;
	return ss.str();
}

void Hospital::mod_arch(string arch,string nomb="NULL",string apell="NULL",int edad=0,int num=0){
    string nameArchivo=arch;
    nameArchivo += ".txt";
    ofstream fs(nameArchivo.c_str());
    fs <<nomb<<endl;
    fs <<apell<<endl;
    fs <<edad<<endl;
    fs <<num<<endl;
    fs.close();

}


int Hospital::convertiranumero(string texto1){
	int number;
	number = atof(texto1.c_str());
	return number;
}


char Hospital::p_l(string a){
    return a[0];
}

void Hospital::imprimir(){
    for(int i=0;i<tamanio;i++){
        cout<<"///////////////////////////////////"<<endl;
        cout<<"POSICION: "<<i+1<<endl;
        cout<<"Nombre: "<<a[i].get_nombre()<<" ";
        cout<<a[i].get_apellido()<<endl;
        cout<<"EDAD: "<<a[i].get_edad()<<endl;
        cout<<"NUMERO DE PACIENTE: "<<a[i].get_numpac()<<endl;
        cout<<"///////////////////////////////////"<<endl;
    }
}
void Hospital::borrar(int posicion){

    for(int i=posicion;i<tamanio-1;i++){
        string nombtemp1=a[i].get_nombre();
        string apelltemp1=a[i].get_apellido();
        int edadtemp1=a[i].get_edad();
        int numptemp1=a[i].get_numpac();

        string nombtemp2=a[i+1].get_nombre();
        string apelltemp2=a[i+1].get_apellido();
        int edadtemp2=a[i+1].get_edad();
        int numptemp2=a[i+1].get_numpac();

        mod_arch(convertiratexto(i+1),nombtemp1,apelltemp1,edadtemp1,numptemp1);
        mod_arch(convertiratexto(i+2),nombtemp2,apelltemp2,edadtemp2,numptemp2);
    }
    //////////
    string nameArchivo=convertiratexto(posicion+1);
    nameArchivo += ".txt";
    char buffer[5];
    strcpy(buffer,nameArchivo.c_str());
    remove(buffer);
    ///////////
    Paciente *nuevo= new Paciente [tamanio-1];
    tamanio--;
    for(int i=0;i<posicion;i++){
        nuevo[i]=a[i];
    }
    for(int i=posicion;i<tamanio;i++){
        nuevo[i]=a[i+1];
    }
    delete [] a;
    a=nuevo;
    //////////////////
    string nameA=convertiratexto(posicion+2);
    nameA+=".txt";
    char buffer1[5];
    strcpy(buffer1,nameA.c_str());
    rename(buffer1,buffer);
}
void Hospital::vacear(){
    for(int i=1;i<=tamanio;i++){

        string nameArchivo=convertiratexto(i);
        nameArchivo += ".txt";
        char buffer[5];
        strcpy(buffer,nameArchivo.c_str());
        remove(buffer);
    }
    cout<<"a"<<endl;
    delete [] a;
    tamanio=0;
}
int Hospital::get_tamanio(){
    return tamanio;
}

void Hospital::agregar(string nuevonombre,string nuevoapellido,int nuevaedad){
    Paciente *nuevo= new Paciente[tamanio+1];
    for(int i=0;i<tamanio;i++){
        nuevo[i]=a[i];
    }
    tamanio++;
    nuevo[tamanio-1].set_nombre(nuevonombre);
    nuevo[tamanio-1].set_apellido(nuevoapellido);
    nuevo[tamanio-1].set_edad(nuevaedad);
    nuevo[tamanio-1].set_numpac(++contador);
    delete [] a;
    a=nuevo;

    mod_arch(convertiratexto(get_tamanio()),nuevonombre,nuevoapellido,nuevaedad,a[tamanio-1].get_numpac());

}
void Hospital::cambiar(int pos,int ed, string nom,string apell){
    a[pos].set_edad(ed);
    a[pos].set_nombre(nom);
    a[pos].set_apellido(apell);
    mod_arch(convertiratexto(pos+1),nom,apell,ed,a[pos].get_numpac());
}
int Hospital::comodin(string a,string b){
    int conta=0;
    if(lenght(b)<lenght(a)){
        return 0;
    }
    for(int i=0;b[i]!='\0';i++){
        if(b[i]==a[0]){
            for(int j=0;j<3;j++){
                if(a[j]==b[i+j]){
                    conta++;
                }
            }
            if(conta==3){
                return 1;
            }
        }
    }
    return 0;
}


void Hospital::ord_edad(){
    int cont=1;
    while(cont!=0){
        cont=0;
        for(int i=0;i<tamanio-1;i++){
            if(a[i] > a[i+1]){
                Paciente b(a[i]);
                a[i]=a[i+1];
                a[i+1]=b;

                string nombtemp1=a[i].get_nombre();
                string apelltemp1=a[i].get_apellido();
                int edadtemp1=a[i].get_edad();
                int numptemp1=a[i].get_numpac();

                string nombtemp2=a[i+1].get_nombre();
                string apelltemp2=a[i+1].get_apellido();
                int edadtemp2=a[i+1].get_edad();
                int numptemp2=a[i+1].get_numpac();

                mod_arch(convertiratexto(i+1),nombtemp1,apelltemp1,edadtemp1,numptemp1);
                mod_arch(convertiratexto(i+2),nombtemp2,apelltemp2,edadtemp2,numptemp2);

                cont+=1;
            }
        }
    }
}

void Hospital::ord_alf()
{
    int cont=1;
    while(cont!=0){
        cont=0;
        for(int i=0;i<tamanio-1;i++){
            string uno=a[i].get_nombre();
            string dos=a[i+1].get_nombre();
            if(conv_char(p_l(uno)) > conv_char(p_l(dos))){
                Paciente temp(a[i]);
                a[i]=a[i+1];
                a[i+1]=temp;


                string nombtemp1=a[i].get_nombre();
                string apelltemp1=a[i].get_apellido();
                int edadtemp1=a[i].get_edad();
                int numptemp1=a[i].get_numpac();

                string nombtemp2=a[i+1].get_nombre();
                string apelltemp2=a[i+1].get_apellido();
                int edadtemp2=a[i+1].get_edad();
                int numptemp2=a[i+1].get_numpac();

                mod_arch(convertiratexto(i+1),nombtemp1,apelltemp1,edadtemp1,numptemp1);
                mod_arch(convertiratexto(i+2),nombtemp2,apelltemp2,edadtemp2,numptemp2);




                cont+=1;
            }
        }
    }
}

void Hospital::ord_numpac(){
    int cont=1;
    while(cont!=0){
        cont=0;
        for(int i=0;i<tamanio-1;i++){
            if(a[i] >= a[i+1]){
                Paciente b(a[i]);
                a[i]=a[i+1];
                a[i+1]=b;

                string nombtemp1=a[i].get_nombre();
                string apelltemp1=a[i].get_apellido();
                int edadtemp1=a[i].get_edad();
                int numptemp1=a[i].get_numpac();

                string nombtemp2=a[i+1].get_nombre();
                string apelltemp2=a[i+1].get_apellido();
                int edadtemp2=a[i+1].get_edad();
                int numptemp2=a[i+1].get_numpac();

                mod_arch(convertiratexto(i+1),nombtemp1,apelltemp1,edadtemp1,numptemp1);
                mod_arch(convertiratexto(i+2),nombtemp2,apelltemp2,edadtemp2,numptemp2);


                cont+=1;
            }
        }
    }
}


bool Hospital::buscar(string a,string b){
    int conta=1;
    if(lenght(b)<lenght(a)){
        return 0;
    }
    for(int i=0;b[i]!='\0';i++){
        if(b[0]==a[0]){
            if(a[i]==b[i]){
                conta++;
            }
            if(conta==lenght(b)){
                return 1;
            }
        }
    }
    return 0;
}

void Hospital::bus_rela(string nnombre){
    for(int i=0;i<tamanio;i++){
        if(buscar(nnombre,a[i].get_apellido())){
            cout<<"Encontrado"<<endl;
            cout<<"Nombre: "<<a[i].get_nombre()<<" ";
            cout<<a[i].get_apellido()<<endl;
            cout<<"Edad: "<<a[i].get_edad()<<endl;
            cout<<"Numero de paciente: "<<a[i].get_numpac()<<endl;
            return;
        }
    }
    cout<<"Busquedas relacionadas: "<<endl;
    for(int i=0;i<tamanio;i++){
        if(comodin(nnombre,a[i].get_nombre())){
            cout<<a[i].get_nombre()<<endl;
        }
    }
}
void Hospital::bus_numpac(int num){
    int en=0;
    for(int i=0;i<tamanio;i++){
        if(a[i].get_numpac() == num){
            cout<<"Encontrado"<<endl;
            cout<<"Nombre: "<<a[i].get_nombre()<<" ";
            cout<<a[i].get_apellido()<<endl;
            cout<<"Edad: "<<a[i].get_edad()<<endl;
            cout<<"Numero de paciente: "<<a[i].get_numpac()<<endl;
            en+=1;
        }
    }
    if(en==0){
        cout<<"NO ENCONTRADO"<<endl;
    }
}
Hospital::~Hospital(){
    delete []a;
}


