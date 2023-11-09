#include "Cliente.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>

int LeerClienteArchivo(sCliente *&cliente, ifstream Archivo){

    int N=1;
    char coma=',';
    stringstream ss;
    string primera_linea, aux,aux_nombre,aux_id,aux_apellido, aux_mail,aux_fechanc, aux_telefono, aux_saldo;


//    Archivo.open(filename);


    if(!Archivo.is_open())
    {
        cout<<"Error al abrir archivo" <<endl;
        return -1;
    }

    getline(Archivo,primera_linea);

    while(Archivo){

        getline(ss,aux);
        ss<<aux;

        getline(ss,aux_id,coma);
        cliente[N-1].id_cliente=aux_id;

        getline(ss,aux_nombre,coma);
        cliente[N-1].Nombre=aux_nombre;

        getline(ss,aux_apellido,coma);
        cliente[N-1].Apellido=aux_apellido;

        getline(ss,aux_mail,coma);
        cliente[N-1].mail=aux_mail;

        getline(ss,aux_telefono,coma);
        cliente[N-1].telefono=aux_telefono;

        getline(ss,aux_fechanc,coma);
        cliente[N-1].fechaNacimiento=aux_fechanc;

        getline(ss,aux_saldo,coma);
        cliente[N-1].saldo= stoi(aux_saldo);


       // aplicarun random para asistencia,cancelac y ausenc

        resize_cliente(cliente,N);

    }

    Archivo.close();
    return 0;



}

void resize_cliente (sCliente *& vector, int &N){
    N=(N)+1;
    sCliente *aux= new sCliente[N];
    for (int i=0; i< N-1; i++){
        aux [i]=vector[i];
    }
    delete[] vector;
    vector = aux;
}

