#ifndef ASISTENCIA_H
#define ASISTENCIA_H
#include <Cliente.h>
#include <Clase.h>
#include <ctime>

struct Inscripciones {
    string id_clase;
    time_t fecha;
}; typedef struct  Inscripciones sInscripciones;

struct Asistencia {
    string id_cliente;
    uint cant_inscriptos;
    sInscripciones *inscripciones;
}; typedef struct  Asistencia sAsistencia;

#endif // ASISTENCIA_H
