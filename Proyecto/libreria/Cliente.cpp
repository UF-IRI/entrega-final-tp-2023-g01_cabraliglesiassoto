#include "Cliente.h"
#include <iostream>
#include<time.h>
#include <fstream>
#include <sstream>

int Leer_Cliente_Archivo(sCliente *&cliente, string filename){
    ifstream file (filename);
    if (!file.is_open()) {
        return 1;
    }
    string header;
    getline(file, header); // leo el header del archivo .csv y lo guardo en un auxiliar
    char coma;
    int N=1;
    while (file.good()){
        file >> cliente->id_cliente >> coma >> cliente->Apellido >> coma >> cliente->Nombre >> coma >> cliente->mail >>
        coma >> cliente->fechaNacimiento >> coma >>cliente->stoi(saldo);
        resize (cliente, N);
    }
    file.close();
}

void resize (sCliente *& vector, int &N){
    N=(N)+1;
    sCliente *aux= new sCliente[N];
    for (int i=0, i< N-1, i++){
        aux [i]=vector[i];
    }
    delete[] vector;
    vector = aux;
}
