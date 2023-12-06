#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include "Asistencia.h"

int main(int argc, char** argv) {

/*
    ifstream archivo_clase,archivo_cliente;
    ofstream archivo_asistencia,texto ;
    sClases* clase = nullptr;
    sCliente* cliente = nullptr;


    uint n=0,k=0;

     //Clases
    archivo_clase.open("iriClasesGYM.csv",ios::in);
    LeerClaseArchivo(archivo_clase,clase, n);
    archivo_clase.close();

    //Clientes
    archivo_cliente.open("iriClientesGYM.csv",ios::in);
    LeerClienteArchivo(cliente,archivo_cliente, k);
    archivo_cliente.close();


*/
  //  delete[]cliente;
  //  delete[]clase;

    return Catch::Session().run(argc, argv);
}
