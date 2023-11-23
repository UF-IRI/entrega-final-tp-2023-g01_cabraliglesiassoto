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


/* Reservas y auxiliares */

void ReservaClase(sAsistencia *&asisten, sCliente *cliente,  sClases *clase);

/* A- Controla clase repetidas */
void ControlRepetidos(sAsistencia *&asist);

/* B- Controla inscripcion de dos clases sea en horario distinto  */
void ControlHorario(sAsistencia *&a, sClases *clase);

/*C- Si hay cupo max y paso las dos funciones anteriores, controla que cliente
se haya inscripto primero(hora menor) , a ese le dan prioridad de cupo */

void ControlCupo (sAsistencia *&asist, sClases *clase);

void ControlSaldo(sAsistencia *&asist, sCliente *cliente);

void ListarAlumnosporClase(sClases *clase, sCliente *cliente, sAsistencia *asistencia); // crea un archivo de los alumnos que se inscriben a la clase.


#endif // ASISTENCIA_H
