#include <Clase.h>
#include <Asistencia.h>
#include <Cliente.h>

int main() {

    //Abrir archivo ....

    ifstream Archivo;
    Archivo.open("iriClasesGYM.csv");
    sClase* CLASE = new sClase[1];
    Leer_Clase_Archivo(CLASE, Archivo);






    delete[] CLASE;
    Archivo.close();
    return 0;
}



