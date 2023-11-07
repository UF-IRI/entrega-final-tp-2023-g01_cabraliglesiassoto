#include <Clase.h>
#include <Asistencia.h>
#include<Cliente.h>

int main() {

    sClase* CLASE = new sClase[1];
    Leer_Clase_Archivo(CLASE);






    delete[] CLASE;
    return 0;
}
