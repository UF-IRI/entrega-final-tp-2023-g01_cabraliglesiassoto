
#include <catch2/catch.hpp>
#include "Asistencia.h"
/*
TEST_CASE("Reserva")
{

    ifstream archivo_clase,archivo_cliente;
    ofstream archivo_asistencia,texto ;
    sClases* clase = nullptr;
    sCliente* cliente = nullptr;
    uint n=0,k=0;

    archivo_clase.open("iriClasesGYM.csv",ios::in);
    LeerClaseArchivo(archivo_clase,clase, n);
    archivo_clase.close();

    archivo_cliente.open("iriClientesGYM.csv",ios::in);
    LeerClienteArchivo(cliente,archivo_cliente, k);
    archivo_cliente.close();


    sInscripciones inscripciones1[2] = {{"1", 109029092}, {"12", 109029323}};
    sInscripciones inscripciones2[1] = {{"1", 132322131}};
    sInscripciones inscripciones3[3] = {{"8", 1231242321}, {"1", 1231242321}, {"8", 1231242321}};
    sInscripciones inscripciones4[2] = {{"10", 1231242321}, {"15", 1231242322}};
    uint tam=4;
    sAsistencia *D=new sAsistencia[tam];

    D[0]=  {"1", 2, inscripciones1};//1- 1 SPINNING 8 , 12 PILATES 8  .. clase mismo horario
    D[1]=  {"2", 1, inscripciones2};    // 2-1 SPINNIN   .. este tiene saldo negativo
    D[2]=  {"3", 3, inscripciones3}; //3-X2 1 SPINNIG, 20 STETCHIN 15   ..clase repetida y cupomax
    D[3]=  {"4", 2, inscripciones4};   // 4- todo ok

    clase[0].cant_clientes=44;


    SECTION("FallasInscripcion"){
        ReservaClase(D,cliente,clase);
        int falla=FallasInscripcion(D[3]);
        REQUIRE(falla==2);
    }

    SECTION("Reserva"){

        ReservaClase(D,cliente,clase);
        REQUIRE(D[2].id_cliente=="0");

    }

    delete []clase;
    delete[]cliente;
    delete []D;

}*/
TEST_CASE("Funciones Auxiliares de Reserva")
{


   sClases *clase = new sClases [5];
   clase[0]={"1","Spinning",8.0,spinn,0};
   clase[1]={"8","Yoga",11.0,yoga,0};
   clase[2]={"10","Yoga",16.0,yoga,0};
   clase[3]={"12","Pilates",8.0,pilates,0};
   clase[4]={"15","Pilates",12.0,pilates,0};

   sCliente *cliente=new sCliente[4];

   cliente[0]={"1", "Agustín", "Guerra", "AgustínGuerra@bolandia.iri", "462-185-1730", "10-12-1966", 0};
   cliente[1]={"2", "Emilio", "Romero", "EmilioRomero@bolandia.iri", "317-427-6829", "14-08-1998", -3241};
   cliente[2]={"3", "Tomás", "Lanaro", "TomásLanaro@bolandia.iri", "426-646-4494", "19-02-1996", 8313};
   cliente[3]={"4", "Gabriel", "Hernández", "GabrielHernández@bolandia.iri", "527-298-4006", "02-05-1990", 0};

    sInscripciones inscripciones1[2] = {{"1", 109029092}, {"12", 109029323}};
    sInscripciones inscripciones2[1] = {{"1", 132322131}};
    sInscripciones inscripciones3[3] = {{"8", 1231242321}, {"1", 1231242321}, {"8", 1231242321}};
    sInscripciones inscripciones4[2] = {{"10", 1231242321}, {"15", 1231242322}};
    uint tam=4;
    sAsistencia *D=new sAsistencia[tam];

    D[0]=  {"1", 2, inscripciones1};// 1 SPINN 8am , 12 PILATES 8am --> clase mismo horario
    D[1]=  {"2", 1, inscripciones2};// 1 SPINN --> este tiene saldo negativo
    D[2]=  {"3", 3, inscripciones3};// 1x2 SPINNIG, 8 YOGA --> clase repetida y cupomax
    D[3]=  {"4", 2, inscripciones4}; // YOGA PILATES -->TODO OK

    clase[0].cant_clientes=44;

    SECTION("ControlSaldo"){

        ControlSaldo(D,cliente,tam);
        CHECK(D[2].id_cliente=="0");}


    SECTION("ControlRepetidos"){

        ControlRepetidos(D,tam);
        CHECK(D[3].inscripciones[2].fecha==0);

    }

    SECTION("ControlHorario"){

        ControlHorario(D,clase,tam);
        CHECK(D[0].inscripciones[1].id_clase=="0");
    }

    SECTION("ControlCupo"){

        ControlCupo(D,clase,tam);
        CHECK(D[3].inscripciones[2].id_clase=="0");
    }


    delete [] D;
    delete [] clase;
    delete [] cliente;
}

