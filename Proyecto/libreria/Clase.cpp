#include <Clase.h>


void Leer_Clase_Archivo( sClase *& CLASE,string filename){

    uint N=1;
    char coma=',';
    stringstream ss;
    string primera_linea, aux,aux_nombre,aux_id,aux_horario;

    ifstream Archivo;
    Archivo.open(filename);


    if(!Archivo.is_open())
    {
        cout<<"Error al abrir archivo" <<endl;
       // return -1;
    }

    getline(Archivo,primera_linea);

    while(Archivo){

        getline(ss,aux,',');
        ss<<aux;
        getline(ss,aux_id,coma);
        CLASE[N-1].id_clase=stoi(aux_id);
        getline(ss,aux_nombre,coma);
        CLASE[N-1].clase_nombre=aux_nombre;
        getline(ss,aux_horario,coma);
        CLASE[N-1].horario=stoi(aux_horario);

        resize(CLASE,N);

    }

    Archivo.close();
    //return 0;

}


void resize(sClase *& CLASE , uint &n ){

    n=(n)+1;
    sClase *aux= new sClase[n];
    for(uint i=0;i<n-1;i++)
    {
        aux[i]= CLASE[i];

    }
    delete[] CLASE;
    CLASE=aux;


}
