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

void ListarAlumnosporClase(sClase *clase, sCliente *cliente, sAsistencia *asistencia); // crea un archivo de los alumnos que se inscriben a la clase.
int ReservaClase( sAsistencia *asisten, sClase *clase, sCliente *cliente );
void LeerArchivoAsist(sAsistencia *&asist, ifstream &archivo );


    /* Necesitamos idCliente idClase
     *  Cliente saldo positivo , no reserve dos clases en el mismo horario o en la misma clase.
     *  Clase horario coincida con el idClase y el nombre
     *  Si dos personas reservan al mismo horario y justo cupomax, priorizo horario(fecha) o cant_ausencia.

    Cliente
    if (Clienteestado()==false)
      return valor;





}*/
