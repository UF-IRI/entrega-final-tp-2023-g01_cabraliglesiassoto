#include "Asistencia.h"
using namespace std;


int main() {

/*DECLARO VARIABLES */

    ifstream archivo_clase,archivo_cliente,archivo_asistencia ;
    sClases* clase = nullptr;
    sCliente* cliente = nullptr;
    sAsistencia *asistencia=nullptr;
    uint n=0,k=0;

 /* Clases*/
    archivo_clase.open("iriClasesGYM.csv",ios::in);
    LeerClaseArchivo(archivo_clase,clase, n);
    archivo_clase.close();

/* Clientes */
    archivo_cliente.open("iriClientesGYM.csv",ios::in);
    LeerClienteArchivo(cliente,archivo_cliente, k);
    archivo_cliente.close();

/* Asistencia */
    archivo_asistencia.open("asistencias_1697673600000.dat", ios::binary);
    //LeerAsistenciaArchivo(asistencia,archivo_asistencia,j);
    archivo_asistencia.close();


 /*Pruebas*/

    //cout<<"cliente"<<sizeof(struct Cliente)<<endl;
    //printCliente(cliente);
   // cout<<"CANTIDAD DE CLASES supuestamente es 60 pero da =="<<sizeof(struct Clases)<<endl;
    // el archivo me lee 12 posiciones mas. Problemas con el archivo !
    //printClase(clase);


   sAsistencia DefaultAsistencias[4] = {
        {"1", 2, new sInscripciones[2]{{"1", 109029092}, {"12", 109029323}}},
        {"2", 1, new sInscripciones[1]{{"1", 132322131}}},
        {"3", 3, new sInscripciones[3]{{"1", 1231242321}, {"20", 1231242321}, {"1", 1231242321}}},
        {"4", 2, new sInscripciones[2]{{"1", 1231242321}, {"20", 1231242322}}}
    };



   //1 SPINNING 8 , 12 PILATES 8  .. clase mismo horario
    // 1 SPINNIN   .. este tiene saldo negativo
    //X2 1 SPINNIG, 20 STETCHIN 15   ..Repetidos.
   //  todo ok


   ReservaClase(DefaultAsistencias,cliente);



    delete[]asistencia;
    delete[]cliente;
    delete[]clase;

    return 0;

    }




