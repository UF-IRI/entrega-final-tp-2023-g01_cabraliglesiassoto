#include "Asistencia.h"
using namespace std;


int main() {

    //ABRO ARCHIVO CLASES

    ifstream archivo_clase,archivo_cliente,archivo_asistencia ;
    archivo_clase.open("iriClasesGYM.csv",ios::in);
    sClases* clase = nullptr;
    sCliente* cliente = nullptr;
    sAsistencia *asistencia=nullptr;
    sInscripciones *inscrip=nullptr;
    uint n=0,j=0,k=0;

    LeerClaseArchivo(archivo_clase,clase, n);
    archivo_clase.close();

   // ABRO ARCHIVO CLIENTES
    archivo_cliente.open("iriClientesGYM.csv",ios::in);
    LeerClienteArchivo(cliente,archivo_cliente, k);
    archivo_cliente.close();


    archivo_asistencia.open("asistencias_1697673600000.dat", ios::binary);
    LeerAsistenciaArchivo(asistencia,archivo_asistencia,j,inscrip);
    cout<< asistencia[4].cant_inscriptos<<endl; // pruebo cant
    archivo_asistencia.close();

    cout<< asistencia[2].id_cliente+"hola"<<endl;





    delete[]asistencia;
    delete[]cliente;
    delete[]clase;

    return 0;

    }




