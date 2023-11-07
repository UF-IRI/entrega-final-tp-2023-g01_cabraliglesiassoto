#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <fstream>
#include <sstream> // hacer variable tipo


typedef unsigned int uint;
using namespace std;

enum e_membresia{ clase=0, musculacion, ambos};


struct Cliente {

    double id_cliente;
    string Nombre,Apellido,mail,telefono,fechaNacimiento;
    uint cant_asistencia,cant_cancel,cant_aus;
    int saldo;
    e_membresia membresia;


}; typedef struct  Cliente sCliente;


void Leer_Cliente_Archivo();

void consultar_estado(int saldo);



#endif
