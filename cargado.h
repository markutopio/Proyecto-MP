//Adminprov, Productos, Categorias, Descuentos, DescuentosClientes, Lockers, CompartimentosLockers, Pedidos, ProductosPedidos, Transportistas y devoluciones
#include "datos.h"
#ifndef _CARGADO_
#define _CARGADO_

int carga_clientes(Clientes **,int);
int carga_adminprov(Adminprov **,int);
int carga_prod(Productos **, int);
int carga_cat(Categorias **, int);
int carga_desc(Descuentos **, int);
int carga_descclient(Descuentosclientes **, int);
int carga_lockers(Lockers **, int);
int carga_compartlockers(Compartimentoslockers **, int);
int carga_ped(Pedidos **, int);
int carga_pedprod(Productospedidos **, int);
int carga_transp(Transportistas **, int);
int carga_devo(Devoluciones **, int);

#endif // _CARGADO_



