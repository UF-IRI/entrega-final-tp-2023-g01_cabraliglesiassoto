#include "Clase.h"



void resize_clase( sClase *& clase , uint &n ){

    if(clase==nullptr){
        if(n==0){
            clase = new sClase[++n];
        }
        return;
    }

    sClase* aux = new sClase[++n];

    for(uint i = 0; i < n-1; i++)
        aux[i] = clase[i];

    delete[] clase;
    clase= aux;

}


/*int LeerClaseArchivo(sClase *&CLASE, ifstream& Archivo)
{
    int N=1;
    char coma=',';
    stringstream ss;
    string primera_linea, aux,aux_nombre,aux_id,aux_horario;

    //    ifstream Archivo;
    //    Archivo.open(filename);

    if(!Archivo.is_open()) {
        cout<<"Error al abrir archivo" <<endl;
        return -1;
    }

    getline(Archivo,primera_linea);

    while(Archivo){
        getline(ss,aux);
        ss<<aux;
        getline(ss,aux_id,coma);
        CLASE[N-1].id_clase=aux_id;
        getline(ss,aux_nombre,coma);
        CLASE[N-1].clase_nombre=aux_nombre;

        getline(ss,aux_horario);
        CLASE[N-1].horario=stof(aux_horario);
        CLASE[N-1].cupo_max= CupoMaximoStruct(CLASE[N-1].clase_nombre);


        resize_clase(CLASE,N);
    return 0;

} */



int LeerClaseArchivo( ifstream &Archivo, sClase *&CLASE, uint &N){

    stringstream ss;
    string primera_linea, linea;//aux,aux_nombre,aux_id,aux_horario;

    // LeerClaseArchivo(CLASE, Archivo);

    if(!Archivo.is_open()) {
        cout<<"Error al abrir archivo " <<endl;
        return -1;
    }

    getline(Archivo,primera_linea);
    while(!Archivo.eof()&& getline(Archivo,linea)){


        ss.clear();
        ss<<linea;
        resize_clase(CLASE,N);

        getline(ss,linea,',');
        CLASE[N-1].id_clase= linea;
        getline(ss,linea,',');
        CLASE[N-1].clase_nombre=linea;
        getline(ss,linea);
        CLASE[N-1].horario=stof(linea);

        CLASE[N-1].cupo_max=spinn; //arbitrario por el momento



}
    return 0;
}

/*eCupo_max CupoMaximoStruct(string nombre_clase){

   switch(nombre_clase)
    case "spinning":
        return spinn;
    case "yoga" : return yoga;
    case"pilates": return pilates;
    case"stretching": return stretching;
    case"zumba": return zumba;
    case"boxeo ": return boxeo;

    return spinn;
} */
