
#include <Clases.h>
#include <catch2/catch.hpp>
TEST_CASE("Funciones Buscar Horario ","BH")
{
    sClases *clase = new sClases [5];
    clase[0]={"1","Spinning",8.0,spinn,0};
    clase[1]={"8","Yoga",11.0,yoga,0};
    clase[2]={"10","Yoga",16.0,yoga,0};
    clase[3]={"12","Pilates",8.0,pilates,0};
    clase[4]={"15","Pilates",12.0,pilates,0};
    REQUIRE (BuscarHorario("1",clase) == 8.0);
  //  REQUIRE (BuscarHorario("10",clase)==16.0);

    delete [] clase;
}

TEST_CASE("LlenarCupo"){

    sClases *clase = new sClases [1];
    clase->id_clase="1";
    clase->clase_nombre="Spinning";
    clase->horario=8.0;
    clase->cupo_max=vacio;
    clase->cant_clientes=0;

    CHECK( LlenarCupo(clase->clase_nombre )== spinn);




}
