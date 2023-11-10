#include <Clase.h>
#include <Asistencia.h>

void resize(sClase *& CLASE , uint &n );

int main() {

    ifstream Archivo("iriClasesGYM.csv");
    sClase* CLASE = nullptr;
    uint N=0;
    char coma=',';
    stringstream ss;
    string primera_linea, aux,aux_nombre,aux_id,aux_horario;

    // LeerClaseArchivo(CLASE, Archivo);

    if(!Archivo.is_open()) {
        cout<<"Error al abrir archivo " <<endl;
       return -1;
    }

    getline(Archivo,primera_linea);

    while(Archivo){
        ss.clear();
        getline(ss,aux);
        ss<<aux;

        resize(CLASE,N);
        getline(ss,aux_id,coma);
        CLASE[N].id_clase=stoi(aux_id);
        getline(ss,aux_nombre,coma);
        CLASE[N].clase_nombre=aux_nombre;
        getline(ss,aux_horario);
        CLASE[N].horario=stoi(aux_horario);


    }


    cout<< CLASE->clase_nombre[2];
    delete[] CLASE;
    Archivo.close();

    ifstream infile("asistencias_1697673600000.dat", ios::binary);
    if (!infile.is_open()) {
        cout << "Error opening binary file" << endl;
        return 1;
    }
    infile.close();
    return 0;
}

void resize( sClase *& clase , uint &n ){

 /*   n=(n)+1;
    sClase *aux= new sClase[n];
    for(uint i=0;i<n-1;i++)
    {
        aux[i]= CLASE[i];

    }
    delete[] CLASE;
    CLASE=aux;
*/
    if(clase==nullptr){
        if(n==0){
            clase = new sClase[++n];
        }
        return;
    }

    sClase* aux = new sClase[++n];

    for(uint i = 0; i < n-1; i++)
        aux[i] = clase[i];

    delete[] clase;
    clase= aux;
}







/* Menu
 *
 *  int opcion;

    cout << "acceder como: " << endl;
    cout << "1_ administrador." << endl;
    cout << "2_ alumno." << endl;

    cin >> opcion;

    if (opcion == 1 || opcion == 2)
    {
        switch (opcion)
        {
        case 1: admin_menu(); break;

        case 2: alumno_menu; break;

        }
    }
    else
    {

        cout << "opcion no valida" << endl;

    }

    return 0;
}

void alumno_menu();

 * 1-Reservar Turno
 * 2-Cancelar Turno
 * 4-Salir
 *
 *
 *
 * 1-Elegir Clase
 *  1-S
 *  2-Box
 *  3-etc
 *
 *
 *
 * 2-Menu Box
 *  imprimirHorario(Box );
 *  cin>> horario;
 *int  ReservaClase( Asistencia, Inscripcion );
 *
 *
 *   ReservaClase== 1 Reserva exitosa, tiene clase horario , el dia ... .
 *   "" == 2; Error en la reserva
 *   ""==  3; Cupo maximo o no es el horario indicado
 *
 *
 * /

*/


/*    sClase clase_p; sCliente cliente_p; sAsistencia asistencia_p;

    // inicializo los structs a mano (los datos los saqué de el PDF que explica los archivos)
    //Clase
    clase_p.clase_nombre = "Spinning";
    clase_p.id_clase = 1;
    clase_p.horario=8;
    //Cliente
    cliente_p.id_cliente="1";
    cliente_p.Nombre="Agustín";
    cliente_p.Apellido="Guerra";
    cliente_p.mail="AgustinGuerra@bolandia.iri";
    cliente_p.telefono="462-185-1730";
    cliente_p.fechaNacimiento="10-12-1966";
    cliente_p.saldo=0;
    //Asistencia
    asistencia_p.id_cliente="1";
    asistencia_p.cant_inscriptos=5;
    asistencia_p.inscripciones->id_clase="1";
    asistencia_p.inscripciones->fecha=1032093211;
    //fin structs prueba*/
