#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <fstream>
#include <sstream> // hacer variable tipo


typedef unsigned int uint;
using namespace std;

//enum e_membresia{ clase=0, musculacion, ambos};


struct Cliente {

    string id_cliente;
    string Nombre,Apellido,mail,telefono,fechaNacimiento;
    uint cant_asistencia,cant_cancel,cant_aus;
    int saldo;
    //e_membresia membresia;


}; typedef struct  Cliente sCliente;


    //Archivo Cliente

int LeerClienteArchivo(sCliente *cliente, ifstream Archivo); // Leo y lleno struct, aplicarun random para asistencia,cancelac y ausenc
void resize_cliente (sCliente *& vector, int &N);

    // Otras funciones
bool ControlEstado(sCliente *cliente); // si el saldo en negativo, devuelve falso
    //void ControlSaldo(int saldo);
#endif
