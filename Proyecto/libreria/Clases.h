#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <ctime>
#include <fstream>
#include "Cliente.h"

//using namespace std;
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
} sClases;


// Archivos
void sizeclases(sClases *& clase , uint &n );
void openclasearchivo(ifstream &archivo, sClases* &clase, uint &n); // leo archivo y lleno struct
void imprimir();

#endif // CLASES_H
