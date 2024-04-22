#ifndef _ME_
#define _ME_
#include "datos.h"
#include "cargado.h"
#include "moduloguardar.h"

void presentacion();
void salir_aplicacion();
int ventana_inicio();
int ventana_cliente();
int ventana_admin();
int ventana_proveedor();
int ventana_transportista();
int login(Clientes *,int);
#endif // _ME_
