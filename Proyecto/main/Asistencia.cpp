#include "Asistencia.h"


void resize_asistencia(sAsistencia *&asist,uint &n){

    if(asist==nullptr){
        if(n==0){
            asist = new sAsistencia[++n];
        }
        return;
    }

    sAsistencia* aux = new sAsistencia[++n];

    for(uint i = 0; i < n-1; i++)
        aux[i] = asist[i];

    delete[] asist;
    asist= aux;
}

void resize_inscriptos(sInscripciones *&inscrip ,uint &n){

    if(inscrip==nullptr){
        if(n==0)
            inscrip = new sInscripciones[++n];

        return;
    }

    sInscripciones* aux = new sInscripciones[++n];


     for(uint i = 0; i < n-1; i++)
         aux[i] = inscrip[i];

    delete[] inscrip;
    inscrip= aux;
}


/*int ReservaClase( sAsistencia *asisten, sClases *clase, sCliente *cliente ){
    // habria que llamar al resize aca ?
    //resize_asistencia (asisten,n); // que n usamos ?
    //resize_inscriptos (asisten->inscripciones,n);
    asisten->id_cliente = cliente->id_cliente;
    asisten->inscripciones->id_clase = clase->id_clase;
    //asisten->inscripciones->fecha = fecha de la reserva, como lo asignamos ?
    //asisten->cant_inscriptos = hay que generar un contador con la cantidad de inscriptos y restarlo al cupo
}*/

int ReservaClase(sAsistencia *&asisten, sClases *&clase, sCliente *&cliente){


  //  if( cliente->saldo>=0 && asisten->id_cliente == cliente->id_cliente)   //controlo si la cuota esta al dia

          // controlo si el horario de la clase que se anoto no es igual
          //
         // asisten->idclase== clase->id_clase && clase->horario == id

}
/*

void ControlHorario(sAsistencia *&a, sClases *&clase, sCliente *&cliente)
{
    for(uint i=1;i<a->cant_inscripcion;i++){

         if( a->inscripciones[i-1].id_clase != a->inscripciones[i].id_clase ) // anoto en clases diferentes
            uint aux1= a->inscripciones[i-1].id_clase;
            uint aux2=a->inscripciones[i].id_clase;

    }
}

void ControlRepetidos(sAsistencia *&a, sClases *&clase, sCliente *&cliente)
{

         for(uint i=0; i<a->cant_inscripcion; i++)
         {
         if (a->inscripciones[i].id_clase == a->inscripciones[i+1].id_clase)
             // se incribio en una misma clase,
             // TE BORRO DE LA CLASE
            cout<<"SE ANOTO mas de una vez" <<endl
         }
}
bool ControlFecha(sAsistencia *&a){

         a->inscripciones->fecha
         // Controla la fecha de inscripcion del cliente.
         // Si es menor que otra fecha de inscripcion devuelve true


}

*/
