#include <Asistencia.h>

int main() {

    //Abrir archivo ....

    ifstream Archivo("iriClasesGYM.csv");
    sClase* CLASE = new sClase[1];
    LeerClaseArchivo(CLASE/*, Archivo*/);


    delete[] CLASE;
    Archivo.close();
    return 0;
}



