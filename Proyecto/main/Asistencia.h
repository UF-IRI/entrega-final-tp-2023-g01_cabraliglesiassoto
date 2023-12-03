#ifndef ASISTENCIA_H
#define ASISTENCIA_H
#include <Cliente.h>
#include <Clases.h>
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

void EscribirArchivoBIN(sAsistencia *&Asistencias, ofstream &archibinwr,uint cant_asistencia);
void EscribirArchivoTXT(sAsistencia *&Asistencias, ofstream &archibinwr,uint cant_asistencia);

void resize_asistencia(sAsistencia *&asist,uint &n);
void resize_inscriptos(sInscripciones *&inscrip ,uint &n);

/* Reservas y auxiliares */

void ReservaClase(sAsistencia *&asisten, sCliente *cliente,  sClases *clase);

void ControlRepetidosyHorario(sAsistencia *&asist, sClases *clase,uint tam);
void ControlRepetidos(sAsistencia *&asist,uint tam); //A
void ControlHorario(sAsistencia *&a, sClases *clase,uint tam);//B
void ControlCupo (sAsistencia *&asist, sClases *clase,uint tam);//C
void ControlSaldo(sAsistencia *&asist, sCliente *cliente,uint tam);//D
int FallasInscripcion(sAsistencia D);//E

/* A- Controla clase repetidas DE UN CLIENTE */
/* B- Controla inscripcion de dos clases sea en horario distinto  */
/* C- Si hay cupo max y paso las dos funciones anteriores, controla que cliente
se haya inscripto primero(hora menor), a ese le dan prioridad de cupo */

/* D- Controla saldo de cliente y coloca 0 id cliente */
/*E- Indica cantidad de inscripciones fallidas de un solo cliente */


void ModificarStruct(sAsistencia *&asist, uint &tam);// hubo problemas al modificar struct.. (no lo pide)
void imprimir(sAsistencia *D,uint num);
void Imprimir(sAsistencia *D,uint num);
#endif // ASISTENCIA_H
