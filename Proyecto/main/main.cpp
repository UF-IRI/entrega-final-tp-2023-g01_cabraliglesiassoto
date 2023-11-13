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
    uint n=0,k=0,j=0,m=0;

    LeerClaseArchivo(archivo_clase,clase, n);
    archivo_clase.close();
    cout<< clase[7].clase_nombre<< endl; // prueba

   // ABRO ARCHIVO CLIENTES
    archivo_cliente.open("iriClientesGYM.csv",ios::in);
    LeerClienteArchivo(cliente,archivo_cliente, k);
    archivo_cliente.close();

    cout<< cliente[2].mail<<endl; // prueba


    archivo_asistencia.open("asistencias_1697673600000.dat", ios::binary);
    LeerAsistenciaArchivo(asistencia,archivo_asistencia,j,inscrip,m);
    cout<< asistencia[4].cant_inscriptos<<endl; // pruebo cant


    archivo_asistencia.close();


    delete[]asistencia;
    delete[]cliente;
    delete[]clase;

    return 0;

    }




