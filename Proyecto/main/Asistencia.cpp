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


void ReservaClase(sAsistencia *&asist, sCliente *cliente ,sClases *clase){

ControlSaldo(asist,cliente);
ControlRepetidosyHorario(asist,clase);// uno dos funciones pq sino mi pc muere con 4 funciones juntas
ControlCupo(asist,clase);


 /*   uint cont=0;
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
}*/
}

void ModificarStruct(sAsistencia *&asist){

sAsistencia *nuevo= nullptr;
uint cant_asistencia=4;
uint aux_asist=0;


for(uint j=0;j<cant_asistencia; j++) {// tamanio nuevo struct con variables nuevas

         sAsistencia *a= &asist[j];

         if(a->id_cliente !="0" ){   // si no pago


            uint aux_insc=0;
            sInscripciones *inscrip_aux= nullptr;

            for(uint m = 0; m < a->cant_inscripcion; m++){

                if(a->inscripciones[m].id_clase != "0"){ // si no se inscribio bien o falta cupo
                    a->cant_inscripcion--;
                    if(a->cant_inscripcion > 0){// inscripcion no vacio
                        resize_inscriptos(inscrip_aux,aux_insc); // agrego una inscripcion a struct auxiliar.
                        inscrip_aux[aux_insc-1]= a->inscripciones[m];
                    }

                }
            }

            if(a->cant_inscripcion >0){

            resize_asistencia(nuevo,aux_asist);
            nuevo[aux_asist-1]= asist[j];
            nuevo->inscripciones = inscrip_aux;
            delete[] inscrip_aux;
         }
}
}

asist=nuevo;
delete[]nuevo;


}

void ControlRepetidosyHorario(sAsistencia *&asist, sClases *clase){

ControlHorario(asist,clase);
ControlRepetidos(asist);

}

void ControlHorario(sAsistencia *&a, sClases *clase)
{

uint cant_asistencia=4;
for (uint i = 0; i < cant_asistencia; i++) {

sAsistencia *asist = &a[i];
sInscripciones *inscripciones = asist->inscripciones;
uint cant_inscripcion = asist->cant_inscripcion;


for (uint j = 0; j < cant_inscripcion; j++) {

    sInscripciones *insc = &inscripciones[j];

         if(insc->id_clase != clase->id_clase){

            if ( clase->horario == BuscarHorario(insc->id_clase ,clase)   ) {

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
            for(uint m=0;m<asist[i].cant_inscripcion;m++){

                if(asist[i].inscripciones[j].id_clase == asist[i].inscripciones[m].id_clase && j!=m){

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

void ControlCupo (sAsistencia *&asistencia, sClases *clase){

    uint cant_asistencia=4;
         for (uint i = 0; i < cant_asistencia; i++) {
            sAsistencia *asist = &asistencia[i];
            sInscripciones *inscripciones = asist->inscripciones;
            uint cant_inscripcion = asist->cant_inscripcion;
            for (uint j = 0; j < cant_inscripcion; j++) {
                sInscripciones *insc = &inscripciones[j];
            if (insc->id_clase == clase->id_clase) {
                clase->cant_clientes += 1;
                if (clase->cant_clientes > clase->cupo_max) {
                       insc->id_clase = "0";
                       insc->fecha = 0;
                    }
                }
            }
         }
}

void imprimir(sAsistencia *D,uint num){
         //size_t a =sizeof(D)/sizeof(struct Asistencia);

         cout<<"tamanio asistencia"<<num << endl;

         for(uint i=0;i<num;i++){

            cout<<"id:" <<D[i].id_cliente<< "  cant: "<< D[i].cant_inscripcion <<endl;
            cout<< "     Inscripciones:";
            for(uint m=0;m<D[i].cant_inscripcion; m++)
            {

                cout<<" "<< D[i].inscripciones[m].id_clase<< "," ;

            }
            cout<< " "<<endl;
         }
    }



