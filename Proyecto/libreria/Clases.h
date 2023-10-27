#ifndef CLASES_H
#define CLASES_H
#include<time.h>
#include <string>
#include "Cliente.h"
using namespace std;
typedef unsigned int uint;

enum sala {bicis,siri,camillas,gim1,gim2,box} ;

uint horario[]={8,9,10,11,12,13,14,15,16,17,18,19};
bool estado_sala;

struct Clase{

    string class_name;
    uint  cupo_max, cupo_reser;
    sala cod_sala;
    tm horario;
    sCliente *cliente;


}; typedef struct Clase sClase;



bool Comprobar_sala(bool estado_sala, sala cod_sala, sClase clase );
bool Comprobar_horario(sClase clase, sCliente cliente);


// si usabamos tiempo ... podiamos usar esta
void ReservarTurno(sClase clase, sCliente client, tm horario );
void CancelarTurno(sClase clase, sCliente client, tm horario);

// con tiempo en uint;
void ReservarTurno2(sClase clase, sCliente client, uint horario );
void CancelarTurno2(sClase clase, sCliente client, uint horario);


void Listar_Alumnos(sClase clase);


#endif
