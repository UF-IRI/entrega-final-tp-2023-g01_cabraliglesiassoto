#ifndef CLASE_H
#define CLASE_H
#include <iostream>
#include<time.h>
#include <string>
#include <fstream>
#include <sstream> // hacer variable tipo
#include "Cliente.h"

using namespace std;
typedef unsigned int uint;

enum sala {bicis,siri,camillas,gim1,gim2,box} ;
enum cupo_max { cupo};

struct sClase{
    uint id_clase;
    string clase_nombre;
   // uint  cupo_max;
  //  sala cod_sala;
    uint horario;

};

 bool estado_sala;
 uint horario[]={8,9,10,11,12,13,14,15,16,17,18,19};


 // Archivos

 int Leer_Clase_Archivo( sClase *& CLASE);
 void resize(sClase *& CLASE , uint &n );


bool Comprobar_sala(bool estado_sala, sala cod_sala, sClase clase );
bool Comprobar_horario(sClase clase, sCliente cliente);


// si usabamos tiempo ... podiamos usar esta
void ReservarTurno(sClase clase, sCliente client, tm horario );


// con tiempo en uint;
void ReservarTurno2(sClase clase, sCliente client, uint horario );
void CancelarTurno2(sClase clase, sCliente client, uint horario);


void Listar_Alumnos(sClase clase);




#endif // CLASE_H
