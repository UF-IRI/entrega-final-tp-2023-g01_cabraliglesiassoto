#include "Cliente.h"


int LeerClienteArchivo(sCliente *&cliente, ifstream &archivo, uint &n){

    stringstream ss;
    string primera_linea, linea;
    char coma=',';

    if(!archivo.is_open()) {
        cout<<"Error al abrir archivo " <<endl;

    }

    getline(archivo,primera_linea);
    while(!archivo.eof()&& getline(archivo,linea)){


        ss.clear();
        ss<<linea;
        resize_cliente(cliente,n);


        getline(ss,linea,coma);
        cliente[n-1].id_cliente=linea;

        getline(ss,linea,coma);
        cliente[n-1].Nombre=linea;

        getline(ss,linea,coma);
        cliente[n-1].Apellido=linea;

        getline(ss,linea,coma);
        cliente[n-1].mail=linea;

        getline(ss,linea,coma);
        cliente[n-1].telefono=linea;

        getline(ss,linea,coma);
        cliente[n-1].fechaNacimiento=linea;

        getline(ss,linea);
        cliente[n-1].saldo= stoi(linea);



    }

    return 0;
}

void resize_cliente (sCliente *& cliente, uint &n){
    if(cliente==nullptr){
        if(n==0){
            cliente = new sCliente[++n];
        }
        return;
    }

    sCliente* aux = new sCliente[++n];

    for(uint i = 0; i < n-1; i++)
        aux[i] = cliente[i];

    delete[] cliente;
    cliente= aux;

}



uint stingtouint(string texto)
{

    uint resultado=0;
    for(uint i=0; i< texto.length(); i++){


        if(texto[i]>='0' && texto[i]<= '9')
            resultado=resultado *10 + (texto[i]-'0');

    }

    return resultado;

}


