#ifndef CLASE_H
#define CLASE_H
#include <iostream>
#include <ctime>
#include "Cliente.h"

using namespace std;
typedef unsigned int uint;

enum sala {bicis,siri,camillas,gim1,gim2,box};
typedef enum sala eSala;
enum cupo_max { spinn=45,yoga= 25, pilates=15, stretching=40,zumba= 50 ,boxeo=30};
typedef enum cupo_max eCupo_max;

typedef struct{
    uint id_clase;
    string clase_nombre;
  //  uint  cupo_max;
 //   sala cod_sala;
    uint horario;
} sClase;

//bool estado_sala;
//uint horario[]={8,9,10,11,12,13,14,15,16,17,18,19};


 // Archivos
int LeerClaseArchivo(sClase *& CLASE, ifstream &Archivo);
 void resize_clase(sClase *& CLASE , int &n );


bool Comprobar_sala(bool estado_sala, sala cod_sala, sClase clase );
bool Comprobar_horario(sClase clase, sCliente cliente);


// con tiempo en uint;
void ReservarTurno2(sClase clase, sCliente client, uint horario );
void CancelarTurno2(sClase clase, sCliente client, uint horario);



void Listar_Alumnos(sClase clase);


#endif // CLASE_H
