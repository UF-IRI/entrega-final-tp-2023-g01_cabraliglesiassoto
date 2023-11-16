#include "Asistencia.h"



void LeerAsistenciaArchivo(sAsistencia *&asist, ifstream &archivo, uint&n ){
    stringstream ss;
    string primera_linea, linea;
    char coma=',';

    if(!archivo.is_open()) {
        cout<<"Error al abrir archivo " <<endl;

    }

    getline(archivo,primera_linea);
    while(!archivo.eof()&& getline(archivo,linea)){

        ss.clear();
        ss<<linea;

        resize_asistencia(asist,n);

        getline(ss,linea,coma);
        asist[n-1].id_cliente=linea;
        getline(ss,linea,coma);
        asist[n-1].cant_inscriptos=stringtouint(linea);  // hasta aca todo bien, problema al llenar struct inscripciones.

        getline(ss,linea,'{');


    // reserva memoria para inscripciones

            for (uint j = 1; j < asist[n-1].cant_inscriptos; j++) {

                resize_inscriptos(asist[n-1].inscripciones,j );

                getline(ss,linea,'(');
                getline(ss,linea , ',');
                asist[n-1].inscripciones[j-1].id_clase=linea;
                getline(ss,linea ,')');
                asist[n-1].inscripciones[j-1].fecha=linea;

            }

         //getline(ss,linea,'}');
        }
    }

            /*
            resize_inscriptos(inscrip,tam);
            for( j=0; j<tam; j++){

            getline(ss,linea,'(');
            inscrip[j-1].id_clase= linea;
            getline(ss,linea,coma);  // paso de string a time_t, con libreria ctime en el pdf de clase habia funcion mktime :D
            cout<<inscrip[j-1].id_clase<<endl;

            inscrip[j-1].fecha= linea;
            getline(ss,linea,')');


            struct tm timeinfo;
            strptime(linea.c_str(),"%s",&timeinfo);     // paso de string a time
            time_t aux_time= mktime(&timeinfo);
            inscrip[j-1].fecha=aux_time;     }*/

           // TENGO PROBLEMAS PQ EN EL FORMATO DE BINARIO ES
            // 20, 3, {(12, 109029092), (12, 109029323), (30, 1032093211)}  COMO TENGO EN CUENTA LOS {{ }} CON UN CICLO WHILE ??


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


