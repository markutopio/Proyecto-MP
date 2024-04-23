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
void iniciar_cliente(Clientes *, int, int);
void iniciar_admin(Adminprov *, int, int);
void iniciar_prov(Adminprov *, int, int);
void iniciar_transp(Transportistas *, int, int);
void crear_cliente(Clientes *, int *);
void crear_admin(Adminprov *, int *);
void crear_prov(Adminprov *, int *);
void crear_transp(Transportistas *, int *);
#endif // _ME_
