#include "Clases.h"


void imprimir(){


    cout<<"prueba de verdad";
}

void sizeclases(sClases *& clase , uint &n ){

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
void openclasearchivo(ifstream &archivo, sClases* &clase, uint &n){

    stringstream ss;
    string primera_linea, linea;//aux,aux_nombre,aux_id,aux_horario;

    // LeerClaseArchivo(CLASE, Archivo);

    if(!archivo.is_open()) {
        cout<<"Error al abrir archivo " <<endl;

    }

    getline(archivo,primera_linea);
    while(!archivo.eof()&& getline(archivo,linea)){


        ss.clear();
        ss<<linea;
        sizeclases(clase,n);

        getline(ss,linea,',');
        clase[n-1].id_clase= linea;
        getline(ss,linea,',');
        clase[n-1].clase_nombre=linea;
        getline(ss,linea);
        clase[n-1].horario=stof(linea);

        clase[n-1].cupo_max=spinn; //arbitrario por el momento
    }



}
