#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <fstream>
#include <sstream> // hacer variable tipo
#include <iostream>
#include <ctime>

typedef unsigned int uint;
using namespace std;

//enum e_membresia{ clase=0, musculacion, ambos};


struct Cliente {

    string id_cliente;
    string Nombre,Apellido,mail,telefono,fechaNacimiento;
    //uint cant_asistencia,cant_cancel,cant_aus;
    int saldo;
    //e_membresia membresia;


}; typedef struct  Cliente sCliente;


    //Archivo Cliente

int LeerClienteArchivo(sCliente *&cliente, ifstream &archivo, uint &n); // Leo y lleno struct, aplicarun random para asistencia,cancelac y ausenc
void resize_cliente (sCliente *& cliente, uint &n);

    // Otras funciones

bool ControlEstado(sCliente *cliente); // si el saldo en negativo, devuelve falso
uint stringtouint(string texto);
void printCliente(sCliente *&cliente,uint n_cliente);


#endif
