#ifndef CLASE_H
#define CLASE_H
#include <iostream>
#include <ctime>
#include <fstream>
#include "Cliente.h"

using namespace std;
typedef unsigned int uint;

enum sala {bicis,siri,camillas,gim1,gim2,box};
typedef enum sala eSala;
enum cupo_max { spinn=45,yoga= 25, pilates=15, stretching=40,zumba= 50 ,boxeo=30};
typedef enum cupo_max eCupo_max;

typedef struct{
    string id_clase;
    string clase_nombre;
    float horario;
    eCupo_max  cupo_max;
    //   sala cod_sala;
} sClase;


 // Archivos
void resize_clase(sClase *& CLASE , uint &n );
int LeerClaseArchivo(ifstream &Archivo, sClase *&clase, uint &n); // leo archivo y lleno struct
eCupo_max CupoMaximoStruct(string nombre_clase); // sirve para llenar cupo max al struct
 //Alumnos

bool Comprobar_sala(bool estado_sala, sala cod_sala, sClase clase );
//bool Comprobar_horario(sClase clase, sCliente cliente);



#endif // CLASE_H














//bool estado_sala;
//uint horario[]={8,9,10,11,12,13,14,15,16,17,18,19};
