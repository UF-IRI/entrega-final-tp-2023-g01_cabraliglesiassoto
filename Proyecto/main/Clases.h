#ifndef CLASES_H
#define CLASES_H
#include "Cliente.h"

//using namespace std;
typedef unsigned int uint;

enum sala {bicis,siri,camillas,gim1,gim2,box};
typedef enum sala eSala;
enum cupo_max { spinn=45,yoga= 25, pilates=15, stretching=40,zumba= 50 ,boxeo=30,musculacion=15};
typedef enum cupo_max eCupo_max;


 struct Clases{
    string id_clase;
    string clase_nombre;
    float horario;
    eCupo_max  cupo_max;
    uint cant_clientes;
    //   sala cod_sala;
 };typedef struct Clases sClases;


// Archivos
void resize_clases(sClases *& clase , uint &n );
void LeerClaseArchivo(ifstream &archivo, sClases* &clase, uint &n); // leo archivo y lleno struct
void printClase(sClases *&clases);
eCupo_max LlenarCupo(string clase_nombre);
float BuscarHorario(string id_clase,sClases *clase);



#endif // CLASES_H
