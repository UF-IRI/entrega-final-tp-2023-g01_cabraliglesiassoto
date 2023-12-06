#include "Cliente.h"
#include <catch2/catch.hpp>

TEST_CASE("Control Saldo"){



   sCliente *cliente=new sCliente[1];
   cliente[0]={"2", "Emilio", "Romero", "EmilioRomero@bolandia.iri", "317-427-6829", "14-08-1998", -3241};


    REQUIRE( ControlEstado(cliente)==false );



    delete [] cliente;
}
