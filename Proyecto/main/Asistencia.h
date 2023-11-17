#ifndef ASISTENCIA_H
#define ASISTENCIA_H
#include <Cliente.h>
#include <Clases.h>
#include <ctime>

struct Inscripciones {
    string id_clase;
    string fecha; //time_t
}; typedef struct  Inscripciones sInscripciones;

struct Asistencia {
    string id_cliente;
    uint cant_inscripcion;
    sInscripciones *inscripciones;
}; typedef struct  Asistencia sAsistencia;


void resize_asistencia(sAsistencia *&asist,uint &n);
void resize_inscriptos(sInscripciones *&inscrip ,uint &n);
void LlenarInscripcion(sInscripciones *&inscript, uint &j );


// Reservas y otros

void ListarAlumnosporClase(sClases *clase, sCliente *cliente, sAsistencia *asistencia); // crea un archivo de los alumnos que se inscriben a la clase.
int ReservaClase(sAsistencia *asisten, sClases *clase, sCliente *cliente );
void ControlRepetidos(sAsistencia *&a, sClases *&clase, sCliente *&cliente);
bool ControlFecha(sAsistencia *&a, sClases *& clase );
void ControlHorario(sAsistencia *&a, sClases *&clase, sCliente *&cliente);

    /* Necesitamos idCliente idClase
     *  Cliente saldo positivo , no reserve dos clases en el mismo horario o en la misma clase.
     *  Clase horario coincida con el idClase y el nombre
     *  Si dos personas reservan al mismo horario y justo cupomax, priorizo horario(fecha) o cant_ausencia.

    Cliente
    if (Clienteestado()==false)
      return valor;





}*/
#endif // ASISTENCIA_H
