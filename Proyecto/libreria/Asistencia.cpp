#include "Asistencia.h"


void EscribirArchivoBIN(sAsistencia *&Asistencia, ofstream &archibinwr,uint cant_asistencia){


    if (archibinwr.is_open()) {

            for( uint i=0;i<cant_asistencia;i++)
            {
                sAsistencia *A= &Asistencia[i];
                if(A->id_cliente !="0" && ( A->cant_inscripcion - FallasInscripcion(Asistencia[i]))>0){

                    archibinwr.write((char*)&A[i].id_cliente, sizeof(string));
                    archibinwr.write((char*)&A[i].cant_inscripcion, sizeof(uint));

                    for(uint j = 0; j < A[i].cant_inscripcion; j++){
                      if(A->inscripciones[j].id_clase!= "0")
                       archibinwr.write((char*)&A[i].inscripciones[j],sizeof(sInscripciones));


                }
            }
        }
    }
}
void EscribirArchivoTXT(sAsistencia *&Asistencias, ofstream &archibinwr,uint cant_asistencia){

    if (archibinwr.is_open()) {

        for( uint i=0;i<cant_asistencia;i++)
        {
           sAsistencia *a= &Asistencias[i];
            if(a->id_cliente !="0" && ( a->cant_inscripcion - FallasInscripcion(Asistencias[i]))>0){

               archibinwr << a->id_cliente<<"," << a->cant_inscripcion-FallasInscripcion(Asistencias[i])<< "{";

               for(uint k=0;k<a->cant_inscripcion;k++ ){
                   if(a->inscripciones[k].id_clase!= "0")
                       archibinwr <<"(" + a->inscripciones[k].id_clase +','<<  a->inscripciones[k].fecha<< ")";

                }
            archibinwr<<"}"<<endl;
            }
        }
    }
}


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

    uint tam=0;
    while ( asist[tam].id_cliente != "") {  // verificamos la cant de elementos
         tam++;
    }
    tam--;


ControlSaldo(asist,cliente,tam);
ControlRepetidosyHorario(asist,clase,tam);// uno dos funciones pq sino mi pc muere con 4 funciones juntas
ControlCupo(asist,clase,tam);

}


void ControlRepetidosyHorario(sAsistencia *&asist, sClases *clase,uint tam){

ControlHorario(asist,clase,tam);
ControlRepetidos(asist,tam);

}


void ControlRepetidos(sAsistencia *&asist,uint cant_asist){

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



void ControlHorario(sAsistencia *&asistencia, sClases *clase,uint cant_asistencia)
{


for (uint i = 0; i < cant_asistencia; i++) {

sAsistencia *asist = &asistencia[i];
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

void ControlCupo (sAsistencia *&asistencia, sClases *clase, uint cant_asistencia){

         for (uint i = 0; i < cant_asistencia; i++) {
            sAsistencia *asist = &asistencia[i];
            sInscripciones *inscripciones = asist->inscripciones;


            for (uint j = 0; j < asist->cant_inscripcion; j++) {
                sInscripciones *insc = &inscripciones[j];
            if (insc->id_clase == clase->id_clase) {
                clase->cant_clientes += 1;

                if (clase->cant_clientes > clase->cupo_max ) {
                       insc->id_clase = "0";
                       insc->fecha = 0;
                    }
                }
            }
         }
}

void ControlSaldo(sAsistencia *&asist, sCliente *cliente,uint cant_asist){

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

int FallasInscripcion(sAsistencia D){
         uint cont=0;
         for(uint m = 0; m < D.cant_inscripcion; m++){

            if(D.inscripciones[m].id_clase == "0") // la inscripcion no valida
                cont++;
         }

         return  cont;

}


void imprimir(sAsistencia *D,uint num){


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

void Imprimir(sAsistencia *D,uint num){

    cout<<"tamanio asistencia"<<num << endl;

    for(uint i=0;i<num;i++){

         cout<<"-ID:" <<D[i].id_cliente<< "  CANT: "<< D[i].cant_inscripcion <<endl;

            //cout<< " Clase y Hora"<<endl;

        for(uint m=0;m<D[i].cant_inscripcion; m++){
             struct tm *tiempo_struct = gmtime(&D[i].inscripciones[m].fecha);
             char buffer[80];
             strftime(buffer, sizeof(buffer), "%H:%M:%S", tiempo_struct);
             cout<<"  "+ D[i].inscripciones[m].id_clase +" - " << buffer <<endl;

         }
        cout<<endl;
        }
}




