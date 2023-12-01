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

/*   sAsistencia D[4] = {
        {"1", 2, new sInscripciones[2]{{"1", 109029092}, {"12", 109029323}}},
        {"2", 1, new sInscripciones[1]{{"1", 132322131}}},
        {"3", 3, new sInscripciones[3]{{"1", 1231242321}, {"20", 1231242321}, {"1", 1231242321}}},
        {"4", 2, new sInscripciones[2]{{"1", 1231242321}, {"20", 1231242322}}}
    };
*/


    sInscripciones inscripciones1[2] = {{"1", 109029092}, {"12", 109029323}};
    sInscripciones inscripciones2[1] = {{"1", 132322131}};
    sInscripciones inscripciones3[3] = {{"8", 1231242321}, {"1", 1231242321}, {"8", 1231242321}};
    sInscripciones inscripciones4[2] = {{"10", 1231242321}, {"15", 1231242322}};

    sAsistencia *D=new sAsistencia[4];

    D[0]=  {"1", 2, inscripciones1};//1-1 SPINNING 8 , 12 PILATES 8  .. clase mismo horario
    D[1]=  {"2", 1, inscripciones2};    // 2-1 SPINNIN   .. este tiene saldo negativo
    D[2]=  {"3", 3, inscripciones3}; //3-X2 1 SPINNIG, 20 STETCHIN 15   ..Repetidos.y cupomax
    D[3]=  {"4", 2, inscripciones4};   // 4- todo ok

    clase[0].cant_clientes=44;

cout<<"--------NORMAL-----------"<<endl;

    imprimir(D,4);


 cout<<endl<<"-----Reserva (los 0 son basuraaa)-----------"<<endl;

  ReservaClase(D,cliente,clase);
 imprimir(D,4);


 uint tam=0;
 while ( D[tam].id_cliente != "") {  // verificamos la cant de elementos
     tam++;
 }
 tam--;

 cout<<endl<<"-----MODIFIC-----------"<<endl;
   ModificarStruct(D,4);
   imprimir(D,tam);


    delete[]asistencia;
    delete[]cliente;
    delete[]clase;

    return 0;

    }

//cout<<"cliente"<<sizeof(struct Cliente)<<endl;
//printCliente(cliente);
// cout<<"CANTIDAD DE CLASES supuestamente es 60 pero da =="<<sizeof(struct Clases)<<endl;
// el archivo me lee 12 posiciones mas. Problemas con el archivo !
//printClase(clase);


/*

 cout<<"--------NO REPETIDO-----------"<<endl;

    ControlRepetidos(D);
    imprimir(D);

 cout<<"--------SALDO NEG-----------"<<endl;

    ControlSaldo(D,cliente);
    imprimir(D);



*/
