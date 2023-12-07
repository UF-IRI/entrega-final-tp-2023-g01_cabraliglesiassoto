#ifndef ASISTENCIA_H
#define ASISTENCIA_H
#include "Clases.h"
#include <ctime>

struct Inscripciones {
    string id_clase;
    time_t fecha; //time_t
}; typedef struct  Inscripciones sInscripciones;

struct Asistencia {
    string id_cliente;
    uint cant_inscripcion;
    sInscripciones *inscripciones;
}; typedef struct  Asistencia sAsistencia;



/*Archivos y resize*/

/* Devuelve un archivo con las asistencias validas en formato binario y txt (esto es para guiarnos nosotros)*/

void EscribirArchivoBIN(sAsistencia *&Asistencia, ofstream &archibinwr,uint cant_asistencia);
void EscribirArchivoTXT(sAsistencia *&Asistencias, ofstream &archibinwr,uint cant_asistencia);

void resize_asistencia(sAsistencia *&asist,uint &n);
void resize_inscriptos(sInscripciones *&inscrip ,uint &n);

/* Reservas y auxiliares */

void ReservaClase(sAsistencia *&asist, sCliente *cliente,  sClases *clase);

void ControlRepetidosyHorario(sAsistencia *&asist, sClases *clase,uint tam);
void ControlRepetidos(sAsistencia *&asist,uint cant_asist); //A
void ControlHorario(sAsistencia *&asistencia, sClases *clase,uint cant_asistencia);//B
void ControlCupo (sAsistencia *&asistencia, sClases *clase,uint cant_asist);//C
void ControlSaldo(sAsistencia *&asist, sCliente *cliente,uint cant_asistencia);//D
int FallasInscripcion(sAsistencia D);//E



/* A- Controla clase repetidas DE UN CLIENTE */
/* B- Controla inscripcion de dos clases sea en horario distinto  */
/* C- Si hay cupo max y paso las dos funciones anteriores, controla que cliente
se haya inscripto primero(hora menor), a ese le dan prioridad de cupo */

/* D- Controla saldo de cliente y coloca 0 id cliente */
/*E- Indica cantidad de inscripciones fallidas de un solo cliente */
/*F Dentro de Control Cupo, si excede cupomaximo, tienen prioridad los que se inscribieron antes :) */

//void ModificarStruct(sAsistencia *&asist, uint &tam); hubo problemas al modificar struct.. (no lo pide)

void Imprimir(sAsistencia *D,uint num);
#endif // ASISTENCIA_H
