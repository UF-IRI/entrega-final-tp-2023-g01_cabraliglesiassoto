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
void resize_asistencia(sAsistencia *&asist,uint &n);
void resize_inscriptos(sInscripciones *&inscrip ,uint &n);
void LlenarInscripcion(sInscripciones *&inscript, uint &j );

/* A- Controla clase repetidas DE UN CLIENTE */
/* B- Controla inscripcion de dos clases sea en horario distinto  */
/* C- Si hay cupo max y paso las dos funciones anteriores, controla que cliente
se haya inscripto primero(hora menor) , a ese le dan prioridad de cupo */

/* D- Controla saldo de cliente y coloca 0 id cliente */

/* Reservas y auxiliares */

void ReservaClase(sAsistencia *&asisten, sCliente *cliente,  sClases *clase);

void ControlRepetidosyHorario(sAsistencia *&asist, sClases *clase);
void ControlRepetidos(sAsistencia *&asist); //A
void ControlHorario(sAsistencia *&a, sClases *clase);//B
void ControlCupo (sAsistencia *&asist, sClases *clase);//C
void ControlSaldo(sAsistencia *&asist, sCliente *cliente);//D
void ModificarStruct(sAsistencia *&asist );

void imprimir(sAsistencia *D,uint num);

#endif // ASISTENCIA_H
