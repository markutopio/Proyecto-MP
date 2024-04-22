#ifndef _CLIENTE_
#define _CLIENTE_
#include "datos.h"
#include "prueba_aux.h"

int intro_client(Clientes **, int);
int modifica_cliente(Clientes *,int);
int alta_clientes(Clientes **,int);
int baja_clientes(Clientes **,int);
void listado_cliente(Clientes *,int);
int busqueda_cliente(Clientes *,int);


#endif // _CLIENTE_
