#include <Clase.h>
#include <Asistencia.h>

void resize(sClase *& CLASE , int &n );



int main() {

    ifstream Archivo("iriClasesGYM.csv");
    sClase* CLASE = new sClase[1];
   // LeerClaseArchivo(CLASE/*, Archivo*/);

    int N=1;
    char coma=',';
    stringstream ss;
    string primera_linea, aux,aux_nombre,aux_id,aux_horario;

    if(!Archivo.is_open()) {
        cout<<"Error al abrir archivo" <<endl;
      //  return -1;
    }

    getline(Archivo,primera_linea);

    while(Archivo){
        getline(ss,aux);
        ss<<aux;
        getline(ss,aux_id,coma);
        CLASE[N-1].id_clase=stoi(aux_id);
        getline(ss,aux_nombre,coma);
        CLASE[N-1].clase_nombre=aux_nombre;

        getline(ss,aux_horario,coma);
        CLASE[N-1].horario=stoi(aux_horario);

        resize(CLASE,N);
    }

    delete[] CLASE;
    Archivo.close();
// estructuras para probar funciones

    sClase clase_p; sCliente cliente_p; sAsistencia asistencia_p;

    // inicializo los structs a mano (los datos los saqué de el PDF que explica los archivos)
    //Clase
    clase_p.clase_nombre = "Spinning";
    clase_p.id_clase = 1;
    clase_p.horario=8;
    //Cliente
    cliente_p.id_cliente="1";
    cliente_p.Nombre="Agustín";
    cliente_p.Apellido="Guerra";
    cliente_p.mail="AgustinGuerra@bolandia.iri";
    cliente_p.telefono="462-185-1730";
    cliente_p.fechaNacimiento="10-12-1966";
    cliente_p.saldo=0;
    //Asistencia
    asistencia_p.id_cliente="1";
    asistencia_p.cant_inscriptos=5;
    asistencia_p.inscripciones->id_clase="1";
    asistencia_p.inscripciones->fecha=1032093211;
    //fin structs prueba
    return 0;
}



void resize( sClase *& CLASE , int &n ){

    n=(n)+1;
    sClase *aux= new sClase[n];
    for(int i=0;i<n-1;i++)
    {
        aux[i]= CLASE[i];

    }
    delete[] CLASE;
    CLASE=aux;

}
