#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include "Asistencia.h"

int main(int argc, char** argv) {


    ifstream archivo_clase,archivo_cliente;
    ofstream archivo_asistencia,texto ;
    sClases* clase = nullptr;
    sCliente* cliente = nullptr;


    uint n=0,k=0;

    /* Clases*/
    archivo_clase.open("iriClasesGYM.csv",ios::in);
    LeerClaseArchivo(archivo_clase,clase, n);
    archivo_clase.close();

    /* Clientes */
    archivo_cliente.open("iriClientesGYM.csv",ios::in);
    LeerClienteArchivo(cliente,archivo_cliente, k);
    archivo_cliente.close();


    sInscripciones inscripciones1[2] = {{"1", 109029092}, {"12", 109029323}};
    sInscripciones inscripciones2[1] = {{"1", 132322131}};
    sInscripciones inscripciones3[3] = {{"8", 1231242321}, {"1", 1231242321}, {"8", 1231242321}};
    sInscripciones inscripciones4[2] = {{"10", 1231242321}, {"15", 1231242322}};
    sAsistencia *D=new sAsistencia[4];

    D[0]=  {"1", 2, inscripciones1};//1-1 SPINNING 8 , 12 PILATES 8  .. clase mismo horario
    D[1]=  {"2", 1, inscripciones2};    // 2-1 SPINNIN   .. este tiene saldo negativo
    D[2]=  {"3", 3, inscripciones3}; //3-X2 1 SPINNIG, 20 STETCHIN 15   ..Repetidos.y cupomax
    D[3]=  {"4", 2, inscripciones4};   // 4- todo ok

  //  cout<<"hola"<<endl;

    delete[]D;
    delete[]cliente;
    delete[]clase;

    return Catch::Session().run(argc, argv);
}
