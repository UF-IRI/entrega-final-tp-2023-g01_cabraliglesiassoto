
#include "Cliente.h"
#include <catch2/catch.hpp>

TEST_CASE("Control Saldo","hola"){



    Cliente *cliente = new Cliente;

    // Asignar valores al cliente
    cliente->id_cliente = "2";
    cliente->Nombre = "Emilio";
    cliente->Apellido = "Romero";
    cliente->mail = "EmilioRomero@bolandia.iri";
    cliente->telefono = "317-427-6829";
    cliente->fechaNacimiento = "14-08-1998";
    cliente->saldo = -3241;

    REQUIRE( ControlEstado(cliente)==false );



    delete cliente;
}
