#include "Clases.h"



void resize_clases(sClases *& clase , uint &n ){

    if(clase==nullptr){
        if(n==0){
            clase = new sClases[++n];
        }
        return;
    }

    sClases* aux = new sClases[++n];

    for(uint i = 0; i < n-1; i++)
        aux[i] = clase[i];

    delete[] clase;
    clase= aux;


}
void LeerClaseArchivo(ifstream &archivo, sClases* &clase, uint &n){


    stringstream ss;
    string primera_linea, linea;
    char coma=',';

    if(!archivo.is_open()) {
        cout<<"Error al abrir archivo " <<endl;

    }

    getline(archivo,primera_linea); //leo primer alinea y descarto
    while(!archivo.eof()&& getline(archivo,linea)){


        ss.clear();
        ss<<linea;
        resize_clases(clase,n);

        getline(ss,linea,coma);
        clase[n-1].id_clase= linea;
        getline(ss,linea,coma);
        clase[n-1].clase_nombre=linea;
        getline(ss,linea);
        clase[n-1].horario=stof(linea);

        clase[n-1].cupo_max=LlenarCupo(clase[n-1].clase_nombre); //arbitrario por el momento
        clase[n-1].cant_clientes=0;
    }



}
void printClase(sClases *&clases){
    size_t numClase =  sizeof(struct Clases)-12;
    for(uint i=0;i<numClase;i++)
    { cout<< clases[i].id_clase<<' '<< clases[i].horario<<' '<< clases[i].cupo_max <<endl;}

}

eCupo_max LlenarCupo(string clase_nombre){

    if (clase_nombre == "Spinning") {
        return spinn;
    } else if (clase_nombre == "Yoga") {
        return yoga;
    } else if (clase_nombre == "Pilates") {
        return pilates;
    } else if (clase_nombre == "Stretching") {
        return stretching;
    } else if (clase_nombre == "Zumba") {
        return zumba;
    } else if (clase_nombre == "Boxeo") {
        return boxeo;
    } else {

        return musculacion; // Puedes devolver un valor por defecto o manejar el error de otra manera.
    }
}

float BuscarHorario(string id_clase, sClases *clase){

    float hora=0;

    size_t numClase =  sizeof(struct Clases);
    for(uint i=0;i<numClase ;i++)
    { if(id_clase == clase[i].id_clase)
        {hora= clase[i].horario;}


    }


    return hora;

}

tm FloattoHora(float hora) {
  //  time_t t = hora * 3600;
   // struct tm *tm = localtime(&t);
   // return *tm;
  /*  float hora = (int)numeroFloat;

    float minutos = (numeroFloat - hora);
    if(minutos == 0.5)
        minutos=30;

    tm horaTM = {};
    horaTM.tm_hour = hora;
    horaTM.tm_min = minutos;
    horaTM.tm_sec=0;
*/


    time_t t = hora * 3600 ;
    struct tm *tm = localtime(&t);
    tm->tm_hour+=3;  // siempre nos devolvia 3horas menos... no sabemos D:
    return *tm;



}
