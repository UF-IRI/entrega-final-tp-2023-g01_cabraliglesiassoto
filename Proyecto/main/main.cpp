#include "Asistencia.h"
using namespace std;

int main() {
 // FUNCIONA TODO OK, ABRE Y ESCRIBE ARCHIVOS , SE MODIFICA STRUCT CORRECTAMENTE

/*DECLARO VARIABLES


    ifstream archivo_clase,archivo_cliente;
    ofstream archivo_asistencia,texto ;
    sClases* clase = nullptr;
    sCliente* cliente = nullptr;
    sAsistencia *asistencia=nullptr;
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
 /*Pruebas*/
 /* sInscripciones inscripciones1[2] = {{"1", 109029092}, {"12", 109029323}};
    sInscripciones inscripciones2[1] = {{"1", 132322131}};
    sInscripciones inscripciones3[3] = {{"8", 1231242321}, {"1", 1231242321}, {"8", 1231242321}};
    sInscripciones inscripciones4[2] = {{"10", 1231242321}, {"15", 1231242322}};

    sAsistencia *D=new sAsistencia[4];

    D[0]=  {"1", 2, inscripciones1};//1-1 SPINNING 8 , 12 PILATES 8  .. clase mismo horario
    D[1]=  {"2", 1, inscripciones2};    // 2-1 SPINNIN   .. este tiene saldo negativo
    D[2]=  {"3", 3, inscripciones3}; //3-X2 1 SPINNIG, 20 STETCHIN 15   ..Repetidos.y cupomax
    D[3]=  {"4", 2, inscripciones4};   // 4- todo ok

    clase[0].cant_clientes=44;
   uint tam=4;

cout<<"--------NORMAL-----------"<<endl;

    Imprimir(D,tam);


cout<<"-----Reserva (los 0 son basuraaa)-----"<<endl;

  ReservaClase(D,cliente,clase);
  Imprimir(D,tam);


cout<<"-----Archivo binario y Txt (PARA NOSOTROS) ----------"<<endl;

 archivo_asistencia.open("asistencias_1697673600000.dat", ios::binary);
 EscribirArchivoBIN(D,archivo_asistencia,tam);  // formato binario
 archivo_asistencia.close();

 texto.open("ReservasValidas.txt");   //formato texto , la implementamos para comprobar si guardaba bien
 EscribirArchivoTXT(D,texto,tam);
 texto.close();

//------------------------------------------------------------------------------

cout<<endl<<"-----Funcion fallas en la inscripcion-----------"<<endl;
cout<< FallasInscripcion(D[0])<<endl;
cout<<FallasInscripcion(D[1])<<endl;
cout<< FallasInscripcion(D[2])<<endl;
cout<< FallasInscripcion(D[3])<<endl;

cout<<"--------NO REPETIDO-----------"<<endl;

    ControlRepetidos(D);
    imprimir(D);

cout<<"--------SALDO NEG-----------"<<endl;

    ControlSaldo(D,cliente);
    imprimir(D);

    delete[]D;
    delete[]asistencia;
    delete[]cliente;
    delete[]clase;

*/

return 0;
}
