#include "Asistencia.h"
const sAsistencia AsistenciaNula = { "", 0, nullptr };

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

void ReservaClase(sAsistencia *&asist, sCliente *cliente /*,  sClases *clase*/){


   /* if( ControlEstado(cliente->saldo)!= false){

        if( ControlRepetidos(asisten) != false){

            //if(ControlHorario() != false){
            cout<< "hola"<<endl;

            }
    }
*/

 //   ControlSaldo(asist,cliente);
  //  ControlRepetidos(asist);
    uint cant_asistencia=4;
    uint cont=0;
    for(uint j=0;j<cant_asistencia; j++) // tamanio nuevo struct con variables nuevas
    {


    if(asist[j].id_cliente !="0" )
    {
            cont++;

    }}

    sAsistencia *nuevo= new sAsistencia[ cant_asistencia-cont];

    for(uint m=0;m<cant_asistencia-cont; m++){
    for(uint j=0;j<cant_asistencia; j++){ // tamanio nuevo struct con variables nuevas

        if(asist[j].id_cliente !="0" ){

            nuevo[m]= asist[j];

               for(uint k=0;k<nuevo[m].cant_inscripcion; k++){

                   if(asist[j].inscripciones[j].id_clase =="0")
                       nuevo[m].cant_inscripcion--;
               }


         }
    }
}

}

  //  if( cliente->saldo>=0 && asisten->id_cliente == cliente->id_cliente)   //controlo si la cuota esta al dia

          // controlo si el horario de la clase que se anoto no es igual
          //
         // asisten->idclase== clase->id_clase && clase->horario == id



void ControlHorario(sAsistencia *&a, sClases *clase)
{
  /*  uint cant_asist=4;

    for(uint i=0;i<cant_asist;i++){

         for(uint j=0;j<asist[i].cant_inscripcion;j++){ // comparo entre inscripciones.

            for(uint m=j+1;m<asist[i].cant_inscripcion;m++){


                 // ya sabemos que no hay clases repetidas porque pusimos variable en 0
                //asist[i].inscripciones[j].id_clase != asist[i].inscripciones[m].id_clase
                if(asist[i].inscripciones[j].id_clase != "0" &&
                   asist[i].inscripciones[j].id_clase == clase->id_clase &&
                   asist[i].inscripciones[m].id_clase == clase->id_clase )


                     ){

                    asist[i].inscripciones[m].id_clase="0";  // llenamos de 0
                }
            }
         }

    }

*/

    uint cant_asistencia=4;
for (uint i = 0; i < cant_asistencia; i++) {

sAsistencia *asist = &a[i];
sInscripciones *inscripciones = asist->inscripciones;
uint cant_inscripcion = asist->cant_inscripcion;



for (uint j = 0; j < cant_inscripcion; j++) {
    sInscripciones *insc = &inscripciones[j];
            if(insc->id_clase != clase->id_clase){
              float hora= clase->horario;
                   if ( clase->horario == hora) {
         insc->id_clase = "0";
         insc->fecha = 0;
           }
           }
   }
}
}


void ControlRepetidos(sAsistencia *&asist){
   // uint cant_asist= sizeof(asist)/ sizeof(asist[0]);
    uint cant_asist=4;
    for(uint i=0;i<cant_asist;i++){

        for(uint j=0;j<asist[i].cant_inscripcion;j++)
        {
            for(uint m=j+1;m<asist[i].cant_inscripcion;m++){

                if(asist[i].inscripciones[j].id_clase == asist[i].inscripciones[m].id_clase){

                    asist[i].inscripciones[m].id_clase="0";  // llenamos de 0
                }
            }
        }

    }
}

void ControlSaldo(sAsistencia *&asist, sCliente *cliente){

    uint cant_asist=4;
    for(uint i=0;i<cant_asist;i++){

         size_t numCliente =  sizeof(struct Cliente);
         for(uint j=0;j<numCliente;j++)
         {
            if(asist[i].id_cliente == cliente[j].id_cliente && cliente[j].saldo <0 )

                // el cliente no tiene la cuota al dia y no puede reservar
                asist[i].id_cliente="0";

         }

    }



}



/*
bool ControlFecha(sAsistencia *&a){

         a->inscripciones->fecha
         // Controla la fecha de inscripcion del cliente.
         // Si es menor que otra fecha de inscripcion devuelve true


}*/

/*bool ControlCupo (sAsistencia *&asist, sClases *clase){

         uint idclaseaux=0;
         uint contador[60];
         uint k=0;
         for (uint i=0; i<60; i++){
         contador[i]=clase[i].cupo_max;
         }
         for (uint j=0; j<sizeof(struct asist);j++){
            while (k<sizeof(asist[j]->inscripciones)){
                if (asist[j]->inscripciones[k]->id_clase == clase[j]->id_clase){
                idclaseaux= stoi(clase[j]->idclase);
                contador[idclaseaux-1]= contador[idclaseaux-1]-1;
                }
                if (contador [idclaseaux]==0){
                return false;
                }
                else(contador [idclaseaux]>0);{
                    return true;
                }
            }
            k++;
         }
 }*/
